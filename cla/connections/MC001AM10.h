/*
Moment Connection Class
==================================================
By		:Roshn Noronha

This class contains the details and functions 
required to design end plate moment connections 
for seismic applications. There are three possible 
configurations: four bolt unstiffened, four bolt 
stiffened and eight bolt stiffened configuration. 
The connection is 
designed as per AISC 360-10 specifications. 
==================================================
*/ 
#ifndef MOMCONNECTION1_H
#define MOMCONNECTION1_H
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

class momConnection1: public connection
{
public:
	enum design_method {LRFD,ASD};
	enum output_type {OUTPUT_NONE,OUTPUT_MINIMAL, OUTPUT_MAXIMUM};
	enum conn_type {CONN_4E,CONN_4ES,CONN_8ES};
	enum column_stiffener_type {COL_STIFFENED, COL_UNSTIFFENED};
	/*constructors*/
	momConnection1();
	momConnection1(std::map<std::string,std::string>);
	
	/*Output functions*/
	std::string designInput();
	std::string designSummary();
	std::string designCalculation();
	bool pass();	
private:	
	/*Methods*/
	void checkFitup();
	void calc();
	double plateYieldLineParameter();
	double columnYieldLineParameter();
	double min(double, double);
	std::string to_string(double);	

	/*Constants*/
	const double phi_r=0.75;					//For LRFD, in bolt rupture
	const double phi_b=0.90;					//For LRFD, in bending
	const double omega_r=2.0;					//For ASD, in bolt rupture
	const double omega_b=1.67;					//For ASD, in bending
	const double phi_v=1.0;						//For LRFD, in shear yielding
	const double omega_v=1.5;					//For ASD, in shear yielding
	const double phi_vr=0.75;					//For LRFD, in shear rupture
	const double omega_vr=2.0;					//For ASD, in shear rupture
	const double phi_bv=0.75;					//For LRFD, in bolt shear 
	const double omega_bv=2.0;					//For ASD, in bolt shear
	const double phi_br=0.75;					//For LRFD, in bolt rupture
	const double omega_br=2.0;					//For ASD, in bolt rupture
	const double phi_wy=1.0;					//For LRFD, in web yielding
	const double omega_wy=1.5;					//For ASD, in web yielding 
	const double phi_wb=0.9;					//For LRFD, in web buckling
	const double omega_wb=1.67;					//For ASD, in web buckling
	const double phi_wc=0.75;					//For LRFD, in web crippling
	const double omega_wc=2.0;					//For ASD, in web crippling
	const double phi_w=0.75;					//LRFD factor for weld 
	const double omega_w=2.0;					//ASD factor for weld
	const double phi_bb=0.75;					//LRFD factor in bolt bearing
	const double omega_bb=2.0;					//ASD factor in bolt bearing
	const double phi_ps = 0.9;					//LRFD factor for panel shear 
	const double omega_ps = 1.67;				//ASD factor for panel shear
	const double phi_c = 0.9;					//LRFD factor in compression
	const double omega_c = 1.67;				//ASD factor in compresstion
	const double phi_vs = 0.9;					//LRFD factor for shear in stiffener
	const double omega_vs = 1.67;				//ASD factor for shear in stiffener
	

	/*Properties*/
	design_method method;
	unit_system us;
	section_property beam;
	section_property column;
	section_property plate;
	conn_type connectionType;
	column_stiffener_type colStiffenerType;
	bolt blt;
	double Vu;									//Beam end shear force
	double Fyb;									//Beam yield strength
	double Fub;									//Beam ultimate strength
	double Fyp;									//Plate yield strength
	double Fup;									//Plate ultimate strength
	double Fyc;									//column yield strength
	double Fuc;									//column ultimate strength
	double Fys;									//stiffener plate yield strength
	double Fus;									//stiffener plate ultimate strength
	double E;									//Modulus of elasticity of steel
	double Ry;									//Material overstrength factor
	double bp;									//Plate width
	double dp;									//Plate depth
	double tp;									//thickness of plate
	double db;									//bolt diameter
	double g;									//bolt gage
	double pb;									//bolt spacing
	double pfo;									//Distance of outside bolt from beam flange
	double pfi;									//Distance of inside bolt from the beam flange
	double lst;									//length of stiffener plate
	double ts;									//Thickness of stiffener plate
	double t_wld;								//Thickness of beam to plate fillet weld
	double twld_b;								//Groove weld reinforcement leg size
	double Fuw;									//strength of weld
	double a;									//Distance from the top of column to the top of beam
	double tst;									//thickness of column stiffener
	weld wld;
	
	std::string b_section;
	double d_beam;								//Beam depth
	double bf_beam;								//Beam flange width
	double tf_beam;								//Beam flange thickness
	double tw_beam;								//Beam web thickness
	double Zx_beam;								//Plastic section modulus in major axis
	double k_beam;								//Beam fillet dimension
	
	std::string c_section;
	double d;									//depth of column
	double bf;									//column flange width
	double tw;									//Column web thickness
	double tf;									//Flange thickness of column
	double k;									//Column fillet dimension
	double kdet;
	
	double Mpe;									//Required plastic moment capacity of beam
	double Lp;									//Distance from the face of the column to the plastic hinge
	double Muc;									//Required moment capacity of connection
	
	double M_np;								//No prying design moment 
	double h0,h1,h2,h3,h4;						//Distance of the centerline of the beam compression flange to the ith tension bolt row
	double Pt;									//Bolt tensile strength
	
	double Yp;									//Yield line parameter for plate bending
	double tp_req;								//Required minimum plate thickness
    double ratio_py;                            //Interaction ratio in plate yielding
	
	double Rn_v;								//Nominal strength in shear yielding
	double P_cap_v;								//Shear yielding capacity of plate
	
	double F_f;									//Flange force
	double P_req_v;								//Required strength of plate in shear yielding
	double ratio_v;								//Interaction ratio in shear yielding
	
	double dbh;									//Standard bolt hole diameter
	double An;									//Net shear area of plate
	double Rn_vr;								//Nominal strength in shear yielding
	double P_cap_vr;							//Shear yielding capacity of plate
	double P_req_vr;							//Required strength of plate in shear yielding
	double ratio_vr;							//Interaction ratio in shear rupture
	
	double ts_req;								//Required minimum stiffener thickness
	double hst;									//Stiffener plate height
	double ts_req_b;							//Required minimum thickness of stiffener plate 
	double ratio_pst;
	
	double ratio_bt;							//Interaction ratio for bolt tension
	double Fnt;									//Bolt nominal tensile stress
	double db_req;								//Required diameter of bolt

	int nb_c;									//Number of bolts provided at compression flange
	double Vb;									//Nominal shear strength of bolt
	
	double Rn_bv;								//Nominal shear strength of connectionType
	double V_cap_bv;							//Bolt shear capacity of connection
	double ratio_bv;							//Interaction ratio in bolt shear
	
	double lco;
	double lci;
	double sb;									//Bolt spacing in direction of shear
	double ed;									//Edge distance of outer bolts
	double Rn_bbo;								//Nominal strength in bolt bearing of outer bolts
	double Rn_bbi;								//Nominal strength in bolt bearing of inner bolts
	double Rn_bbi4;                             //Nominal strength in bolt bearing of 4th row of the inner bolts
    double Rn_bb;								//Nominal strength of connection in bolt bearing
	double V_cap_bb;							//Allowable strength in bolt bearing
	double ratio_bb;							//Interaction ratio in bolt bearing

    double ed_col_top;                          //bolt edge distance to column top
    double lco_col;  
    double lci_col;
    double Rn_bbco;                             //nominal strength of outer bolt in bearing at flange
    double Rn_bbci;                             //nominal strength of inner bolt in bearing at flange
	double Rn_bbci4;                            //Nominal strength in bolt bearing of 4th row of the inner bolts
	double Rn_bbc;								//nominal strength of bolt bearing on column
	double V_cap_bbc;							//allowable strength of bolt bearing on column
	double ratio_bbc;							//interaction ratio for bolt bearing on column
  
    double fwwt;                                //required strenght of web weld in tension    
    double fn_wwt;                              //nominal strength of  web weld in tension
    double fa_wwt;                              //allowable strength of  web weld in tension
    double ratio_wwt;                           //interactiion ratio in weld tension at web
    
	double lw;									//web weld length
	double Rn_ww;								//nominal strenght of web weld
	double Ra_ww;								//allowable strength of web weld
	double ratio_ww;							//interaction ratio for weld at web

	double t_wld_s;								//thickness of stiffener to beam fillet weld
	double Vs;									//shear strength of stiffener per unit lenght
	double Rn_ws;								//nominal strength o stiffener to beam weld
	double Ra_ws;								//allowable strength of stiffener to beam weld
	double ratio_ws;							//interaction ratio for stiffener to beam weld

	double tf_req; 								//Required minimum column flange thickness
	double Yc;									//Column yield line parameter 
	double ratio_fy;							//Interaction ratio for column flange yielding
	
	double Ct;									//Column edge factor for web yielding
	double N;									//Bearing length for web yielding
	double Rn_wy;								//Nominal strength of column web in local yielding
	double P_cap_wy;							//Column local web yielding capacity
	double ratio_wy;							//Interaction ratio in web local yielding
	
	double h;									//Clear distance between the flanges minus the fillet
	double Rn_wb;								//Nominal strength of column in web buckling
	double P_cap_wb;							//Column local web buckling capacity
	double ratio_wb;							//Interaction ratio in column web buckling
	
