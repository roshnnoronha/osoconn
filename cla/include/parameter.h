#ifndef PARAMETER_H
#define PARAMETER_H
//Parameter class
class parameter{
public:
	std::string name;
	std::string defaultValue;
	void addAllowableValue(std::string val){_allowableValues.push_back(val);_allowsLimitedValues = true;}
	void isPositiveNumber(){_isPositive = true;_isNumeric =true;}
	void isNumber(){_isNumeric = true;}
	void isInteger(){_isInteger = true;_isNumeric = true;}
	void setMinimumValue(double m){_minValue = m;_isNumeric = true;_isMinBound = true;}
	void setMaximumValue(double m){_maxValue = m;_isNumeric = true;_isMaxBound = true;}
	bool _allowsLimitedValues = false;
	bool _isInteger = false;
	bool _isNumeric = false;
	bool _isPositive = false;
	bool _isNonNegative = false;
	bool _isMaxBound = false;
	bool _isMinBound = false;
	double _maxValue = 0;
	double _minValue = 0;
	std::vector<std::string> _allowableValues;
};
#endif
