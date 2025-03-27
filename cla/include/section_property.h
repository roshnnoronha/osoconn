/*
Section Property Class
==================================================
By		:Roshn Noronha

This code is part of the osoConn open source 
connection design project.
==================================================
*/ 
#ifndef SECTIONPROPERTY_H
#define SECTIONPROPERTY_H

class section_property
{
public:
	enum memberType {MEMB_TYPE_I,MEMB_TYPE_C,MEMB_TYPE_L,MEMB_TYPE_DL,MEMB_TYPE_TEE,MEMB_TYPE_PLATE};
	enum materialGrade {ASTM_A36, ASTM_A992};
	//constructors
	section_property(std::string,memberType,materialGrade,unit_system::EUS);
	section_property(memberType);
	section_property();
	static std::string filePath;
	//ptoperty functions
	double depth();
	double flangeWidth();
	double flangeThickness();
	double webThickness();
	double filletDimension();
	double detFilletDimension();
	double leg1();
	double leg2();
	double shortLeg();
	double longLeg();
	double thickness();
	double area(){return A;}
	double plasticSectionModulus();
	double centroidOnShortLeg();
	double centroidOnLongLeg();
	double yieldStrength(){return fy;}
	double tensileStrength(){return fu;}
	void setSection(std::string);
	void setGrade (materialGrade);
	void setUnitSystem(unit_system::EUS);
	std::string getGrade(){return (grade == ASTM_A36)?"ASTM A36":"ASTM A992";}
	std::string getSection(){return name;}
private:
	unit_system us;
	std::string name;
	memberType mtype;
	double d;
	double bf;
	double tw;
	double tf;
	double kdet;
	double k;
	
	double l1;
	double l2;
	double ta;
	
	std::string unit;
	materialGrade grade;
	double fy;
	double fu;
	
	double A;
	double Zx;		//plastic section modulus in the major axis
	double x_bar;	//Distance of centroid
	double y_bar;

