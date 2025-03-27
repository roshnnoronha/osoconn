/*
Shear Connection Class
==================================================
By		:Roshn Noronha

This class contains the details and functions 
requried to design a shear connection using clip 
angles welded to the beam and bolted to the 
supporting member. The supporting member my be a 
column flange, column web or beam web. The 
connection is designed as per AISC 360-10 
specifications. 
==================================================
*/ 
#ifndef SHEARCONNECTION1_H
#define SHEARCONNECTION1_H
#define _p o=o+oso::format_p
#define _h1 o=o+oso::format_h1
#define _h2 o=o+oso::format_h2
#define _h3 o=o+oso::format_h3
#define _br o=o+oso::format_br()
#define _length us.lengthUnit()
#define _force us.forceUnit()
#define _area us.areaUnit()
#define _stress us.stressUnit()
#define _moment us.momentUnit()

class shearConnection1 : public connection
{
public:
	/*Constructors*/
	shearConnection1();
	shearConnection1(std::map<std::string,std::string>&);
	
	/*Output functions*/
	std::string designInput();
	std::string designSummary();
	std::string designCalculation();
	bool pass();
	
private:
	//input variables
	int method;								//LRFD method by default
	unit_system us;
	
	double E;								//modulus of elasticity of steel
	double nu;	
	double fy_a;							//yield strength of angle
	double fu_a;							//tensile strength of angle
	double fy_b;							//yield strength of beam
	double fy_s;							//yield strength of supporting member
	double fu_b;							//tensile strength of beam
	double fu_s;							//tensile strength of supporting member
	double fu_w;							//tensile strength of weld
	double setback;							//setback

	double tf; 								//transfer force
	double sf;								//shear force

	bolt blt;
    std::string boltType;
	double db;								//bolt diameter
	int nb;									//bolt numbers
	double gb;								//bolt gage
	double sb; 								//bolt spacing
	double fnt_b;							//bolt nominal tensile capacity
	double fnv_b;							//bolt nominal shear capacity

	weld wld;
	double wt;								//weld thickness

	section_property angleSection;
	double la;								//length of clip angle
	double li;								//inside leg width
	double lo;								//outside leg width
	double ta;								//thickness of clip angle 
	double kdet;							//fillet dimension of clip angle
	double ct;								//clip angle top from top of beam
	
	bool backingBeam;						//indicates if a backing beam is present
	
	std::string b_section;
	section_property beamSection;
	double b_d;								//beam depth
	double b_bf;							//beam flange width
	double b_tf;							//beam fange thickness
	double b_tw;							//beam web thickness
	double b_k; 							//beam fillet dimension
	double b_kdet;							//beam detailing filler dimension
	double dct;								//top cope depth
	double c;								//cope length
	double dcb;								//bottom cope depth

	std::string s_section;
	section_property supportSection;
	double s_d;								//supporting member depth
	double s_bf;							//supporting member flange width
	double s_tf;							//supporting member fange thickness
	double s_tw;							//supporting member web thickness 
	double s_k;								//dimension of fillet
	double s_kdet;							//support detailing fillet dimension
	int supp_type; 							//supporting member type 1->beam web, 2->column web, 3->column flange
	
	//constants
	const double phi_bv = 0.75;				//LRFD factor for bolt shear
	const double omega_bv = 2.0;			//ASD factor for bolt shear
	const double phi_sl = 1.0;				//LRFD factor for bolt slip resistance
	const double omega_sl = 1.5;			//ASD factor for bolt slip resistance    
	const double phi_bt = 0.75;				//LRFD factor for bolt tension
	const double omega_bt = 2.0;			//ASD factor for bolt tension
	const double phi_bb=0.75;				//LRFD factor in bolt bearing
	const double omega_bb=2.0;				//ASD factor in bolt bearing
	const double phi_w=0.75;				//LRfD factor for weld strength
	const double omega_w=2.0;				//ASD factor for weld strength
	const double phi_f=0.9;					//LRFD factor in flexure
	const double omega_f=1.67;				//ASD factor in flexure
	const double phi_c = 0.9;				//LRFD factor in compession
	const double omega_c =1.67;				//ASD factor in compression
	const double phi_vy=1.0;				//LRFD factor for shear yielding
	const double omega_vy=1.5;				//ASD factor for shear yielding
	const double phi_vr=0.75;				//LRFD factor for shear rupture
	const double omega_vr=2.0;				//ASD factor for shear rupture
	const double phi_wy=1.0;				//LRFD factor for beam web yielding
	const double omega_wy=1.5;				//ASD factor for beam web yielding
	const double phi_wc=0.75;				//LRFD factor for beam web crippling
	const double omega_wc=2.0;				//ASD factor for beam web crippling
	const double phi_bs=0.75;				//LRFD factor for block shear
	const double omega_bs=2.0;				//ASD factor for block shear
	
	//output varialbles
    
	double Tb;								//tension per bolt
	double Vb;								//shear per bolt
	
	double ab;								//bolt area
	double Rn_bv;							//nominal strength in bolt shear
	double Ra_bv;							//allowable strength in bolt shear
	double UR_bv;							//utility ratio in bolt shear	
	double frv;								//shear per bolt

	double mod_fnt_b;						//modified nominal tensile stress
	double Rn_bt;							//Nominal strength in bolt tension
	double Ra_bt;							//Allowable strength in bolt tension
	double UR_bt;							//utility ratio in bolt tension

	double dbh;								//bolt hole diameter
	double ed;								//bolt edge distance
	double edc; 							//clear edge distance
	double sbc;					 			//clear spacing b/n bolts
	double lc;
	double Rn_bb;							//nominal strength in bolt bearing
	double Rn1_bb;
	double Ra_bb;							//allowable strength in bolt bearing
	double UR_bb;							//utility ratio in bolt bearing	

	double lc_s;
	double ts;								//thickness of supporting member
	double redFact;							//reduction factor to account for shear in backing beam
	double Rn_bbs;							//nominal strength in bolt bearing at support
	double Rn1_bbs; 
	double Ra_bbs; 							//allowable strength in bolt bearing at support
	double UR_bbs;							//utility ratio for bolt bearing at support
	
	
	double bl;								//length of horizontal run of weld
	double x;								//cetroid of weld group
	double wl;								//total weld length
	double Ip;								//polar moment of inertia of weld group
	double e;								//eccentricity of force
	double fx;								//horizontal component of the stress
	double fy;								//vertical component of the stress
	double fw;
	double Rn_w;							//nominal weld strength
	double Ra_w;							//allowable weld strength
	double UR_w;							//utility ratio for weld

	double tw_min;							//minimum thickness of beam at weld
	double UR_wr;							//utility ratio for weld rupture
	
	double Snet;							//net section modulus of coped section
	double h0;								//depth of coped beam
	double h1;								//distance of centroid of coped section from top of coped section
	double Inet;							//Moment of inertia of coped section
	double If;								//moment of inertia of bottom flange
	double Iw;								//moment of inertia of coped web
	double h2;								//depth of coped web
	double hw;								//distance of centroid of coped web from top of coped section
	double hf;								//distance of centroid of bottom flance from top of coped section
	double Fcr;								//critical stress
	double f;								//buckling adjustment factor
	double k;								//plate buckling coeff
	double ac;
	double fd;
	double Mn;								//nominal strength in flexure
	double Ma;								//allowable strength in flexure
	double xc;								//distance of the centroid of coped section from top of beam
	double xw;								//distance of centroid of weld from top of beam
	double etf;								//eccentricity of transfer load from centroid of cope
	double Mc;								//required moment strength at cope
	double UR_cf;							//utility ratio in cope flexure