	double N_wc;								//Bearing area for web crippling
	double Rn_wc;								//Nominal strength in column web crippling
	double P_cap_wc;							//Column web crippling capacity
	double ratio_wc;							//Interaction ratio in column web buckling
	

	double P_req_vp;							//Required strength of plate in shear yielding

	double P_cap_min;
	
	double Puc;									//Axial force in column
	double Vus;									//story shear
	double Pyc;									//yield strength of column
	double Ac;									//cross section area of column
	double Rn_ps;								//nominal strength in panel shear 
	double Ra_ps;								//allowable strength in panel shear
	double ratio_ps;							//Interaction ratio for panel shear
	double tw_min;								//minimum thickness of column web to avoid shear buckling
	double tw_min1;
	double ratio_twc;							//interaction ratio in column web shear buckling

	double Yc_cfu;								//yield line parameter for unstiffened column
	double Mn_cfu;								//Unstiffened flange nominal moment capacity
	double Ma_cfu;								//Unstiffened flange allowable moment capacity
	double P_cap_cfu;							//Unstiffened column allowable flange force

	double Ru_st;								//Required strength of stiffener
	double wst;									//width of stiffener
	double clip_st;								//dimension of stiffener clipst
	double Pn_cst;								//nominal axial strength of stiffener
	double Pa_cst;								//allowable axial force in stiffener
	double ratio_cst;							//interaction ratio for stiffener

	double Rn_vst;								//nominal shear strength of stiffener
	double Ra_vst;								//allowable shear strength of stiffener
	double ratio_vst;							//interaction ratio for stiffener in shear

	double tst_min;								//minimum thickness of transverse stiffener
	double ratio_tst;							//interaction ratio for minimum thickness of stiffener

	double Rn_wsf;								//nominal strength of stiffener to flange weld
	double twld_wsf;							//thickness of stiffener to flange weld
	double Ra_wsf;								//allowable strength of stiffener to flange weld
	double Py_st;								//Required strength of stiffener to flange weld
	double ratio_wsf;							//interaction ratio for stiffener to flange weld

	double Rn_wsw;								//nominal strength of stiffener to web weld
	double twld_wsw;							//thickness of stiffener to web weld
	double Ra_wsw;								//allowable strength of stiffener to web weld
	double ratio_wsw;							//interaction ratio for stiffener to web weld

	double Vu_dp;								//required strength of doubler plate
	double Rn_vdp;								//nominal strength of doubler plate
	double Ra_vdp;								//allowable strength of doubler plate
	double tdp;									//thickness of doubler plate
	double ratio_vdp;							//interaction ratio for doubler plate shear

	double wdp_min;								//minimum height of doubler plate
	double wdp;									//height of doubler plate
	double ratio_wdp;							//interaction ratio for doubler plate thickness

	double tdp_min;								//minimum thickness of doubler plate
	double tdp_min1;
	double ratio_tdp;							//interaction ratio for minimum plate thickness

    double Rn_wdf;                              //nominal strength of doubler plate to flange weld
    double Ra_wdf;                              //allowable strength of doubler plate to flange weld
	//double tdp_req;						    //required thickness of doubler plate
	double twld_dp;								//thickness of doubler plate to flange weld
	//double twld_dp_req;						//required thickness of doubler plate to flange weld
	double ratio_wdf;							//interaction ratio for doubler plate to flange weld
	
	bool col_doubler_plate;						//boolean to indicate if doubler plate is present

	double ratio_max;							//maximum interaction ratio
};

