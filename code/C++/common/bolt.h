/*
Bolt Class
==================================================
By		:Roshn Noronha
Date	:XX/XXX/XXXX

This file defines the class that contains the 
definitions and common functions for bolt design as 
per AISC 360-2010 Steel Specifications. The bolts 
can be specified to ASTM F3125, either as grade 
A325 or A490. The bolts may be either bearing or 
slip-critical bolts with threads included or not 
included in the shear plane.

This code is part of the osoConn open source 
connection design project.
==================================================
*/ 

#ifndef BOLT_H
#define BOLT_H

class bolt
{
public:
	enum grade {ASTM_A325,ASTM_A490};
	enum bolt_type {BEARING,FRICTION};
	enum bolt_thread {THREAD_INCLUDED_IN_SHEAR_PLANE, THREAD_EXCLUDED_FROM_SHEAR_PLANE};
	enum bolt_dia {M16, M20, M22, M24,M27,M30,M36,IN_1_2,IN_5_8,IN_3_4,IN_7_8,IN_1,IN_1_1_8,IN_1_1_4,IN_1_3_8,IN_1_1_2};
	enum surface {CLASS_A,CLASS_B};
	enum bearing_type {DEFORMATION_IS_A_CONSIDERATION,DEFORMATION_IS_NOT_A_CONSIDERATION};
	enum design_method {LRFD,ASD};
	//constructors
	bolt(bolt_dia, grade, bolt_type, design_method,unit_system::EUS);

	//utility functions
	void setBoltDiameter(bolt_dia);
	void setBoltDiameter(std::string);
	void setBoltType(bolt_type t){typ=t;}
	void setBoltGrade(grade);
	void setMethod(design_method m){method = m;}
	void setUnitSystem(unit_system::EUS);
	void setBoltThreadType(bolt_thread);
	void setFayingSurface(surface s){sur = s;}
	std::string boltGrade(){return (grad==ASTM_A325)?"ASTM A325": "ASTM A490";}
	bolt_type boltType(){return typ;}
	bool boltThreadInShearPlane(){return (thrd == THREAD_EXCLUDED_FROM_SHEAR_PLANE)?false:true;}
	double nominalTensileStress(){return Fnt;}
	double nominalShearStress(){return Fnv;}
	double nominalShearStrength(int);
	double nominalShearStrength(double T, int);					//shear strength of slip critical bolts combined with tension T
	double nominalTensionStrength();
	double nominalTensionStrength(double V);					//Tension strength of bearing bolts combined with shear V
	double nominalBearingStrength(double,double,double);
	double minEdgeDistance();
	double minBoltSpacing(){return 2.66667*db;}
	double diameter(){return db;}
	double standardBoltHole();
	
private:
	bolt_dia Mdia;
	design_method method;
	unit_system us;
	double db;						//bolt dia
	double Fnt;						//Nominal tensile strength
	double Fnv;						//Nominal shear strength
	bolt_thread thrd;
	grade grad;						//bolt grade
	bolt_type typ;
	surface sur;
	double Tb;						//minimum fastner pretension
	int ns;							//number of slip planes
	bearing_type brtyp;
	void setBoltPretension();

};

//////////////////////CONSTRUCTORS/////////////////////////////
bolt::bolt(bolt_dia dia = M22, grade gr = ASTM_A325, bolt_type t = BEARING, design_method m = LRFD, unit_system::EUS us = unit_system::NEWTON_MM){
	setBoltType(t);
	setBoltGrade(gr);
	setBoltDiameter(dia);
	setMethod(m);
	setUnitSystem(us);
	setBoltThreadType(THREAD_INCLUDED_IN_SHEAR_PLANE);
	setFayingSurface(CLASS_A);
	brtyp=DEFORMATION_IS_A_CONSIDERATION;
}