	double Ac;								//area of coped section
	double Iy;								//moment of inertia about minor axis
	double rc;								//radius of gyration of coped section
	double ulc;								//unsupported length of cope
	double klr;								//slenderness ratio of coped section
	double fe;								//elastic buckling stress
	double fcr;
	double Pn;								//nominal strength of cope in compression
	double Pa_ca;							//allowable strength of cope in compression
	double UR_ca;							//utility ratio of cope in compression

	double Agv;								//gross area of coped section in shear
	double Rn_cv;							//nominal strength of cope in shear
	double Ra_cv;							//allowable strength of cope in shear
	double UR_cv;							//utility ratio of coped section in shear
	
	double p;								//minimum pitch distance
	double B;								//available tension per bolt
	double a;								//distance of bolt centerline to edge of fitting
	double b;
	double a1;
	double b1;
	double rho;
	double beta;
	double d1;
	double delta;
	double alpha1;
	double tmin;							//minimum required thickness
	double Q;
	double UR_pr;							//utility ratio in clip prying

	double tc;								//angle thickness required to develop available strength of the bolt B 
	double tr;
	double alpha;
	double q;

	double Rn_vyc;							//nominal strength in shear yielding of clip
	double Ra_vyc;							//allowable strength in shear yielding of clip
	double fav;								//shear in clip angle
	double UR_vyc;							//utility ratio in clip shear yielding

	double b_co;
	double b1_co;
	double p_eff;							//effective pitch on column
	double delta_co;
	double a_co;
	double a1_co;
	double rho_co;
	double tc_co;
	double tr_co;
	double alpha1_co;
	double Q_co;
	double UR_prc;

	double Rn_wyc;							//nominal strength in column web yielding
	double Ra_wyc;							//allowable strength in column web yielding
	double UR_wyc;							//interaction ratio in web yielding

	double Rn_wcc;							//nominal strength in web crippling
	double Ra_wcc;							//allowable strength in web crippling
	double UR_wcc;							//interaction ratio in web crippling

    double ho;                              //flange to flange height of column web
    double Pn_wb;                           //nominal strength in column web yielding
    double Pa_wb;                           //allowable strength in column web yielding
    double UR_wb;                           //utility ratio in column web yielding
	
	double Anet;							//net area of clip in shear
	double Rn_vrc;							//nominal strength of clip in shear rupture
	double Ra_vrc;							//allowable strength in shear rupture
	double UR_vrc;							//utility ratio in clip shear rupture
    
    double Agvb;                            //gross area subjected to shear for block shear
    double Anvb;                            //net area subjected to shear for block shear
    double Antb;                            //net are subjected to tension for block shear
    double Rn_bs1, Rn_bs2, Rn_bs;           //nominal strength of clip in block shear
    double Ra_bs;                           //allowable strength of clip in block shear	
	double UR_bs;                           //utility ratio in block shear
    
	double UR_max;							//maximum utility ratio
	