////////////////////CONSTRUCTORS/////////////////////////
momConnection1::momConnection1(){
}
momConnection1::momConnection1(std::map<std::string,std::string> data):plate(section_property::MEMB_TYPE_PLATE){	
	addParameter("CONNECTION_CODE");
	addParameter("CONNECTION_ID");
	addParameter("DESCRIPTION","MOMENT CONNECTION");	
	addParameter("METHOD");	
	param("METHOD").addAllowableValue("LRFD");
	param("METHOD").addAllowableValue("ASD");
	addParameter("UNITS");	
	param("UNITS").addAllowableValue("NEWTON_MM");
	param("UNITS").addAllowableValue("KIP_IN");
	addParameter("MODULUS_OF_ELASTICITY");		
	param("MODULUS_OF_ELASTICITY").isPositiveNumber();
	addParameter("STEEL_GRADE_OF_PLATE","A36");
	param("STEEL_GRADE_OF_PLATE").addAllowableValue("A36");
	addParameter("WELD_ELECTRODE","E70");
	param("WELD_ELECTRODE").addAllowableValue("E70");
	addParameter("BOLT_GRADE");
	param("BOLT_GRADE").addAllowableValue("A325");
	param("BOLT_GRADE").addAllowableValue("A490");
	addParameter("SHEAR_FORCE","0");
	param("SHEAR_FORCE").isPositiveNumber();
	addParameter("COLUMN_AXIAL_FORCE","0");
	param("COLUMN_AXIAL_FORCE").isPositiveNumber();
	addParameter("PLATE_WIDTH");
	param("PLATE_WIDTH").isPositiveNumber();
	addParameter("PLATE_HEIGHT");	
	param("PLATE_HEIGHT").isPositiveNumber();
	addParameter("PLATE_THICKNESS");		
	param("PLATE_THICKNESS").isPositiveNumber();
	addParameter("BOLT_DIAMETER");		
	addParameter("CONFIGURATION");			
	param("CONFIGURATION").addAllowableValue("4_BOLTS");
	param("CONFIGURATION").addAllowableValue("4_BOLTS_STIFFENED");
	param("CONFIGURATION").addAllowableValue("8_BOLTS_STIFFENED");
	addParameter("BOLT_GAGE");				
	param("BOLT_GAGE").isPositiveNumber();
	if (data["CONFIGURATION"] == "8_BOLTS_STIFFENED")
		addParameter("BOLT_SPACING");	
	else 
		addParameter("BOLT_SPACING","0");
	param("BOLT_SPACING").isPositiveNumber();
	addParameter("INNER_BOLT_TO_FLANGE");				
	param("INNER_BOLT_TO_FLANGE").isPositiveNumber();
	addParameter("OUTER_BOLT_TO_FLANGE");					
	param("OUTER_BOLT_TO_FLANGE").isPositiveNumber();
	addParameter("WEB_WELD");					
	param("WEB_WELD").isPositiveNumber();
	addParameter("FLANGE_WELD_REINFORCEMENT","0");					
	param("FLANGE_WELD_REINFORCEMENT").isPositiveNumber();
	addParameter("BEAM_SECTION");						
	addParameter("STEEL_GRADE_OF_BEAM");							
	param("STEEL_GRADE_OF_BEAM").addAllowableValue("A36");
	param("STEEL_GRADE_OF_BEAM").addAllowableValue("A992");
	addParameter("COLUMN_SECTION");								
	addParameter("STEEL_GRADE_OF_COLUMN");									
	param("STEEL_GRADE_OF_COLUMN").addAllowableValue("A36");
	param("STEEL_GRADE_OF_COLUMN").addAllowableValue("A992");
	addParameter("DISTANCE_TO_COLUMN_TOP","0");								
	param("DISTANCE_TO_COLUMN_TOP").isPositiveNumber();
	if (data["CONFIGURATION"] != "4_BOLTS"){
		addParameter("PLATE_STIFFENER_WELD");
		addParameter("PLATE_STIFFENER_LENGTH");	
		addParameter("PLATE_STIFFENER_THICKNESS");
	}else{
		addParameter("PLATE_STIFFENER_WELD","0");	
		addParameter("PLATE_STIFFENER_LENGTH","0");	
		addParameter("PLATE_STIFFENER_THICKNESS","0");	
	}
	param("PLATE_STIFFENER_WELD").isPositiveNumber();
	param("PLATE_STIFFENER_LENGTH").isPositiveNumber();
	param("PLATE_STIFFENER_THICKNESS").isPositiveNumber();
	addParameter("COLUMN_STIFFENER");
	param("COLUMN_STIFFENER").addAllowableValue("YES");
	param("COLUMN_STIFFENER").addAllowableValue("NO");
	if (data["COLUMN_STIFFENER"] == "YES"){
		addParameter("COLUMN_STIFFENER_THICKNESS");
		addParameter("COLUMN_STIFFENER_TO_FLANGE_WELD");
		addParameter("COLUMN_STIFFENER_TO_WEB_WELD");
	}else{
		addParameter("COLUMN_STIFFENER_THICKNESS","0");
		addParameter("COLUMN_STIFFENER_TO_FLANGE_WELD","0");
		addParameter("COLUMN_STIFFENER_TO_WEB_WELD","0");
	}
	param("COLUMN_STIFFENER_THICKNESS").isPositiveNumber();
	param("COLUMN_STIFFENER_TO_FLANGE_WELD").isPositiveNumber();
	param("COLUMN_STIFFENER_TO_WEB_WELD").isPositiveNumber();	
	addParameter("COLUMN_STIFFENER_WIDTH","0");
	param("COLUMN_STIFFENER_WIDTH").isPositiveNumber();
	addParameter("COLUMN_STIFFENER_CLIP","0");
	param("COLUMN_STIFFENER_CLIP").isPositiveNumber();
	addParameter("DOUBLER_PLATE");
	param("DOUBLER_PLATE").addAllowableValue("YES");
	param("DOUBLER_PLATE").addAllowableValue("NO");
	if (data["DOUBLER_PLATE"] == "YES"){
		addParameter("DOUBLER_PLATE_THICKNESS");
		addParameter("DOUBLER_PLATE_WELD");
        addParameter("DOUBLER_PLATE_HEIGHT");
	}else{
		addParameter("DOUBLER_PLATE_THICKNESS","0");
		addParameter("DOUBLER_PLATE_WELD","0");	
        addParameter("DOUBLER_PLATE_HEIGHT","0");
	}
	param("DOUBLER_PLATE_THICKNESS").isPositiveNumber();
	param("DOUBLER_PLATE_WELD").isPositiveNumber();
	param("DOUBLER_PLATE_HEIGHT").isPositiveNumber();
	validateParameters(data);


	connCode = data["CONNECTION_CODE"];
	connID = data["CONNECTION_ID"];

	if (data["METHOD"] == "LRFD")
		method = LRFD;
	else
		method = ASD;
	if (data["UNITS"] == "NEWTON_MM") {
		us.setUnitSystem(unit_system::NEWTON_MM);
		blt.setUnitSystem(unit_system::NEWTON_MM);
		beam.setUnitSystem(unit_system::NEWTON_MM);
		column.setUnitSystem(unit_system::NEWTON_MM);
		plate.setUnitSystem(unit_system::NEWTON_MM);
		wld.setUnitSystem(unit_system::NEWTON_MM);
	}else{
		us.setUnitSystem(unit_system::KIP_IN);
		blt.setUnitSystem(unit_system::KIP_IN);
		beam.setUnitSystem(unit_system::KIP_IN);
		column.setUnitSystem(unit_system::KIP_IN);
		plate.setUnitSystem(unit_system::KIP_IN);
		wld.setUnitSystem(unit_system::KIP_IN);
	}
	//MATERIAL PROPERTIES
	E = atof(data["MODULUS_OF_ELASTICITY"].c_str());
	plate.setGrade(section_property::ASTM_A36);
	Fyp = plate.yieldStrength();
	Fup = plate.tensileStrength();	
	wld.setGrade(weld::FEXX70);
	Fuw = wld.tensileStrength();
	if (data["BOLT_GRADE"] == "A325")
		blt.setBoltGrade(bolt::ASTM_A325);
	else
		blt.setBoltGrade(bolt::ASTM_A490);
	//CONNECTION FORCES
	Vu = atof(data["SHEAR_FORCE"].c_str());
	Puc = atof(data["COLUMN_AXIAL_FORCE"].c_str());
	//END PLATE DETAILS
	bp = atof(data["PLATE_WIDTH"].c_str());
	dp = atof(data["PLATE_HEIGHT"].c_str());
	tp = atof(data["PLATE_THICKNESS"].c_str());
	//BOLT DETAILS
	blt.setBoltDiameter(data["BOLT_DIAMETER"]);
	db = blt.diameter();	
	if (data["CONFIGURATION"] == "4_BOLTS")
		connectionType = CONN_4E;
	else if (data["CONFIGURATION"] == "4_BOLTS_STIFFENED")
		connectionType = CONN_4ES;
	else 
		connectionType = CONN_8ES;	
	g = atof(data["BOLT_GAGE"].c_str());
	if (connectionType == CONN_8ES){
		pb = atof(data["BOLT_SPACING"].c_str());
	}
	pfi = atof(data["INNER_BOLT_TO_FLANGE"].c_str());
	pfo = atof(data["OUTER_BOLT_TO_FLANGE"].c_str());
	//WELD DETAILS
	t_wld = atof(data["WEB_WELD"].c_str());	
	twld_b = atof(data["FLANGE_WELD_REINFORCEMENT"].c_str());		
	t_wld_s = atof(data["PLATE_STIFFENER_WELD"].c_str());
	//BEAM DETAILS
	b_section = data["BEAM_SECTION"];
	beam.setSection(b_section);
	d_beam = beam.depth();								
	bf_beam = beam.flangeWidth();								
	tf_beam = beam.flangeThickness();
	tw_beam = beam.webThickness();
	k_beam = beam.filletDimension();
	Zx_beam = beam.plasticSectionModulus();
	if (data["STEEL_GRADE_OF_BEAM"] == "A36"){
		beam.setGrade(section_property::ASTM_A36);
		Ry = 1.5;
	}else{
		beam.setGrade(section_property::ASTM_A992);
		Ry = 1.1;
	}
	Fyb = beam.yieldStrength();
	Fub = beam.tensileStrength();
	//COLUMN DETAILS
	c_section = data["COLUMN_SECTION"];
	column.setSection(c_section);
	d = column.depth();								
	bf = column.flangeWidth();								
	tf = column.flangeThickness();
	tw = column.webThickness();		
	k = column.filletDimension();
	kdet = column.detFilletDimension();
	Ac = column.area();
	if (data["STEEL_GRADE_OF_COLUMN"] == "A36") 
		column.setGrade(section_property::ASTM_A36);
	else
		column.setGrade(section_property::ASTM_A992);
	Fyc = column.yieldStrength();
	Fuc = column.tensileStrength();	
	if (data.count("DISTANCE_TO_COLUMN_TOP") != 0)
		a = atof(data["DISTANCE_TO_COLUMN_TOP"].c_str());
	else
		a=d;
	if (connectionType != CONN_4E){
		lst = atof(data["PLATE_STIFFENER_LENGTH"].c_str());
		ts = atof(data["PLATE_STIFFENER_THICKNESS"].c_str());
	}
	//COLUMN STRIFFENER DETAILS
	if (data["COLUMN_STIFFENER"]=="YES"){		
		colStiffenerType = COL_STIFFENED;
		tst = atof(data["COLUMN_STIFFENER_THICKNESS"].c_str());
		if (data.count("COLUMN_STIFFENER_WIDTH") == 0)
			wst = (bf-tw)/2;
		else{
			wst = atof(data["COLUMN_STIFFENER_WIDTH"].c_str());
		}
		if (data.count("COLUMN_STIFFENER_CLIP") == 0)
			clip_st = (k - tf);
		else{
			clip_st = atof(data["COLUMN_STIFFENER_CLIP"].c_str());
		}
		twld_wsf = atof(data["COLUMN_STIFFENER_TO_FLANGE_WELD"].c_str());
		twld_wsw = atof(data["COLUMN_STIFFENER_TO_WEB_WELD"].c_str());	
	}else{
		tst = 0;
		colStiffenerType = COL_UNSTIFFENED;	
	}
	//DOUBLER PLATE DETAILS

	if (data["DOUBLER_PLATE"]=="YES"){
		col_doubler_plate = true;
		tdp = atof(data["DOUBLER_PLATE_THICKNESS"].c_str());
		twld_dp = atof(data["DOUBLER_PLATE_WELD"].c_str());
        wdp = atof(data["DOUBLER_PLATE_HEIGHT"].c_str());
	}else
		col_doubler_plate = false;

	if (err.isError()) throw err.errorMessage();	

	//check fitup
	checkFitup();
	if (err.isError()) throw err.errorMessage();		
	
	calc();	
	
}
//////////////////DESIGN FUNCTIONS/////////////////////
void momConnection1::checkFitup(){
	//bolt vertical edge distance to plate
	double ed_min = blt.minEdgeDistance();
	double ed1;
	if (connectionType == CONN_8ES)
		ed1 = (dp - d_beam - 2*pfo - 2*pb)/2;
	else
		ed1 = (dp - d_beam - 2*pfo)/2;	
	if (ed1 < ed_min) err.addError("Bolt vertical edge distance to end plate is insufficient. Try increasing the plate height.");
	//bolt horizontal edge distance on plate
	double ed2;
	ed2 = (bp - g)/2;
	if (ed2 < ed_min) err.addError("Bolt horizontal edge distance to end plate is insufficient. Try increasing the plate width or reducing the bolt gage.");	
	//edge distance on column flange
	double ed3;
	ed3 = (bf - g)/2;
	if (ed3 < ed_min) err.addError("Bolt edge distance column flange is insufficient. Try reducing the bolt gage.");	
	//bolt spacing
	if (connectionType == CONN_8ES)
		if (pb < blt.minBoltSpacing()) err.addError("Bolt minimum spacing not satistied. Try increasing the bolt spacing.");
	//inner and outer bolt pitch to flange
	double gap;
	if (us.getUnitSystem() == unit_system::NEWTON_MM)
		gap = 12;
	else 
		gap = 0.5;
	if (pfo < db + gap) err.addError("Insufficient pitch for outer bolt. Try increasing the pitch of the outer bolts.");
	if (pfi < db + gap) err.addError("Insufficient pitch for inner bolt. Try increasing the pitch of the inner bolts.");
	//plate width check
	if (bp < bf_beam) err.addError("End plate width cannot be lesser than beam width. Try increasing plate width.");	 
	//bolt clash with column fillet area
	double rr = kdet - tf;				//fillet area radius
	if (!col_doubler_plate){
		if (g/2 - tw/2 - rr < db) err.addError("Bolt clashes with the column fillet area. Try increasing the bolt gage.");
	}else{
		if (g/2 - tw/2 -  tdp < db) err.addError("Bolt clashes with the column doubler plate. Try increasing the bolt gage.");
    }
    //maximum gage (limited to beam flange width)
	if (g > bf_beam) err.addError("Bolt gage should not exceed the beam width. Try reducing bolt gage.");
	if (connectionType != CONN_4E){
		//minimum length of stiffener
		double hst = (dp - d_beam)/2; 		//stiffener height
		double lst_min = hst / 0.57735;		//hst/tan(30)
		if (lst < lst_min) err.addError("Minimum length of plate stiffener not provided. Try increasing the length of the plate stiffener");
	}
	if (colStiffenerType == COL_STIFFENED){
		//column transverse stiffener width check
		if (wst > (bf - tw)/2) err.addError("Column transverse stiffener exceeds the column flange dimensions. Try reducing the stiffener width.");
		//column transverse stiffener clip check
		if (clip_st < (k - tf)) err.addError("Stiffener clip dimension clashes with the column fillet area. Try increasing the stiffener clip dimension.");	
		if (clip_st >= wst) err.addError("Stiffener clip dimension cannot exceed stiffener width. Try decreasing the stiffener clip dimension.");	
	}
    //column doubler plate minimum thickness check
	if (col_doubler_plate)
		if (tdp < rr) err.addError("Doubler plate thickness should exceed the column fillet area radius. Try increasing the doubler plate thickness.");
	
}
void momConnection1::calc(){
	db = blt.diameter();
	Pt=blt.nominalTensionStrength();					//Bolt tensile strength
	dbh=blt.standardBoltHole();							//Standard bolt hole diameter
	Vb=blt.nominalShearStrength();						//Nominal shear strength of bolt
	
	//Design Moment
	Mpe=1.1*Ry*Fyb*Zx_beam;								//Required plastic moment capacity of beam
	if (connectionType==CONN_4E)
		Lp=min(d_beam/2.,3.*bf_beam);					//Distance from the face of the column to the plastic hinge
	else
		Lp=lst+tp;
	Muc=Mpe + Vu*Lp;									//Required moment capacity of connection
	
	//No Prying Moment
	if (connectionType==CONN_8ES){
		h1= d_beam - 0.5*tf_beam + pfo + pb;			//h0,h1,h2,h3,h4:Distance of the centerline of the beam compression flange to the ith tension bolt row
		h2= d_beam - 0.5*tf_beam + pfo;
		h3= d_beam - tf_beam - pfi;
		h4= d_beam - tf_beam - pfi - pb;
		M_np= 2.0*Pt*(h1+h2+h3+h4);						//No prying design moment
	}else{
		h0=d_beam - 0.5*tf_beam + pfo;
		h1= d_beam - tf_beam - pfi;
		M_np=2.0*Pt*(h0+h1);
	}
	
	//Plate Thickness Calculation
	Yp = plateYieldLineParameter();				
	if (method==LRFD)
		tp_req=sqrt(1.11*phi_r*M_np/(phi_b*Fyp*Yp));
	else
		tp_req=sqrt(1.11*omega_b*M_np/(omega_r*Fyp*Yp));	
    ratio_py = tp_req/tp;
  	
	//Plate Shear Yielding 
	Rn_v=0.6*Fyp*bp*tp;									//Nominal strength in shear yielding
	if (method==LRFD)
		P_cap_v=Rn_v*phi_v;
	else	
		P_cap_v=Rn_v/omega_v;
	F_f=Muc/(d_beam-tf_beam);							//Flange force
	P_req_v=F_f/2.;										//Required strength of plate in shear yielding
	if (connectionType != CONN_4E)
        ratio_v = 0;
    else
        ratio_v=P_req_v/P_cap_v;						//Interaction ratio in shear yielding
	
	//Plate Shear Rupture
	An=(bp-2.*dbh)*tp;									//Net shear area of plate
	Rn_vr=0.6*Fup*An;									//Nominal strength in shear yielding
	if (method==LRFD)
		P_cap_vr=Rn_vr*phi_vr;
	else	
		P_cap_vr=Rn_vr/omega_vr;
	P_req_vr=F_f/2.;									//Required strength of plate in shear yielding
	if (connectionType != CONN_4E)
        ratio_vr = 0;
    else
        ratio_vr=P_req_vr/P_cap_vr;						//Interaction ratio in shear rupture
	
	//Stiffener checks    
    ts_req=tw_beam*(Fyb/Fyp);	                    //required stiffener Plate Thickness				
    hst=(dp-d_beam)/2.0;							//Stiffener plate height
    ts_req_b=1.79*hst*sqrt(Fyp/E);					//Required minimum thickness of stiffener plate for local buckling
	ts_req = ts_req_b>ts_req?ts_req_b:ts_req;
    if (connectionType != CONN_4E)
        ratio_pst = ts_req/ts;	
    else
        ratio_pst = 0;

	//Bolt tension check
	Fnt = blt.nominalTensileStress();
    if (method==LRFD){
        if (connectionType == CONN_8ES)
            db_req = sqrt(2*Muc/(PI*phi_bv*Fnt*(h1+h2+h3+h4)));
        else
            db_req = sqrt(2*Muc/(PI*phi_bv*Fnt*(h0+h1)));
    }else{
        if (connectionType == CONN_8ES)
            db_req = sqrt(2*omega_bv*Muc/(PI*Fnt*(h1+h2+h3+h4)));
        else
            db_req = sqrt(2*omega_bv*Muc/(PI*Fnt*(h0+h1)));        
    }
	ratio_bt = db_req/db;
	
	//Bolt Shear Rupture									
	if (connectionType==CONN_8ES)
		nb_c=8;											//Number of bolts provided at compression flange
	else 
		nb_c=4;
	Rn_bv=nb_c*Vb;										//Nominal shear strength of connectionType
	if (method==LRFD)
		V_cap_bv=Rn_bv*phi_bv;
	else	
		V_cap_bv=Rn_bv/omega_bv;
	ratio_bv=Vu/V_cap_bv;								//Interaction ratio in bolt shear
	//Bolt Bearing On Plate	    
    if (connectionType==CONN_8ES){
        ed = (dp - d_beam)/2 - pfo - pb;
        sb = pfo + pfi + tf_beam;
        lco =  min(ed - dbh/2,pb - dbh);
        lci = min(sb - dbh, pb - dbh);
        Rn_bbo = 2 * min(1.2*lco*tp*Fup,2.4*db*tp*Fup);
        Rn_bbi = 2 * min(1.2*lci*tp*Fup,2.4*db*tp*Fup);
        Rn_bbi4 = 2 * min(1.2*(pb - dbh)*tp*Fup,2.4*db*tp*Fup);
        Rn_bb = Rn_bbo + 2*Rn_bbi + Rn_bbi4;
    }else{
        ed = (dp - d_beam)/2 - pfo;
        sb = pfo + pfi + tf_beam;
        lco = min(ed- dbh/2,sb - dbh);
        lci = sb - dbh;
        Rn_bbo = 2 * min(1.2*lco*tp*Fup,2.4*db*tp*Fup);
        Rn_bbi = 2 * min(1.2*lci*tp*Fup,2.4*db*tp*Fup);
        Rn_bb = Rn_bbo + Rn_bbi;
    }	
	if (method==LRFD)
		V_cap_bb = Rn_bb*phi_bb;
	else 
		V_cap_bb = Rn_bb / omega_bb;
	ratio_bb = Vu/V_cap_bb;

	//Bolt Bearing on column flange    
    if (connectionType == CONN_8ES){
        ed_col_top = a - pb- pfo;
        lco_col = min(ed_col_top - dbh/2, pb - dbh);
        lci_col = min(sb - dbh, pb-dbh); 
        Rn_bbco = 2 * min(1.2*lco_col*tf*Fuc,2.4*db*tf*Fuc);
        Rn_bbci = 2 * min(1.2*lci_col*tf*Fuc,2.4*db*tf*Fuc);  
        Rn_bbci4 = 2 * min(1.2*(pb - dbh)*tf*Fuc,2.4*db*tf*Fuc);
        Rn_bbc = Rn_bbco + 2*Rn_bbci + Rn_bbci4;        
    }else{
        ed_col_top = a - pfo;
        lco_col = min(ed_col_top - dbh/2, sb - dbh);
        lci_col = sb - dbh;    
        Rn_bbco = 2 * min(1.2*lco_col*tf*Fuc,2.4*db*tf*Fuc);
        Rn_bbci = 2 * min(1.2*lci_col*tf*Fuc,2.4*db*tf*Fuc);
        Rn_bbc = Rn_bbco + Rn_bbci;
    }
    if (method==LRFD)
		V_cap_bbc = Rn_bbc*phi_bb;
	else 
		V_cap_bbc = Rn_bbc / omega_bb;	
	ratio_bbc = Vu/V_cap_bbc;
	
    //Web to plate weld tension check    
    fwwt = Fyb*tw_beam;
    fn_wwt = 1.5*2*0.6*Fuw*0.707*t_wld;
	if (method==LRFD)
		fa_wwt = fn_wwt*phi_w;
	else
		fa_wwt = fn_wwt/omega_w;
	ratio_wwt = fwwt/fa_wwt;    
    
	//Web to plate weld shear check	
    if (us.getUnitSystem() == unit_system::KIP_IN)
        lw = 2*(d_beam - tf_beam - k_beam - pfi - 6);
    else
        lw = 2*(d_beam - tf_beam - k_beam - pfi - 6*25.4);
	Rn_ww = 0.6*Fuw*0.707*t_wld*lw;
	if (method==LRFD)
		Ra_ww = Rn_ww*phi_w;
	else
		Ra_ww = Rn_ww/omega_w;
	ratio_ww = Vu/Ra_ww;
	
	//Stiffener to beam flange weld check
	Vs = phi_v * 0.6 *Fyp*ts;
	Rn_ws = 0.6*Fuw*0.707*t_wld_s*2;
	if (method==LRFD)
		Ra_ws = Rn_ws*phi_w;
	else
		Ra_ws = Rn_ws/omega_w;
	if (connectionType != CONN_4E)
        ratio_ws = Vs/Ra_ws;	
    else
        ratio_ws = 0;
	//Column web panel shear check
	Pyc = Fyc * Ac;
	if(Puc/Pyc<0.75)
		Rn_ps = 0.6*Fyc*d*tw*(1 + 3*bf*tf*tf/(d_beam*d*tw));
	else
		Rn_ps = 0.6*Fyc*d*tw*(1 + 3*bf*tf*tf/(d_beam*d*tw)) * (1.9 - 1.2*Puc/Pyc);
	
	if (method == LRFD)
		Ra_ps = phi_ps * Rn_ps;
	else
		Ra_ps = Rn_ps / omega_ps;
	if (col_doubler_plate)
        ratio_ps = 0;
    else
        ratio_ps = F_f/Ra_ps;
	
    //Column web shear buckling
    tw_min = (d_beam - tf_beam + d - 2*tf)/90;
    ratio_twc = tw_min / tw;
    
	//Column Flange Yielding
	Yc=columnYieldLineParameter();						//Column yield line parameter 
	if (method==LRFD)
		tf_req=sqrt(1.11*phi_br*M_np/(phi_b*Fyc*Yc));	
	else	
		tf_req=sqrt(1.11*omega_b*M_np/(omega_br*Fyc*Yc));
	ratio_fy=tf_req/tf;									//Interaction ratio for column flange yielding
	
	
	if (colStiffenerType == COL_STIFFENED){
		colStiffenerType = COL_UNSTIFFENED;
		Yc_cfu = columnYieldLineParameter();
		colStiffenerType = COL_STIFFENED;
		Mn_cfu = Fyc*Yc_cfu*tf*tf;
		if(method == LRFD)
			Ma_cfu = phi_b*Mn_cfu;
		else
			Ma_cfu = Mn_cfu / omega_b;
		P_cap_cfu = Ma_cfu/(d_beam - tf_beam);
		P_cap_min = P_cap_cfu;
	}
	//Column Web Yielding
	if (a<d) 	Ct=0.5;									//Column edge factor for web yielding
	else		Ct=1.0;
	N=tf_beam + 2.0*twld_b;								//Bearing length
	Rn_wy=(Ct*(6.*k + 2.*tp)+N)*Fyc*tw;					//Nominal strength of column web in local yielding
	if (method==LRFD)
		P_cap_wy=Rn_wy*phi_wy;
	else	
		P_cap_wy=Rn_wy/omega_wy;
	P_cap_min = P_cap_wy<P_cap_min? P_cap_wy: P_cap_min;
	if (colStiffenerType == COL_STIFFENED)
        ratio_wy = 0;
    else
        ratio_wy=F_f/P_cap_wy;							//Interaction ratio in web local yielding

	//Column Web Crippling
	N_wc = tf_beam + 2.*twld_b;							//Bearing area for web crippling
	if (a>=0.5*d)
		Rn_wc=0.8 * (tw*tw) * (1.+ 3.*N_wc/d * pow(tw/tf,1.5) ) * sqrt(E*Fyc*tf/tw);
	else if (N_wc/d<0.2) 
		Rn_wc=0.4 * (tw*tw) * (1. +3.*N_wc/d * pow(tw/tf,1.5)) * sqrt(E*Fyc*tf/tw);
	else
		Rn_wc=0.4 * (tw*tw) * (1. + (4.*N_wc/d-0.2) * pow(tw/tf,1.5))* sqrt(E*Fyc*tf/tw);
	if (method==LRFD)
		P_cap_wc=Rn_wc*phi_wc;
	else
		P_cap_wc=Rn_wc/omega_wc;
	P_cap_min = P_cap_wc<P_cap_min? P_cap_wc: P_cap_min;
	if (colStiffenerType == COL_STIFFENED)
        ratio_wc = 0;
    else
        ratio_wc=F_f/P_cap_wc;							//Interaction ratio in column web crippling

	//Stiffener and doubler plates
	if (colStiffenerType == COL_STIFFENED){		
		//transverse stiffener axial strength
		Ru_st = F_f - P_cap_min;
		Ru_st = Ru_st>0? Ru_st:0;
		Pn_cst = Fyp * (wst-clip_st)*tst;
		if (method==LRFD)
			Pa_cst = phi_c * Pn_cst;
		else
			Pa_cst = Pn_cst / omega_c;
		ratio_cst = Ru_st/(2*Pa_cst);
		
		//transverse stiffener shear strength
		Rn_vst = 0.6*Fyp*tst*(d - 2 *(tf + clip_st));
		if (method==LRFD)
			Ra_vst = phi_vs * Rn_vst;
		else 
			Ra_vst = Rn_vst / omega_vs;
		ratio_vst = Ru_st/(2*Ra_vst);
		
		//transverse stiffener minimum thickness
        if (us.getUnitSystem() == unit_system::KIP_IN)
            tst_min = wst*sqrt(Fyp)/95;
        else
            tst_min = wst/25.4*sqrt(Fyp/6.895)/95 * 25.4;
		tst_min = tst_min>(tf_beam/2)? tst_min: (tf_beam/2);
		ratio_tst = tst_min/tst;
		
		//transverse stiffener to flange weld check
		Rn_wsf = 2*1.5*0.6*Fuw*0.707*twld_wsf;
		if (method == LRFD)
			Ra_wsf = phi_w * Rn_wsf;
		else 
			Ra_wsf = Rn_wsf /omega_w;
		Py_st = 0.9 *Fyp*tst;
		ratio_wsf = Py_st / Ra_wsf;
		
		//transverse stiffener to web weld check
		Rn_wsw = 0.6*Fuw*(d - 2* (tf + clip_st))*2*0.707*twld_wsw;
		if (method == LRFD)
			Ra_wsw = phi_w*Rn_wsw;
		else
			Ra_wsw = Rn_wsw / omega_w;
		ratio_wsw = Ru_st/(2*Ra_wsw);
		
	}
	
	if (col_doubler_plate){
		//Doubler plate design
		Vu_dp = F_f - Ra_ps;
		Rn_vdp = 0.6*Fyp * d *tdp;
		if (method == LRFD)
			Ra_vdp = phi_v * Rn_vdp;
		else 
			Ra_vdp = Rn_vdp / omega_v;
		ratio_vdp = Vu_dp / Ra_vdp;
		
		//Minimum width of doubler plate
		wdp_min = d_beam + 2 *(3*k + tp);
		ratio_wdp = wdp_min/ wdp;
		
		//Minimum thickness of doubler plate
        if (us.getUnitSystem() == unit_system::KIP_IN)
            tdp_min = (d-2*k)*sqrt(Fyp)/418;
		else
            tdp_min = (d-2*k)*sqrt(Fyp/6.895)/418;
        tdp_min1 = ((d_beam - tf_beam) - tst + d- 2*tf)/90;
		tdp_min = tdp_min1>tdp_min? tdp_min1: tdp_min;
		ratio_tdp = tdp_min / tdp;
		
		//Doubler plate to flange weld check        
        Rn_wdf = 0.6*Fuw*0.707*twld_dp*wdp;
 		if (method == LRFD)
			Ra_wdf = phi_w * Rn_wdf;
		else 
			Ra_wdf = Rn_wdf /omega_w;
        ratio_wdf = Vu_dp / Ra_wdf;
    }
	//maxumum interaction ratio
	ratio_max = 0;
	ratio_max = ratio_bt > ratio_max?ratio_bt:ratio_max;							//Interaction ratio in bolt tension
    ratio_max = ratio_py > ratio_max?ratio_py:ratio_max;                            //Interaction ratio in plate yielding
	ratio_max = ratio_v > ratio_max?ratio_v:ratio_max;								//Interaction ratio in shear yielding
	ratio_max = ratio_vr > ratio_max?ratio_vr:ratio_max;							//Interaction ratio in shear rupture
	ratio_max = ratio_bv > ratio_max?ratio_bv:ratio_max;							//Interaction ratio in bolt shear
	ratio_max = ratio_bb > ratio_max?ratio_bb:ratio_max;							//Interaction ratio in bolt bearing
	ratio_max = ratio_bbc > ratio_max?ratio_bbc:ratio_max;							//interaction ratio for bolt bearing on column
    ratio_max = ratio_wwt > ratio_max?ratio_wwt:ratio_max;							//interaction ratio for weld tension at web
	ratio_max = ratio_ww > ratio_max?ratio_ww:ratio_max;							//interaction ratio for weld shear at web
	ratio_max = ratio_pst > ratio_max?ratio_pst:ratio_max;		    				//interaction ratio for end plate stiffener thickness
	ratio_max = ratio_ws > ratio_max?ratio_ws:ratio_max;		    				//interaction ratio for stiffener to beam weld
	ratio_max = ratio_fy > ratio_max?ratio_fy:ratio_max;							//Interaction ratio for column flange yielding
	ratio_max = ratio_wy > ratio_max?ratio_wy:ratio_max;						    //Interaction ratio in web local yielding
	ratio_max = ratio_wc > ratio_max?ratio_wc:ratio_max;						    //Interaction ratio in column web crippling
	ratio_max = ratio_ps > ratio_max?ratio_ps:ratio_max;                            //Interaction ratio in panel shear
	ratio_max = ratio_twc > ratio_max?ratio_twc:ratio_max;						    //Interaction ratio in column web buckling

	if (colStiffenerType == COL_STIFFENED){
		ratio_max = ratio_cst > ratio_max?ratio_cst:ratio_max;						//interaction ratio for transverse stiffener axial strength
		ratio_max = ratio_vst > ratio_max?ratio_vst:ratio_max;						//interaction ratio for transverse stiffener shear strength
		ratio_max = ratio_tst > ratio_max?ratio_tst:ratio_max;						//interaction ratio for minimum thickness of stiffener
		ratio_max = ratio_wsf > ratio_max?ratio_wsf:ratio_max;						//interaction ratio for stiffener to flange weld
		ratio_max = ratio_wsw > ratio_max?ratio_wsw:ratio_max;						//interaction ratio for stiffener to web weld
	}

	if(col_doubler_plate){
		ratio_max = ratio_vdp > ratio_max?ratio_vdp:ratio_max;						//interaction ratio for doubler plate shear
		ratio_max = ratio_wdp > ratio_max?ratio_wdp:ratio_max;                      //interaction ratio for doubler plate height
        ratio_max = ratio_tdp > ratio_max?ratio_tdp:ratio_max;						//interaction ratio for minimum plate thickness
		ratio_max = ratio_wdf > ratio_max?ratio_wdf:ratio_max;						//interaction ratio for doubler plate to flange weld
	}
}


