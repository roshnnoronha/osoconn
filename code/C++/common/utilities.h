namespace oso{

//File IO functions
int parseNextLine(std::ifstream& file,std::string& paraName, std::string& paraVal,std::string& line){
	line = "";
	paraName = "";
	paraVal = "";
	if (file.is_open())
		if(std::getline(file,line)){
			if(line[0]!='*'){
				std::stringstream ln(line);
				ln >> paraName;
				ln >> paraVal;
			}
			return 1;
		}else
			return 0;
	return 0;
}
//function to read conneciton data from file
void readFile(std::map<std::string,std::string>& connData, std::string filename){
	std::string paramName, paramVal,line;
	std::ifstream file(filename);
	if (file.is_open()){
		while (parseNextLine(file,paramName,paramVal,line)){
			if (paramName != ""){
				if (connData.count(paramName) == 0)
					connData.insert(std::pair<std::string,std::string>(paramName,paramVal));
				else 
					connData[paramName] = paramVal;
			}
		}
		file.close();
	}	

}
//function to update the contents of an input file with the data in connData
void updateFile(std::map<std::string,std::string>& connData, std::string filename, bool overwriteFile = false){
	
	std::string outputString = "";
	std::string paramName,paramVal,line,fParamName;
	std::vector<std::string> fileContent;
	bool found;
	//read contents of input file into a vector
	if (!overwriteFile){
		std::ifstream in(filename);
		if (in.is_open()){
			while(std::getline(in,line))
				fileContent.push_back(line);
			in.close();
		}else throw "Unable to open file " + filename;
	}
	//update the vector with connData
	for(auto i : connData){
		paramName = i.first;
		paramVal = i.second;
		if (!overwriteFile){
			found = false;
			for (auto& fl : fileContent){
				std::stringstream ln(fl);
				ln >> fParamName;
				if (fParamName == paramName){
					found = true;
					fl = paramName + " " + paramVal;
				}
			}
			if (!found) fileContent.push_back(paramName + " " + paramVal);
		}else
			fileContent.push_back(paramName + " " + paramVal);
	}
	// update file with new vector
	std::ofstream out(filename);
	if(out.is_open()){
		for (auto fl : fileContent)
			out << fl + "\n";
		
		out.close();
	}else throw "Unable to open file " + filename;
	
}
//function to read a string of the for 'PARAMETER_NAME1 VALUE1; PARMETER_NAME2 VALUE2...'
//and copy the parameter value pair to the connData variable
void readString(std::map<std::string,std::string>& stringData,std::string inputString){
	std::string paraName, paraVal;
	std::string line;
	std::stringstream inStr(inputString);
	paraName = "";
	paraVal = "";
	while (std::getline(inStr,line,';')){
		if(line[0]!='*'){
			//std::cout<<"DEBUG:line="<<line<<std::endl;
			std::stringstream ln(line);
			ln >> paraName;
			ln >> paraVal;
			if (paraName != ""){
				stringData.insert(std::pair<std::string,std::string>(paraName,paraVal));
			}
		}	
	}

}
//function update the connection data in 'toData' with the values in 'fromData'.
void updateConnectionData(const std::map<std::string,std::string>& fromData, std::map<std::string,std::string>& toData){
	std::string paraName;
	std::string paraVal;
	for (auto i : fromData){
		paraName = i.first;
		paraVal = i.second;
		//check if parameter already exists in the data. If it does update it.
		if (toData.count(paraName) == 0)
			toData.insert(std::pair<std::string,std::string>(paraName,paraVal));
		else 
			toData[paraName] = paraVal;
	}
}
//function to define connections 
connection* defineConnection(std::map<std::string,std::string> connData){
	if (connData["CONNECTION_CODE"] == "SC001"){		
		shearConnection1* c = new shearConnection1(connData);
		return c;
	}else if (connData["CONNECTION_CODE"] == "MC001"){
		momConnection1* c = new momConnection1(connData);
		return c;
	}else if (connData["CONNECTION_CODE"] == "HB001"){
		HBConnection1* c = new HBConnection1(connData);
		return c;
	}else if (connData["CONNECTION_CODE"] == "VB001"){
		vbConnection1* c = new vbConnection1(connData);
		return c;
	}else throw "Invalid CONNECTION_CODE";
}

}