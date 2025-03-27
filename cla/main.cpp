#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <filesystem>
#include "osoconnConfig.h"
#include "sqlite3.h"
#include "unit_system.h"
#include "bolt.h"
#include "section_property.h"
#include "weld.h"
#include "common.h"
#include "error.h"
#include "parameter.h"
#include "connection.h"
#include "SC001AM10.h"
#include "MC001AM10.h"
#include "HB001AM10.h"
#include "VB001AM10.h"
#include "utilities.h"
namespace fs = std::filesystem;
int main(int argc, char *argv[])
{	
	std::map<std::string,std::string> connData;
	std::vector<std::string> fileList;
	std::string connString;
	std::string fp = "";
	std::string filename;
	std::string outputFilename;
	bool showOutput = false;
	bool inputByString = false;
	bool noInputFile = true;
	bool updateByString = false;
	bool outputFileSpecified = false;
	bool overwriteFile = false;
    bool webMode = false;
	std::string updateString;
	std::vector<std::string> inputStringList;
	std::string inputString = "";
	std::ofstream fout;
	connection* conn = NULL;
	size_t pos;
	std::filesystem::path progPath(argv[0]);
    
    std::filesystem::path databasePath = progPath.parent_path() / "data" / "AISCSections.db";
    section_property::filePath =  databasePath.string();
	try{
		if (argc > 1){		
			for (int i = 1; i < argc; i++){
                if (strcmp(argv[i],"--web") == 0){
                    webMode = true;
                }else if (strcmp(argv[i], "-p") == 0){
					showOutput = true;
				}else if (strcmp(argv[i],"-ow") == 0){
					overwriteFile = true;
				}else if (strcmp(argv[i],"-u") == 0) {
					updateByString = true;
					i++;	
					if ((*argv[i] == '-')||(i == argc)) throw "Expecting update string after the -u flag.";
					updateString = argv[i];				
				}else if (strcmp(argv[i], "-s") == 0){
					inputByString = true;
					i++;			
					if ((*argv[i] == '-')||(i == argc)) throw "Expecting string or filename after the -s flag.";
					inputString = argv[i];
				}else if (strcmp(argv[i], "-o") == 0){
					outputFileSpecified = true;
					i++;
					if ((*argv[i] == '-')||(i == argc)) throw "Expecting filename after the -o flag.";
					outputFilename = argv[i];
				}else if (*argv[i]=='-'){
					char a[] = "Unknown flag ";
					throw strcat(a, argv[i]);
				}else{
					fp = argv[i];
					noInputFile = false;
				}
			}	
	        if (!webMode){
                std::cout<<"\nOsoconn v"<<osoconn_VERSION_MAJOR<<"."<<osoconn_VERSION_MINOR<<"\n============\n";
                std::cout<<"Osoconn is a free and open source connection design app. This\napp is licensed under the MIT open-source license.\n\n*\n\n";
            }        
			//check if no input file or no input string is provided
			if (noInputFile && inputByString)
				fileList.push_back("");
			else if (noInputFile)
				throw "Missing input file/path.";
			//get list of input files
			if (!noInputFile){
				fs::path filePath(fp);
				if (fs::is_directory(filePath)){
					//folder with multiple input files
					for(auto fp : fs::directory_iterator(filePath)){
						filename = fp.path().filename().string();
						pos = filename.find(".cin");
						if (pos != std::string::npos)
							fileList.push_back(fp.path().string());
					}
				}else if (fs::is_regular_file(filePath)){
					//single input file
					fileList.push_back(fp);
				}else{
					//file does not exist try and create empty file
					std::ofstream temp(fp);
					if (temp.is_open()){
						fileList.push_back(fp);
						temp.close();
					}else throw "Invalid file name/path.\n";
				}
			}
			//manual input by string or list of strings in file
			if (inputByString){
				try{
					fs::path filePath(inputString);
					if (fs::is_regular_file(filePath)){
						//file with multiple input strings follows the -s flag
						std::ifstream file(inputString);
						std::string line;
						if (file.is_open()){
							while (std::getline (file,line))
								inputStringList.push_back(line);
							file.close();
						}else if(!webMode)
                            throw "Unable to open file " + inputString;
					}else
						inputStringList.push_back(inputString);
				}catch(std::filesystem::__cxx11::filesystem_error e){
					inputStringList.push_back(inputString);
				}
			}
			//generate and run connection 
			for (auto fp : fileList){	
				try{
                    connData.clear();
					if (fp != ""){
						if (!webMode) std::cout<<"Running file "<<fp<<"...\n";
						//update file with update strings
						if (updateByString){
							std::map<std::string,std::string> stringData;
							oso::readString(stringData,updateString);
							oso::updateFile(stringData, fp, overwriteFile);
						}
						oso::readFile(connData,fp);
					}
					//get string inputs
					if (inputByString){
						for (auto inputString : inputStringList){
							std::map<std::string,std::string> stringData;
							oso::readString(stringData,inputString);
							if ((stringData.count("CONNECTION_CODE") != 0) && (connData.count("CONNECTION_CODE") != 0))
								if (stringData["CONNECTION_CODE"] != connData["CONNECTION_CODE"]) 
									break;
							if ((stringData.count("CONNECTION_ID") != 0) && (connData.count("CONNECTION_ID") != 0))
								if (stringData["CONNECTION_ID"] != connData["CONNECTION_ID"])
									break;
							oso::updateConnectionData(stringData,connData);	
							conn = oso::defineConnection(connData);
							if (conn->pass()) break;
							if (conn){
								delete conn;
								conn = NULL;
							}								
						}
					}
					if (!conn) conn = oso::defineConnection(connData);
                    if (!webMode){
                        std::cout<<"Run successful.\n";
                        if (conn->pass()) 
                            std::cout<<"Connection is OK.\n";
                        else 
                            std::cout<<"Connection is NOT OK.\n";
                    }
					//write output file
					if (outputFileSpecified)
						filename = outputFilename;
					else{
						if (fp == "")
							filename = conn->connectionID() + ".cou";
						else{
							fs::path filePath(fp);
							fs::path ext(".cou");
							filePath.replace_extension(ext);
							filename = filePath.string();
						}
					}
					fout.open (filename);
					if (fout.is_open()){
						fout<<conn->designOutput();
						fout.close();	
					}else if (!webMode)
                        throw "Unable to open file "+filename+" for writing.";
					if (!webMode) std::cout<<"Output written to file "<<filename<<"\n";
					//display input/design summary/calculation as per flags set
					if (showOutput)
						std::cout<<conn->designOutput();
					//free memory 
					if (conn) {
						delete conn;
						conn = NULL;
					}
				}catch (char const* e){
					std::cout<<"Run unsuccessful.\n"<<e<<'\n';
				}catch (std::string e){
					std::cout<<"Run unsuccessful.\n"<<e<<'\n';
				}
				std::cout<<"*\n";
			}
		}else{
			std::cout<<"To run osoconn for a input file use the following syntax:\n\n\tosoconn <filename>\n\nwhere <filename> should be replaced by the path to a osoconn\ninput file having a .cin extension. To run osoconn on multiple\nfiles, replace the <filename> parameter with the path to the\nfolder containing the osoconn input files.\n";
			
		}
	}catch (char const* e){
		std::cout<<"Error: \n"<<e<<'\n';
	}catch (std::string e){
		std::cout<<"Error: \n"<<e<<'\n';
	}
	return 0;

}
