#ifndef ERROR_H
#define ERROR_H
//Error class
class connectionError{
public:
	void addError(std::string msg){errMsg = errMsg + msg + "\n"; error = true;}
	bool isError(){return error;}
	std::string errorMessage(){return errMsg;}
private:
	std::string errMsg = "";
	bool error = false;
};
#endif