/////////////////////UTILITY FUNCTIONS////////////////////////
void bolt::setBoltGrade(grade gr){
	grad=gr;
	switch (grad){
		case ASTM_A325:
			Fnt=(us.getUnitSystem()==unit_system::NEWTON_MM)?620.0:90.0;
			if (thrd==THREAD_INCLUDED_IN_SHEAR_PLANE)	
				Fnv=(us.getUnitSystem()==unit_system::NEWTON_MM)?372.0:54.0;
			else 
				Fnv=(us.getUnitSystem()==unit_system::NEWTON_MM)?457.0:68.0; 
			break;
		case ASTM_A490:
			Fnt=(us.getUnitSystem()==unit_system::NEWTON_MM)?780.0:113.0;
			if (thrd==THREAD_INCLUDED_IN_SHEAR_PLANE)	
				Fnv=(us.getUnitSystem()==unit_system::NEWTON_MM)?457.0:68.0;
			else 
				Fnv=(us.getUnitSystem()==unit_system::NEWTON_MM)?579.0:84.0;
			break;			
	}
	
	setBoltPretension();
}
void bolt::setBoltThreadType(bolt_thread t){
	thrd = t;
	setBoltGrade(grad);
}
void bolt::setUnitSystem(unit_system::EUS unitSys){
	us.setUnitSystem(unitSys);
	//convert bolt dia to nearest equivalent
	if (unitSys == unit_system::KIP_IN){
		switch (Mdia){
			case M16: 
				setBoltDiameter(IN_5_8); break;
			case M20: 
				setBoltDiameter(IN_3_4); break;
			case M22:
				setBoltDiameter(IN_7_8); break;
			case M24: 
				setBoltDiameter(IN_1); break;
			case M27: 
				setBoltDiameter(IN_1_1_8); break;
			case M30: 
				setBoltDiameter(IN_1_1_4); break;
			case M36: 
				setBoltDiameter(IN_1_3_8); break;				
		}
	}else{
		switch (Mdia){
			case IN_1_2: 
				setBoltDiameter(M16); break; //NOTE:AISC does not specify metric bolts smaller that M16
			case IN_5_8: 
				setBoltDiameter(M16); break;
			case IN_3_4:
				setBoltDiameter(M20); break;
			case IN_7_8: 
				setBoltDiameter(M22); break;
			case IN_1: 
				setBoltDiameter(M24); break;
			case IN_1_1_8: 
				setBoltDiameter(M27); break;
			case IN_1_1_4: 
				setBoltDiameter(M30); break;
			case IN_1_3_8: 
				setBoltDiameter(M36); break;
			case IN_1_1_2: 
				setBoltDiameter(M36); break;	
		}		
	}	
}
void bolt::setBoltDiameter(bolt_dia dia){
	Mdia=dia;
	if (us.getUnitSystem() == unit_system::NEWTON_MM){
		switch (Mdia){
			case M16: 
				db=16.0; break;
			case M20: 
				db=20.0; break;
			case M22:
				db= 22.0; break;
			case M24: 
				db=24.0; break;
			case M27: 
				db=27.0; break;
			case M30: 
				db=30.0; break;
			case M36: 
				db=36.0; break;
			default:
				throw "Invalid bolt diameter. Expecting values M16|M20|M22|M24|M27|M30|M36";
		}
	}else{
		switch (Mdia){
			case IN_1_2: 
				db=0.5; break;
			case IN_5_8: 
				db=0.625; break;
			case IN_3_4:
				db= 0.75; break;
			case IN_7_8: 
				db=0.875; break;
			case IN_1: 
				db=1.0; break;
			case IN_1_1_8: 
				db=1.125; break;
			case IN_1_1_4: 
				db=1.25; break;
			case IN_1_3_8: 
				db=1.375; break;
			case IN_1_1_2: 
				db=1.5; break;	
			default:
				throw "Invalid bolt diameter. Expecting values 1/2 | 5/8 | 3/4 | 7/8 | 1 | 1_1/8 | 1_1/4 | 1_3/8 | 1_1/2";
		}
	}
	setBoltPretension();
}
void bolt::setBoltDiameter(std::string dia){
	if (us.getUnitSystem() == unit_system::NEWTON_MM){
		if (dia == "M16")
			setBoltDiameter(M16);
		else if (dia == "M20")
			setBoltDiameter(M20);
		else if (dia == "M22")
			setBoltDiameter(M22);
		else if (dia == "M24")
			setBoltDiameter(M24);
		else if (dia == "M27")
			setBoltDiameter(M27);
		else if (dia == "M30")
			setBoltDiameter(M30);
		else if (dia == "M36")
			setBoltDiameter(M36);
		else throw "Invalid bolt diameter. Expecting values M16|M20|M22|M24|M27|M30|M36";
	}else{
		if (dia == "1/2")
			setBoltDiameter(IN_1_2);
		else if (dia == "5/8")
			setBoltDiameter(IN_5_8);
		else if (dia == "3/4")
			setBoltDiameter(IN_3_4);
		else if (dia == "7/8")
			setBoltDiameter(IN_7_8);
		else if (dia == "1")
			setBoltDiameter(IN_1);
		else if (dia == "1_1/8")
			setBoltDiameter(IN_1_1_8);
		else if (dia == "1_1/4")
			setBoltDiameter(IN_1_1_4);
		else if (dia == "1_3/8")
			setBoltDiameter(IN_1_3_8);
		else if (dia == "1_1/2")
			setBoltDiameter(IN_1_1_2);
		else throw "Invalid bolt diameter. Expecting values 1/2 | 5/8 | 3/4 | 7/8 | 1 | 1_1/8 | 1_1/4 | 1_3/8 | 1_1/2";
	}	
	setBoltPretension();
}
void bolt::setBoltPretension(){
	switch (Mdia){
		case M16: 
			Tb=(grad==bolt::ASTM_A325)?91000.0:114000.0; break;
		case M20: 
			Tb=(grad==bolt::ASTM_A325)?142000.0:179000.0; break;
		case M22:
			Tb=(grad==bolt::ASTM_A325)?176000.0:221000.0; break;
		case M24: 
			Tb=(grad==bolt::ASTM_A325)?205000.0:257000.0; break;
		case M27: 
			Tb=(grad==bolt::ASTM_A325)?267000.0:334000.0; break;
		case M30: 
			Tb=(grad==bolt::ASTM_A325)?326000.0:408000.0; break;
		case M36: 
			Tb=(grad==bolt::ASTM_A325)?475000.0:595000.0; break;
		case IN_1_2: 
			Tb=(grad==bolt::ASTM_A325)?12.0:15.0; break;
		case IN_5_8: 
			Tb=(grad==bolt::ASTM_A325)?19.0:24.0; break;
		case IN_3_4:
			Tb=(grad==bolt::ASTM_A325)?28.0:35.0; break;
		case IN_7_8: 
			Tb=(grad==bolt::ASTM_A325)?39.0:49.0; break;
		case IN_1: 
			Tb=(grad==bolt::ASTM_A325)?51.0:64.0; break;
		case IN_1_1_8: 
			Tb=(grad==bolt::ASTM_A325)?56.0:80.0; break;
		case IN_1_1_4: 
			Tb=(grad==bolt::ASTM_A325)?71.0:102.0; break;
		case IN_1_3_8: 
			Tb=(grad==bolt::ASTM_A325)?85.0:121.0; break;
		case IN_1_1_2: 
			Tb=(grad==bolt::ASTM_A325)?103.0:148.0; break;
	}			
}
double bolt::standardBoltHole(){
	switch (Mdia){
		case M16: 
			return 18.0;
		case M20: 
			return 22.0;
		case M22:
			return 24.0;
		case M24: 
			 return 27.0; 
		case M27: 
			return 30.0; 
		case M30: 
			return 33.0; 
		case M36: 
			return 39.0; 
		case IN_1_2: 
			return 0.5625; 
		case IN_5_8: 
			return 0.6875; 
		case IN_3_4:
			return 0.8125; 
		case IN_7_8: 
			return 0.9375; 
		case IN_1: 
			return 1.0625; 
		case IN_1_1_8: 
			return 1.1875; 
		case IN_1_1_4: 
			return 1.3125; 
		case IN_1_3_8: 
			return 1.4375; 
		case IN_1_1_2: 
			return 1.5625; 
	}
	return 0;
}
double bolt::minEdgeDistance(){
	switch (Mdia){
		case M16: 
			return 22.0;
		case M20: 
			return 26.0;
		case M22:
			return 28.0;
		case M24: 
			return 30.0;
		case M27: 
			return 34.0;
		case M30: 
			return 38.0;
		case M36: 
			return 46.0;
		case IN_1_2: 
			return 0.75; 
		case IN_5_8: 
			return 0.875; 
		case IN_3_4:
			return 1.0; 
		case IN_7_8: 
			return 1.125; 
		case IN_1: 
			return 1.25; 
		case IN_1_1_8: 
			return 1.5; 
		case IN_1_1_4: 
			return 1.625; 
		case IN_1_3_8: 
			return 1.71875; 
		case IN_1_1_2: 
			return 1.875; 
	}
	return 0;
}
double bolt::nominalShearStrength(int ns=1){					//ns is the number of shear/slip planes
	if (typ==BEARING){
		double ab=3.14*db*db/4.0; 
		return(Fnv*ab*ns);
	}
	else{
		double mu;	//mean slip coefficient
		if (sur==CLASS_A) mu=0.3; else mu=0.5;
		return (mu*1.13*Tb*ns);
	}
}
double bolt::nominalShearStrength(double T, int ns=1){
	double ksc;
	if (typ==FRICTION){
		if(method==LRFD)	
			ksc=1.0-T/(1.13*Tb);
		else 				
			ksc=1.0-1.5*T/(1.13*Tb);
	}
	else 			ksc=1.0;
	double V=nominalShearStrength(ns);
	return ksc*V;
}
double bolt::nominalTensionStrength(){	
	double ab=3.14*db*db/4.0; 
	return (Fnt*ab); 
}
double bolt::nominalTensionStrength(double V){
	double phi=0.75;
	double omega=2.0;
	double Ab=3.14*db*db/4.0;					
	double frv=V/Ab;
	double Fnt_mod;
	if (method==LRFD)
		Fnt_mod=1.3*Fnt-Fnt*frv/(phi*Fnv);
	else
		Fnt_mod=1.3*Fnt-omega*Fnt*frv/Fnv;
	if (Fnt_mod>Fnt||typ==FRICTION)
		return (Fnt*Ab);
	else 
		return (Fnt_mod*Ab);
}
double bolt::nominalBearingStrength(double lc,double t, double Fu){
	double Rn,Rn1;
	if (brtyp==DEFORMATION_IS_A_CONSIDERATION){
		Rn=1.2*lc*t*Fu;
		Rn1=2.4*db*t*Fu;
	}else{
		Rn=1.5*lc*t*Fu;
		Rn1=3.0*db*t*Fu;		
	}
	if (Rn<Rn1) return Rn; else return Rn1;
}
#endif