	//connection design functions
	void checkFitup();
	void calc();
	//Fitup check functions
	void calculateCopeDimensions();
	//miscellaneous functions
	double min(double a,double b){if(a<b) return a; else return b;}
	double min(double a,double b,double c){if ((a<b) && (a<c)) return a; else if ((b<a) && (b<c)) return b; else return c;}
	std::string to_string(double a){std::ostringstream s; s << a; return s.str();}
	bool isNumber(std::string);
};
//////////////////////////////CONSTRUCTORS////////////////////////////////////
shearConnection1::shearConnection1(){

}
shearConnection1::shearConnection1(std::map<std::string,std::string>& data):angleSection(section_property::MEMB_TYPE_L){
	addParameter("CONNECTION_CODE");
	addParameter("CONNECTION_ID");
	addParameter("METHOD");
	param("METHOD").addAllowableValue("LRFD");
	param("METHOD").addAllowableValue("ASD");
	addParameter("UNITS");
	param("UNITS").addAllowableValue("NEWTON_MM");
	param("UNITS").addAllowableValue("KIP_IN");
	addParameter("MODULUS_OF_ELASTICITY");
	param("MODULUS_OF_ELASTICITY").isPositiveNumber();
	addParameter("POISSON_RATIO","0.3");
	param("POISSON_RATIO").isPositiveNumber();
	param("POISSON_RATIO").setMinimumValue(0);
	param("POISSON_RATIO").setMaximumValue(0.5);	
	addParameter("TRANSFER_FORCE","0");
	param("TRANSFER_FORCE").isNumber();
	addParameter("SHEAR_FORCE","0");
	param("SHEAR_FORCE").isNumber();
	addParameter("BOLT_GRADE");
	param("BOLT_GRADE").addAllowableValue("A325");
	param("BOLT_GRADE").addAllowableValue("A490");	
	addParameter("BOLT_DIAMETER");
	addParameter("BOLT_TYPE");
	param("BOLT_TYPE").addAllowableValue("BEARING");
	param("BOLT_TYPE").addAllowableValue("FRICTION");	
	addParameter("THREAD_INCLUDED_IN_SHEAR","YES");
	param("THREAD_INCLUDED_IN_SHEAR").addAllowableValue("YES");
	param("THREAD_INCLUDED_IN_SHEAR").addAllowableValue("NO");
	addParameter("FAYING_SURFACE","CLASS_A");
	param("FAYING_SURFACE").addAllowableValue("CLASS_A");
	param("FAYING_SURFACE").addAllowableValue("CLASS_B");
	addParameter("NUMBER_OF_BOLTS_PER_ROW");
	param("NUMBER_OF_BOLTS_PER_ROW").isInteger();
	param("NUMBER_OF_BOLTS_PER_ROW").setMinimumValue(2);
	addParameter("BOLT_GAGE");
	param("BOLT_GAGE").isPositiveNumber();
	addParameter("BOLT_SPACING");
	param("BOLT_SPACING").isPositiveNumber();
	addParameter("THICKNESS_OF_WELD");
	param("THICKNESS_OF_WELD").isPositiveNumber();
	addParameter("STEEL_GRADE_OF_ANGLE");
	param("STEEL_GRADE_OF_ANGLE").addAllowableValue("A36");
	param("STEEL_GRADE_OF_ANGLE").addAllowableValue("A992");
	addParameter("CLIP_ANGLE");			
	addParameter("CLIP_ANGLE_LENGTH");
	param("CLIP_ANGLE_LENGTH").isPositiveNumber();
	addParameter("CLIP_ANGLE_TOP");		
	param("CLIP_ANGLE_TOP").isPositiveNumber();
	addParameter("STEEL_GRADE_OF_BEAM");	
	param("STEEL_GRADE_OF_BEAM").addAllowableValue("A36");
	param("STEEL_GRADE_OF_BEAM").addAllowableValue("A992");
	addParameter("BEAM_SECTION");					
	addParameter("STEEL_GRADE_OF_SUPPORT");	
	param("STEEL_GRADE_OF_SUPPORT").addAllowableValue("A36");
	param("STEEL_GRADE_OF_SUPPORT").addAllowableValue("A992");
	addParameter("SUPPORT_SECTION");							
	addParameter("SUPPORT_TYPE");	
	param("SUPPORT_TYPE").addAllowableValue("COLUMN_FLANGE");
	param("SUPPORT_TYPE").addAllowableValue("COLUMN_WEB");
	param("SUPPORT_TYPE").addAllowableValue("BEAM");
	addParameter("CONNECTION_SETBACK");	
	param("CONNECTION_SETBACK").isPositiveNumber();	
	addParameter("BACKING_BEAM","YES");
	param("BACKING_BEAM").addAllowableValue("YES");
	param("BACKING_BEAM").addAllowableValue("NO");
	addParameter("TOP_COPE_DEPTH","0");
	param("TOP_COPE_DEPTH").isPositiveNumber();
	addParameter("BOTTOM_COPE_DEPTH","0");
	param("BOTTOM_COPE_DEPTH").isPositiveNumber();
	addParameter("COPE_LENGTH","0");
	param("COPE_LENGTH").isPositiveNumber();
	addParameter("DESCRIPTION","CONN");
	addParameter("OUTSTANDING_LEG","LONG_LEG");
	param("OUTSTANDING_LEG").addAllowableValue("LONG_LEG");
	param("OUTSTANDING_LEG").addAllowableValue("SHORT_LEG");
	addParameter("WELD_ELECTRODE","E70");
	
	validateParameters(data);

	connID = data["CONNECTION_ID"];
    connCode = data["CONNECTION_CODE"];
    
	if (data["METHOD"] == "LRFD"){
		method = 1;
		blt.setMethod(bolt::LRFD);
	}else{
		method = 0;
		blt.setMethod(bolt::ASD);
	}	
	if (data["UNITS"] == "NEWTON_MM"){
		us.setUnitSystem(unit_system::NEWTON_MM);
		blt.setUnitSystem(unit_system::NEWTON_MM);
		angleSection.setUnitSystem(unit_system::NEWTON_MM);
		beamSection.setUnitSystem(unit_system::NEWTON_MM);
		supportSection.setUnitSystem(unit_system::NEWTON_MM);
		wld.setUnitSystem(unit_system::NEWTON_MM);
	}else{
		us.setUnitSystem(unit_system::KIP_IN);
		blt.setUnitSystem(unit_system::KIP_IN);		
		angleSection.setUnitSystem(unit_system::KIP_IN);
		beamSection.setUnitSystem(unit_system::KIP_IN);
		supportSection.setUnitSystem(unit_system::KIP_IN);
		wld.setUnitSystem(unit_system::KIP_IN);
	}
	//Material properties
	E = atof(data["MODULUS_OF_ELASTICITY"].c_str());
	nu = atof(data["POISSON_RATIO"].c_str());		
	//Connection forces
	tf = atof(data["TRANSFER_FORCE"].c_str());	
	sf = atof(data["SHEAR_FORCE"].c_str());
	//Bolt details
	if (data["BOLT_GRADE"] == "A325")
		blt.setBoltGrade(bolt::ASTM_A325);
	else
		blt.setBoltGrade(bolt::ASTM_A490);
	blt.setBoltDiameter(data["BOLT_DIAMETER"]);
	db = blt.diameter();
	boltType = data["BOLT_TYPE"];
	if (boltType == "BEARING")
		blt.setBoltType(bolt::BEARING);
	else
		blt.setBoltType(bolt::FRICTION);
	if (boltType == "BEARING"){
		if(data.count("THREAD_INCLUDED_IN_SHEAR") != 0){
			std::string thrInc = data["THREAD_INCLUDED_IN_SHEAR"];
			if (thrInc == "YES")
				blt.setBoltThreadType(bolt::THREAD_INCLUDED_IN_SHEAR_PLANE);
			else
				blt.setBoltThreadType(bolt::THREAD_EXCLUDED_FROM_SHEAR_PLANE);
		}
	}
	if (boltType == "FRICTION"){
		if(data.count("FAYING_SURFACE") != 0){
			std::string sur = data["FAYING_SURFACE"];
			if (sur == "CLASS_A")
				blt.setFayingSurface(bolt::CLASS_A);
			else
				blt.setFayingSurface(bolt::CLASS_B);
		}
	}
	fnt_b = blt.nominalTensileStress();
	fnv_b = blt.nominalShearStress();
	nb = atoi(data["NUMBER_OF_BOLTS_PER_ROW"].c_str());
	gb = atof(data["BOLT_GAGE"].c_str());
	sb = atof(data["BOLT_SPACING"].c_str());
	//Weld details
	wt = atof(data["THICKNESS_OF_WELD"].c_str());
	std::string weldGr;
	if (data.count("WELD_ELECTRODE") == 0) 
		weldGr = "E70";				//default value
	else
		weldGr = data["WELD_ELECTRODE"];
	if (weldGr == "E70")
		wld.setGrade(weld::FEXX70);
	fu_w = wld.tensileStrength();
	//Clip angle details
	std::string angleGr = data["STEEL_GRADE_OF_ANGLE"];
	if (angleGr == "A36")
		angleSection.setGrade(section_property::ASTM_A36);
	else
		angleSection.setGrade(section_property::ASTM_A992);
	fy_a = angleSection.yieldStrength();
	fu_a = angleSection.tensileStrength();
	std::string a_section = data["CLIP_ANGLE"];
	angleSection.setSection(a_section);
	ta = angleSection.thickness();	
	lo = angleSection.longLeg();
	li = angleSection.shortLeg();
	kdet = angleSection.detFilletDimension();
	if (lo != li){
		std::string lo_type = data["OUTSTANDING_LEG"];
		if (lo_type == "LONG_LEG"){
			lo = angleSection.longLeg();
			li = angleSection.shortLeg();
		}else{
			lo = angleSection.shortLeg();
			li = angleSection.longLeg();
		}
	}
	la = atof(data["CLIP_ANGLE_LENGTH"].c_str());
	ct = atof(data["CLIP_ANGLE_TOP"].c_str());
	//Beam details
	std::string beamGr = data["STEEL_GRADE_OF_BEAM"];
	if (beamGr == "A36")
		beamSection.setGrade(section_property::ASTM_A36);
	else
		beamSection.setGrade(section_property::ASTM_A992);
	fy_b = beamSection.yieldStrength();
	fu_b = beamSection.tensileStrength();
    b_section = data["BEAM_SECTION"];	
	beamSection.setSection(data["BEAM_SECTION"]);
	b_d = beamSection.depth();
	b_tw = beamSection.webThickness();
	b_bf = beamSection.flangeWidth();
	b_tf = beamSection.flangeThickness();
	b_k = beamSection.filletDimension();	
	b_kdet = beamSection.detFilletDimension();
	if (data.count("TOP_COPE_DEPTH") == 0) 
		dct = 0;
	else
		dct = atof(data["TOP_COPE_DEPTH"].c_str());
	if (data.count("BOTTOM_COPE_DEPTH") == 0) 
		dcb = 0;
	else
		dcb = atof(data["BOTTOM_COPE_DEPTH"].c_str());
	c = 0;
	if ((dct != 0)||(dcb != 0)){
		if (data.count("COPE_LENGTH") == 0) err.addError("Missing input parameter COPE_LENGTH.");							
		c = atof(data["COPE_LENGTH"].c_str());
	}
	//Column details
	if (data["STEEL_GRADE_OF_SUPPORT"] == "A36")
		supportSection.setGrade(section_property::ASTM_A36);
	else
		supportSection.setGrade(section_property::ASTM_A992);
	fy_s = supportSection.yieldStrength();
	fu_s = supportSection.tensileStrength();
	s_section = data["SUPPORT_SECTION"]; 
	supportSection.setSection(s_section);
	s_d = supportSection.depth();
	s_tw = supportSection.webThickness();
	s_bf = supportSection.flangeWidth();
	s_tf = supportSection.flangeThickness();
	s_k = supportSection.filletDimension();
	s_kdet = supportSection.detFilletDimension();
	std::string s_supp_type = data["SUPPORT_TYPE"];
	if (s_supp_type == "COLUMN_FLANGE") 
		supp_type = 3;
	else if (s_supp_type == "COLUMN_WEB") 
		supp_type = 2;
	else if (s_supp_type == "BEAM") 
		supp_type = 1;
	setback = atof(data["CONNECTION_SETBACK"].c_str());
	backingBeam = false;
	if (data.count("BACKING_BEAM") != 0){
		if (data["BACKING_BEAM"] == "YES")
			backingBeam = true;
		else
			backingBeam = false;
	}

	if (err.isError()) throw err.errorMessage();	
	//check fitup
	checkFitup();
	if (err.isError()) throw err.errorMessage();		
	calc();
	
}
bool shearConnection1::isNumber(std::string num){
	if (num=="0") return true;
	if (atof(num.c_str())!=0) return true;
	return false;
}
////////////////////////////////////////////////////////////////////////////////
void shearConnection1::checkFitup(){
	//bolt spacing
	if (sb < blt.minBoltSpacing()) err.addError("Bolt minimum spacing not satistied. Try increasing the bolt spacing.");
	//bolt edge dist on clip
	double ed1 = (la - (nb - 1)*sb)/2;
	if (ed1 < blt.minEdgeDistance()) err.addError("Insufficient vertical edge distance on clip angle. Try increasing the clip angle length or reducing bolt spacing.");
	double ed2 = (2*lo + b_tw - gb)/2;
	if (ed2 < blt.minEdgeDistance()) err.addError("Insufficient horizontal edge distance on clip angle. Try reducing the bolt gage or using a larger clip angle.");
	//bolt edge dist on column flange
	double ed3 = (s_bf - gb)/2;
	if (supp_type == 3)
		if (ed3 < blt.minEdgeDistance()) err.addError("Insufficient horizontal edge distance on column flange. Try reducing the bolt gage.");
	//bolt nut to column fillet area 
	double s_rr = s_kdet - s_tf;	//fillet area radius
	if (supp_type == 3)
		if (gb < (s_tw + 2*s_rr + 2*db)) err.addError("Bolt clashes with the column fillet area. Try increasing the bolt gage.");
	//bolt nut to clip angle fillet area
	if (gb < (b_tw + 2*kdet)) err.addError("Bolt clashes with the clip angle fillet area. Try increasing the bolt gage.");
	//angle top from top cope
	double gap;
	if (us.getUnitSystem() == unit_system::NEWTON_MM)
		gap = 2;
	else 
		gap = 0.1;    
    double min_ct = (dct > b_kdet)?(dct + wt + gap):(b_kdet + wt + gap);
	if (ct < min_ct) err.addError("Insufficient space for weld at top of clip angle. Try lowering the clip angle."); 
	//angle botton from bottom cope
    double max_ct = (dcb > b_kdet)?(b_d - dcb - wt - gap - la):(b_d - b_kdet - wt - gap - la);
	if (ct > max_ct) err.addError("Insufficient space for weld at bottom of clip angle. Try raising the clip angle or reducing the length of the angle.");
	//top cope to beam fillet 
	double minClr;
	if (us.getUnitSystem() == unit_system::NEWTON_MM)
		minClr = 16;
	else 
		minClr = 0.667;
	if (supp_type == 1) 
		if(dct < b_tf + minClr) err.addError("Minimum cope depth not satified at beam top. Try increasing top cope depth.");
	//bottom cope to beam fillet
	if (supp_type == 1)
		if (b_d > s_d - s_tf)
			if (dcb < b_tf + minClr) err.addError("Minimum cope depth not satified at beam bottom. Try increasing bottom cope depth.");
	//cope length check
	double minClr1;
	if (us.getUnitSystem() == unit_system::NEWTON_MM)
		minClr1 = 12;
	else 
		minClr1 = 0.5;
	if (supp_type == 1)
		if (c < (s_bf - s_tw)/2 - setback + minClr1) err.addError("Minimum cope length not satified. Try increasing cope length.");

}
void shearConnection1::calc(){
	Tb = tf/(2.0*nb);													//tension per bolt
	Vb = sf/(2.0*nb);													//shear per bolt

	//bolt shear strength
	Rn_bv = blt.nominalShearStrength(Tb);
	if (method==1) 
        if (boltType == "BEARING")
            Ra_bv = (phi_bv*Rn_bv);
        else
            Ra_bv = (phi_sl*Rn_bv);
	else 
        if (boltType == "BEARING")
            Ra_bv = (Rn_bv / omega_bv);
        else
            Ra_bv = (Rn_bv / omega_sl);
	UR_bv = Vb/Ra_bv;
	
	//bolt tension strength
	Rn_bt = blt.nominalTensionStrength(Vb);
	if (method==1) 
		Ra_bt = (phi_bt*Rn_bt); 
	else 
		Ra_bt = (Rn_bt / omega_bt);
	UR_bt = Tb/Ra_bt;
	
	//bolt bearing on clip angle
	dbh = blt.standardBoltHole();
	ed=(la-(nb-1)*sb)/2.0;												//bolt edge distance
	edc= ed - dbh/2; 													//clear edge distance
	sbc=sb-dbh;					 										//clear spacing b/n bolts
	lc= min(edc,sbc);
	Rn_bb=1.2*lc*ta*fu_a;												//nominal strength in bolt bearing
	Rn1_bb=2.4*db*ta*fu_a;
	Rn_bb=min(Rn_bb,Rn1_bb);
	if(method==1) 
		Ra_bb = phi_bb*Rn_bb; 
	else
		Ra_bb = Rn_bb/omega_bb;
	UR_bb = Vb/Ra_bb;
	
	//bolt bearing at supporting member
	lc_s = sbc;
	if (supp_type == 1){												//beam 
		ts = s_tw;														//thickness of supporting member
		redFact = backingBeam?0.5:1.0;									//reduction factor to account for shear in backing beam
	}else if (supp_type == 2){											//column web
		ts = s_tw;
		redFact = backingBeam?0.5:1.0;
	}else{																//column flange
		ts = s_tf;
		redFact = 1.0;
	}
	Rn_bbs=1.2*lc_s*ts*fu_s;											//nominal strength in bolt bearing at support
	Rn1_bbs=2.4*db*ts*fu_s; 
	Rn_bbs=min(Rn_bbs,Rn1_bbs);
	if(method==1) 
		Ra_bbs = phi_bb*Rn_bbs; 										//allowable strength in bolt bearing at support
	else
		Ra_bbs = Rn_bbs/omega_bb;
	UR_bbs = Vb/(Ra_bbs*redFact);										//utility ratio for bolt bearing at support
	
	//weld shear 
	bl=li-setback;														//length of horizontal run of weld
	x=(bl*bl)/(2*bl + la);												//cetroid of weld group
	wl=2*bl + la;														//total weld length
	Ip=(2*bl+la)*(2*bl+la)*(2*bl+la)/12 - bl*bl*(bl+la)*(bl+la)/(2*bl + la);//polar moment of inertia of weld group
	e=li-x;																//eccentricity of force
	fx=tf/(2*wl) + (sf*e)*la/(4*Ip);									//horizontal component of the stress
	fy=sf/(2*wl) + (sf*e)*(bl-x)/(2*Ip);								//vertical component of the stress
	fw=sqrt(fx*fx + fy*fy);
	Rn_w = 0.707*wt*0.6*fu_w;
	if(method==1) 
		Ra_w = Rn_w*phi_w; 
	else 
		Ra_w = Rn_w/omega_w;
	UR_w = fw / Ra_w;	

	//minimum thickness of beam at weld
	if (method==1)
		tw_min = (2*fw)/(0.6 * fu_b * phi_vr); 
	else 
		tw_min = (2*fw)/(0.6 * fu_b /omega_vr); 
	UR_wr = tw_min/b_tw;
	//cope flexure strength
	if (dcb == 0){  														
		h0=b_d-dct;															            //total depth of coped section
		h2=h0-b_tf;															            //depth of web
		h1=((h2*h2)*b_tw + b_tf*b_bf*(2.0*h2 + b_tf)) / (2.0*(h2*b_tw + b_tf*b_bf));    //centroid dist of coped section from top of cope
		Iw=(h2*h2*h2)*b_tw / 12.0;											            //moment of inertia of web
		hw=h2/2.0;															            //cetroid of web from top of coped section
		If=b_bf*(b_tf*b_tf*b_tf)/12.0;										            //moment of inertia of flange
		hf=h2 + b_tf/2.0;													            //centroid of flange from top of coped section
		Inet=Iw + (h2*b_tw)*(hw-h1)*(hw-h1) + If + (b_tf*b_bf)*(hf-h1)*(hf-h1);         //moment of inertia of coped section
	}else{
		h0=b_d-dct-dcb;
		h1=h0/2.0;
		Inet=(h0*h0*h0)*b_tw / 12.0;
	}
	Snet=Inet/h1;
	if (dcb==0){
		if (c/b_d<=1) 
			f=2*c/b_d;
		else 
			f=1 + c/b_d;
		if (c/h0<=1)
			k=2.2*pow(h0/c,1.65);
		else
			k=2.2*(h0/c);		
		ac= b_tw/h0;
		Fcr=((PI*PI)*E) / (12.0 * (1- nu * nu)) *(ac*ac) * f * k;
	}else{
		fd=3.5-7.5 * dct / b_d;
		Fcr=0.62 * PI * E * (b_tw*b_tw) * fd / (c * h0);
	}
	if (Fcr>fy_b)	Fcr=fy_b;
	Mn = Fcr * Snet;

	if (method==1) 
		Ma=Mn*phi_f; 
	else 
		Ma=Mn/omega_f;	
	xc = h1 + dct;														//distance of the centroid of coped section from top of beam
	xw = ct + la/2;														//distance of centroid of weld from top of beam
    etf = (xc-xw)<0?xw-xc:xc-xw;										//eccentricity of transfer load from centroid of cope
	Mc = sf*(setback+c) + tf * etf;										//Required moment capacity at cope 
	UR_cf = Mc/Ma;
	
	//cope axial strength
	if (dcb == 0){
		Ac = (h2*b_tw + b_tf*b_bf);										//area of coped section
		Iy = (h2*b_tw*b_tw*b_tw+ b_tf*b_bf *b_bf*b_bf)/12;				//moment of inertia about minor axis
	}else{
		Ac = h0*b_tw;
		Iy = (h0*b_tw*b_tw*b_tw)/12;
	}
	rc = sqrt(min(Inet,Iy)/Ac);											//radius of gyration of coped section
	ulc = c + setback;													//unsupported length of cope
	klr = ulc / rc;														//slenderness ratio of coped section
	fe = PI*PI*E/(klr*klr);												//elastic buckling stress
	if (klr < 4.71*sqrt(E/fy_b))
		fcr = pow(0.658,fy_b/fe)*fy_b;
	else
		fcr = 0.877* fe;
	Pn = fcr*Ac;														//nominal strength in compression
	if (method == 1)
		Pa_ca = phi_c*Pn;
	else
		Pa_ca = Pn/omega_c;
	UR_ca = tf/Pa_ca;

	//cope shear strength 
	Agv = h0 *b_tw;														//gross area of coped section in shear
	Rn_cv = 0.6*fy_b*Agv;												//nominal strength of cope in shear
	if (method == 1)
		Ra_cv = phi_vy*Rn_cv;
	else
		Ra_cv = Rn_cv/omega_vy;	
	UR_cv = sf / Ra_cv;													//utility ratio of coped section in shear

	//Clip angle prying	check
	B = Ra_bt;															//available tension strength per bolt
	b = (gb - b_tw - ta)/2.0;	    									//distance of bolt centerline to centerline of clip angle
	a = lo - b - ta/2.0;        										//distance of bolt centerline to edge of fitting
	a1 = a + db/2.0;
	if (a1 > (1.25*b + db/2.0)) 
		a1 = 1.25*b + db/2.0;
	b1 = b - db/2.0;
    p = min(2*b, b+ed);                                                 //bolt pitch
    p = min(p, sb);
	rho = b1/a1;
	delta = 1.0 - dbh/p;															
	if (method == 1) 
		tc = sqrt(4.0*B*b1 / (phi_f*p*fu_a));							//eqn. 9-30a, AISC Manual
	else
		tc = sqrt(omega_f*4.0*B*b1 / (p*fu_a));							//eqn. 9-30b, AISC Manual
	tr = tc / ta;
	alpha1 = 1/(delta*(1+rho)) * ((tr*tr) - 1);							//eqn. 9-29, AISC Manual
	if (alpha1 < 0.0)	
		Q = 1;
	else if ((alpha1 >= 0.0) && (alpha1 <= 1.0))
		Q = 1/(tr*tr) * (1 + alpha1*delta);	
    else
        Q = 1/(tr*tr) * (1 + delta);
	UR_pr = Tb / (B*Q);
	
	if (supp_type == 3){
		//Column flange prying check
		b_co = (gb - s_tw) / 2.0;
		b1_co = b_co - db / 2.0;
		p_eff = ((nb - 1)*sb + PI*b_co + (s_bf - gb)) / nb;				//effective pitch at column
		delta_co = 1.0 - dbh / p_eff;									//ratio of net length at bolt line to gross length at face of stem
		a_co = min((s_bf - gb) / 2.0, (2*lo + b_tw - gb)/2.0);
		a1_co = min(a_co, 1.25*b_co) + db/2.0;
		rho_co = b1_co / a1_co;
		if (method == 1)
			tc_co = sqrt((4.0 * B * b1_co) / (phi_f * p_eff * fu_s));
		else
			tc_co = sqrt((omega_f * 4.0 *B * b1_co)/(p_eff * fu_s));
		tr_co = tc_co / s_tf;
		alpha1_co = 1/(delta_co*(1+rho_co)) * (tr_co*tr_co - 1);
		if (alpha1_co < 0.0)	
			Q_co = 1;
		else if ((alpha1_co >= 0.0) && (alpha1_co <= 1.0))
			Q_co = 1/(tr_co*tr_co) * (1 + alpha1_co*delta_co);
        else
            Q_co = 1/(tr_co*tr_co) * (1 + delta_co);
		UR_prc = Tb / (B * Q_co);
		
		//Column web yielding check
		Rn_wyc = fy_s*s_tw*(2.5*s_k + la);							
		if (method == 1)
			Ra_wyc = phi_wy*Rn_wyc;
		else
			Ra_wyc = Rn_wyc/omega_wy;	
		UR_wyc = tf/Ra_wyc;	

		//Column web crippling check
		if (la/s_d <= 0.2)
			Rn_wcc = 0.40*s_tw*s_tw*(1.0 + 3.0*la/s_d*pow(s_tw/s_tf,1.5))*sqrt(E*fy_s*s_tf/s_tw);
		else
			Rn_wcc = 0.40*s_tw*s_tw*(1.0 + (4.0*la/s_d - 0.2)*pow(s_tw/s_tf,1.5))*sqrt(E*fy_s*s_tf/s_tw);
		if (method == 1)
			Ra_wcc = phi_wc*Rn_wcc;
		else
			Ra_wcc = Rn_wcc/omega_wc;	
		UR_wcc = tf/Ra_wcc;						

	}
    
    if ((supp_type==2) && (!backingBeam)){
        ho = s_d - 2*s_tf;                                                  //flange to flange height of column web
        Pn_wb = 2*fy_s*s_tw*s_tw*sqrt(2*ho/(ho-gb) + (nb-1)*sb/(2*ho-gb));   //nominal strength in column web yielding
        if (method == 1)
            Pa_wb = phi_f*Pn_wb;
        else
            Pa_wb = Pn_wb/omega_f;
        UR_wb = tf/Pa_wb;
    }

	//clip angle shear yielding
	Rn_vyc=0.60*fy_a*ta*la;												//nominal strength in shear yielding of clip
	if (method==1) 
		Ra_vyc =  Rn_vyc *phi_vy; 
	else 
		Ra_vyc = Rn_vyc/omega_vy;
	fav = sqrt(tf*tf+sf*sf)/2;
	UR_vyc = fav/Ra_vyc;
	
	//clip angle shear rupture
	Anet=ta*la - nb*dbh*ta;												//net area of clip in shear
	Rn_vrc=0.60*fu_a*Anet;												//nominal strength of clip in shear rupture
	if (method==1) 
		Ra_vrc = Rn_vrc * phi_vr; 
	else 
		Ra_vrc = Rn_vrc/ omega_vr;		
	UR_vrc = fav / Ra_vrc;
	
    
    //clip angle block shear check
    Agvb = 2*(la-ed)*ta;                                                //gross area subjected to shear
    Anvb = Agvb - 2*(nb-0.5)*dbh*ta;                                    //net area subjected to shear
    Antb = 0.5*(2*lo + b_tw - gb - dbh)*ta;                             //net are subjected to tension
    Rn_bs1 = 0.6*fu_a*Anvb + fu_a*Antb;
    Rn_bs2 = 0.6*fy_a*Agvb + fu_a*Antb;
    Rn_bs = (Rn_bs1<Rn_bs2)?Rn_bs1:Rn_bs2;                              //nominal strength of clip in block shear
 	if (method==1) 
		Ra_bs = Rn_bs * phi_bs; 
	else 
		Ra_bs = Rn_bs/ omega_bs;		
	UR_bs = sf / Ra_bs;   
    
    
	//maximum interaction ratio
	UR_max = 0;
	UR_max = (UR_max>UR_bv)?UR_max:UR_bv;
	UR_max = (UR_max>UR_bt)?UR_max:UR_bt;
	UR_max = (UR_max>UR_bb)?UR_max:UR_bb;								//bolt bearing
	UR_max = (UR_max>UR_bbs)?UR_max:UR_bbs;								//bolt bearing	
	UR_max = (UR_max>UR_w)?UR_max:UR_w;									//weld shear
	UR_max = (UR_max>UR_wr)?UR_max:UR_wr;								//rupture at weld
	UR_max = (UR_max>UR_pr)?UR_max:UR_pr;								//prying action
	UR_max = (UR_max>UR_vyc)?UR_max:UR_vyc;								//clip shear yielding
	UR_max = (UR_max>UR_vrc)?UR_max:UR_vrc;								//clip shear rupture
    UR_max = (UR_max>UR_bs)?UR_max:UR_bs;                               //clip block shear
	if (supp_type == 3){
		UR_max = (UR_max>UR_prc)?UR_max:UR_prc;							//flange prying
		UR_max = (UR_max>UR_wyc)?UR_max:UR_wyc;							//web yeilding
		UR_max = (UR_max>UR_wcc)?UR_max:UR_wcc;							//web crippling		
	}
    if ((supp_type==2) && (!backingBeam))
        UR_max = (UR_max>UR_wb)?UR_max:UR_wb;                           //web flexure yielding
	if ((dct != 0) || (dcb != 0)){
		UR_max = (UR_max>UR_cf)?UR_max:UR_cf;							//cope flexure
		UR_max = (UR_max>UR_ca)?UR_max:UR_ca;							//cope axial
		UR_max = (UR_max>UR_cv)?UR_max:UR_cv;							//cope shear		
	}
}
void shearConnection1::calculateCopeDimensions()
{
}
//////////////////////////OUTPUT FUNCTIONS //////////////////////
bool shearConnection1::pass()
{
	if (UR_max > 1)
		return false;
	else 
		return true;
}
std::string shearConnection1::designInput()
{
	std::string o = "";
	_h1("Design Inputs");
		_p((method==1)?"LRFD":"ASD","Design method");
		_p(E,"Young's modulus of elasticity","",_stress);
		_p(nu, "Poisson's ratio","","");
	_h3("Connection forces");
		_p(tf,"Transfer force (TF)","",_force);
		_p(sf,"Shear force (SF)","",_force);
	_h3("Bolt Details");
		_p(db, "Bolt Diameter","",_length);
		_p(nb,"Number of bolts per clip angle (n)","","");
		_p(gb,"Bolt Gage","",_length);
		_p(sb,"Bolt Spacing","",_length);
		_p(fnt_b,"Nominal tensile capacity of bolt","", _stress);
		_p(fnv_b,"Nominal shear capacity of bolt", "", _stress);
	_h3("Weld Details");
		_p(wt,"Weld thickness", "", _length);
		_p(fu_w,"Weld tensile strength", "", _stress);
	_h3("Clip angle dimensions");
		_p(to_string(li) + "x" +	to_string(lo) + "x" + to_string(ta),"Clip angle  size (li x lo x ta)", "",_length);
		_p(la,"Clip angle length","", _length);
		_p(fy_a,"Yield strength of clip angle","",_stress);
		_p(fu_a,"Tensile strenght of clip angle","",_stress);
	_h3("Connecting beam properties");
		_p(b_section,"Section size", "","");
		_p(b_d, "   Depth","",_length);
		_p(b_bf,"   Flange width","",_length);
		_p(b_tf,"   Flange thickness","",_length);
		_p(b_tw,"   Web thickness (tw)","", _length);
		_p(fy_b,"Yield strength of beam","",_stress);
		_p(fu_b,"Tensile strength of beam","",_stress);
		_p(setback,"Beam setback from connection member (s)","",_length);
		if (supp_type==1)
		{
			_p(dct,"Top cope depth ","",_length);
			_p(dcb,"Bottom cope depth","",_length);
			_p(c,"Cope length (c)","",_length);
		}
	_h3("Supporting member properties");
		_p((supp_type==1)?"Beam Web":((supp_type==2)?"Column Web":"Column Flange"), "Support type","","");
		_p(s_section,"Section size","","");
		_p(s_d,"   Depth","", _length);
		_p(s_bf,"   Flange width","",_length);
		_p(s_tf,"   Flange thickness","",_length);
		_p(s_tw,"   Web thickness","",_length);
        _p(fy_s,"Yield strength of support","",_stress);
		_p(fu_s,"Tensile strength of support","",_stress);
	return o;
	
}