	void initialize(std::string,memberType,materialGrade,unit_system::EUS);
};
std::string section_property::filePath = "";
///////////////////////CONSTRUCTORS////////////////////////
section_property::section_property(std::string s,memberType m = MEMB_TYPE_I, materialGrade gr = ASTM_A36,unit_system::EUS unitSys = unit_system::NEWTON_MM){
	initialize(s,m,gr,unitSys);
}
section_property::section_property(memberType m){
	if (m == MEMB_TYPE_I)
		initialize("W150X29.8",m,ASTM_A36,unit_system::NEWTON_MM);
	else if (m == MEMB_TYPE_L)
		initialize("L102X102X6.4",m,ASTM_A36,unit_system::NEWTON_MM);
	else
		initialize("W150X29.8",m,ASTM_A36,unit_system::NEWTON_MM);
}
section_property::section_property(){
	initialize("W150X29.8",MEMB_TYPE_I,ASTM_A36,unit_system::NEWTON_MM);
}
////////////////////////Property functions////////////////////////
void section_property::setSection(std::string name){
	initialize(name, mtype, grade,us.getUnitSystem());
}
void section_property::setGrade(materialGrade gr){
	initialize(name,mtype,gr,us.getUnitSystem());
}
void section_property::setUnitSystem(unit_system::EUS unitSys){
	initialize(name,mtype,grade,unitSys);	
}
void section_property::initialize(std::string s,memberType m, materialGrade gr, unit_system::EUS unitSys){
	int res;
	int prep;
	name=s;
	mtype=m;
	us.setUnitSystem(unitSys);
	sqlite3 *db;
	std::string databaseFile = filePath;
	int fail = sqlite3_open(databaseFile.c_str(),&db);
	if (fail)
		throw sqlite3_errmsg(db);
	sqlite3_stmt *statement;

	if (m==MEMB_TYPE_I){
		std::string query= "SELECT * FROM Wsection WHERE Section LIKE \""+s+"\";";
				
		prep = sqlite3_prepare_v2(db,query.c_str(),-1,&statement,NULL);
		if (prep!=SQLITE_OK)
			throw sqlite3_errmsg(db);
		res=sqlite3_step(statement);
		if (res!=SQLITE_ROW) throw "Invalid section:" + s; 
		A=sqlite3_column_double(statement,2);
		d=sqlite3_column_double(statement,3);
		bf=sqlite3_column_double(statement,4);
		tw=sqlite3_column_double(statement,5);
		tf=sqlite3_column_double(statement,6);
		kdet=sqlite3_column_double(statement,7);
		Zx = sqlite3_column_double(statement,8);
		k = sqlite3_column_double(statement,9);
		unit = (char*)sqlite3_column_text(statement,10);
	}else if (m==MEMB_TYPE_L){
		std::string s_query="SELECT * FROM Angles WHERE Section=\'"+s+"\';";
		const char *query=s_query.c_str();
		if (sqlite3_prepare(db,query,-1,&statement,0)==SQLITE_OK){
			res=sqlite3_step(statement);
			if (res!=SQLITE_ROW) throw "Invalid section:" + s; 
			A=sqlite3_column_double(statement,7);
			l1=sqlite3_column_double(statement,1);
			l2=sqlite3_column_double(statement,2);
			ta=sqlite3_column_double(statement,3);
			kdet=sqlite3_column_double(statement,4);
            x_bar=sqlite3_column_double(statement,8);
            y_bar=sqlite3_column_double(statement,9);
			unit = (char*)sqlite3_column_text(statement,5);
			//std::cout<<l1<<" "<<l2<< " " <<ta<<" " <<kdet<<" " <<unit<<std::endl;
		}else throw "Section " + s +" not found.";
	}
		
	if (unit == "mm"){
		if (us.getUnitSystem() == unit_system::KIP_IN){
			//convert from mm to inches
			d = d/25.4;
			bf = bf/25.4;
			tw = tw/25.4;
			tf = tf/25.4;
			kdet = kdet/25.4;
			Zx = Zx/(25.4*25.4*25.4);
			k = k /25.4;
			l1 = l1/25.4;
			l2 = l2/25.4;
			ta = ta/25.4;
		}
	}else{ 
		if(us.getUnitSystem() == unit_system::NEWTON_MM){
			//convert from in to mm
			d = d*25.4;
			bf = bf*25.4;
			tw = tw*25.4;
			tf = tf*25.4;
			kdet = kdet*25.4;
			Zx = Zx*(25.4*25.4*25.4);
			k = k *25.4;
			l1 = l1*25.4;
			l2 = l2*25.4;
			ta = ta*25.4;			
		}
	}
	sqlite3_close(db);

	if (gr == ASTM_A36){
		grade = gr;
		fy = (us.getUnitSystem() == unit_system::NEWTON_MM)?250.0:36.0;
		fu = (us.getUnitSystem() == unit_system::NEWTON_MM)?400.0:58.0;
	}else if (gr == ASTM_A992){
		grade = gr;
		fy = (us.getUnitSystem() == unit_system::NEWTON_MM)?345.0:50.0;
		fu = (us.getUnitSystem() == unit_system::NEWTON_MM)?450.0:65.0;		
	}else throw "Invalid material grade.";

}
double section_property::depth(){
	if (mtype==MEMB_TYPE_I) 
		return d; 
	else{
		throw "Invalid property.";
		return 0;
	}
}
double section_property::flangeWidth(){
	if (mtype==MEMB_TYPE_I) 
		return bf; 
	else{
		throw "Invalid property.";
		return 0;
	}
}
double section_property::flangeThickness(){
	if (mtype==MEMB_TYPE_I) 
		return tf; 
	else{
		throw "Invalid property."; 
		return 0;
	}
}
double section_property::webThickness(){
	if (mtype==MEMB_TYPE_I) return tw; 
	else{
		throw "Invalid property.";
		return 0;
	}
}
double section_property::filletDimension(){
	if (mtype==MEMB_TYPE_I) 
		return k; 
	else{
		throw "Invalid property.";
		return 0;
	}
}
double section_property::detFilletDimension(){
	if ((mtype == MEMB_TYPE_I)||(mtype == MEMB_TYPE_L)) 
		return kdet; 
	else{
		throw "Invalid property.";
		return 0;
	}
}
double section_property::leg1(){
	if (mtype==MEMB_TYPE_L) 
		return l1; 
	else{
		throw "Invalid property."; 
		return 0;
	}
}
double section_property::leg2(){
	if (mtype==MEMB_TYPE_L) 
		return l2; 
	else {
		throw "Invalid property."; 
		return 0;
	}
}
double section_property::shortLeg(){
	if (mtype==MEMB_TYPE_L) 
		return l1; 
	else {
		throw "Invalid property."; 
		return 0;
	}
}
double section_property::longLeg(){
	if (mtype==MEMB_TYPE_L) 
		return l2; 
	else {
		throw "Invalid property."; 
		return 0;
	}
}
double section_property::thickness(){
	if (mtype==MEMB_TYPE_L) 
		return ta; 
	else {
		throw "Invalid property."; 
		return 0;
	}
}
double section_property::plasticSectionModulus(){
	if (mtype==MEMB_TYPE_I) 
		return Zx; 
	else {
		throw "Invalid property.";
		return 0;
	}
}
double section_property::centroidOnShortLeg(){
	if (mtype==MEMB_TYPE_L) 
		return x_bar; 
	else {
		throw "Invalid property."; 
		return 0;
	}
}
double section_property::centroidOnLongLeg(){
	if (mtype==MEMB_TYPE_L) 
		return y_bar; 
	else {
		throw "Invalid property."; 
		return 0;
	}
}


#endif
