#ifndef COMMON_H
#define COMMON_H


#define PI 3.141592653589793238462643383279

namespace oso{

	//Output functions

	std::string format_p(std::string value,std::string description,std::string formula="",std::string units ="",std::string reference="", int prescision=3,int padding = 70){
		std::ostringstream s;
		if (formula == "")
			s<<std::setfill(' ')<<std::setw(padding)<<std::left<< "   " + description  << " | " <<value << " "<< units;
		else{
			s<<std::setfill(' ')<<std::setw(padding)<<std::left<< "   " + description  << " | " <<std::endl;
			formula = (formula=="")?formula:"[" + formula +"]";
			s<<std::setfill(' ')<<std::setw(padding)<<std::left<< "      " + formula<<" | " <<value << " "<< units;
		}
		s<<std::endl;
		std::setprecision(0);
		return s.str();
	}
	std::string format_p(double value,std::string description,std::string formula="",std::string units = "",std::string reference="", int prescision=3, int padding = 70){	
		std::ostringstream s;
		if (formula == "")
			s<<std::setfill(' ')<<std::setw(padding)<<std::left<< "   " + description  << " | " <<std::fixed<<std::setprecision(prescision) <<value << " "<< units;
		else{
			s<<std::setfill(' ')<<std::setw(padding)<<std::left<< "   " + description  << " | " <<std::endl;
			formula = (formula=="")?formula:"[" + formula +"]";
			s<<std::setfill(' ')<<std::setw(padding)<<std::left<< "      " + formula<<" | "<<std::fixed<<std::setprecision(prescision) <<value << " "<< units;
		}
		s<<std::endl;
		std::setprecision(0);
		return s.str();
	}
	std::string format_br(int padding = 70){
		std::ostringstream s;
		s<<std::setw(padding)<<std::left<< " "<<" | " <<std::endl;
		return s.str();
	}
	std::string format_hr(int padding = 70){
		std::ostringstream s;
		for (int i = 0 ; i<padding; i++)
			s<<"-";
		s<<"-+---------------------" <<std::endl;
		return s.str();
	}
	std::string format_h1(std::string heading,int padding = 70){
		std::ostringstream s;
		s<<format_hr();
		s<<std::setw(padding)<<std::left<< heading <<" | " <<std::endl;
		s<<format_hr();
		//for(int i=0; i<heading.length() ;i++)ul = ul + "-";
		//s<<std::setw(padding)<<std::left<< ul <<" | " <<std::endl;		
		return s.str();
	}
	std::string format_h2(std::string heading,int padding = 70){
		std::ostringstream s;
		std::string ul;
		s<<format_br();
		s<<std::setw(padding)<<std::left<< heading <<" | " <<std::endl;
		for(int i=0; i<heading.length() ;i++)ul = ul + "-";
		s<<std::setw(padding)<<std::left<< ul <<" | " <<std::endl;		

		return s.str();
	}
	std::string format_h3(std::string heading,int padding = 70){
		std::ostringstream s;
		s<<format_br();
		s<<std::setw(padding)<<std::left<< heading + ":"<<" | " <<std::endl;
		return s.str();
	}	

	//Validation functions
	bool isNumber(std::string numStr){
		for(int i = 0; i<numStr.length();i++)
			if(!isdigit(numStr[i]) && numStr[i]!='.' && numStr[i]!='-') return false;
		return true;
	}
	bool isInteger(std::string numStr){
		for(int i = 0; i<numStr.length();i++)
			if(!isdigit(numStr[i]) && numStr[i]!='-') return false;
		return true;		
	}
	bool isNumberInRange(std::string numStr, double minVal, double maxVal){
		if (!isNumber(numStr))return false;
		double num = atof(numStr.c_str());
		if ((num<minVal)||(num>maxVal)) return false;
		return true;
	}
	bool isPositiveNumber(std::string numStr){
		if (!isNumber(numStr))return false;
		double num = atof(numStr.c_str());
		if (num<0) return false;
		return true;
	}
	bool isNotNegativeNumber(std::string numStr){
		if (!isNumber(numStr))return false;
		double num = atof(numStr.c_str());
		if (num<=0) return false;
		return true;
	}
	std::string to_string(double a){
		std::ostringstream s; 
		s << a; 
		return s.str();
	}



}




#endif