double momConnection1::plateYieldLineParameter()
{
	double Yp;										//Yield line parameter
	double s=0.5*sqrt(bp*g);
	double pfi_mod=min(pfi,s);	
    
	double d_e;					//Bolt edge distance	
	if (connectionType==CONN_4E){
        Yp=0.5*bp*(h1*(1./pfi_mod+1./s) + h0/pfo - 0.5) + 2./g*(h1*(pfi_mod+s));
	}else if (connectionType==CONN_4ES){
        d_e=0.5*(dp-d_beam)-pfo;
        if (d_e < s)
			Yp=0.5*bp*(h1*(1./pfi_mod+1./s) + h0*(1./pfo + 0.5/s)) + 2./g*(h1*(pfi_mod+s) + h0*(d_e + pfo));
		else
			Yp=0.5*bp*(h1*(1./pfi_mod+1./s) + h0*(1./pfo + 1./s)) + 2./g*(h1*(pfi_mod+s) + h0*(s + pfo));
	}else{
        d_e=0.5*(dp-d_beam)- pfo - pb;
        if (d_e < s)
			Yp=0.5*bp*(0.5*h1/d_e + h2/pfo + h3/pfi_mod + h4/s) + 2./g*(h1*(d_e+pb/4.) + h2*(pfo+3.*pb/4.) + h3*(pfi_mod + pb/4.) + h4*(s+3.*pb/4.) + (pb*pb)) + g;
		else
			Yp=0.5*bp*(h1/s + h2/pfo + h3/pfi_mod + h4/s) + 2./g*(h1*(s+pb/4.) + h2*(pfo+3.*pb/4.) + h3*(pfi_mod + pb/4.) + h4*(s+3.*pb/4.) + (pb*pb)) + g;
	}
	return Yp;
}
double momConnection1::columnYieldLineParameter()
{
	double Yc;										//Column Flange yield line parameter
	double s=0.5*sqrt(bf*g);
	double c=pfo+pfi+tf_beam;						//Distance between the outer and inner bolts
	double psi=pfi+0.5*(tf_beam-tst);				//Distance of the inner bolt from the column stiffener plate edge
	double pso= pfo+0.5*(tf_beam-tst);				//Distance of the outer bolt from the column stiffener plate edge
	double psi_mod=min(psi,s);
    
	if ((connectionType==CONN_4E)||(connectionType==CONN_4ES))
	{
		if (colStiffenerType==COL_UNSTIFFENED)
			Yc=0.5*bf*(h1/s + h0/s) + 2./g*(h1*(s+3.*c/4.) + h0*(s+c/4.) + 0.5*c*c) + 0.5*g;
		else
			Yc=0.5*bf*(h1*(1./s+1./psi_mod) + h0*(1./s+1./pso)) + 2./g*(h1*(s+psi_mod) + h0*(s+pso));
	}else
	{
		if (colStiffenerType==COL_UNSTIFFENED)
			Yc=0.5*bf*(h1/s + h4/s) + 2./g*(h1*(pb+0.5*c+s) + h2*(0.5*pb + 0.25*c) + h3*(0.5*pb + 0.5*c) + h4*s) + 0.5*g;
		else
			Yc=0.5*bf*(h1/s + h2/pso + h3/psi_mod + h4/s) + 2./g*(h1*(s+ 0.25*pb) + h2*(pso+0.75*pb)+ h3*(psi_mod+0.25*pb) + h4*(s+0.75*pb) + pb*pb) +g;
	}	
    return Yc;	
}

