#ifndef CONNECTION_H
#define CONNECTION_H

//Connection class
class connection{
public:
    void printDesignOutput();
	virtual std::string designInput()=0;
	virtual std::string designSummary()=0;
	virtual std::string designCalculation()=0;
	virtual bool pass()=0;
	void addParameter(std::string,std::string);
	void validateParameters(std::map<std::string,std::string>&);
	parameter& param(std::string);
	std::string designOutput();
	std::string connectionID(){return connID;}
protected:
	std::map<std::string,parameter> connParams;
	std::string connID;
    std::string connCode;
	connectionError err;
};

void connection::printDesignOutput()
{
    std::cout<<"Osoconn v"<< osoconn_VERSION_MAJOR << "." << osoconn_VERSION_MINOR <<"\n";
    std::cout<<"Connection code : "<<connCode << "\n";
    std::cout<<"Connection ID : "<<connID <<"\n";
	std::cout<<designInput();
	std::cout<<designSummary();
	std::cout<<designCalculation();
}
void connection::addParameter(std::string name,std::string defaultValue = ""){
	parameter p;
	p.name = name;
	p.defaultValue = defaultValue;
	connParams[name] = p;
}
void connection::validateParameters(std::map<std::string,std::string>& data){
	for (auto para : connParams){        
		if (para.second.defaultValue == ""){
			if (data.count(para.first) == 0)                
                err.addError("Missing input parameter " + para.first + ".");
        }
	}
	for (auto datum : data){
		std::string paraName = datum.first;
		std::string paraVal = datum.second;
		if (connParams.count(paraName) == 0) 
			err.addError("Unknown input parameter " + paraName + ".");
		else{
			//check for allowable values
			if (connParams[paraName]._allowsLimitedValues){
				std::string allVals = "";
				int allValCount = 0;
				bool isAllowed = false;
				for (auto val : connParams[paraName]._allowableValues){
					if (allVals != "")
						allVals = allVals + "|" + val;
					else
						allVals = val;
					allValCount++;
					if (val == paraVal) isAllowed = true;
				}
				if (!isAllowed) err.addError("Invalid input for " + paraName + ". Expecting " +(allValCount==1?"value ":"values ")+allVals + ".");
			}
			//Numeric value checks		
			if (!connParams[paraName]._isNumeric) 
				continue;
			
			if (!oso::isNumber(paraVal)){
				err.addError("Invalid input for " + paraName + ". Expecting a numeric value.");
				continue;	
			}else{
				if (connParams[paraName]._isPositive)
					if (!oso::isPositiveNumber(paraVal)){
						err.addError("Invalid input for " + paraName + ". Expecting a positive number.");
						continue;
					}
				if (connParams[paraName]._isInteger)
					if (!oso::isInteger(paraVal)){
						err.addError("Invalid input for " + paraName + ". Expecting an integer.");
						continue;
					}
				if (connParams[paraName]._isMinBound){
					double num = atof(paraVal.c_str());
					std::string minVal = oso::to_string(connParams[paraName]._minValue);
					if (num < connParams[paraName]._minValue){
						err.addError("Invalid input for " + paraName + ". Value must be greater than or equal to " + minVal + ".");
						continue;
					}
				}
				if (connParams[paraName]._isMaxBound){
					double num = atof(paraVal.c_str());
					std::string maxVal = oso::to_string(connParams[paraName]._maxValue);
					if (num > connParams[paraName]._maxValue){
						err.addError("Invalid input for " + paraName + ". Value must be lesser than or equal to " + maxVal + ".");
						continue;
					}					
				}				
			}
		}
	}
}
parameter& connection::param(std::string paramName){
	return connParams[paramName];
}
std::string connection::designOutput(){
	std::string o = "";
    o = o + "Osoconn v" + std::to_string(osoconn_VERSION_MAJOR) +  "."  +  std::to_string(osoconn_VERSION_MINOR)  + "\n";
    o = o + "Connection code : " + connCode + "\n";
    o = o + "Connection ID : " + connID + "\n";
   	o = o + designSummary();
	o = o + designInput();
	o = o + designCalculation();
	return o;
}
#endif