std::string shearConnection1::designSummary()
{
	std::string o = "";
	_h1("Design Summary");
	if (UR_max < 1)
		_p("","Connection is OK");
	else
		_p("","Connection is NOT OK");
	_p(UR_max, "Maximum utility ratio for connection");
	if (UR_bv>1)
		_p("","Fails in bolt shear");
	if (UR_bt>1)	
		_p("","Fails in bolt tension");
	if (UR_bb>1)	
		_p("","Fails in bolt bearing at clip");	
	if (UR_bbs>1)	
		_p("","Fails in bolt bearing at support");		
	if (UR_w>1)	
		_p("","Fails in weld shear");
	if (UR_wr>1)	
		_p("","Fails in web rupture at weld");							
	if (UR_pr>1)	
		_p("","Fails in clip angle prying");							
	if (UR_vyc>1)	
		_p("","Fails in clip angle shear yielding");							
	if (UR_vrc>1)	
		_p("","Fails in clip angle shear rupture");	
    if (UR_bs>1)	
		_p("","Fails in clip angle block shear");	
	if (supp_type == 3){
		if (UR_prc>1)	
			_p("","Fails in column flange prying");							
		if (UR_wyc>1)	
			_p("","Fails in column web yielding");							
		if (UR_wcc>1)	
			_p("","Fails in column web crippling");							
	}
    if ((supp_type==2) && (!backingBeam))
        if (UR_wb>1)
            _p("","Fails in column web flexure yeilding");		
	if ((dct != 0) || (dcb != 0)){
		if (UR_cf>1)	
			_p("","Fails in flexure strength of coped section");							
		if (UR_ca>1)	
			_p("","Fails in compression strength of coped section");							
		if (UR_cv>1)	
			_p("","Fails in shear strength of coped section");									
	}
	return o;
}
std::string shearConnection1::designCalculation()
{
	std::string o = "";	
	_h1("Design Calculations");
	_h3("Bolt Shear Check");
		_p(Vb,"Shear per bolt","Vb=SF/(2*n)",_force);
		_p(Rn_bv,"Nominal shear strength of bolt (Rn)","",_force);
		if (method == 1){
            if (boltType == "BEARING")
                _p(phi_bv,"LRFD factor in bolt shear (phi)");
            else
                _p(phi_sl,"LRFD factor in bolt shear (phi)");
			_p(Ra_bv,"Allowable shear strength of bolt","Ra=phi*Rn",_force);
		}else{
            if(boltType == "BEARING")
                _p(omega_bv,"ASD factor in bolt shear (omega)");
            else
                _p(omega_sl,"ASD factor in bolt shear (omega)");
			_p(Ra_bv,"Allowable shear strength of bolt","Ra=Rn/omega",_force);
		}
		_p(UR_bv,"Interaction ratio in bolt shear","Vb/Ra");

	_h3("Bolt Tension Check (without prying");	
		_p(Tb,"Tension per bolt without prying","Tb=TF/(2*n)", _force);
		_p(Rn_bt,"Nominal bolt strength in tension (Rn)","",_force);
		if (method == 1){
			_p(phi_bt,"LRFD factor in bolt tension (phi)");
			_p(Ra_bt,"Allowable bolt strength in tension","B=phi*Rn",_force);
		}else{
			_p(omega_bt,"ASD factor in bolt tension (omega)");		
			_p(Ra_bt,"Allowable bolt strength in tension","B=Rn/omega",_force);
		}
		_p(UR_bt,"Interaction ratio in bolt tension","Tb/B");
	
	_h3("Bolt Bearing at Clip Angle Check");	
		_p(Rn_bb,"Nominal strength in bearing at clip angle (Rn)","", _force);	
		if (method == 1){
			_p(phi_bb,"LRFD factor in bolt bearing (phi)");
			_p(Ra_bb,"Allowable strength in bearing at clip angle","Ra=phi*Rn", _force);
		}else{
			_p(omega_bb,"ASD factor in bolt bearing (omega)");
			_p(Ra_bb,"Allowable strength in bearing at clip angle","Ra=Rn/omega", _force);
		}
		_p(UR_bb,"Interaction ratio in bearing at clip angle","Vb/Ra");	

	_h3("Bolt Bearing at Support Check");	
		_p(Rn_bbs,"Nominal strength in bearing at support (Rn)","", _force);	
		if (method == 1){
			_p(phi_bb,"LRFD factor in bolt bearing (phi)");
			_p(Ra_bbs,"Allowable strength in bearing at support","Ra=phi*Rn", _force);
		}else{
			_p(omega_bb,"ASD factor in bolt bearing (omega)");
			_p(Ra_bbs,"Allowable strength in bearing at support","Ra=Rn/omega", _force);
		}
		_p(redFact, "Strength reduction factor to account for backing beam (r)");
		_p(UR_bbs,"Interaction ratio in bearing at support","Vb/(Ra*r)");

	_h3("Clip Angle Shear Yielding Check");
		_p(fav, "Shear in clip angle","Va=sqrt(TF^2+SF^2)/2", _force);
		_p(Rn_vyc,"Nominal shear yeilding strength of clip angle (Rn)","",_force);
		if (method == 1){
			_p(phi_vy,"LRFD factor for shear yielding (phi)");
			_p(Ra_vyc,"Allowable shear yielding strength of clip angle","Ra=phi*Rn",_force);
		}else{
			_p(omega_vy,"ASD factor for shear yielding (omega)");		
			_p(Ra_vyc,"Allowable shear yielding strength of clip angle","Ra=Rn/omega",_force);
		}	
		_p(UR_vyc,"Interaction ratio in shear yielding", "Va/Ra");

	_h3("Clip Angle Shear Rupture Check");	
		_p(Rn_vrc,"Nominal shear rupture strength of clip angle (Rn)","",_force);
		if (method == 1){
			_p(phi_vr,"LRFD factor for shear rupture (phi)");
			_p(Ra_vrc,"Shear rupture strength of clip angle","Ra=phi*Rn", _force);
		}else{
			_p(omega_vr,"ASD factor for shear rupture (omega)");
			_p(Ra_vrc,"Shear rupture strength of clip angle","Ra=Rn/omega", _force);
		}			
		_p(UR_vrc,"Interaction ratio in shear rupture","Va/Ra");

	_h3("Clip Angle Block Shear Check");	
		_p(Rn_bs,"Nominal block shear strength of clip angle (Rn)","",_force);
		if (method == 1){
			_p(phi_bs,"LRFD factor for block shear (phi)");
			_p(Ra_bs,"Block shear strength of clip angle","Ra=phi*Rn", _force);
		}else{
			_p(omega_bs,"ASD factor for block shear (omega)");
			_p(Ra_bs,"Block shear strength of clip angle","Ra=Rn/omega", _force);
		}			
		_p(UR_bs,"Interaction ratio in block shear","SF/Ra");
		
    	_h3("Clip angle prying action check");
		_p(Q,"Bolt strength reduction factor due to clip prying (Q)");
		_p(UR_pr, "Interaction ratio in clip prying","Tb/(Q*B)","");

	if (supp_type == 3){
		_h3("Column flange prying action check");
			_p(Q_co,"Bolt strength reduction factor due to column flange prying (Q)");
			_p(UR_prc, "Interaction ratio in column flange prying","Tb/(Q*B)","");
    }
    
	_h3("Weld Check");
		_p(fw,"Maximum stress in weld group (fw)","",_force + "/" + _length);
		_p(Rn_w,"Nominal strength of weld (Rn)","",_force + "/" + _length);
		if (method == 1){
			_p(phi_w,"LRFD factor for weld (phi)");
			_p(Ra_w,"Allowable weld strength","Ra=phi*Rn",_force + "/" + _length);
		}else{
			_p(omega_bt,"ASD factor for weld (omega)");		
			_p(Ra_w,"Allowable weld strength","Ra=Rn/omega",_force + "/" + _length);
		}	
		_p(UR_w,"Interaction ratio for weld", "fw/Ra");	
	
	_h3("Web Rupture at Weld Check");	
		_p(tw_min,"Minimum thickness of web at weld (tw`)","",_length);
		_p(UR_wr,"Interaction ratio in rupture at weld","tw`/tw");
        
	if (supp_type == 3){
		_h3("Column web yielding check");
			_p(Rn_wyc,"Nominal strength of column web yielding (Rn)","",_force);
			if (method == 1){
				_p(phi_wy, "LRFD factor in web yielding (phi)");			
				_p(Ra_wyc, "Allowable strength of column in web yielding","Ra=Rn*phi",_force);
			}else{
				_p(omega_wy, "ASD factor in web yielding (omega)");
				_p(Ra_wyc, "Allowable strength of column in web yielding","Ra=Rn/omega",_force);
			}
			_p(UR_wyc,"Interaction ratio in column web yielding","TF/Ra");
			
		_h3("Column web crippling check");
			_p(Rn_wcc,"Nominal strength of column in web crippling (Rn)","",_force);
			if (method == 1){
				_p(phi_wc, "LRFD factor in web crippling (phi)");			
				_p(Ra_wcc, "Allowable strength of column in web crippling","Ra=Rn*phi",_force);
			}else{
				_p(omega_wc, "ASD factor in web crippling (omega)");
				_p(Ra_wcc, "Allowable strength of column in web crippling","Ra=Rn/omega",_force);
			}
			_p(UR_wcc,"Interaction ratio in column web crippling","TF/Ra");
		
	}
    if ((supp_type==2) && (!backingBeam)){
        _h3("Column web flexure yielding check");
            _p(Pn_wb,"Nominal strength of column in web flexure yielding (Rn)","",_force);
            if (method == 1){
                _p(phi_f, "LRFD factor in flexure (phi)");			
                _p(Pa_wb, "Allowable strength of column in web flexure yielding","Ra=Rn*phi",_force);
            }else{
                _p(omega_f, "ASD factor in flexure (omega)");
                _p(Pa_wb, "Allowable strength of column in web flexure yielding","Ra=Rn/omega",_force);
            }
            _p(UR_wb,"Interaction ratio in column web flexure yielding","TF/Ra");       
    }
    
	if ((dct != 0) || (dcb != 0)){
		_h3("Beam Cope Flexure Check");
			_p(etf,"Eccetricity of applied transfer force from centroid of cope (e)","",_length);
			_p(Mc,"Bending moment in coped section","M=SF*(s+c)+TF*e",_moment);	
			_p(Snet,"Section modulus of coped section about major axis (Sx)","",_length + "^3");
			_p(Fcr,"Critical stress in coped section (Fcr)","",_stress);
			_p(Mn, "Nominal flexural strength of coped section", "Mn=Fcr*Sx",_moment); 
			if (method == 1){
				_p(phi_f,"LRFD factor in flexure (phi)");
				_p(Ma,"Allowable flexural strength of coped section","Ma=phi*Mn",_moment);
			}else{
				_p(omega_f,"ASD factor in flexure (omega)");
				_p(Ma,"Allowable flexural strength of coped section","Ma=Mn/omega",_moment);
			}		
			_p(UR_cf,"Interaction ratio in coped section flexure","M/Ma");

		_h3("Beam Cope Compression Check");	
			_p(Ac,"Cross section area of coped section (Ac)","",_area);
			_p(fcr,"Critical compressive stress in coped section (fcr)","",_stress);
			_p(Pn, "Nominal strength of coped section in compression (Pn)","Pn=fcr*Ac",_force);
			if (method == 1){
				_p(phi_c,"LRFD factor in compression (phi)");
				_p(Pa_ca,"Allowable compression strength of coped section","Pa=phi*Pn",_force);
			}else{
				_p(omega_c,"ASD factor in compression (omega)");
				_p(Pa_ca,"Allowable compression strength of coped section","Pa=Pn/omega",_force);
			}	
			_p(UR_ca,"Interaction ratio in coped section compression","TF/Pa");	
		
		_h3("Beam Cope Shear Check");	
			_p(Rn_cv, "Nominal strength of cope in shear (Rn)","",_force);
			if (method == 1){
				_p(phi_vy,"LRFD factor in shear yeilding (phi)");
				_p(Ra_cv,"Allowable shear strength of coped section","Ra=phi*Rn",_force);
			}else{
				_p(omega_vy,"ASD factor in shear (omega)");
				_p(Ra_cv,"Allowable shear strength of coped section","Ra=Rn/omega",_force);
			}		
			_p(UR_cv,"Interaction ratio in coped section shear","SF/Ra");
	}
	return o;
}

#endif