double momConnection1::min(double a, double b)
{
	if (a<b)	return a;
	else 		return b;
}
std::string momConnection1::to_string(double a)
{	
	std::ostringstream s; 
	s << a; 
	return s.str();
}	
/////////////OUTPUT FUNCTIONS//////////////
bool momConnection1::pass(){

	if (ratio_max > 1)
		return false;
	else
		return true;	
}

std::string momConnection1::designInput()
{
	std::string o = "";
	_h1("Design Inputs");
	_p(connectionType==CONN_4E?"4 BOLT - UNSTIFFENED":(connectionType==CONN_4ES?"4 BOLT - STIFFENED":"8 BOLT - STIFFENED"),"Extended plate moment connection configuration");
	_p(method==LRFD?"LRFD":"ASD","Design method");
	_p(Vu, "Shear force in connection (V)","",_force);
    _p(Puc, "Column axial force","",_force);
	_p(E, "Modulus of elasticity of steel","",_stress);
	_p(Fyb, "Yield strength of beam (Fyb)","",_stress);
	_p(Fub, "Tensile strength of beam","",_stress);
	_p(Fyc, "Yield strength of column","",_stress);
	_p(Fuc, "Tensile strength of column","",_stress);
	_p(Fyp, "Yield strength of plate","",_stress);
	_p(Fup, "Tensile strength of plate", "", _stress);
	_p(Fuw, "Tensile strength of weld","",_stress);
	_p(Ry, "Material overstrength factor for beam (Ry)");

	_p(oso::to_string(bp) + " x " + oso::to_string(dp) + " x " + oso::to_string(tp) , "End plate dimensions (b x d x tp)","",_length);

	_p(db, "Bolt diamter","",_length);
	_p(blt.boltGrade(), "Bolt grade");
	
	_p(t_wld, "Thickness of beam web to plate fillet weld","",_length);
	_p(twld_b, "Thickness of flange weld reinforing fillet weld","",_length);
	if (connectionType != CONN_4E){
		_p(ts, "Thickness of end plate stiffener (tsp)","",_length);
        _p(lst, "Length of end plate stiffener","",_length);
        _p(t_wld_s, "Thickness of plate stiffener to beam flange weld","",_length);
	}
	_p(b_section, "Beam section property");
	_p(d_beam, "   Depth (d)","",_length);
	_p(bf_beam,"   Flange width","",_length);
	_p(tw_beam,"   Web thickness","",_length);
	_p(tf_beam,"   Flange thickness (tf)","",_length);
	_p(k_beam, "   Fillet dimension","",_length);
	_p(Zx_beam, "   Plastic section modulus (Zx)","",_length+"^3");
	_p(c_section, "Column section property");
	_p(d, "   Depth","",_length);
	_p(bf,"   Flange width","",_length);
	_p(tw, "   Web thickness","",_length);
	_p(tf,"   Flange thickness","",_length);
	_p(k,"   Fillet dimension","",_length);
    
	if (colStiffenerType == COL_STIFFENED){
		_p(tst, "Thickness of column stiffener (tsc)","",_length);
        _p(wst, "Width of column stiffener","",_length);
        _p(clip_st, "Column stiffener clip dimension","",_length);
        _p(twld_wsf, "Column stiffener to flange weld","",_length);        
        _p(twld_wsw, "Column stiffener to web weld","",_length);
	}
    if(col_doubler_plate){
		_p(tdp, "Thickness of column doubler plate","",_length);
        _p(wdp, "Height of column doubler plate","",_length);
        _p(twld_dp, "Column doubler to flange weld","",_length);        
    }
 /*
tdp = atof(data["DOUBLER_PLATE_THICKNESS"].c_str());
		twld_dp = atof(data["DOUBLER_PLATE_WELD"].c_str());
        wdp =
*/ 

	return o;
}
std::string momConnection1::designSummary()
{
	std::string o = "";
	if (ratio_bt > 1) _p("","Fails in bolt tension");
    if (ratio_py > 1) _p("","Fails in end plate yielding");
	if (ratio_v > 1) _p("","Fails in end plate shear yielding");
	if (ratio_vr > 1) _p("","Fails in end plate shear rupture");
	if (ratio_bv > 1) _p("","Fails in bolt shear");
	if (ratio_bb > 1) _p("","Fails in bolt bearing on end plate");
	if (ratio_bbc > 1) _p("","Fails in bolt bearing on column");
	if (ratio_wwt > 1) _p("","Fails in web weld tension strength");
	if (ratio_ww > 1) _p("","Fails in web weld shear strength");
    if (ratio_pst > 1) _p("","Fails in end plate stiffener thickness requirement");
	if (ratio_ws > 1) _p("","Fails in end plate stiffener to beam weld strength");
	if (ratio_fy > 1) _p("","Fails in column flange yielding");
	if (ratio_wy > 1) _p("","Fails in column local web yielding");
	if (ratio_wc > 1) _p("","Fails in column local web crippling");
    if (ratio_ps > 1) _p("","Fails in column web panel shear");
	if (ratio_twc > 1) _p("","Fails in column web shear buckling");
	if (colStiffenerType == COL_STIFFENED){
		if (ratio_cst > 1) _p("","Fails in column stiffener axial strength");
		if (ratio_vst > 1) _p("","Fails in column stiffener shear strength");
		if (ratio_tst > 1) _p("","Fails in column minimum stiffener thickness");
		if (ratio_wsf > 1) _p("","Fails in column stiffener to flange strength");
		if (ratio_wsw > 1) _p("","Fails in column stiffener to web strength");
	}
	if(col_doubler_plate){
		if (ratio_vdp > 1) _p("","Fails in doubler plate shear");
        if (ratio_wdp > 1) _p("","Fails in doubler plate height");
		if (ratio_tdp > 1) _p("","Fails in doubler minimum plate thickness");
		if (ratio_wdf > 1) _p("","Fails in doubler plate to flange weld strength");
	}
	
	o = oso::format_p(ratio_max,"Maximum interaction ratio") + o;
	if (ratio_max > 1)
		o = oso::format_p("","Connection is NOT OK") + o;
	else
		o = oso::format_p("","Connection is OK") + o;
	o = oso::format_h1("Design Summary") + o;
	
	return o;
}
std::string momConnection1::designCalculation()
{
	std::string o = "";
	_h1("Design calculations");
	_h3("Connection design forces");
		_p(Mpe,"Required plastic moment capacity of beam","Mpe=1.1*Ry*Fyb*Zx",_moment);
		if (connectionType==CONN_4E)
			_p(Lp,"Distance from the face of the column to the plastic hinge (Lp)","",_length);
		else
			_p(Lp,"Distance from the face of the column to the plastic hinge (Lp)","",_length);
		if (method == LRFD)
			_p(Muc,"Required moment capacity of connection","Muc=Mpe+V*Lp" ,_moment);
		else
			_p(Muc,"Required moment capacity of connection","Muc=Mpe+1.5*V*Lp" ,_moment);
		_p(F_f,"Flange force","Fu=Muc/(d-tf)" ,_force);	
		
	_h3("Bolt Tension check");
		_p("","Distance of the centerline of the beam compression flange to the");
		if (connectionType==CONN_8ES){
			_p(h1,"   1st tension bolt row (h1)","",_length);
			_p(h2,"   2nd tension bolt row (h2)","",_length);
			_p(h3,"   3rd tension bolt row (h3)","",_length);
			_p(h4,"   4th tension bolt row (h4)","",_length);	
		}else{
			_p(h0,"   1st tension bolt row (h0)","",_length);
			_p(h1,"   2nd tension bolt row (h1)","",_length);		
		}
		_p(Fnt, "Bolt nominal tensile stress","",_stress);
		if (connectionType == CONN_8ES)
			_p(db_req,"Required bolt diameter","db`=sqrt(2*Muc/(PI*phi_bv*Fnt*(h1+h2+h3+h4)))",_length);
		else
			_p(db_req,"Required bolt diameter","db`=sqrt(2*Muc/(PI*phi_bv*Fnt*(h0+h1)))",_length);
		_p(ratio_bt,"Interaction ratio in bolt tension","db`/db","");
	
	
	_h3("Bolt Shear Rupture Check");	
		_p(nb_c,"Number of bolts provided at compression flange (nc)","" , "" );
		_p(Vb, "Nominal shear strength of bolt (Vb)","" , _force);
		_p(Rn_bv,"Nominal shear strength of connectionType","Rn=nc*Vb" , _force);
		if(method==LRFD){
			_p(phi_bv, "LRFD factor in bolt shear (phi)","" , "");
			_p(V_cap_bv,"Bolt shear capacity","Ra=Rn*phi" , _force);
		}else{
			_p(omega_bv,"ASD factor in bolt shear (omega)","" , "");
			_p(V_cap_bv,"Bolt shear capacity","Ra=Rn/omega" , _force);			
		}
		_p(ratio_bv,"Interaction ratio in bolt shear","Vu/Ra","");	
	
	_h3("Bolt Bearing on Plate");
		_p(Rn_bb,"Nominal strength in bolt bearing on plate (Rn)","",_force);
		if(method==LRFD){
			_p(phi_bb, "LRFD factor in bolt bearing (phi)","" , "");
			_p(V_cap_bb,"Bolt bearing on plate capacity","Ra=Rn*phi" , _force);
		}else{
			_p(omega_bb,"ASD factor in bolt bearing (omega)","" , "");
			_p(V_cap_bb,"Bolt bearing on plate capacity","Ra=Rn/omega" , _force);			
		}
		_p(ratio_bb,"Interaction ratio in bolt bearing on plate","Vu/Ra","");	

	_h3("Bolt Bearing on Column Flange");
		_p(Rn_bbc,"Nominal strength in bolt bearing on flange (Rn)","",_force);
		if(method==LRFD){
			_p(phi_bb, "LRFD factor in bolt bearing (phi)","" , "");
			_p(V_cap_bbc,"Bolt bearing on flange capacity","Ra=Rn*phi" , _force);
		}else{
			_p(omega_bb,"ASD factor in bolt bearing (omega)","" , "");
			_p(V_cap_bbc,"Bolt bearing on flange capacity","Ra=Rn/omega" , _force);			
		}
		_p(ratio_bbc,"Interaction ratio in bolt bearing on flange","Vu/Ra","");	
		
	_h3("Plate Thickness Calculation");
	_p(Pt, "Bolt tensile strength (Pt)","",_force);
		if (connectionType==CONN_8ES)
			_p(M_np,"No prying design moment","Mnp= 2*Pt*(h1+h2+h3+h4)",_moment);
		else
			_p(M_np,"No prying design moment","Mnp= 2*Pt*(h0+h1)",_moment);
		if (method==LRFD){
			_p(phi_r,"LRFD factor in bolt rupture (phi)","","");
			_p(phi_b,"LRFD factor in bending (phi_b)","","");
			_p(Yp, "Yield line parameter for plate (Yp)","",_length);
			_p(tp_req,"Required minimum plate thickness","tp`=sqrt(1.11*phi*Mnp/(phi_b*Fyp*Yp))",_length);
		}else{
			_p(omega_r,"ASD factor in bolt rupture (omega)","","");
			_p(omega_b,"ASD factor in bending (omega_b)","","");
			_p(Yp, "Yield line parameter for plate (Yp)","",_length);
			_p(tp_req,"Required minimum plate thickness","tp`=sqrt(1.11*omega_b*Mnp/(omega*Fyp*Yp))",_length);			
		}
		_p(ratio_py, "Interaction ratio for plate thickness","tp`/tp","");
	
	if (connectionType == CONN_4E){
		_h3("Plate Shear Yielding Check");
			_p(bp*tp,"Gross shear area of plate","" ,_area);
			_p(Rn_v,"Nominal strength in shear yielding (Rn)","" , _force);
			if (method==LRFD){
				_p(phi_v,"LRFD factor in shear yielding (phi)","","");
				_p(P_cap_v, "Shear yielding capacity of plate","Ra=Rn*phi",_force);
			}else{
				_p(omega_v,"ASD factor in shear yielding (omega)","","");
				_p(P_cap_v,"Shear yielding capacity of plate","Ra=Rn/omega",_force);			
			}
			_p(ratio_v, "Interaction ratio in shear yielding","Fu/(2*Ra)" , "");

		_h3("Plate Shear Rupture Check");
			_p(An,"Net shear area of plate","" ,_area);
			_p(Rn_vr,"Nominal strength in shear rupture (Rn)","" , _force);
			if (method==LRFD){
				_p(phi_vr,"LRFD factor in shear rupture (phi)","" , "");
				_p(P_cap_vr,"Shear rupture capacity of plate","Ra=Rn*phi" , _force);
			}else{
				_p(omega_vr,"ASD factor in shear rupture (omega)","", "");
				_p(P_cap_vr,"Shear rupture capacity of plate","Ra=Rn/omega", _force);			
			}
			_p(ratio_vr,"Interaction ratio in shear rupture","Fu/(2*Ra)" , "");
	
	}
    
    _h3("Beam Web to End Plate Weld Tension Check");
        _p(fwwt, "Required tension strength of weld at beam web (fw)","", _force + "/" + _length); 
		_p(fn_wwt, "Nominal strength of weld at beam web (fn)","",_force + "/" + _length);
		if(method==LRFD){
			_p(phi_w, "LRFD factor for weld (phi)","" , "");
			_p(fa_wwt,"Beam web weld capacity","fa=fn*phi" , _force + "/" + _length);
		}else{
			_p(omega_w,"ASD factor in weld (omega)","" , "");
			_p(fa_wwt,"Beam web weld capacity","fa=fn/omega" , _force + "/" + _length);			
		}	
		_p(ratio_wwt,"Interaction ratio for beam web weld in tension","fw/fa","");	
        
    _h3("Beam Web to End Plate Weld Shear Check");
		_p(lw, "Total weld length","",_length);
		_p(Rn_ww, "Nominal strength of weld at beam web (Rn)","",_force);
		if(method==LRFD){
			_p(phi_w, "LRFD factor for weld (phi)","" , "");
			_p(Ra_ww,"Beam web weld capacity","Ra=Rn*phi" , _force);
		}else{
			_p(omega_w,"ASD factor in weld (omega)","" , "");
			_p(Ra_ww,"Beam web weld capacity","Ra=Rn/omega" , _force);			
		}	
		_p(ratio_ww,"Interaction ratio for beam web weld in shear","Vu/Ra","");	
    
	if (connectionType != CONN_4E){
		_h3("End Plate Stiffener Thickness Check");
			_p(ts_req,"Required minimum stiffener thickness (tsp`)","", _length);
			_p(ratio_pst, "Interaction ratio for stiffener thickness","tsp`/tsp","");

		_h3("End Plate Stiffener to Flange Weld Check");
			_p(Vs, "Required strength of stiffener weld","Vs=0.6*Fyp*ts",_force + "/" + _length);
			_p(Rn_ws, "Nominal strength of stiffener to flange weld (Rn)","",_force + "/" + _length);
			if(method==LRFD){
				_p(phi_w, "LRFD factor for weld (phi)","" , "");
				_p(Ra_ws,"Stiffener to flange weld capacity","Ra=Rn*phi" , _force);
			}else{
				_p(omega_w,"ASD factor in weld (omega)","" , "");
				_p(Ra_ws,"Stiffener to flange weld capacity","Ra=Rn/omega" , _force);			
			}		
			_p(ratio_ws,"Interaction ratio for stiffener to flange weld","Vs/Ra","");
	
	}


	_h3("Column Flange Yielding Check");		
		_p(Yc,"Column yield line parameter (Yc)","" , _length);
		if (method==LRFD){
			_p(phi_r,"LRFD factor in bolt rupture (phi)","" , "");
			_p(phi_b,"LRFD factor in flexure (phi_b)","" ,"");
			_p(tf_req,"Required minimum column flange thickness","tf`=sqrt(1.11*phi*Mnp/(phi_b*Fyc*Yc))" ,_length);
		}else{
			_p(omega_r, "ASD factor in bolt rupture (omega)","" , "");
			_p(omega_b,"ASD factor in flexure (omega_b)","" ,"");
			_p(tf_req,"Required minimum column flange thickness","tf`=sqrt(1.11*omega_b*Mnp/(omega*Fyc*Yc))" ,_length);			
		}
		_p(ratio_fy,"Interaction ratio for column flange yielding","ratio=tf`/tf" ,"");

	_h3("Column Web Yielding Check");	
		_p(N,"Bearing length","N=tf+2*wb", _length);	
		if (a<d)
			_p(Rn_wy,"Nominal strength of column web in local yielding (Rn)","" , _force);
		else
			_p(Rn_wy,"Nominal strength of column web in local yielding (Rn)","" , _force);
		if (method==LRFD){
			_p(phi_wy, "LRFD factor in local web yielding (phi)","" , "" );
			_p(P_cap_wy,"Column local web yielding capacity","Ra=Rn*phi" , _force);
		}else{
			_p(omega_wy,"LRFD factor in local web yielding (omega)","" , "" );
			_p(P_cap_wy,"Column local web yielding capacity","Ra=Rn/omega" , _force);			
		}
		_p(ratio_wy,"Interaction ratio in web local yielding","Fu/Ra" , "");

	_h3("Column Local Web Crippling Check");	
		if (a>=0.5*d)
			_p(Rn_wc,"Nominal strength in column web crippling (Rn)",""  , _force);
		else if (N_wc/d<0.2)
			_p(Rn_wc,"Nominal strength in column web crippling (Rn)",""  , _force);
		else
			_p(Rn_wc,"Nominal strength in column web crippling (Rn)",""  , _force);
		if (method==LRFD){
			_p(phi_wc, "LRFD factor in web crippling (phi)", "", "");
			_p(P_cap_wc,"Column web crippling capacity","Ra=Rn*phi" , _force);
		}else{
			_p(omega_wc,"ASD factor in web crippling (omega)","" , "");
			_p(P_cap_wc, "Column web crippling capacity","Ra=Rn/omega" , _force);
		}
		_p(ratio_wc, "Interaction ratio in web crippling","Fu/Ra","");

	_h3("Column Panel Shear Check");
		_p(Rn_ps,"Nominal strength of column in panel shear","",_force);
		if (method == LRFD){
			_p(phi_ps,"LRFD factor for column panel shear (phi)");
			_p(Ra_ps,"Column panel shear capacity","Ra=Rn*phi",_force);
		}else{
			_p(omega_ps,"ASD factor for column panel shear (omega)");
			_p(Ra_ps,"Column panel shear capacity","Ra=Rn/omega",_force);
		}
		_p(ratio_ps,"Interaction ratio for column panel shear","Fu/Ra","");
		
    _h3("Column Web Shear Buckling Check");
        _p(tw_min,"Minimum thickness of web to prevent shear buckling (tw`)","",_length);
        _p(ratio_twc,"Interaction ratio for thickness of web","tw`/tw","");	
	
	if(colStiffenerType == COL_STIFFENED){
		_h3("Transverse Stiffener Axial Strength");
			_p(Ru_st,"Required strength of column stiffener (Ru)","",_force);
			_p(Pn_cst,"Nominal yield strength of stiffener (Rn)","",_force);
			if (method==LRFD){
				_p(phi_c, "LRFD factor in axial strength (phi)", "", "");
				_p(Pa_cst,"Stiffener axial yield capacity","Ra=Rn*phi",_force);
			}else{
				_p(omega_c,"ASD factor in axial strength (omega)","" , "");
				_p(P_cap_wc, "Stiffener axial yield capacity","Ra=Rn/omega" , _force);	
			}
			_p(ratio_cst,"Interaction ratio for stiffener in axial strength","Ru/Ra","");	
			
		_h3("Transverse stiffener shear strength");
			_p(Rn_vst,"Nominal shear strength of stiffener (Rn)","",_force);
			if (method==LRFD){
				_p(phi_vs, "LRFD factor in stiffener shear strength (phi)", "", "");
				_p(Ra_vst,"Stiffener shear capacity","Ra=Rn*phi",_force);
			}else{
				_p(omega_vs,"ASD factor in stiffener shear strength (omega)","" , "");
				_p(Ra_vst, "Stiffener shear capacity","Ra=Rn/omega" , _force);	
			}
			_p(ratio_vst,"Interaction ratio for stiffener in shear","Ru/(2*Ra)","");

		_h3("Transverse Stiffener Thickness Check");
			_p(tst_min, "Minimum required thickness of stiffener (tsc`)","",_length);
			_p(ratio_tst,"Interaction ratio for stiffener thickness", "tsc`/tsc","");
		
		_h3("Transverse Stiffener to Flange Weld Check");
			_p(Py_st,"Required strength for stifferner to flange weld (Ps)","",_force + "/" + _length);
			_p(Rn_wsf,"Nominal strength of stiffener to flange weld (Rn)","",_force + "/" + _length);
			if (method==LRFD){
				_p(phi_w, "LRFD factor for weld strength (phi)", "", "");
				_p(Ra_wsf,"Stiffener to flange weld capacity","Ra=Rn*phi",_force);
			}else{
				_p(omega_w,"ASD factor weld strength (omega)","" , "");
				_p(Ra_wsf, "Stiffener to flange weld capacity","Ra=Rn/omega" , _force);	
			}
			_p(ratio_wsf,"Interaction ratio for stiffener to flange weld","Ps/Ra","");
		
		_h3("Transverse Stiffener to Web Weld Check");
			_p(Rn_wsw, "Nominal strength of stiffener to web weld (Rn)","",_force + "/" + _length);
			if (method==LRFD){
				_p(phi_w, "LRFD factor for weld strength (phi)", "", "");
				_p(Ra_wsw,"Stiffener to web weld capacity","Ra=Rn*phi",_force+ "/" + _length);
			}else{
				_p(omega_w,"ASD factor weld strength (omega)","" , "");
				_p(Ra_wsw, "Stiffener to web weld capacity","Ra=Rn/omega" , _force+ "/" + _length);	
			}		
			_p(ratio_wsw,"Interaction ratio for stiffener to web weld","Ru/(2*Ra)","");		
	}
	
	if(col_doubler_plate){
		_h3("Doubler Plate Shear Check");
			_p(Vu_dp, "Required shear strength of doubler plate (Vd)","",_force);
			_p(Rn_vdp, "Nomimal shear strength of doubler plate (Rn)","",_force);
			if (method==LRFD){
				_p(phi_v, "LRFD factor for shear (phi)", "", "");
				_p(Ra_vdp,"Doubler plate shear capacity","Ra=Rn*phi",_force);
			}else{
				_p(omega_v,"ASD factor for shear (omega)","" , "");
				_p(Ra_vdp, "Doubler plate shear capacity","Ra=Rn/omega" , _force);	
			}
			_p(ratio_vdp,"Interaction ratio for doubler plate shear","Vd/Ra","");		

		_h3("Doubler Plate Height Check");
			_p(wdp_min,"Minimum required height of doubler plate (wd`)","",_length);
			_p(ratio_wdp, "Interaction ratio for doubler plate height","wd`/wd","");

		_h3("Doubler Plate Thickness Check");
			_p(tdp_min,"Minimum required thickness of doubler plate (td`)","",_length);
			_p(ratio_tdp, "Interaction ratio for doubler plate thickness","td`/td","");
			
		_h3("Doubler Plate to Flange Weld Check");
			_p(Rn_wdf, "Nominal strength of doubler to flange weld (Rn)","",_force);
			if (method==LRFD){
				_p(phi_w, "LRFD factor for weld strength (phi)", "", "");
				_p(Ra_wdf,"Doubler to flange weld capacity","Ra=Rn*phi",_force);
			}else{
				_p(omega_w,"ASD factor weld strength (omega)","" , "");
				_p(Ra_wdf, "Doubler to flange weld capacity","Ra=Rn/omega" , _force);	
			}		
			_p(ratio_wdf,"Interaction ratio for plate to weld thickness","Vd/Ra","");
	}


	
	return o;
}


#endif
