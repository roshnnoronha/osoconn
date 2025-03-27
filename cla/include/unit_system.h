/*
Unit System Class
==================================================
By		:Roshn Noronha
Date	:XX/XXX/XXXX

This file defines the class that contains the 
definitions of the unit systems used for the 
connection calculations. The two systems defined 
by this class is the NEWTON_MM and KIP_IN. 

This code is part of the osoConn open source 
connection design project.
==================================================
*/ 
#ifndef UNITSYSTEM_H
#define UNITSYSTEM_H

class unit_system
{
public:
	enum EUS {NEWTON_MM,KIP_IN};
	//constructors
	unit_system(){
		u = NEWTON_MM;
	}
	unit_system (EUS unitSys){
		u = unitSys;
	}
	//output functions 
	void setUnitSystem(EUS unitSys){
		u = unitSys;
	}
	EUS getUnitSystem(){
		return u;
	}
	std::string forceUnit(){
		if (u == NEWTON_MM)
			return "N";
		else
			return "kip";
	}
	std::string lengthUnit(){
		if (u == NEWTON_MM)
			return "mm";
		else
			return "in";		
	}
	std::string stressUnit(){
		if (u == NEWTON_MM)
			return "MPa";
		else
			return "ksi";		
	}
	std::string forcePerUnitLength(){
		if (u == NEWTON_MM)
			return "N/mm";
		else
			return "kip/in";			
	}
	std::string momentUnit(){
		if (u == NEWTON_MM)
			return "N mm";
		else
			return "kip in";		
	}	
	std::string areaUnit(){
		if (u == NEWTON_MM)
			return "mm^2";
		else
			return "in^2";		
	}
private:
	EUS u;
};

#endif
