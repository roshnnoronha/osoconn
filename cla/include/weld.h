#ifndef WELD_H
#define WELD_H
class weld{
public:
	enum materialGrade {FEXX70};
	weld(materialGrade);
	double tensileStrength() {return fu;}
	void setGrade(materialGrade);
	std::string getGrade(){return "E70";}
	void setUnitSystem(unit_system::EUS);
private:
	unit_system us;
	double fu;
};
///////CONSTRUCTOR/////////
weld::weld (materialGrade gr = FEXX70){
	setGrade (FEXX70);
}
void weld::setGrade (materialGrade gr){
	if (gr == FEXX70){
		if (us.getUnitSystem() == unit_system::NEWTON_MM)
			fu = 482.0;
		else
			fu = 70.0;
	}
}
void weld::setUnitSystem(unit_system::EUS u){
	us = u;
	setGrade (FEXX70);
}
#endif