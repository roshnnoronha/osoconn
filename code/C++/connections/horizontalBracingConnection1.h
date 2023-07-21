/*
Horizontal Bracing Connection Class
==================================================
By		:Roshn Noronha
Date	:09/SEP/2021

This class contains the details and functions 
requried to design a bolted horizontal bracing 
connection to two beams. The connections to the 
beams can be either using a pair of clip angles, 
shear tabs, or by direct bolting to the bottom the
beam flange.
==================================================
*/ 
#ifndef HORIZONTAL_BRACING_CONNECTION_H
#define HORIZONTAL_BRACING_CONNECTION_H
#define _p o=o+oso::format_p
#define _h1 o=o+oso::format_h1
#define _h2 o=o+oso::format_h2
#define _h3 o=o+oso::format_h3
#define _br o=o+oso::format_br()
#define _length us.lengthUnit()
#define _force us.forceUnit()
#define _area us.areaUnit()
#define _stress us.stressUnit()

class HBConnection1: public connection
{
public:
	enum method {LRFD,ASD};
	enum conn_type {CLIP_ANGLE,SHEAR_PLATE,BOTTOM_FLANGE};
	enum brace_memb_type {SINGLE_ANGLE_BRACE, DOUBLE_ANGLE_BRACE_BBLH,DOUBLE_ANGLE_BRACE_BBLV};
	enum outstanding_leg_type {SHORT_LEG, LONG_LEG};
	enum output_type {OUTPUT_NONE,OUTPUT_MINIMAL, OUTPUT_MAXIMUM};
	HBConnection1();
	HBConnection1(std::map<std::string,std::string>);
	
	
	void printDesignOutput();
	std::string designInput();
	std::string designSummary();
	std::string designCalculation();
	bool pass();
	
private:
	const double phi_br=0.75;	//LRFD factor in brace rupture
	const double omega_br=2.0;	//ASD factor in brace rupture
	const double phi_yg=0.9;	//LRFD factor in gusset yielding
	const double omega_yg=1.67;	//ASD fctor in gusset yielding
	const double phi_bs=0.75;	//LRFD factor in block shear
	const double omega_bs=2.0;	//ASD factor in block shear
	const double phi_y=1.0;		//LRFD factor in shear yielding
	const double omega_y=1.5;	//ASD factor in shear yielding
	const double phi_r=0.75;	//LRFD factor un shear rupture
	const double omega_r=2.0;	//ASD factor in shear rupture
	const double phi_f=0.90;	//LRFD factor in flexure
	const double omega_f=1.67;	//ASD factor in flexure
	const double phi_w=0.75;	//LRFD factor in weld strength
	const double omega_w=2.0;	//ASD factor in weld strength
	double phi_bb=0.75;			//LRFD factor in bolt bearing
	double omega_bb=2.0;		//ASD factor in bolt bearing

	//Input vatiables
	method met;
	unit_system us;
	double P;					//Brace force
	double tog;					//distance of top of steel of gusset plate from TOS of beam
	int n_br;					//number of bolts per row of gusset to brace connection
	int n1;						//number of bolts per row in connction 1
	int n2;						//number of bolts per row in connection 2
	double sb;					//bolt spacing
	double nr;					//number of bolt rows
	double sr;					//spaceing between bolt rows
	conn_type conn1;
	conn_type conn2;
	double theta;				//brace angle
	double tg;					//gusset plate thickness
	bolt blt;					//connection bolts
	double ed;					//bolt edge distance on brace
	double edg;					//bolt edge distance on gusset
	double edt;					//bolt edge distance on shear tab
	double edc;					//bolt edge distance on clip angle 
	double edb;					//bolt edge distance on beam
	section_property brace;
	brace_memb_type brtype;
	section_property plate;
	outstanding_leg_type outstandingLeg;
	double kdet;				//fillet dimension of brace
	double sa;					//spacing btw double angles
	double l_c1;				//connection 1 length
	double l_c2;				//connection 2 length
	double c_c1;				//gusset cutout in near connection 1
	double c_c2;				//gusset cutout in near connection 2
	double ts;					//thickness of shear tab
	double bs;					//width of shear tab
	double w_t;					//thickness of shear tab to beam weld 
	double w_c;					//thickness of clip angle to gusset weld
	section_property clip;		//connection 1/2 clip angle 
	outstanding_leg_type clipOutstandingLeg;
	double t_c;					//thickness of clip angle leg
	double kdet_c;				//fillet dimension of clip angle
	double ol_c;				//length of outstanding leg of clip angle
	double il_c;				//length of back to back instanding leg of clip
	double g_c1;				//Gusset length at connection 1
	double g_c2;				//Gusset length at connection 2
	double loc_c1;				//Distance of connecting element from work point  at connection 1
	double loc_c2;				//Distance of connecting element from work point at connection 2
	double setback_c1;			//Gusset setback from beam at connection 1
	double setback_c2;			//Gusset setback from beam at connection 2
	double width_t;				//width of shear plate
	double Fu_g;				//tensile strength on gusset plate
	double Fy_g;				//yield strength of gusset plate
	double Fu_a;				//tensile strength on angle section
	double Fy_a;				//yield strength of angle section
	double Fu_b;				//tensile strength of beam
	double FEXX;				//tensile strength of weld
	double gage_b;				//bolt gage on brace angle
	double gage_c;				//bolt gage on clip angle 
	double gage_t;				//bolt gage to shear tab
	weld wld;
	section_property beam1;
	double d_c1;				//depth of beam at connection 1
	double tf_c1;				//thickness of flange at beam 1
	double tw_c1;				//thickness of web at beam 1	
	double bf_c1;				//flange width of beam 1
	double kdet_c1;				//fillet dimension of beam 1
	section_property beam2;
	double d_c2;				//depth of beam at connection 2
	double tf_c2;				//thickness of flange at beam 2
	double tw_c2;				//thickness of web at beam 2
	double bf_c2;				//flange width of beam 2
	double kdet_c2;				//fillet dimension of beam 2
	
	double a;					//TOS?
	
	//variables for bolt shear check
	double Rn_bv;				//Nominal strength of bolt in shear
	int nv;						//number of planes in shear 
	int nb;						//number of bolts in connection
	double cap_bv;				//bolt capacity in shear
	double phi_bv;				//LRFD factor for bolt shear
	double omega_bv;			//ASD factor for bolt shear 
	double ratio_bv;			//Interaction ratio for bolt shear 

	//variables far brace rupture check
	double l1;					//length of connection
	double ola;					//brace outstanding angle leg
	double ila;					//brace angle leg attached to gusset
	int na;						//number of angles
	double ta;					//thickness of angle
	double A;					//cross section area
	double x_bar;
	double db;					//bolt diameter
	double U;					//shear lag factor
	double dbh;					//bolt hole dia
	double An;					//net area
	double Ae;					//effective area in rupture
	double Pn_rb;				//nominal strength in brace rupture
	double cap_rb;				//brace rupture capacity
	double ratio_rb;			//interaction ratio in brace rupture

	//variables for bolt bearing check at brace
	double Pb;					//Shear per bolt
	double Rn_bbb;				//nominal strength in bolt bearing at brace
	double Rn1_bbb;
	double lcb;					//clear distance for bearing
	double cap_bbb;				//capacity of bolt in bearing on brace
	double ratio_bbb;			//interaction ratio of bolts in bearing on brace

	//variables for brace block shear check
	double Agv;					//gross area in shear, for block shear
	double Anv;					//net area in shear, for block shear
	double Ant;					//net area in tension, for block shear
	double Rn_bsb;				//nominal strength in block shear at brace
	double cap_bsb;				//capacity in block shear at brace
	double ratio_bsb;			//Interaction ratio in brace block shear
	
	//variables for gusset tension yield strength
	double lg;					//whitmore section length
	double Ag;					//gross area of gusset in yielding
	double Pn_yg;				//nominal strength for gusset tension yielding 
	double cap_yg;				//gusset yieling capacity
	double ratio_yg;			//Interaction ratio in gusset tension yielding 

	//variables for bolt bearing at gusset
	double Rn_bbg;				//nominal strength for bolt bearing on gusset
	double Rn1_bbg;
	double lcg;					//clear distance for bolt bearing on gusset
	double cap_bbg;				//capacity of bolts in bearing at gusset
	double ratio_bbg;			//Interaction ratio for bearing at gusset
	
	//variables for block shear check at gusset
	double Ant_bsg;				//gross area in shear, for block shear at gusset
	double Agv_bsg;				//net area in shear, for block shear at gusset
	double Anv_bsg;				//net area in tension, for block shear at gusset
	double Rn_bsg;				//nominal strenght of gusset in block shear at gusset
	double cap_bsg;				//capacity of gusset in block shear at gusset
	double ratio_bsg;			//Interaction ratio for block shear at gusset
	
	//variables for bolt shear check at connection 1
	double Pb_c1;				//Shear per bolt
	double Rn_bv_c1;			//nominal strength in bolt shear at connection 1
	double cap_bv_c1;			//bolt shear capacity at connection 1
	double ratio_bv_c1;			//interaction ratio in bolt shear at connection 1

	//variables for bolt bearing at shear tab for connection 1
	double lct_c1;				//clear distance b/w bolt holes and edge at connection 
	double Rn_bbt_c1;			//nominal strength of bolt bearing at tab for connection 1
	double Rn1_bbt_c1;
	double cap_bbt_c1;			//bolt bearing capacity at shear tab
	double ratio_bbt_c1;		//interaction ratio for bolt bearing at shear tab

	//variables for bolt bearing at clip angle for connection 1
	double tc;																//thickness of clip angle
	double lcc_c1;				//edge clear distance at clip angle 
	double Rn_bbc_c1;			//nominal strength in bolt bearing at clip for connection 1
	double Rn1_bbc_c1;
	double cap_bbc_c1;			//capacity in bolt bearing at clip angle for connection 1
	double ratio_bbc_c1;		//interaction ratio in bolt bearing at clip for conn 1

	//variables for bolt bearing check at beam web for connection 1
	double lcw_c1;				//edge clear distance at beam web
	double Rn_bbw_c1;			//nominal strength of bolt in bearing at beam web
	double Rn1_bbw_c1;
	double cap_bbw_c1;			//bolt bearing capacity at beam web
	double ratio_bbw_c1;		//interaction ratio for bolt bearing at beam web

	//variables for bolt bearing check at beam flange for connection 1
	double lcf_c1;				//edge clear distance for bearing at beam flange
	double Rn_bbf_c1;			//nominal strength of bolt bearing at beam flange
	double Rn1_bbf_c1;							
	double cap_bbf_c1;			//bolt bearing capacity at beam flange
	double ratio_bbf_c1;		//interaction ratio for bolt bearing at beam flange

	//variables for bolt bearing at gusset for connection 1
	double lcg_c1;				//bolt hold edge clear distance 
	double Rn_bbg_c1;			//nominal strength in bolt bearing at gusset at connection 1
	double Rn1_bbg_c1;
	double cap_bbg_c1;			//allowable strength in bolt bearing at gusset at connection 1
	double ratio_bbg_c1;		//interaction ratio in bolt bearing at gusset at connection 1

	//variables for gusset block shear at connection 1
	double gedo_c1;				//distance of outer edge of gusset from connection work point
	double gedi_c1;				//distance of inner edge of gusset from connection work point 
	double edo_c1;				//edge distance of bolt to gusset outer edge
	double edi_c1;				//edge distance of bolt to gusset inner edge
	double ed_c1;				//minimum edge distance 
	double P_c1;				//component of brace force along connection 1
	double Agv_bsg_c1;			//Gross area in shear for block shear rupture
	double Anv_bsg_c1;			//Net area in shear for block shear rupture
	double Ant_bsg_c1;			//Net area in tension for block shear rupture
	double Rn_bsg_c1;			//Nominal strenght in block shear rupture
	double cap_bsg_c1;		
	double ratio_bsg_c1;		//interaction ratio for gusset bloc shear at connection 1

	//variables for block shear in element at connection 1
	double Agv_bse_c1;			//Gross area in shear for element at connection 1
	double Anv_bse_c1;			//Net area in shear for element at connection 1
	double Ant_bse_c1;			//Net area in tension for element at connection 1
	double Rn_bse_c1;			//Nominal strength in block shear of element at connection 1
	double cap_bse_c1;			//Element capacity in block shear at connection 1
	double ratio_bse_c1;		//Interation ratio in block shear at connection 1
		
	//variables for gusset shear yeilding at connection 1
	double Av_yg_c1;			//Gusset plate shear area
	double Rn_yg_c1;			//Nominal shear strength of gusset in yielding [eq J4-3, AISC-360 2010]
	double cap_yg_c1;			//Gusset shear yielding strength
	double ratio_yg_c1;			//interaction ratio for gusset shear yielding at connection 1

	//variables for gusset shear rupture at connection 1
	double Agv_rg_c1;			//Gusset gross area in shear
	double Anv_rg_c1;			//Gusset net area in shear
	double Rn_rg_c1;			//Nominal shear strength of gusset in rupture [eq J4-4, AISC-360 2010]
	double cap_rg_c1;			//Gusset plate shear rupture strength at connection 1
	double ratio_rg_c1;			//interaction ratio for gusset shear rupture at connection 1
	
	//variables for shear yielding of element at connection 1
	double Agv_c1;				//Gross area of connecting element in shear
	double Rn_ye_c1;			//Nominal shear strength of connecting element in yielding [eq J4-3, AISC-360 2010]
	double cap_ye_c1;			//Gusset shear yielding strength
	double ratio_ye_c1;			//interaction ratio for element shear yielding

	//variables for shear rupture of element at connection 1
	double Anv_c1;				//Connecting element net area in shear
	double Rn_re_c1;			//Nominal shear strength of connecting element in rupture [eq J4-4, AISC-360 2010]
	double cap_re_c1;			//Element shear rupture strength at connection 1
	double ratio_re_c1;			//Interaction ratio for shear rupture of element
	
	//variables for weld check at connection 1
	double b_c1;				//Weld group short dimension
	double lw_c1;				//Total weld length
	double x_c1;				//Centroid of weld group
	double Ip_c1;				//Polar moment of inertia of weld group
	double e_c1;				//Eccentricity of force
	double fx_c1;				//Component of weld stress in direction of applied shear
	double fy_c1;				//Component of weld stress perpendicular to applied shear								
	double f_w_c1;				//Maximum stress in weld
	double fn_w_c1;				//Nominal weld strength
	double cap_w_c1;			//Weld capacity
	double ratio_w_c1;			//interaction ratio for weld check at connection 1

	//variables for rupture of gusset at weld for connection 1
	double fn_rwg_c1;			//nominal rupture strength of gusset at weld
	double cap_rwg_c1;			//capacity of gusset in rupture at weld
	double ratio_rwg_c1;		//interaction ratio for gusset of element at weld

	//variables for rupture of shear tab at weld for connection 1
	double fn_rwt_c1;			//nominal rupture strength of shear tab at weld
	double cap_rwt_c1;			//capacity of shear tab in rupture at weld
	double ratio_rwt_c1;		//interaction ratio for rupture of shear tab at weld

	//variables for rupture of beam web at weld for connection 1
	double fn_rww_c1;			//nominal rupture strength of beam web at weld
	double cap_rww_c1;			//capacity of beam web in rupture at weld
	double ratio_rww_c1;		//interaction ratio for rupture of beam web at weld
	
	//variables for bolt shear check at connection 2
	double Pb_c2;				//Shear per bolt
	double Rn_bv_c2;			//nominal strength in bolt shear at connection 2
	double cap_bv_c2;			//bolt shear capacity at connection 2
	double ratio_bv_c2;			//interaction ratio in bolt shear at connection 2

	//variables for bolt bearing at shear tab for connection 2
	double lct_c2;				//clear distance b/w bolt holes and edge at connection 
	double Rn_bbt_c2;			//nominal strength of bolt bearing at tab for connection 2
	double Rn1_bbt_c2;
	double cap_bbt_c2;			//bolt bearing capacity at shear tab
	double ratio_bbt_c2;		//interaction ratio for bolt bearing at shear tab

	//variables for bolt bearing at clip angle for connection 2
	double lcc_c2;				//edge clear distance at clip angle 
	double Rn_bbc_c2;			//nominal strength in bolt bearing at clip for connection 2
	double Rn1_bbc_c2;
	double cap_bbc_c2;			//capacity in bolt bearing at clip angle for connection 2
	double ratio_bbc_c2;		//interaction ratio in bolt bearing at clip for conn 2

	//variables for bolt bearing check at beam web for connection 2
	double lcw_c2;				//edge clear distance at beam web
	double Rn_bbw_c2;			//nominal strength of bolt in bearing at beam web
	double Rn1_bbw_c2;
	double cap_bbw_c2;			//bolt bearing capacity at beam web
	double ratio_bbw_c2;		//interaction ratio for bolt bearing at beam web

	//variables for bolt bearing check at beam flange for connection 2
	double lcf_c2;				//edge clear distance for bearing at beam flange
	double Rn_bbf_c2;			//nominal strength of bolt bearing at beam flange
	double Rn1_bbf_c2;							
	double cap_bbf_c2;			//bolt bearing capacity at beam flange
	double ratio_bbf_c2;		//interaction ratio for bolt bearing at beam flange

	//variables for bolt bearing check at gusset for connection 2
	double lcg_c2;				//bolt hole edge clear distance 
	double Rn_bbg_c2;			//nominal strength in bolt bearing at gusset at connection 2
	double Rn1_bbg_c2;
	double cap_bbg_c2;			//allowable strength in bolt bearing at gusset at connection 2
	double ratio_bbg_c2;		//interaction ratio in bolt bearing at gusset at connection 2

	//variables for gusset block shear at connection 2
	double gedo_c2;				//distance of outer edge of gusset from connection work point
	double gedi_c2;				//distance of inner edge of gusset from connection work point 
	double edo_c2;				//edge distance of bolt to gusset outer edge
	double edi_c2;				//edge distance of bolt to gusset inner edge
	double ed_c2;				//minimum edge distance 
	double P_c2;				//component of brace force along connection 2
	double Agv_bsg_c2;			//Gross area in shear for block shear rupture
	double Anv_bsg_c2;			//Net area in shear for block shear rupture
	double Ant_bsg_c2;			//Net area in tension for block shear rupture
	double Rn_bsg_c2;			//Nominal strenght in block shear rupture
	double cap_bsg_c2;		
	double ratio_bsg_c2;		//interaction ratio for gusset bloc shear at connection 2

	//variables for block shear at element at connection 2
	double Agv_bse_c2;			//Gross area in shear for element at connection 2
	double Anv_bse_c2;			//Net area in shear for element at connection 2
	double Ant_bse_c2;			//Net area in tension for element at connection 2
	double Rn_bse_c2;			//Nominal strength in block shear of element at connection 2
	double cap_bse_c2;			//Element capacity in block shear at connection 2
	double ratio_bse_c2;		//Interation ratio in block shear at connection 2
	
	//variables for gusset shear yeilding at connection 2
	double Av_yg_c2;			//Gusset plate shear area
	double Rn_yg_c2;			//Nominal shear strength of gusset in yielding [eq J4-3, AISC-360 2010]
	double cap_yg_c2;			//Gusset shear yielding strength
	double ratio_yg_c2;			//interaction ratio for gusset shear yielding at connection 2

	//variables for gusset shear rupture at connection 2
	double Agv_rg_c2;			//Gusset gross area in shear
	double Anv_rg_c2;			//Gusset net area in shear
	double Rn_rg_c2;			//Nominal shear strength of gusset in rupture [eq J4-4, AISC-360 2010]
	double cap_rg_c2;			//Gusset plate shear rupture strength at connection 2
	double ratio_rg_c2;			//interaction ratio for gusset shear rupture at connection 2
	
	//variables for shear yielding of element at connection 2
	double Agv_c2;				//Gross area of connecting element in shear
	double Rn_ye_c2;			//Nominal shear strength of connecting element in yielding [eq J4-3, AISC-360 2010]
	double cap_ye_c2;			//Gusset shear yielding strength
	double ratio_ye_c2;			//interaction ratio for element shear yielding

	//variables for shear rupture of element at connection 2
	double Anv_c2;				//Connecting element net area in shear
	double Rn_re_c2;			//Nominal shear strength of connecting element in rupture [eq J4-4, AISC-360 2010]
	double cap_re_c2;			//Element shear rupture strength at connection 2
	double ratio_re_c2;			//Interaction ratio for shear rupture of element
	
	//variables for weld check at connection 2
	double b_c2;				//Weld group short dimension
	double lw_c2;				//Total weld length
	double x_c2;				//Centroid of weld group
	double Ip_c2;				//Polar moment of inertia of weld group
	double e_c2;				//Eccentricity of force
	double fx_c2;				//Component of weld stress in direction of applied shear
	double fy_c2;				//Component of weld stress perpendicular to applied shear								
	double f_w_c2;				//Maximum stress in weld
	double fn_w_c2;				//Nominal weld strength
	double cap_w_c2;			//Weld capacity
	double ratio_w_c2;			//interaction ratio for weld check at connection 2

	//variables for rupture of gusset at weld for connection 2
	double fn_rwg_c2;			//nominal rupture strength of gusset at weld
	double cap_rwg_c2;			//capacity of gusset in rupture at weld
	double ratio_rwg_c2;		//interaction ratio for gusset of element at weld

	//variables for rupture of shear tab at weld for connection 2
	double fn_rwt_c2;			//nominal rupture strength of shear tab at weld
	double cap_rwt_c2;			//capacity of shear tab in rupture at weld
	double ratio_rwt_c2;		//interaction ratio for rupture of shear tab at weld

	//variables for rupture of beam web at weld for connection 2
	double fn_rww_c2;			//nominal rupture strength of beam web at weld
	double cap_rww_c2;			//capacity of beam web in rupture at weld
	double ratio_rww_c2;		//interaction ratio for rupture of beam web at weld
	
	double ratio_max;			//maximum interaction ratio

	double g3;
	////Design functions////
	void checkFitup();
	void calc();
	double blockShear(double,double,double,double,double);

	double min(double,double);
	std::string to_string(double);	
};

/////////////////////CONSTRUCTORS///////////////////////

HBConnection1::HBConnection1():
brace(section_property::MEMB_TYPE_L), clip(section_property::MEMB_TYPE_L),plate(section_property::MEMB_TYPE_PLATE){
}
HBConnection1::HBConnection1(std::map<std::string,std::string> data):
brace(section_property::MEMB_TYPE_L), clip(section_property::MEMB_TYPE_L),plate(section_property::MEMB_TYPE_PLATE){	
	addParameter("CONNECTION_CODE");
	param("CONNECTION_CODE").addAllowableValue("HB001");
	addParameter("CONNECTION_ID");
	addParameter("METHOD");
	param("METHOD").addAllowableValue("LRFD");
	param("METHOD").addAllowableValue("ASD");
	addParameter("UNITS");
	param("UNITS").addAllowableValue("NEWTON_MM");
	param("UNITS").addAllowableValue("KIP_IN");
	addParameter("BEAM_GRADE");
	param("BEAM_GRADE").addAllowableValue("A36");
	param("BEAM_GRADE").addAllowableValue("A992");
	addParameter("ANGLE_GRADE");
	param("ANGLE_GRADE").addAllowableValue("A36");
	param("ANGLE_GRADE").addAllowableValue("A992");
	addParameter("PLATE_GRADE","A36");
	param("PLATE_GRADE").addAllowableValue("A36");
	addParameter("WELD_ELECTRODE","E70");
	param("WELD_ELECTRODE").addAllowableValue("E70");
	addParameter("BOLT_GRADE");
	param("BOLT_GRADE").addAllowableValue("A325");
	param("BOLT_GRADE").addAllowableValue("A490");
	addParameter("BRACE_FORCE");
	param("BRACE_FORCE").isNumber();
	addParameter("BOLT_DIAMETER");
	addParameter("BOLT_TYPE");
	param("BOLT_TYPE").addAllowableValue("FRICTION");
	param("BOLT_TYPE").addAllowableValue("BEARING");
	addParameter("BOLT_SPACING");		
	param("BOLT_SPACING").isPositiveNumber();
	addParameter("EDGE_DISTANCE_ON_GUSSET");		
	param("EDGE_DISTANCE_ON_GUSSET").isPositiveNumber();
	addParameter("EDGE_DISTANCE_ON_BRACE");		
	param("EDGE_DISTANCE_ON_BRACE").isPositiveNumber();
	addParameter("BOLT_GAGE_ON_BRACE");
	param("BOLT_GAGE_ON_BRACE").isPositiveNumber();
	addParameter("BRACE_ANGLE");
	param("BRACE_ANGLE").setMinimumValue(20);
	param("BRACE_ANGLE").setMaximumValue(70);
	addParameter("BRACE_TYPE");
	param("BRACE_TYPE").addAllowableValue("DOUBLE_ANGLE");
	param("BRACE_TYPE").addAllowableValue("SINGLE_ANGLE");
	if (data["BRACE_TYPE"] == "DOUBLE_ANGLE")
		addParameter("BACK_TO_BACK_LEG_ORIENTATION");
	else
		addParameter("BACK_TO_BACK_LEG_ORIENTATION","HORIZONTAL");
	param("BACK_TO_BACK_LEG_ORIENTATION").addAllowableValue("HORIZONTAL");
	param("BACK_TO_BACK_LEG_ORIENTATION").addAllowableValue("VERTICAL");
	addParameter("BRACE_SECTION");				
	addParameter("BRACE_NUMBER_OF_BOLTS_PER_ROW");						
	param("BRACE_NUMBER_OF_BOLTS_PER_ROW").isInteger();
	param("BRACE_NUMBER_OF_BOLTS_PER_ROW").setMinimumValue(2);
	addParameter("BRACE_NUMBER_OF_BOLT_ROWS");								
	param("BRACE_NUMBER_OF_BOLT_ROWS").setMinimumValue(1);
	param("BRACE_NUMBER_OF_BOLT_ROWS").setMaximumValue(2);
	addParameter("BRACE_OUTSTANDING_LEG","SHORT_LRG");
	param("BRACE_OUTSTANDING_LEG").addAllowableValue("SHORT_LEG");
	param("BRACE_OUTSTANDING_LEG").addAllowableValue("LONG_LEG");
	addParameter("GUSSET_THICKNESS");										
	param("GUSSET_THICKNESS").isPositiveNumber();
	addParameter("GUSSET_TOP_OFFSET");										
	param("GUSSET_TOP_OFFSET").isPositiveNumber();	
	addParameter("GUSSET_LENGTH_1");										
	param("GUSSET_LENGTH_1").isPositiveNumber();
	addParameter("GUSSET_LENGTH_2");										
	param("GUSSET_LENGTH_2").isPositiveNumber();
	addParameter("CONNECTION1_CUTOUT","0");
	param("CONNECTION1_CUTOUT").setMinimumValue(0);
	addParameter("CONNECTION2_CUTOUT","0");
	param("CONNECTION2_CUTOUT").setMinimumValue(0);
	addParameter("CONNECTION1_TYPE");												
	param("CONNECTION1_TYPE").addAllowableValue("SHEAR_TAB");
	param("CONNECTION1_TYPE").addAllowableValue("CLIP_ANGLE");
	param("CONNECTION1_TYPE").addAllowableValue("BOTTOM_FLANGE");
	addParameter("CONNECTION2_TYPE");												
	param("CONNECTION2_TYPE").addAllowableValue("SHEAR_TAB");
	param("CONNECTION2_TYPE").addAllowableValue("CLIP_ANGLE");
	param("CONNECTION2_TYPE").addAllowableValue("BOTTOM_FLANGE");
	addParameter("CONNECTION1_NUMBER_OF_BOLTS");	
	param("CONNECTION1_NUMBER_OF_BOLTS").isInteger();
	param("CONNECTION1_NUMBER_OF_BOLTS").setMinimumValue(2);
	addParameter("CONNECTION2_NUMBER_OF_BOLTS");	
	param("CONNECTION2_NUMBER_OF_BOLTS").isInteger();
	param("CONNECTION2_NUMBER_OF_BOLTS").setMinimumValue(2);
	addParameter("CONNECTION1_LOCATION","0");		
	param("CONNECTION1_LOCATION").setMinimumValue(0);
	addParameter("CONNECTION2_LOCATION","0");		
	param("CONNECTION2_LOCATION").setMinimumValue(0);
	addParameter("CONNECTION1_SETBACK");		
	param("CONNECTION1_SETBACK").isPositiveNumber();
	addParameter("CONNECTION2_SETBACK");		
	param("CONNECTION2_SETBACK").isPositiveNumber();
	addParameter("BEAM1_SECTION");	
	addParameter("BEAM2_SECTION");	
	if ((data["CONNECTION1_TYPE"] == "SHEAR_TAB")||(data["CONNECTION2_TYPE"] == "SHEAR_TAB")){
		addParameter("TAB_THICKNESS");	
		addParameter("TAB_WIDTH");
		addParameter("TAB_TO_BEAM_WELD");
		addParameter("EDGE_DISTANCE_ON_TAB");
		addParameter("BOLT_GAGE_ON_TAB");
	}else{
		addParameter("TAB_THICKNESS","0");	
		addParameter("TAB_WIDTH","0");
		addParameter("TAB_TO_BEAM_WELD","0");
		addParameter("EDGE_DISTANCE_ON_TAB","0");	
		addParameter("BOLT_GAGE_ON_TAB","0");
	}
	param("TAB_THICKNESS").isPositiveNumber();
	param("TAB_WIDTH").isPositiveNumber();
	param("TAB_TO_BEAM_WELD").isPositiveNumber();
	param("EDGE_DISTANCE_ON_TAB").isPositiveNumber();
	param("BOLT_GAGE_ON_TAB").isPositiveNumber();
	if ((data["CONNECTION1_TYPE"] == "CLIP_ANGLE")||(data["CONNECTION2_TYPE"] == "CLIP_ANGLE")){
		addParameter("CLIP_SECTION");	
		addParameter("CLIP_TO_GUSSET_WELD");	
		addParameter("EDGE_DISTANCE_ON_CLIP");	
		addParameter("BOLT_GAGE_ON_CLIP");	
	}else{
		addParameter("CLIP_SECTION","0");	
		addParameter("CLIP_TO_GUSSET_WELD","0");	
		addParameter("EDGE_DISTANCE_ON_CLIP","0");	
		addParameter("BOLT_GAGE_ON_CLIP","0");		
	}
	param("CLIP_TO_GUSSET_WELD").isPositiveNumber();
	param("EDGE_DISTANCE_ON_CLIP").isPositiveNumber();
	param("BOLT_GAGE_ON_CLIP").isPositiveNumber();
	addParameter("CLIP_OUTSTANDING_LEG","SHORT_LEG");	
	param("CLIP_OUTSTANDING_LEG").addAllowableValue("SHORT_LEG");
	param("CLIP_OUTSTANDING_LEG").addAllowableValue("LONG_LEG");
	if ((data["CONNECTION1_TYPE"] == "BOTTOM_FLANGE")||(data["CONNECTION2_TYPE"] == "BOTTOM_FLANGE"))
		addParameter("EDGE_DISTANCE_ON_BEAM");	
	else
		addParameter("EDGE_DISTANCE_ON_BEAM","0");		
	param("EDGE_DISTANCE_ON_BEAM").isPositiveNumber();
	
	validateParameters(data);

	connID = data["CONNECTION_ID"];
	if (data["METHOD"] == "LRFD")
		met = LRFD;
	else
		met = ASD;
	if (data["UNITS"] == "NEWTON_MM"){
		us.setUnitSystem(unit_system::NEWTON_MM);
		blt.setUnitSystem(unit_system::NEWTON_MM);
		brace.setUnitSystem(unit_system::NEWTON_MM);
		clip.setUnitSystem(unit_system::NEWTON_MM);
		plate.setUnitSystem(unit_system::NEWTON_MM);
		beam1.setUnitSystem(unit_system::NEWTON_MM);
		beam2.setUnitSystem(unit_system::NEWTON_MM);
		wld.setUnitSystem(unit_system::NEWTON_MM);
	}else{ 
		us.setUnitSystem(unit_system::KIP_IN);
		blt.setUnitSystem(unit_system::KIP_IN);	
		brace.setUnitSystem(unit_system::KIP_IN);
		clip.setUnitSystem(unit_system::KIP_IN);
		plate.setUnitSystem(unit_system::KIP_IN);
		beam1.setUnitSystem(unit_system::KIP_IN);
		beam2.setUnitSystem(unit_system::KIP_IN);
		wld.setUnitSystem(unit_system::KIP_IN);
	}
	//MATERIAL PROPERTIES
	if (data["BEAM_GRADE"] == "A36"){
		beam1.setGrade(section_property::ASTM_A36);
		beam2.setGrade(section_property::ASTM_A36);
	}else{
		beam1.setGrade(section_property::ASTM_A992);
		beam2.setGrade(section_property::ASTM_A992);
	}
	Fu_b = beam1.tensileStrength();
	if (data["ANGLE_GRADE"] == "A36"){
		brace.setGrade(section_property::ASTM_A36);
		clip.setGrade(section_property::ASTM_A36);
	}else{
		brace.setGrade(section_property::ASTM_A992);
		clip.setGrade(section_property::ASTM_A992);
	}	
	Fy_a = brace.yieldStrength();
	Fu_a = brace.tensileStrength();
	plate.setGrade(section_property::ASTM_A36);
	Fy_g = plate.yieldStrength();
	Fu_g = plate.tensileStrength();
	wld.setGrade(weld::FEXX70);
	FEXX = wld.tensileStrength();
	if (data["BOLT_GRADE"] == "A325")
		blt.setBoltGrade(bolt::ASTM_A325);
	else
		blt.setBoltGrade(bolt::ASTM_A490);
	//CONNECTION FORCES
	P = atof(data["BRACE_FORCE"].c_str());
	//BOLT DETAILS
	blt.setBoltDiameter(data["BOLT_DIAMETER"]);
	db = blt.diameter();
	if (data["BOLT_TYPE"] == "FRICTION")
		blt.setBoltType(bolt::FRICTION);
	else 
		blt.setBoltType(bolt::BEARING);
	sb = atof(data["BOLT_SPACING"].c_str());
	edg = atof(data["EDGE_DISTANCE_ON_GUSSET"].c_str());
	ed = atof(data["EDGE_DISTANCE_ON_BRACE"].c_str());		
	gage_b = atof(data["BOLT_GAGE_ON_BRACE"].c_str());	
	//BRACE TO GUSSET CONNECTION DETAILS 
	theta = atof(data["BRACE_ANGLE"].c_str());
	if (data["BRACE_TYPE"] == "DOUBLE_ANGLE")
		brtype = DOUBLE_ANGLE_BRACE_BBLH;
	else 
		brtype = SINGLE_ANGLE_BRACE;
	if (data["BACK_TO_BACK_LEG_ORIENTATION"] == "HORIZONTAL")
		brtype = DOUBLE_ANGLE_BRACE_BBLH;
	else 
		brtype = DOUBLE_ANGLE_BRACE_BBLV;
	brace.setSection(data["BRACE_SECTION"]);
	n_br = atoi(data["BRACE_NUMBER_OF_BOLTS_PER_ROW"].c_str()); 
	nr = atoi(data["BRACE_NUMBER_OF_BOLT_ROWS"].c_str()); 
	outstandingLeg = SHORT_LEG;
	if (brace.leg1() != brace.leg2()){
		if (data.count("BRACE_OUTSTANDING_LEG") == 0) throw "Missing input parameter: BRACE_OUTSTANDING_LEG";
		if (data["BRACE_OUTSTANDING_LEG"] == "SHORT_LEG")
			outstandingLeg = SHORT_LEG;
		else
			outstandingLeg = LONG_LEG;	
	}
	if (outstandingLeg == SHORT_LEG){
		ila = brace.leg1();
		ola = brace.leg2();		
	}else{
		ila = brace.leg2();
		ola = brace.leg1();
	}		
	kdet = brace.detFilletDimension();
	//GUSSET PLATE DETAILS 
	tg = atof(data["GUSSET_THICKNESS"].c_str());
	tog = atof(data["GUSSET_TOP_OFFSET"].c_str());
	g_c1 = atof(data["GUSSET_LENGTH_1"].c_str());
	g_c2 = atof(data["GUSSET_LENGTH_2"].c_str());
	if (data.count("CONNECTION1_CUTOUT") == 0) 
		c_c1=0;
	else
		c_c1 = atof(data["CONNECTION1_CUTOUT"].c_str());
	if (data.count("CONNECTION2_CUTOUT") == 0) 
		c_c2=0;
	else
		c_c2 = atof(data["CONNECTION2_CUTOUT"].c_str());
	//GUSSET TO BEAM CONNECTION DETAILS 
	if (data["CONNECTION1_TYPE"] == "SHEAR_TAB")
		conn1 = SHEAR_PLATE;
	else if (data["CONNECTION1_TYPE"] == "CLIP_ANGLE")
		conn1 = CLIP_ANGLE;
	else 
		conn1 = BOTTOM_FLANGE;
	if (data["CONNECTION2_TYPE"] == "SHEAR_TAB")
		conn2 = SHEAR_PLATE;
	else if (data["CONNECTION2_TYPE"] == "CLIP_ANGLE")
		conn2 = CLIP_ANGLE;
	else 
		conn2 = BOTTOM_FLANGE;
	n1 = atof(data["CONNECTION1_NUMBER_OF_BOLTS"].c_str());
	n2 = atof(data["CONNECTION2_NUMBER_OF_BOLTS"].c_str());
	loc_c1 = atof(data["CONNECTION1_LOCATION"].c_str());
	loc_c2 = atof(data["CONNECTION2_LOCATION"].c_str());
	setback_c1 = atof(data["CONNECTION1_SETBACK"].c_str());
	setback_c2 = atof(data["CONNECTION2_SETBACK"].c_str());
	beam1.setSection(data["BEAM1_SECTION"]);
	d_c1 = beam1.depth();
	tw_c1 = beam1.webThickness();
	tf_c1 = beam1.flangeThickness();
	bf_c1 = beam1.flangeWidth();
	kdet_c1 = beam1.detFilletDimension();
	beam2.setSection(data["BEAM2_SECTION"]);
	d_c2 = beam2.depth();
	tw_c2 = beam2.webThickness();
	tf_c2 = beam2.flangeThickness();
	bf_c2 = beam2.flangeWidth();	
	kdet_c2 = beam2.detFilletDimension();
	if ((conn1 == SHEAR_PLATE)||(conn2 == SHEAR_PLATE)){
		ts = atof(data["TAB_THICKNESS"].c_str());	
		bs = atof(data["TAB_WIDTH"].c_str());	
		w_t = atof(data["TAB_TO_BEAM_WELD"].c_str());
		edt = atof(data["EDGE_DISTANCE_ON_TAB"].c_str());
		gage_t = atof(data["BOLT_GAGE_ON_TAB"].c_str());
	}
	if ((conn1 == CLIP_ANGLE)||(conn2 == CLIP_ANGLE)){
		clip.setSection(data["CLIP_SECTION"]);
		il_c = clip.leg1();
		ol_c = clip.leg2();	
		clipOutstandingLeg = SHORT_LEG;
		if (clip.leg1() != clip.leg2()){
			if (data.count("CLIP_OUTSTANDING_LEG") == 0) throw "Missing input parameter: CLIP_OUTSTANDING_LEG";
			if (data["CLIP_OUTSTANDING_LEG"] == "SHORT_LEG"){
				clipOutstandingLeg = SHORT_LEG;
				il_c = clip.leg1();
				ol_c = clip.leg2();			
			}else{
				clipOutstandingLeg = LONG_LEG;
				il_c = clip.leg2();
				ol_c = clip.leg1();
			}
		}
		t_c = clip.thickness();
		kdet_c = clip.detFilletDimension();
		w_c = atof(data["CLIP_TO_GUSSET_WELD"].c_str());
		edc = atof(data["EDGE_DISTANCE_ON_CLIP"].c_str());
		gage_c = atof(data["BOLT_GAGE_ON_CLIP"].c_str());
	}
	if ((conn1 == BOTTOM_FLANGE)||(conn2 == BOTTOM_FLANGE))
		edb = atof(data["EDGE_DISTANCE_ON_BEAM"].c_str());			
	
	if (err.isError()) throw err.errorMessage();	
	//check fitup
	checkFitup();
	if (err.isError()) throw err.errorMessage();	
	
	calc();
}

////////////////////DESIGN FUNCTIONS//////////////////
void HBConnection1::checkFitup(){
	//minimum bolt edge distance on gusset
	double ed_min = blt.minEdgeDistance();
	if (edg < ed_min) err.addError("Minimum edge distance for bolts is not satisfied at gusset near brace connection. Try increasing edge distance on gusset.");
	//minimum bolt edge distance on brace
	if (ed < ed_min) err.addError("Minimum edge distance for bolts is not satisfied at brace. Try increasing edge distance on brace.");
	//minimum bolt edge distance on clipangle
	if ((conn1 == CLIP_ANGLE)||(conn2 == CLIP_ANGLE))
		if (edc < ed_min) err.addError("Minimum edge distance for bolts is not satisfied at clip angle. Try increasing edge distance on clip angle.");
	//minimum bolt edge distance on shear tab
	if ((conn1 == SHEAR_PLATE)||(conn2 == SHEAR_PLATE))
		if (edt < ed_min) err.addError("Minimum edge distance for bolts is not satisfied at shear tab. Try increasing edge distance on shear tab.");
	//minimum bolt edge distance on beam flange
	if ((conn1 == BOTTOM_FLANGE)||(conn2 == BOTTOM_FLANGE))
		if (edb < ed_min) err.addError("Minimum edge distance for bolts is not satisfied at beam flange. Try increasing edge distance on beam flange.");
	//minimum bolt spacing
	if (sb < blt.minBoltSpacing()) err.addError("Bolt minimum spacing not satistied. Try increasing the bolt spacing.");
	//bolt clash with brace fillet area
	if (gage_b < kdet + db) err.addError ("Insufficient bolt clearance from brace fillet area. Try increasing bolt gage.");
	//bolt edge distance perpendicular to connection
	if (ila - gage_b < ed_min) err.addError("Inadequate bolt edge distance on brace (perpendicular to brace cernterline). Try reducing bolt gage or using a larger section.");
	//clip angle weld space at connection
	double gap;
	if (us.getUnitSystem() == unit_system::NEWTON_MM)
		gap = 2;
	else 
		gap = 0.1;
	if (conn1 == CLIP_ANGLE){
		if ((g_c1 + setback_c1 + 0.5*tw_c2) <  (loc_c1 + 2*edc + (n1 - 1)*sb + w_c + gap)) err.addError("Inadequate space for weld at the outer edge of the clip angle at connection 1. Try adjusting the clip angle location or increasing the gusset dimension.");
		if (c_c1 + setback_c1 + 0.5*tw_c2 > loc_c1 - w_c - gap) err.addError( "Inadequate space for weld at the inner edge of the clip angle at connection 1. Try adjusting the clip angle location or reducing the cutout dimension.");
		//check maximum connection setback
		if (setback_c1 >= il_c) err.addError("Value provided for connection setback at connection 1 is high. Try reducing the connection setback.");

	}
	if (conn2 == CLIP_ANGLE){
		if ((g_c2 + setback_c2 + 0.5*tw_c1) <  (loc_c2 + 2*edc + (n2 - 1)*sb + w_c + gap)) err.addError("Inadequate space for weld at the outer edge of the clip angle at connection 2. Try adjusting the clip angle location or increasing the gusset dimension.");
		if (c_c2 + setback_c2 + 0.5*tw_c1 > loc_c2 - w_c - gap) err.addError( "Inadequate space for weld at the inner edge of the clip angle at connection 2. Try adjusting the clip angle location or reducing the cutout dimension.");
		//check maximum connection setback
		if (setback_c2 >= il_c) err.addError("Value provided for connection setback at connection 2 is high. Try reducing the connection setback.");

	}
	if ((conn1 == CLIP_ANGLE)||(conn2 == CLIP_ANGLE)){
		//bolt clearance from clip fillet area
		if (gage_c < kdet_c - db) err.addError("Inadequate clearance of bolt from fillet area of clip angle. Try increasing bolt gage at clip angle.");
		//bolt perpendicular edge distance to clip angle
		if (ol_c - gage_c < ed_min) err.addError("Minimum edge distance for bolts is not satisfied at clip angle (perpendicular to clip angle centerline). Try increasing clip angle size or reducing the gage on clip angle.");	
	}
	if (conn1 == CLIP_ANGLE){
		//clip angle clash with beam top fillet
		if (tog - ol_c < kdet_c1) err.addError("Insufficient clearance from clip angle to beam top fillet area at connection 1. Try increasing the gusset top offset or using smaller clip angles.");	
		//clip angle clash with beam bottom fillet
		if (tog + tg + ol_c > d_c1 - kdet_c1) err.addError("Insufficient clearance from clip angle to beam bottom fillet area at connection 1. Try reducing the gusset top offset or using smaller clip angles.");
	}
	if (conn2 == CLIP_ANGLE){
		//clip angle clash with beam top fillet
		if (tog - ol_c < kdet_c2) err.addError("Insufficient clearance from clip angle to beam top fillet area at connection 2. Try increasing the gusset top offset or using smaller clip angles.");	
		//clip angle clash with beam bottom fillet
		if (tog + tg + ol_c > d_c2 - kdet_c2) err.addError("Insufficient clearance from clip angle to beam bottom fillet area at connection 2. Try reducing the gusset top offset or using smaller clip angles.");
	}
	if ((conn1 == SHEAR_PLATE)||(conn2 == SHEAR_PLATE)) {
		//bolt at shear tab clearance from beam web 
		if(gage_t < w_t + db + gap) err.addError ("Inadequate clearance of bolt from shear tab to beam weld. Try increasing the bolt gage at shear tab.");
		//bolt perpendicular edge distance at shear tab
		if (bs - gage_t < ed_min) err.addError("Minimum edge distance for bolts is not satisfied at shear tab (perpendicular to shear tab). Try increasing shear tab width or reducing the gage on shear tab.");
		//connection bolting clearance from top flange
		double bf_max = bf_c1 > bf_c2 ? bf_c1 : bf_c2;
		if (tog - ts < 0.5 * bf_max) err.addError("Inadequate clearance of shear tab from top flange of beam. Try increasing the value of the gusset top offset.");		
		//connection bolting clearance from bottom flange
		double d_min = d_c1 < d_c2 ? d_c1 : d_c2;
		double bf1 = d_c1 < d_c2 ? bf_c1 : bf_c2;
		if (d_min - tog < 0.5 * bf1) err.addError("Inadequate clearance of shear tab from bottom flange of beam. Try reducing the value of the gusset top offset or increasing the beam size.");	
	}	
	// for connections to bottom flange connection top must exceed beam depth
	if (((conn1 == BOTTOM_FLANGE)&&(tog < d_c1)) || ((conn2 == BOTTOM_FLANGE)&&(tog < d_c2)))
		err.addError("For connection to bottom flange connection top must exceed beam depth. Try increasing gusset top offset.");

}
void HBConnection1::calc(){
	//brace connection checks
	//Bolt shear check
	if (brtype == DOUBLE_ANGLE_BRACE_BBLH)		nv = 2;
	else 										nv = 1;
	if (brtype == DOUBLE_ANGLE_BRACE_BBLV)		nb = n_br*2;
	else										nb = n_br;
	Rn_bv = nb*blt.nominalShearStrength(nv);
	if (blt.boltType() == bolt::BEARING){
		phi_bv = 0.75;
		omega_bv = 2.0;
	}else{
		phi_bv = 1.0;
		omega_bv = 1.5;
	}
	if (met == LRFD)
		cap_bv = phi_bv*Rn_bv;
	else 
		cap_bv = Rn_bv/omega_bv;
	ratio_bv = P / cap_bv;
	
	//Brace rupture strength
	l1=(n_br-1.0)*sb;												//length of connection
	ta=brace.thickness();		
	na = (brtype == SINGLE_ANGLE_BRACE)?1:2;
	A=na*((ila*ta)+(ola-ta)*ta); 									//cross section area
	if (brtype != DOUBLE_ANGLE_BRACE_BBLH){
		x_bar=(ila*ta*0.5*ta + (ola-ta)*ta*(0.5*(ola-ta)+ta))/A;
		U=1.0-x_bar/l1;												//shear lag factor
	}else U = 1.0;
	dbh=blt.standardBoltHole();										//bolt hole dia
	An=A-dbh*na*nr*ta;												//net area
	Ae=An*U;	
	Pn_rb = Fu_a*Ae;												//Nominal strength in tension rupture of brace
	if (met==LRFD) 
		cap_rb = phi_r*Pn_rb; 
	else 
		cap_rb = Pn_rb/omega_r;	
	ratio_rb = P / cap_rb;											//utility ratio for brace rupture
	
	//Bolt bearing at brace
	if (brtype == DOUBLE_ANGLE_BRACE_BBLV)
		Pb = P/(2*n_br*nr);
	else
		Pb = P/(n_br*nr);											//Shear per bolt
	lcb = min(ed-0.5*dbh,sb-dbh);
	Rn_bbb = 1.2*lcb*ta*Fu_a;	
	Rn1_bbb = 2.4*db*ta*Fu_a;
	Rn_bbb = min(Rn_bbb,Rn1_bbb);
	if (met == LRFD)
		cap_bbb = Rn_bbb*phi_bb;
	else
		cap_bbb = Rn_bbb/omega_bb;
	if (brtype == DOUBLE_ANGLE_BRACE_BBLH)
		ratio_bbb = Pb/(2*cap_bbb);
	else
		ratio_bbb = Pb/cap_bbb;
	
	//Brace block shear
	Agv = na*(l1+ed)*ta;											//gross area in shear, for block shear
	Anv = Agv-na*(n_br-0.5)*dbh*ta;									//net area in shear, for block shear
	Ant = na*(ila-gage_b-(nr-0.5)*dbh)*ta;							//net area in tension, for block shear
	Rn_bsb = blockShear(Agv,Anv,Ant,Fu_a,Fy_a);
	if (met == LRFD) 
		cap_bsb = phi_bs*Rn_bsb; 
	else 
		cap_bsb = Rn_bsb/omega_bs;
	ratio_bsb = P/cap_bsb;

	//Gusset plate checks
	//Gusset tension yield strength
	if (brtype == DOUBLE_ANGLE_BRACE_BBLV)
		lg=2.0*l1*tan(30.0*PI/180.0) + 2*(nr-1.0)*sr + 2*gage_b + sa;	
	else
		lg=2.0*l1*tan(30.0*PI/180.0) + (nr-1.0)*sr;					//whitmore section length
	Ag=lg*tg;														//gross area of gusset in yielding
	Pn_yg = Fy_g*Ag;
	if (met==LRFD) 
		cap_yg= phi_yg*Pn_yg; 
	else 
		cap_yg= Pn_yg/omega_yg;
	ratio_yg = P/cap_yg;
	
	//Bolt bearing at gusset
	lcg = min(edg-0.5*dbh,sb-dbh);
	Rn_bbg = 1.2*lcg*tg*Fu_g;
	Rn1_bbg = 2.4*lcg*tg*Fu_g;
	Rn_bbg =min(Rn_bbg,Rn1_bbg);
	if (met == LRFD)
		cap_bbg = Rn_bbg * phi_bb;
	else 
		cap_bbg = Rn_bbg / omega_bb;
	ratio_bbg = Pb / cap_bbg;
	
	//Gusset block shear at brace to gusset connection
	if ((nr > 1) || (brtype == DOUBLE_ANGLE_BRACE_BBLV)){
		if ((brtype==SINGLE_ANGLE_BRACE) || (brtype==DOUBLE_ANGLE_BRACE_BBLH)){
			Agv_bsg=2*((n_br-1)*sb+ed)*tg;
			Anv_bsg=Agv_bsg-2*(n_br-0.5)*dbh*tg;
			Ant_bsg=(sr-dbh)*tg;
		}else{
			Agv_bsg=2*((n_br-1)*sb+ed)*tg;
			Anv_bsg=Agv_bsg-2*(n_br-0.5)*dbh*tg;
			Ant_bsg=(2*gage_b + sa + 2*sr*(nr-1) - dbh*(2*nr-1))*tg;
		}
		Rn_bsg=blockShear(Agv_bsg,Anv_bsg,Ant_bsg,Fu_g,Fy_g);			
		if (met == LRFD) 
			cap_bsg = phi_bs*Rn_bsg; 
		else 
			cap_bsg = Rn_bsg/omega_bs;
		ratio_bsg = P/cap_bsg;
	}
	
	//Connection to beam 1 checks 
	P_c1 = P*cos(theta*PI/180.0);
	//Bolt shear at connection 1
	if (conn1 == CLIP_ANGLE)
		Pb_c1 = P_c1 / (2*n1);	
	else
		Pb_c1 = P_c1 / n1;	
	Rn_bv_c1 = blt.nominalShearStrength(1);
	if (met == LRFD)
		cap_bv_c1 = Rn_bv_c1 * phi_bv;
	else
		cap_bv_c1 = Rn_bv_c1 / omega_bv;
	ratio_bv_c1 = Pb_c1 / cap_bv_c1;

	//Bolt bearing at shear tab at connection 1
	if (conn1 == SHEAR_PLATE){
		lct_c1 = min(edt-0.5*dbh,sb-dbh);
		Rn_bbt_c1 = 1.2*lct_c1*ts*Fu_g;
		Rn1_bbt_c1 = 2.4*db*ts*Fu_g;
		Rn_bbt_c1 = min(Rn_bbt_c1,Rn1_bbt_c1);
		if (met == LRFD)
			cap_bbt_c1 = Rn_bbt_c1 * phi_bb;
		else 
			cap_bbt_c1 = Rn_bbt_c1 / omega_bb;
		ratio_bbt_c1 = Pb_c1 / cap_bbt_c1;	
	}
	
	//bolt bearing at clip angle at connection 1
	if (conn1 == CLIP_ANGLE){
		tc = clip.thickness();
		lcc_c1 = min(edc-0.5*dbh,sb-dbh);
		Rn_bbc_c1 = 1.2*lcc_c1*tc*Fu_a;
		Rn1_bbc_c1 = 2.4*db*tc*Fu_a;
		Rn_bbc_c1 = min(Rn_bbc_c1,Rn1_bbc_c1);
		if (met == LRFD)
			cap_bbc_c1 = Rn_bbc_c1 * phi_bb;
		else 
			cap_bbc_c1 = Rn_bbc_c1 / omega_bb;
		ratio_bbc_c1 = Pb_c1 / cap_bbc_c1;	
	}
	
	//bolt bearing at beam web at connection 1
	if (conn1 == CLIP_ANGLE){
		lcw_c1 = sb-dbh;
		Rn_bbw_c1 = 1.2*lcw_c1*tw_c1*Fu_b;
		Rn1_bbw_c1 = 2.4*db*tw_c1*Fu_b;
		Rn_bbw_c1 = min(Rn_bbw_c1,Rn1_bbw_c1);
		if (met == LRFD)
			cap_bbw_c1 = Rn_bbw_c1 * phi_bb;
		else 
			cap_bbw_c1 = Rn_bbw_c1 / omega_bb;
		ratio_bbw_c1 = Pb_c1 / cap_bbw_c1;		
	}
	
	//bolt bearing at beam flange at connection 1
	if (conn1 == BOTTOM_FLANGE){
		lcf_c1 = sb-dbh;
		Rn_bbf_c1 = 1.2*lcf_c1*tf_c1*Fu_b;
		Rn1_bbf_c1 = 2.4*db*tf_c1*Fu_b;
		Rn_bbf_c1 = min(Rn_bbf_c1,Rn1_bbf_c1);
		if (met == LRFD)
			cap_bbf_c1 = Rn_bbf_c1 * phi_bb;
		else 
			cap_bbf_c1 = Rn_bbf_c1 / omega_bb;
		ratio_bbf_c1 = Pb_c1 / cap_bbf_c1;	
	}
	
	//Gusset block shear at connection 1
	gedo_c1 = g_c1 + setback_c1 + tw_c2/2;								//distance of outer edge of gusset from connection work point
	gedi_c1 = c_c1 + setback_c1 + tw_c2/2;								//distance of inner edge of gusset from connection work point 
	if(conn1 == SHEAR_PLATE){ 
		l_c1 = (n1-1)*sb + 2.0*edt;										//lenght of connection
		edo_c1 = gedo_c1 - (loc_c1 + l_c1 - edt);						//edge distance of bolt to gusset outer edge
		edi_c1 = (loc_c1 + edt) - gedi_c1;								//edge distance of bolt to gusset inner edge
		ed_c1 = min(edo_c1, edi_c1);									//minimum edge distance 
		Agv_bsg_c1 = ((n1-1)*sb + ed_c1) * tg;							//gross area in shear for block shear
		Anv_bsg_c1 = Agv_bsg_c1 - (n1-0.5) * dbh * tg;					//net area in shear for block shear
		Ant_bsg_c1 = (gage_t - setback_c1 - 0.5*dbh) * tg;				//net area in tension for block shear
	}else if (conn1 == CLIP_ANGLE){
		l_c1 = (n1-1)*sb + 2.0*edc;										//lenght of connection
		edo_c1 = gedo_c1 - (loc_c1 + l_c1);								//edge distance of clip to gusset outer edge
		edi_c1 = loc_c1 - gedi_c1;										//edge distance of clip to gusset inner edge
		ed_c1 = min(edo_c1, edi_c1);									//minimum edge distance 
		Agv_bsg_c1 = tg * (l_c1 + ed_c1);
		Anv_bsg_c1 = Agv_bsg_c1;
		Ant_bsg_c1 = tg * (il_c - setback_c1);
	}else if (conn1 == BOTTOM_FLANGE){
		l_c1 = (n1 - 1)*sb;
		edo_c1 = gedo_c1 - (loc_c1 + l_c1);								//edge distance of bolt to gusset outer edge
		edi_c1 = loc_c1 - gedi_c1;										//edge distance of bolt to gusset inner edge
		ed_c1 = min(edo_c1, edi_c1);									//minimum edge distance 
		Agv_bsg_c1 = ((n1-1)*sb + ed_c1) * tg;							//gross area in shear for block shear
		Anv_bsg_c1 = Agv_bsg_c1 - (n1-0.5) * dbh * tg;					//net area in shear for block shear
		Ant_bsg_c1 = (bf_c1 / 2 - edb - 0.5*dbh) * tg;				//net area in tension for block shear
	}
	Rn_bsg_c1=blockShear(Agv_bsg_c1,Anv_bsg_c1,Ant_bsg_c1,Fu_g,Fy_g);	//nominal strenght in block shear at connection 1
	if (met == LRFD) 
		cap_bsg_c1 = phi_bs*Rn_bsg_c1; 
	else 
		cap_bsg_c1 = Rn_bsg_c1/omega_bs;
	ratio_bsg_c1 = P_c1 / cap_bsg_c1;									//interation ratio for block shear at connection 1


	//Block shear in connecting element at connection 1
	if (conn1 == SHEAR_PLATE){
		Agv_bse_c1 = (l_c1 - edt)*ts;
		Anv_bse_c1 = Agv_bse_c1 - (n1 - 0.5)*dbh*ts;
		Ant_bse_c1 = (width_t - gage_t - 0.5*dbh) * ts;
		Rn_bse_c1 = blockShear(Agv_bse_c1,Anv_bse_c1,Ant_bse_c1,Fu_g,Fy_g);
	}else if (conn1 == CLIP_ANGLE){
		Agv_bse_c1 = 2*(l_c1 - edt)*tc;
		Anv_bse_c1 = Agv_bse_c1 - 2*(n1 - 0.5)*dbh*tc;
		Ant_bse_c1 = 2*(ol_c - gage_c - 0.5*dbh) * tc;
		Rn_bse_c1 = blockShear(Agv_bse_c1,Anv_bse_c1,Ant_bse_c1,Fu_a,Fy_a);

	}
	if (met == LRFD) 
		cap_bse_c1 = phi_bs*Rn_bse_c1; 
	else 
		cap_bse_c1 = Rn_bse_c1/omega_bs;
	ratio_bse_c1 = P_c1 / cap_bse_c1;	

	//bolt bearing at gusset at connection 1 
	if ((conn1 == BOTTOM_FLANGE)||(conn1 == SHEAR_PLATE)){
		lcg_c1 = min(ed_c1-0.5*dbh,sb-dbh);
		Rn_bbg_c1 = 1.2*lcg_c1*tg*Fu_g;
		Rn1_bbg_c1 = 2.4*db*tg*Fu_g;
		Rn_bbg_c1 = min(Rn_bbg_c1,Rn1_bbg_c1);
		if (met == LRFD)
			cap_bbg_c1 = Rn_bbg_c1 * phi_bb;
		else 
			cap_bbg_c1 = Rn_bbg_c1 / omega_bb;
		ratio_bbg_c1 = Pb_c1 / cap_bbg_c1;	
	}	
	
	//Gusset shear yielding at connection 1
	Av_yg_c1 = (g_c1 - c_c1) * tg;										//Gusset plate shear area
	Rn_yg_c1 = 0.6 * Fy_g * Av_yg_c1;									//Nominal shear strength of gusset in yielding [eq J4-3, AISC-360 2010]
	if (met == LRFD) 		
		cap_yg_c1 = phi_y*Rn_yg_c1;
	else				
		cap_yg_c1 = Rn_yg_c1/omega_y;
	ratio_yg_c1 = P_c1 / cap_yg_c1;

	//Gusset shear rupture at connection 1
	if ((conn1 == SHEAR_PLATE)||(conn1 == BOTTOM_FLANGE)){
		Agv_rg_c1 = (g_c1 - c_c1) * tg;									//Gusset gross area in shear
		Anv_rg_c1 = Agv_rg_c1 - n1*dbh*tg;								//Gusset net area in shear
		Rn_rg_c1 = 0.60*Fu_g*Anv_rg_c1;									//Nominal shear strength of gusset in rupture [eq J4-4, AISC-360 2010]
		if (met == LRFD) 		
			cap_rg_c1 = phi_r*Rn_rg_c1;
		else				
			cap_rg_c1 = Rn_rg_c1/omega_r;
		ratio_rg_c1 = P_c1 / cap_rg_c1;
	}
	
	//Shear yielding of element at connection 1
	if (conn1 != BOTTOM_FLANGE){
		if (conn1 == SHEAR_PLATE){			
			Agv_c1 = l_c1 * ts ;		
			Rn_ye_c1 = 0.6 * Fy_g * Agv_c1;	
		}else{	//CLIP_ANGLE
			Agv_c1 = l_c1 * t_c * 2.0;
			Rn_ye_c1 = 0.6 * Fy_a * Agv_c1;	
		}
		if (met == LRFD) 		
			cap_ye_c1 = phi_y * Rn_ye_c1;
		else				
			cap_ye_c1 = Rn_ye_c1/omega_y;
		ratio_ye_c1 = P_c1 / cap_ye_c1;
	}
	
	//Shear rupture of element at connection 1
	if (conn1 != BOTTOM_FLANGE){
		if (conn1 == SHEAR_PLATE){
			Anv_c1 = Agv_c1 - n1*dbh*ts;	
			Rn_re_c1 = 0.60 * Fu_g * Anv_c1;						
		}else{
			Anv_c1 = Agv_c1 - n1*dbh*t_c *2.0;	
			Rn_re_c1 = 0.60 * Fu_a * Anv_c1;
		}
		if (met == LRFD) 		
			cap_re_c1 = phi_r * Rn_re_c1;
		else				
			cap_re_c1 = Rn_re_c1/omega_r;
		ratio_re_c1 = P_c1 / cap_re_c1;
	}
	
	//Weld strength at connection 1
	if (conn1 != BOTTOM_FLANGE){
		if (conn1 == CLIP_ANGLE){								
			b_c1 = il_c - setback_c1;													
			lw_c1 = 2*b_c1 + l_c1;											//total length of weld group		
			x_c1 = b_c1*b_c1 / lw_c1;										//centroid of weld group										
			Ip_c1 = (lw_c1*lw_c1*lw_c1) / 12. + b_c1*b_c1 * (l_c1 + b_c1)*(l_c1 + b_c1) / lw_c1;	
																			//Polar moment of inertia of weld group
			e_c1 = il_c - x_c1;												//eccentricity of force from centroid of weld
			fx_c1 = P_c1/(2*lw_c1) + P_c1*e_c1*(b_c1-x_c1) / (2*Ip_c1);							
			fy_c1 = P_c1*e_c1*l_c1 / (4*Ip_c1);																
			f_w_c1 = sqrt(fx_c1*fx_c1 + fy_c1*fy_c1);						//Maximum stress in weld
			fn_w_c1 = 0.707*w_c*0.6*FEXX;									//Nominal weld strength

		}else{
			Ip_c1 = l_c1*l_c1*l_c1 / 12;									//Polar moment of inertia of weld group
			fx_c1 = P_c1 / (2 * l_c1);
			fy_c1 = P_c1*gage_t*l_c1 / (4*Ip_c1);
			f_w_c1 = sqrt(fx_c1*fx_c1 + fy_c1*fy_c1);						//Maximum stress in weld
			fn_w_c1 = 0.707*w_t*0.6*FEXX;									//Nominal weld strength

		}	
		if (met == LRFD)	
			cap_w_c1 = phi_w * fn_w_c1;
		else			
			cap_w_c1 = fn_w_c1 / omega_w;
		ratio_w_c1 = f_w_c1 / cap_w_c1;
	}
	
	//Rupture of welded element at connection 1
	if (conn1 != BOTTOM_FLANGE){
		if (conn1 == CLIP_ANGLE){
			fn_rwg_c1 = 0.6 * Fu_g * tg;									//nominal rupture strength of gusset at weld
			if (met == LRFD)
				cap_rwg_c1 = fn_rwg_c1 * phi_r;
			else
				cap_rwg_c1 = fn_rwg_c1 / omega_r;
			ratio_rwg_c1 = 2*f_w_c1 / cap_rwg_c1;
		}
	
		if (conn1 == SHEAR_PLATE){
			fn_rww_c1 = 0.6 * Fu_b * tw_c1;									//nominal rupture strength of beam web at weld
			if (met == LRFD)
				cap_rww_c1 = fn_rww_c1 * phi_r;
			else
				cap_rww_c1 = fn_rww_c1 / omega_r;
			ratio_rww_c1 = 2*f_w_c1 / cap_rww_c1;
			
			fn_rwt_c1 = 0.6 * Fu_b * ts;									//nominal rupture strength of shear tab at weld
			if (met == LRFD)
				cap_rwt_c1 = fn_rwt_c1 * phi_r;
			else
				cap_rwt_c1 = fn_rwt_c1 / omega_r;
			ratio_rwt_c1 = 2*f_w_c1 / cap_rwt_c1;
			
		}
	}

	//connection to beam2 checks
	P_c2  = P*sin(theta*PI/180.0);
	//Bolt shear at connection 2
	if (conn2 == CLIP_ANGLE)
		Pb_c2 = P_c2 / (2*n2);	
	else
		Pb_c2 = P_c2 / n2;	
	Rn_bv_c2 = blt.nominalShearStrength(1);
	if (met == LRFD)
		cap_bv_c2 = Rn_bv_c2 * phi_bv;
	else
		cap_bv_c2 = Rn_bv_c2 / omega_bv;
	ratio_bv_c2 = Pb_c2 / cap_bv_c2;
	
	//Bolt bearing at shear tab at connection 2
	if (conn2 == SHEAR_PLATE){
		lct_c2 = min(edt-0.5*dbh,sb-dbh);
		Rn_bbt_c2 = 1.2*lct_c2*ts*Fu_g;
		Rn1_bbt_c2 = 2.4*db*ts*Fu_g;
		Rn_bbt_c2 = min(Rn_bbt_c2,Rn1_bbt_c2);
		if (met == LRFD)
			cap_bbt_c2 = Rn_bbt_c2 * phi_bb;
		else 
			cap_bbt_c2 = Rn_bbt_c2 / omega_bb;
		ratio_bbt_c2 = Pb_c2 / cap_bbt_c2;	
	}

	//bolt baring at clip angle at connection 2
	if (conn2 == CLIP_ANGLE){
		tc = clip.thickness();
		lcc_c2 = min(edc-0.5*dbh,sb-dbh);
		Rn_bbc_c2 = 1.2*lcc_c2*tc*Fu_a;
		Rn1_bbc_c2 = 2.4*db*tc*Fu_a;
		Rn_bbc_c2 = min(Rn_bbc_c2,Rn1_bbc_c2);
		if (met == LRFD)
			cap_bbc_c2 = Rn_bbc_c2 * phi_bb;
		else 
			cap_bbc_c2 = Rn_bbc_c2 / omega_bb;
		ratio_bbc_c2 = Pb_c2 / cap_bbc_c2;	
	}
	
	//bolt bearing at beam web at connection 2
	if (conn2 == CLIP_ANGLE){
		lcw_c2 = sb-dbh;
		Rn_bbw_c2 = 1.2*lcw_c2*tw_c2*Fu_b;
		Rn1_bbw_c2 = 2.4*db*tw_c2*Fu_b;
		Rn_bbw_c2 = min(Rn_bbw_c2,Rn1_bbw_c2);
		if (met == LRFD)
			cap_bbw_c2 = Rn_bbw_c2 * phi_bb;
		else 
			cap_bbw_c2 = Rn_bbw_c2 / omega_bb;
		ratio_bbw_c2 = Pb_c2 / cap_bbw_c2;		
	}	
	//bolt bearing at beam flange at connection 2
	if (conn2 == BOTTOM_FLANGE){
		lcf_c2 = sb-dbh;
		Rn_bbf_c2 = 1.2*lcf_c2*tf_c2*Fu_b;
		Rn1_bbf_c2 = 2.4*db*tf_c2*Fu_b;
		Rn_bbf_c2 = min(Rn_bbf_c2,Rn1_bbf_c2);
		if (met == LRFD)
			cap_bbf_c2 = Rn_bbf_c2 * phi_bb;
		else 
			cap_bbf_c2 = Rn_bbf_c2 / omega_bb;
		ratio_bbf_c2 = Pb_c2 / cap_bbf_c2;	
	}
	
	//Gusset block shear at connection 2
	gedo_c2 = g_c2 + setback_c2 + tw_c1/2;								//distance of outer edge of gusset from connection work point
	gedi_c2 = c_c2 + setback_c2 + tw_c1/2;								//distance of inner edge of gusset from connection work point 
	if(conn2 == SHEAR_PLATE){ 
		l_c2 = (n2-1)*sb + 2.0*edt;										//lenght of connection
		edo_c2 = gedo_c2 - (loc_c2 + l_c2 - edt);						//edge distance of bolt to gusset outer edge
		edi_c2 = (loc_c2 + edt) - gedi_c2;								//edge distance of bolt to gusset inner edge
		ed_c2 = min(edo_c2, edi_c2);									//minimum edge distance 
		Agv_bsg_c2 = ((n2-1)*sb + ed_c2) * tg;							//gross area in shear for block shear
		Anv_bsg_c2 = Agv_bsg_c2 - (n2-0.5) * dbh * tg;					//net area in shear for block shear
		Ant_bsg_c2 = (gage_t - setback_c2 - 0.5*dbh) * tg;				//net area in tension for block shear
	}else if (conn2 == CLIP_ANGLE){
		l_c2 = (n2-1)*sb + 2.0*edc;										//lenght of connection
		edo_c2 = gedo_c2 - (loc_c2 + l_c2);								//edge distance of clip to gusset outer edge
		edi_c2 = loc_c2 - gedi_c2;										//edge distance of clip to gusset inner edge
		ed_c2 = min(edo_c2, edi_c2);									//minimum edge distance 
		Agv_bsg_c2 = tg * (l_c2 + ed_c2);
		Anv_bsg_c2 = Agv_bsg_c2;
		Ant_bsg_c2 = tg * (il_c - setback_c2);
	}else if (conn2 == BOTTOM_FLANGE){
		l_c2 = (n2 - 1)*sb;
		edo_c2 = gedo_c2 - (loc_c2 + l_c2);								//edge distance of bolt to gusset outer edge
		edi_c2 = loc_c2 - gedi_c2;										//edge distance of bolt to gusset inner edge
		ed_c2 = min(edo_c2, edi_c2);									//minimum edge distance 
		Agv_bsg_c2 = ((n2-1)*sb + ed_c2) * tg;							//gross area in shear for block shear
		Anv_bsg_c2 = Agv_bsg_c2 - (n2-0.5) * dbh * tg;					//net area in shear for block shear
		Ant_bsg_c2 = (bf_c2/2 - edb - 0.5*dbh) * tg;				//net area in tension for block shear
	}
	Rn_bsg_c2 = blockShear(Agv_bsg_c2,Anv_bsg_c2,Ant_bsg_c2,Fu_g,Fy_g);	//nominal strenght in block shear at connection 1
	if (met == LRFD) 
		cap_bsg_c2 = phi_bs*Rn_bsg_c2; 
	else 
		cap_bsg_c2 = Rn_bsg_c2/omega_bs;
	ratio_bsg_c2 = P_c2 / cap_bsg_c2;									//interation ratio for block shear at connection 1

	//Block shear in connecting element at connection 2	
	if (conn2 == SHEAR_PLATE){
		Agv_bse_c2 = (l_c2 - edt)*ts;
		Anv_bse_c2 = Agv_bse_c2 - (n2 - 0.5)*dbh*ts;
		Ant_bse_c2 = (w_t - gage_t - 0.5*dbh) * ts;
		Rn_bse_c2 = blockShear(Agv_bse_c2,Anv_bse_c2,Ant_bse_c2,Fu_g,Fy_g);
	}else if (conn2 == CLIP_ANGLE){
		Agv_bse_c2 = 2*(l_c2 - edt)*tc;
		Anv_bse_c2 = Agv_bse_c2 - 2*(n2 - 0.5)*dbh*tc;
		Ant_bse_c2 = 2*(ol_c - gage_c - 0.5*dbh) * tc;
		Rn_bse_c2 = blockShear(Agv_bse_c2,Anv_bse_c2,Ant_bse_c2,Fu_a,Fy_a);
	}
	if (met == LRFD) 
		cap_bse_c2 = phi_bs*Rn_bse_c2; 
	else 
		cap_bse_c2 = Rn_bse_c2/omega_bs;
	ratio_bse_c2 = P_c2 / cap_bse_c2;	

	//bolt bearin at gusset at connection 2 
	if ((conn2 == BOTTOM_FLANGE)||(conn2 == SHEAR_PLATE)){
		lcg_c2 = min(ed_c2-0.5*dbh,sb-dbh);
		Rn_bbg_c2 = 1.2*lcg_c2*tg*Fu_g;
		Rn1_bbg_c2 = 2.4*db*tg*Fu_g;
		Rn_bbg_c2 = min(Rn_bbg_c2,Rn1_bbg_c2);
		if (met == LRFD)
			cap_bbg_c2 = Rn_bbg_c2 * phi_bb;
		else 
			cap_bbg_c2 = Rn_bbg_c2 / omega_bb;
		ratio_bbg_c2 = Pb_c2 / cap_bbg_c2;	
	}
	
	//Gusset shear yielding at connection 2
	Av_yg_c2 = (g_c2 - c_c2) * tg;										//Gusset plate shear area
	Rn_yg_c2 = 0.6 * Fy_g * Av_yg_c2;									//Nominal shear strength of gusset in yielding [eq J4-3, AISC-360 2010]
	if (met == LRFD) 		
		cap_yg_c2 = phi_y*Rn_yg_c2;
	else				
		cap_yg_c2 = Rn_yg_c2/omega_y;
	ratio_yg_c2 = P_c2 / cap_yg_c2;

	//Gusset shear rupture at connection 2
	if ((conn2 == SHEAR_PLATE)||(conn2 == BOTTOM_FLANGE)){
		Agv_rg_c2 = (g_c2 - c_c2) * tg;									//Gusset gross area in shear
		Anv_rg_c2 = Agv_rg_c2 - n2*dbh*tg;								//Gusset net area in shear
		Rn_rg_c2 = 0.60*Fu_g*Anv_rg_c2;									//Nominal shear strength of gusset in rupture [eq J4-4, AISC-360 2010]
		if (met == LRFD) 		
			cap_rg_c2 = phi_r*Rn_rg_c2;
		else				
			cap_rg_c2 = Rn_rg_c2/omega_r;
		ratio_rg_c2 = P_c2 / cap_rg_c2;
	}
	
	//Shear yielding of element at connection 2
	if (conn2 != BOTTOM_FLANGE){
		if (conn2 == SHEAR_PLATE){			
			Agv_c2 = l_c2 * ts;		
			Rn_ye_c2 = 0.6 * Fy_g * Agv_c2;	
		}else{	//CLIP_ANGLE
			Agv_c2 = l_c2 * t_c * 2;
			Rn_ye_c2 = 0.6 * Fy_a * Agv_c2;	
		}
		if (met == LRFD) 		
			cap_ye_c2 = phi_y * Rn_ye_c2;
		else				
			cap_ye_c2 = Rn_ye_c2/omega_y;
		ratio_ye_c2 = P_c2 / cap_ye_c2;
	}
	
	//Shear rupture of element at connection 2
	if (conn2 != BOTTOM_FLANGE){
		if (conn2 == SHEAR_PLATE){
			Anv_c2 = Agv_c2 - n2*dbh*ts;	
			Rn_re_c2 = 0.60 * Fu_g * Anv_c2;						
		}else{
			Anv_c2 = Agv_c2 - n2*dbh*t_c *2;	
			Rn_re_c2 = 0.60 * Fu_a * Anv_c2 ;
		}
		if (met == LRFD) 		
			cap_re_c2 = phi_r * Rn_re_c2;
		else				
			cap_re_c2 = Rn_re_c2/omega_r;
		ratio_re_c2 = P_c2 / cap_re_c2;
	}
	
	//Weld strength at connection 2
	if (conn2 != BOTTOM_FLANGE){
		if (conn2 == CLIP_ANGLE){								
			b_c2 = il_c - setback_c2;													
			lw_c2 = 2*b_c2 + l_c2;											//total length of weld group		
			x_c2 = b_c2*b_c2 / lw_c2;										//centroid of weld group										
			Ip_c2 = (lw_c2*lw_c2*lw_c2) / 12. + b_c2*b_c2 * (l_c2 + b_c2)*(l_c2 + b_c2) / lw_c2;
																			//Polar moment of inertia of weld group
			e_c2 = il_c - x_c2;												//eccentricity of force from centroid of weld
			fx_c2 = P_c2/(2*lw_c2) + P_c2*e_c2*(b_c2-x_c2) / (2*Ip_c2);							
			fy_c2 = P_c2*e_c2*l_c2 / (4*Ip_c2);																
			f_w_c2 = sqrt(fx_c2*fx_c2 + fy_c2*fy_c2);						//Maximum stress in weld
			fn_w_c2 = 0.707*w_c*0.6*FEXX;									//Nominal weld strength

		}else{
			Ip_c2 = l_c2*l_c2*l_c2 / 12;									//Polar moment of inertia of weld group
			fx_c2 = P_c2 / (2 * l_c2);
			fy_c2 = P_c2*gage_t*l_c2 / (4*Ip_c2);
			f_w_c2 = sqrt(fx_c2*fx_c2 + fy_c2*fy_c2);						//Maximum stress in weld
			fn_w_c2 = 0.707*w_t*0.6*FEXX;									//Nominal weld strength
		}	
		if (met == LRFD)	
			cap_w_c2 = phi_w * fn_w_c2;
		else			
			cap_w_c2 = fn_w_c2 / omega_w;
		ratio_w_c2 = f_w_c2 / cap_w_c2;
	}
	
	//Rupture of welded element at connection 2
	if (conn2 != BOTTOM_FLANGE){
		if (conn2 == CLIP_ANGLE){
			fn_rwg_c2 = 0.6 * Fu_g * tg;									//nominal rupture strength of gusset at weld
			if (met == LRFD)
				cap_rwg_c2 = fn_rwg_c2 * phi_r;
			else
				cap_rwg_c2 = fn_rwg_c2 / omega_r;
			ratio_rwg_c2 = 2*f_w_c2 / cap_rwg_c2;
		}
	
		if (conn2 == SHEAR_PLATE){
			fn_rww_c2 = 0.6 * Fu_b * tw_c2;									//nominal rupture strength of beam web at weld
			if (met == LRFD)
				cap_rww_c2 = fn_rww_c2 * phi_r;
			else
				cap_rww_c2 = fn_rww_c2 / omega_r;
			ratio_rww_c2 = 2*f_w_c2 / cap_rww_c2;
			
			fn_rwt_c2 = 0.6 * Fu_b * ts;									//nominal rupture strength of shear tab at weld
			if (met == LRFD)
				cap_rwt_c2 = fn_rwt_c2 * phi_r;
			else
				cap_rwt_c2 = fn_rwt_c2 / omega_r;
			ratio_rwt_c2 = 2*f_w_c2 / cap_rwt_c2;
		}
	}
	
	//max interaction ratio
	ratio_max = 0;
	ratio_max = ratio_bv > ratio_max? ratio_bv : ratio_max;  			//Interaction ratio for bolt shear 
	ratio_max = ratio_rb > ratio_max? ratio_rb : ratio_max;				//interaction ratio in brace rupture
	ratio_max = ratio_bbb > ratio_max? ratio_bbb : ratio_max;			//interaction ratio of bolts in bearing on brace
	ratio_max = ratio_bsb > ratio_max? ratio_bsb : ratio_max;			//Interaction ratio in brace block shear
	ratio_max = ratio_yg > ratio_max? ratio_yg : ratio_max;				//Interaction ratio in gusset tension yielding 
	ratio_max = ratio_bbg > ratio_max? ratio_bbg : ratio_max;			//Interaction ratio for bearing at gusset
	if ((brtype == DOUBLE_ANGLE_BRACE_BBLV)||(nr > 1))
		ratio_max = ratio_bsg > ratio_max? ratio_bsg : ratio_max;		//Interaction ratio for block shear at gusset
	ratio_max = ratio_bv_c1 > ratio_max? ratio_bv_c1 : ratio_max;		//interaction ratio in bolt shear at connection 1
	if (conn1 == SHEAR_PLATE)
		ratio_max = ratio_bbt_c1 > ratio_max? ratio_bbt_c1 : ratio_max;	//interaction ratio for bolt bearing at shear tab
	if (conn1 == CLIP_ANGLE){
		ratio_max = ratio_bbc_c1 > ratio_max? ratio_bbc_c1 : ratio_max;	//interaction ratio in bolt bearing at clip for conn 1
		ratio_max = ratio_bbw_c1 > ratio_max? ratio_bbw_c1 : ratio_max;	//interaction ratio for bolt bearing at beam web
	}
	if (conn1 == BOTTOM_FLANGE)
		ratio_max = ratio_bbf_c1 > ratio_max? ratio_bbf_c1 : ratio_max;	//interaction ratio for bolt bearing at beam flange
	if ((conn1 == BOTTOM_FLANGE)||(conn1 == SHEAR_PLATE))
		ratio_max = ratio_bbg_c1 > ratio_max? ratio_bbg_c1 : ratio_max;	//interaction ratio for bolt bearing at gusset
	ratio_max = ratio_bsg_c1 > ratio_max? ratio_bsg_c1 : ratio_max;		//interaction ratio for gusset block shear at connection 1
	ratio_max = ratio_bse_c1 > ratio_max? ratio_bse_c1 : ratio_max;		//Interation ratio in block shear at connection 1
	ratio_max = ratio_yg_c1 > ratio_max? ratio_yg_c1 : ratio_max;		//interaction ratio for gusset shear yielding at connection 1
	if ((conn1 == BOTTOM_FLANGE)||(conn1 == SHEAR_PLATE))
		ratio_max = ratio_rg_c1 > ratio_max? ratio_rg_c1 : ratio_max;	//interaction ratio for gusset shear rupture at connection 1
	if ((conn1 == CLIP_ANGLE)||(conn1 == SHEAR_PLATE)){
		ratio_max = ratio_ye_c1 > ratio_max? ratio_ye_c1 : ratio_max;	//interaction ratio for element shear yielding
		ratio_max = ratio_re_c1 > ratio_max? ratio_re_c1 : ratio_max;	//Interaction ratio for shear rupture of element
		ratio_max = ratio_w_c1 > ratio_max? ratio_w_c1 : ratio_max;		//interaction ratio for weld check at connection 1
	}
	if (conn1 == CLIP_ANGLE)
		ratio_max = ratio_rwg_c1 > ratio_max? ratio_rwg_c1 : ratio_max;	//interaction ratio for rupture of gusset at weld
	if (conn1 == SHEAR_PLATE){
		ratio_max = ratio_rwt_c1 > ratio_max? ratio_rwt_c1 : ratio_max;	//interaction ratio for rupture of shear tab at weld
		ratio_max = ratio_rww_c1 > ratio_max? ratio_rww_c1 : ratio_max;	//interaction ratio for rupture of beam web at weld
	}
	ratio_max = ratio_bv_c2 > ratio_max? ratio_bv_c2 : ratio_max;		//interaction ratio in bolt shear at connection 2
	if (conn2 == SHEAR_PLATE)
		ratio_max = ratio_bbt_c2 > ratio_max? ratio_bbt_c2 : ratio_max;	//interaction ratio for bolt bearing at shear tab
	if (conn2 == CLIP_ANGLE){
		ratio_max = ratio_bbc_c2 > ratio_max? ratio_bbc_c2 : ratio_max;	//interaction ratio in bolt bearing at clip for conn 2
		ratio_max = ratio_bbw_c2 > ratio_max? ratio_bbw_c2 : ratio_max;	//interaction ratio for bolt bearing at beam web
	}
	if (conn2 == BOTTOM_FLANGE)
		ratio_max = ratio_bbf_c2 > ratio_max? ratio_bbf_c2 : ratio_max;	//interaction ratio for bolt bearing at beam flange
	ratio_max = ratio_bsg_c2 > ratio_max? ratio_bsg_c2 : ratio_max;		//interaction ratio for gusset block shear at connection 2
	ratio_max = ratio_bse_c2 > ratio_max? ratio_bse_c2 : ratio_max;		//Interaction ratio for element block shear at connection 2
	ratio_max = ratio_yg_c2 > ratio_max? ratio_yg_c2 : ratio_max;		//interaction ratio for gusset shear yielding at connection 2
	if ((conn2 == BOTTOM_FLANGE)||(conn2 == SHEAR_PLATE))
		ratio_max = ratio_rg_c2 > ratio_max? ratio_rg_c2 : ratio_max;	//interaction ratio for gusset shear rupture at connection 2
	if ((conn2 == CLIP_ANGLE)||(conn2 == SHEAR_PLATE)){
		ratio_max = ratio_ye_c2 > ratio_max? ratio_ye_c2 : ratio_max;	//interaction ratio for element shear yielding
		ratio_max = ratio_re_c2 > ratio_max? ratio_re_c2 : ratio_max;	//Interaction ratio for shear rupture of element
		ratio_max = ratio_w_c2 > ratio_max? ratio_w_c2 : ratio_max;		//interaction ratio for weld check at connection 2
	}
	if (conn2 == CLIP_ANGLE)
		ratio_max = ratio_rwg_c2 > ratio_max? ratio_rwg_c2 : ratio_max;	//interaction ratio for rupture of gusset at weld
	if (conn2 == SHEAR_PLATE){
		ratio_max = ratio_rwt_c2 > ratio_max? ratio_rwt_c2 : ratio_max;	//interaction ratio for rupture of shear tab at weld
		ratio_max = ratio_rww_c2 > ratio_max? ratio_rww_c2 : ratio_max;	//interaction ratio for rupture of beam web at weld
	}

}

double HBConnection1::blockShear(double Agv,double Anv,double Ant,double Fu, double Fy)
{
	double Rn1=0.60*Fu*Anv + Fu*Ant;
	double Rn2=0.60*Fy*Agv + Fu*Ant;
	if (Rn1<Rn2) return Rn1; else return Rn2;
}
double HBConnection1::min(double a,double b)
{
	if(a<b) return a;
	else return b;
}
std::string HBConnection1::to_string(double a)
{	
	std::ostringstream s; 
	s << a; 
	return s.str();
}	
/////////////////////OUTPUT FUNCTIONS//////////////////////////
bool HBConnection1::pass(){

	if (ratio_max > 1.0)
		return false;
	else
		return true;
}
void HBConnection1::printDesignOutput()
{
	std::cout<<designInput();
	std::cout<<designSummary();
	std::cout<<designCalculation();
}

std::string HBConnection1::designInput(){
	std::string o = "";
	_h1("Design Input");
	_p((met == LRFD)?"LRFD":"ASD","Design method");
	_p(P, "Brace axial force (P)", "", _force);
	_br;
	_p(beam1.getGrade(),"Beam steel grade");
	_p(beam1.yieldStrength(),"Beam yield strength","",_stress);
	_p(beam1.tensileStrength(),"Beam tensile strength","",_stress);
	_br;
	_p(brace.getGrade(),"Angle steel grade");
	_p(brace.yieldStrength(),"Angle yield strength","",_stress);
	_p(brace.tensileStrength(),"Angle tensile strength","",_stress);
	_br;
	_p(plate.getGrade(),"Plate steel grade");
	_p(plate.yieldStrength(),"Plate yield strength","",_stress);
	_p(plate.tensileStrength(),"Plate tensile strength","",_stress);
	_br;
	_p(n_br, "Number of bolts in gusset to brace connection","","","",0);
	_p(nr, "Number of bolt rows in gusset to brace connection","","","",0);
	_p(n1, "Number of bolts in connection 1 (n1)","","","",0);
	_p(n2, "Number of bolts in connection 2 (n2)","","","",0);
	_br;
	_p(blt.boltGrade(),"Bolt grade");
	_p(blt.nominalTensileStress(),"Bolt nominal tensile strength","",_stress);
	_p(blt.boltType() == bolt::BEARING?"Bearing":"Friction","Bolt type");
	_p(blt.boltThreadInShearPlane()?"Yes":"No","Bolt thread in shear plane");
	_p(db, "Bolt diameter","",_length);
	_p(gage_b, "Bolt gage on brace angle","", _length);
	_p(sb, "Bolt spacing","",_length);
	_p(ed, "Bolt distance to edge on brace in the direction of force","", _length);
	_br;
	_p(wld.getGrade(),"Weld electrode");
	_p(wld.tensileStrength(),"Weld tensile strength","",_stress);
	_br;
	_p((brtype == SINGLE_ANGLE_BRACE)?"":"2 X " + brace.getSection(), "Brace section");
	_p(theta, "Brace angle from beam at connection 1 (theta)","","deg");
	if (brtype != SINGLE_ANGLE_BRACE)
		_p((brtype ==DOUBLE_ANGLE_BRACE_BBLH)?"Horizontal":"Vertical","Orientation of back to back legs");
	_p("Short Leg", "Outstanding leg type");
	_br;
	_p(tg, "Gusset plate thickness","",_length);
	_p(g_c1, "Gusset dimension along connection 1","",_length);
	_p(g_c2, "Gusset dimension along connection 2","",_length);
	_p(c_c1, "Gusset cutout along connection 1","",_length);
	_p(c_c2, "Gusset cutout along connection 2","",_length);
	_br;
	_p(conn1 == SHEAR_PLATE?"Shear Tab":(conn1 == CLIP_ANGLE? "Clip Angle":"Bolted to Flange"), "Connection type at connection 1");
	_p(conn2 == SHEAR_PLATE?"Shear Tab":(conn2 == CLIP_ANGLE?"Clip Angle":"Bolted to Flange"),"Connection type at connection 2");
	_br;
	if ((conn1 == SHEAR_PLATE)||(conn2 == SHEAR_PLATE))
		_p(ts, "Thickness of shear tab","",_length);
	_p(w_t, "Thickness of shear tab to beam weld","",_length);

	_p("2 X " + clip.getSection(), "Clip angles at connection to beam");
	_p(w_c, "Thickness of clip to gusset weld","",_length);
	_br;
	_p(beam1.getSection(),"Section property of beam at connection 1");
	_p(tw_c1,"   Thickness of web","",_length);
	_p(tf_c1,"   Thickness of flange","",_length);
	_p(bf_c1,"   Width of fange","",_length);	
	_p(beam2.getSection(),"Section property of beam at connection 2");
	_p(tw_c2,"   Thickness of web","",_length);
	_p(tf_c2,"   Thickness of flange","",_length);
	_p(bf_c2,"   Width of fange","",_length);	
	
	return o;
}

std::string HBConnection1::designSummary(){
	std::string o="";
	if (ratio_bv > 1.0) _p("","Fails in bolt shear");
	if (ratio_rb > 1.0)	_p("","Fails in brace rupture");
	if (ratio_bbb > 1.0) _p("","Fails in bolt bearing at brace");
	if (ratio_bsb >  1.0) _p("","Fails in brace block shear");
	if (ratio_yg > 1.0) _p("","Fails in gusset tension yielding");
	if (ratio_bbg > 1.0) _p("","Fails in bolt bearing at gusset");
	if ((brtype == DOUBLE_ANGLE_BRACE_BBLV)||(nr > 1))
		if (ratio_bsg > 1.0) _p("","Fails in block shear at gusset");
	if (ratio_bv_c1 > 1.0) _p("","Fails in bolt shear at connection 1");
	if (conn1 == SHEAR_PLATE)
		if (ratio_bbt_c1 > 1.0) _p("","Fails in bolt bearing at shear tab at connection 1");
	if (conn1 == CLIP_ANGLE){
		if (ratio_bbc_c1 > 1.0) _p("","Fails in bolt bearing at clip at connection 1");
		if (ratio_bbw_c1 > 1.0) _p("","Fails in bolt bearing at beam web at connection 1");
	}
	if (conn1 == BOTTOM_FLANGE)
		if (ratio_bbf_c1 > 1.0) _p("","Fails in bolt bearing at beam flange at connection 1");
	if ((conn1 == BOTTOM_FLANGE)||(conn1 == SHEAR_PLATE))
		if (ratio_bbg > 1.0) _p("","Fails in bolt bearing at gusset at connection 1");
	if (ratio_bsg_c1 > 1.0) _p("","Fails in gusset block shear at connection 1");
	if (ratio_bse_c1 > 1.0) _p("","Fails in element block shear at connection 1");
	if (ratio_yg_c1 > 1.0) _p("","Fails in gusset shear yielding at connection 1");
	if ((conn1 == BOTTOM_FLANGE)||(conn1 == SHEAR_PLATE))
		if (ratio_rg_c1 > 1.0) _p("","Fails in gusset shear rupture at connection 1");
	if ((conn1 == CLIP_ANGLE)||(conn1 == SHEAR_PLATE)){
		if (ratio_ye_c1 > 1.0) _p("","Fails in element shear yielding at connection 1");
		if (ratio_re_c1 > 1.0) _p("","Fails in element shear rupture at connection 1");
		if (ratio_w_c1 > 1.0) _p("","Fails in weld strength at connection 1");
	}
	if (conn1 == CLIP_ANGLE)
		if (ratio_rwg_c1 > 1.0) _p("","Fails in gusset rupture at weld at connection 1");
	if (conn1 == SHEAR_PLATE){
		if (ratio_rwt_c1 > 1.0) _p("","Fails in shear tab rupture at weld at connection 1");
		if (ratio_rww_c1 > 1.0) _p("","Fails in beam web rupture at weld at connection 1");
	}
	if (ratio_bv_c2 > 1.0) _p("","Fails in bolt shear at connection 2");
	if (conn2 == SHEAR_PLATE)
		if (ratio_bbt_c2 > 1.0) _p("","Fails in bolt bearing at shear tab at connection 2");
	if (conn2 == CLIP_ANGLE){
		if (ratio_bbc_c2 > 1.0) _p("","Fails in bolt bearing at clip at connection 2");
		if (ratio_bbw_c2 > 1.0) _p("","Fails in bolt bearing at beam web at connection 2");
	}
	if (conn2 == BOTTOM_FLANGE)
		if (ratio_bbf_c2 > 1.0) _p("","Fails in bolt bearing at beam flange at connection 2");
	if (ratio_bsg_c2 > 1.0) _p("","Fails in gusset block shear at connection 2");
	if (ratio_bse_c2 > 1.0) _p("","Fails in element block shear at connection 2");
	if (ratio_yg_c2 > 1.0) _p("","Fails in gusset shear yielding at connection 2");
	if ((conn2 == BOTTOM_FLANGE)||(conn2 == SHEAR_PLATE))
		if (ratio_rg_c2 > 1.0) _p("","Fails in gusset shear rupture at connection 2");
	if ((conn2 == CLIP_ANGLE)||(conn2 == SHEAR_PLATE)){
		if (ratio_ye_c2 > 1.0) _p("","Fails in element shear yielding at connection 2");
		if (ratio_re_c2 > 1.0) _p("","Fails in element shear rupture at connection 2");
		if (ratio_w_c2 > 1.0) _p("","Fails in weld strength at connection 2");
	}
	if (conn2 == CLIP_ANGLE)
		if (ratio_rwg_c2 > 1.0) _p("","Fails in gusset rupture at weld at connection 2");
	if (conn2 == SHEAR_PLATE){
		if (ratio_rwt_c2 > 1.0) _p("","Fails in shear tab rupture tab at weld at connection 2");
		if (ratio_rww_c2 > 1.0) _p("","Fails in beam web rupture at weld at connection 2");
	}
	o = oso::format_p(ratio_max,"Maximum interaction ratio") + o;
	if (ratio_max < 1.0)
		o = oso::format_p("","Connection is OK") + o;
	else
		o = oso::format_p("","Connection is NOT OK") + o;	
	
	o = oso::format_h1("Design Summary") + o;

	return o;
}

std::string HBConnection1::designCalculation(){
	std::string o="";
	_h1("Design Calculation");
	//brace connection checks
	_h3("Bolt shear check at brace");
	_p(Rn_bv, "Nominal strength of bolts in shear (Rn)","",_force);
	if (met == LRFD){
		_p(phi_bv,"LRFD factor in bolt shear (phi)","","");
		_p(cap_bv,"Allowable strength in bolt shear","Ra=phi*Rn",_force);		
	}else{
		_p(omega_bv,"ASD factor in bolt shear (omega)","","");
		_p(cap_bv,"Allowable strength in bolt shear","Ra=Rn/omega",_force);				
	}
	_p(ratio_bv,"Interaction ratio in bolt shear","P/Ra","");
	
	_h3("Brace rupture check");
	_p(A,"Gross area of brace","",_area);
	_p(U,"Shear Lag Factor (U)","","");
	_p(An,"Net area of brace (An)","",_area);
	_p(Ae,"Effective area for tensile rupture","Ae=An*U",_area);
	_p(Pn_rb,"Nominal strength in brace rupture (Pn)","",_force);
	if (met == LRFD){
		_p(phi_r,"LRFD factor in tension rupture (phi)","","");
		_p(cap_rb,"Allowable strength in brace rupture","Pa=phi*Pn",_force);
	}else{
		_p(omega_r,"ASD factor in tension rupture (omega)","","");
		_p(cap_rb,"Allowable strength in brace rupture","Pa=Pn/omega",_force);		
	}	
	_p(ratio_rb,"Interaction ratio in brace rupture","P/Pa","");
	
	_h3("Bolt bearing at brace check");
	_p(Pb, "Shear force per bolt in brace connection (Pb)","",_force);
	_p(Rn_bbb, "Nominal strength in bolt bearing at brace (Rn)","",_force);
	if (met == LRFD){
		_p(phi_bb,"LRFD factor in bolt bearing (phi)","","");
		_p(cap_bbb,"Allowable strength in bolt bearing at brace","Ra=phi*Rn",_force);
	}else{
		_p(omega_bb,"ASD factor in bolt bearing (omega)","","");
		_p(cap_bbb,"Allowable strength in bolt bearing","Ra=Rn/omega",_force);		
	}	
	if (brtype == DOUBLE_ANGLE_BRACE_BBLH)
		_p(ratio_bbb,"Interaction ratio in bolt bearing at brace","Pb/(2*Ra)","");
	else
		_p(ratio_bbb,"Interaction ratio in bolt bearing at brace","Pb/Ra","");
	
	_h3("Block shear at brace check");
	_p(Agv,"Gross area in shear","",_area);
	_p(Anv,"Net area in shear","",_area);
	_p(Ant,"Net area in tension","",_area);
	_p(Rn_bsb,"Nominal block shear strength at brace (Rn)","",_force);
	if (met == LRFD){
		_p(phi_bs,"LRFD factor in block shear (phi)","","");
		_p(cap_bsb,"Alloable block shear strength at brace","Ra=phi*Rn",_force);
	}else{
		_p(omega_bs,"ASD factor in block shear (omega)","","");
		_p(cap_bsb,"Allowable block shear strength at brace","cap= Rn/omega",_force);		
	}	
	_p(ratio_bsb,"Interaction ratio in block shear at brace","P/Ra","");
	
	//Gusset plate checks
	_h3("Gusset plate yielding check");
	_p(lg,"Lenght of Whitmore section","",_length);
	_p(A,"Gusset plate area in tension yielding","",_area);
	_p(Pn_yg,"Nominal strength in gusset yielding (Pn)","",_force);
	if (met == LRFD){
		_p(phi_yg,"LRFD factor in tension yielding","phi","");
		_p(cap_yg,"Allowable strength of gusset tension yielding","Pa=phi*Pn",_force);
	}else{
		_p(omega_yg,"ASD factor in tension yielding","omega","");
		_p(cap_yg,"Allowable strength of gusset in tension yielding","Pa=Pn/omega",_force);		
	}
	_p(ratio_yg,"Interaction ratio in gusset plate tension yielding","P/Pa","");
	
	_h3("Bolt bearing at gusset check");
	_p(Rn_bbg,"Nominal strength in bolt bearing at gusset plate","",_force);
	if (met == LRFD){
		_p(phi_bb,"LRFD factor in bolt bearing (phi)","","");
		_p(cap_bbg,"Allowable strength in bolt bearing at gusset","Ra=phi*Rn",_force);
	}else{
		_p(omega_bb,"ASD factor in bolt bearing (omega)","","");
		_p(cap_bbg,"Allowable strength in bolt bearing at gusset","Ra=Rn/omega",_force);		
	}
	_p(ratio_bbg,"Interaction ratio in bolt bearing at gusset plate","Pb/Ra","");


	if ((nr > 1) || (brtype == DOUBLE_ANGLE_BRACE_BBLV)){
		_h3("Block shear at gusset check");	
		_p(Agv_bsg,"Gross area in shear","",_area);
		_p(Anv_bsg,"Net area in shear","",_area);
		_p(Ant_bsg,"Net area in tension", "",_area);
		_p(Rn_bsg,"Nominal strength of gusset in block shear (Rn)","",_force);
		if (met == LRFD){
			_p(phi_bs,"LRFD factor in block shear (phi)","","");
			_p(cap_bsg,"Allowable strength og gusset in block shear","Ra=phi*Rn",_force);
		}else{
			_p(omega_bs,"ASD factor in block shear (omega)","","");
			_p(cap_bsg,"Allowable strength og gusset in block shear","Ra=Rn/omega",_force);		
		}
		_p(ratio_bsg,"Interaction ratio in block shear at gusset plate","P/Ra","");
	}

	//connection 1 checks
	_h2("Connection 1 Checks");
	_p(P_c1, "Component of brace force along connection 1","P1=P*cos(theta)",_force);
	_p(Pb_c1, "Force per bolt in connection 1","Pb1=P1/n1",_force);
	_h3("Bolt shear check");
	_p(Rn_bv_c1,"Nominal strength in bolt shear (Rn)","",_force);
	if (met == LRFD){
		_p(phi_bv,"LRFD factor in bolt shear (phi)","","");
		_p(cap_bv_c1,"Allowable strength in bolt shear","Ra=phi*Rn",_force);
	}else{
		_p(omega_bv,"ASD factor in bolt shear (omega)","","");
		_p(cap_bv_c1,"Allowable strength in bolt shear","Ra=Rn/omega",_force);		
	}
	_p(ratio_bv_c1,"Interaction ratio in bolt shear","Pb1/Ra","");

	if (conn1 == SHEAR_PLATE){	
		_h3("Bolt bearing at shear tab check");
		_p(Rn_bbt_c1, "Nominal strength in bolt bearing at shear tab (Rn)","",_force);
		if (met == LRFD){
			_p(phi_bb,"LRFD factor in bolt bearing (phi)","","");
			_p(cap_bbt_c1,"Allowable strength in bolt bearing at shear tab","Ra=phi*Rn",_force);
		}else{
			_p(omega_bb,"ASD factor in bolt shear (omega)","","");
			_p(cap_bbt_c1,"Allowable strength in bolt bearing at shear tab","Ra=Rn/omega",_force);		
		}		
		_p(ratio_bbt_c1,"Interaction ratio in bolt bearing at shear tab","Pb1/Ra","");
	}
	
	if (conn1 == CLIP_ANGLE){
		_h3("Bolt bearing at clip angle check");
		_p(Rn_bbc_c1,"Nominal strength in bolt bearing at clip angle (Rn)","",_force);
		if (met == LRFD){
			_p(phi_bb,"LRFD factor in bolt bearing (phi)","","");
			_p(cap_bbc_c1,"Allowable strength in bolt bearing at clip angle","Ra=phi*Rn",_force);
		}else{
			_p(omega_bb,"ASD factor in bolt shear (omega)","","");
			_p(cap_bbc_c1,"Allowable strength in bolt bearing at clip angle","Ra=Rn/omega",_force);		
		}		
 		_p(ratio_bbc_c1,"Interaction ratio in bolt bearing at clip angle","Pb1/Ra","");

		_h3("Bolt bearing at beam web check");
		_p(Rn_bbw_c1,"Nominal strength in bolt bearing at beam web (Rn)","",_force);
		if (met == LRFD){
			_p(phi_bb,"LRFD factor in bolt bearing (phi)","","");
			_p(cap_bbw_c1,"Allowable strength in bolt bearing at beam web","Ra=phi*Rn",_force);
		}else{
			_p(omega_bb,"ASD factor in bolt shear (omega)","","");
			_p(cap_bbw_c1,"Allowable strength in bolt bearing at beam web","Ra=Rn/omega",_force);		
		}		
 		_p(ratio_bbw_c1,"Interaction ratio in bolt bearing at beam web","Pb1/Ra","");		
	}

	if (conn1 == BOTTOM_FLANGE){
		_h3("Bolt bearing at beam flange check");
		_p(Rn_bbf_c1,"Nominal strength in bolt bearing at beam flange (Rn)","",_force);
		if (met == LRFD){
			_p(phi_bb,"LRFD factor in bolt bearing (phi)","","");
			_p(cap_bbf_c1,"Allowable strength in bolt bearing at beam flange","Ra=phi*Rn",_force);
		}else{
			_p(omega_bb,"ASD factor in bolt shear (omega)","","");
			_p(cap_bbf_c1,"Allowable strength in bolt bearing at beam flange","Ra=Rn/omega",_force);		
		}		
 		_p(ratio_bbf_c1,"Interaction ratio in bolt bearing at beam flange","Pb1/Ra","");		
	}

	if ((conn1 == BOTTOM_FLANGE)||(conn1 == SHEAR_PLATE)){
		_h3("Bolt bearing at gusset check");
		_p(Rn_bbg_c1,"Nominal strength in bolt bearing at gusset (Rn)","",_force);
		if (met == LRFD){
			_p(phi_bb,"LRFD factor in bolt bearing (phi)","","");
			_p(cap_bbg_c1,"Allowable strength in bolt bearing at gusset","Ra=phi*Rn",_force);
		}else{
			_p(omega_bb,"ASD factor in bolt shear (omega)","","");
			_p(cap_bbg_c1,"Allowable strength in bolt bearing at gusset","Ra=Rn/omega",_force);		
		}		
 		_p(ratio_bbg_c1,"Interaction ratio in bolt bearing at gusset","Pb1/Ra","");		
		
	}

	_h3("Gusset block shear check");
	_p(Agv_bsg_c1,"Gross area in shear for block shear rupture","",_area);
	_p(Anv_bsg_c1,"Net area in shear for block shear rupture","",_area);
	_p(Ant_bsg_c1,"Net area in tension for block shear rupture","",_area);
	_p(Rn_bsg_c1, "Nominal strength in block shear at gusset (Rn)","",_area);
	if (met == LRFD){
		_p(phi_bs,"LRFD factor in BLOCK shear (phi)","","");
		_p(cap_bsg_c1,"Allowable strength in block shear at gusset plate","Ra=phi*Rn",_force);
	}else{
		_p(omega_bs,"ASD factor in block shear (omega)","","");
		_p(cap_bsg_c1,"Allowable strength in block shear at gusset plate","Ra=Rn/omega",_force);		
	}		
	_p(ratio_bsg_c1,"Interaction ratio in block shear at gusset plate","P1/Ra","");		
	
	if (conn1 != BOTTOM_FLANGE){
		if (conn1 == SHEAR_PLATE)
			_h3("Shear tab block shear check");
		else if (conn1 == CLIP_ANGLE)
			_h3("Clip angle block shear check");
		_p(Agv_bse_c1, "Gross area in shear for block shear rupture","",_area);
		_p(Anv_bse_c1, "Net area in shear for block shear rupture","",_area);
		_p(Ant_bse_c1, "Net area in tension for block shear rupture","",_area);
		_p(Rn_bse_c1, "Nominal strength in block shear at shear tab (Rn)","",_force);
		if (met == LRFD){
			_p(phi_bs,"LRFD factor in block shear (phi)","","");
			_p(cap_bse_c1,"Allowable strength in block shear at connecting element","Ra=phi*Rn",_force);
		}else{
			_p(omega_bs,"ASD factor in block shear (omega)","","");
			_p(cap_bse_c1,"Allowable strength in block shear at connecting element","Ra=Rn/omega",_force);		
		}
		_p(ratio_bse_c1,"Interaction ratio in block shear at connecting element","P1/Ra","");		
		
	}		

	_h3("Gusset shear yielding check");
	_p(Av_yg_c1,"Gusset plate shear area", "", _area);
	_p(Rn_yg_c1,"Nominal shear strength of gusset in yielding (Rn)", "", _force);
	if (met == LRFD){
		_p(phi_y,"LRFD factor in shear yielding (phi)","","");
		_p(cap_yg_c1,"Allowable shear strength of gusset in yielding","Ra=phi*Rn",_force);
	}else{
		_p(omega_y,"ASD factor in shear yielding (omega)","","");
		_p(cap_yg_c1,"Allowable shear strength of gusset in yielding","Ra=Rn/omega",_force);		
	}
	_p(ratio_yg_c1,"Interaction ratio in shear yielding at gusset", "P1/Ra","");  
	
	if (conn1 != CLIP_ANGLE){
		_h3("Gusset shear rupture check");
		_p(Agv_rg_c1,"Gusset gross area in shear", "", _area);
		_p(Anv_rg_c1,"Gusset net area in shear", "", _area);
		_p(Rn_rg_c1,"Nominal shear strength of gusset in rupture (Rn)", "", _force);
		if (met==LRFD){
			_p(phi_r,"LRFD factor in shear rupture (phi)","","");
			_p(cap_rg_c1,"Allowable shear strength of gusset in rupture","phi*Rn",_force);
		}else{
			_p(omega_r,"ASD factor in shear rupture (omega)","","");
			_p(cap_rg_c1,"Allowable shear strength of gusset in rupture","Rn/omega",_force);		
		}			
		_p(ratio_rg_c1, "Interaction ratio in shear rupture of gusset", "P1/Ra","");
	}
	
	if (conn1 != BOTTOM_FLANGE){
		if (conn1==SHEAR_PLATE)
			_h3("Shear tab shear yielding check");
		else
			_h3("Clip angle shear yielding check");
		_p(Agv_c1,"Gross area in shear", "", _area);
		_p(Rn_ye_c1,"Nominal shear yielding strength of connecting element (Rn)", "", _force);
		if (met==LRFD){
			_p(phi_y,"LRFD factor in shear yielding (phi)","","");
			_p(cap_ye_c1,"Allowable shear yielding strength of connecting element","Ra=phi*Rn",_force);
		}else{
			_p(omega_y,"ASD factor in shear yielding (omega)","","");
			_p(cap_ye_c1,"Allowable shear yielding strength of connecting element","Ra=Rn/omega",_force);		
		}				
		_p(ratio_ye_c1, "Interaction ratio in shear yielding of element","P1/Ra","");
		
		if(conn1==SHEAR_PLATE)
			_h3("Shear tab shear rupture check");
		else
			_h3("Clip angle shear rupture check");
		_p(Anv_c1,"Connecting element net area in shear","", _area);
		_p(Rn_re_c1,"Nominal shear strength of connecting element in rupture (Rn)", "",_force);
		if (met==LRFD){
			_p(phi_r,"LRFD factor in shear rupture (phi)","","");
			_p(cap_re_c1,"Allowable shear strength of connecting element in rupture","Ra=phi*Rn",_force);
		}else{
			_p(omega_r,"ASD factor in shear rupture (omega)","","");
			_p(cap_re_c1,"Allowable shear strength of connecting element in rupture","Ra=Rn/omega",_force);		
		}			
		_p(ratio_re_c1, "Interaction ratio in shear rupture of connecting element","P1/Ra","");

		_h3("Weld check");
		_p(f_w_c1,"Maximum stress in weld (f)","",_force + "/" + _length);
		_p(fn_w_c1,"Nominal weld strength (fn)", "", _force + "/" + _length);
		if (met == LRFD){
			_p(phi_w,"LRFD factor for weld strength(phi)","","");
			_p(cap_w_c1,"Allowable weld strength","fa=phi*fn",_force + "/" + _length);
		}else{
			_p(omega_w,"ASD factor for weld strength (omega)","","");
			_p(cap_w_c1,"Allowable weld strength","fa=fn/omega",_force + "/" + _length);		
		}
		_p(ratio_w_c1, "Interaction ratio for weld strength","f/fa","");
		
		if (conn1 == CLIP_ANGLE){
			_h3("Gusset rupture at weld check");
			_p(fn_rwg_c1, "Nominal strength of gusset at weld (Rn)","",_force + "/" + _length);
			if (met == LRFD){
				_p(phi_r,"LRFD factor for rupture at weld (phi)","","");
				_p(cap_rwg_c1,"Allowable strength of gusset rupture at weld","Ra=phi*Rn",_force + "/" + _length);
			}else{
				_p(omega_r,"ASD factor for rupture at weld (omega)","","");
				_p(cap_rwg_c1,"Allowable strength of gusset rupture at weld","Ra=Rn/omega",_force + "/" + _length);		
			}
			_p(ratio_rwg_c1, "Interaction ratio for gusset rupture at weld","P1/Ra","");			
		}
		
		if (conn1 == SHEAR_PLATE){			
			_h3("Shear tab rupture at weld check");
			_p(fn_rwt_c1, "Nominal strength of shear tab rupture at weld (Rn)","",_force + "/" + _length);
			if (met == LRFD){
				_p(phi_r,"LRFD factor for rupture at weld (phi)","","");
				_p(cap_rwt_c1,"Allowable strength of shear tab rupture at weld","Ra=phi*Rn",_force + "/" + _length);
			}else{
				_p(omega_r,"ASD factor for rupture at weld (omega)","","");
				_p(cap_rwt_c1,"Allowable strength of shear tab rupture at weld","Ra=Rn/omega",_force + "/" + _length);		
			}
			_p(ratio_rwt_c1, "Interaction ratio for shear tab rupture at weld","P1/Ra","");			
			
			_h3("Beam web rupture at weld check");
			_p(fn_rww_c1, "Nominal strength of beam web at weld (Rn)","",_force + "/" + _length);
			if (met == LRFD){
				_p(phi_r,"LRFD factor for rupture at weld (phi)","","");
				_p(cap_rww_c1,"Allowable strength of beam web rupture at weld","Ra=phi*Rn",_force + "/" + _length);
			}else{
				_p(omega_r,"ASD factor for rupture at weld (omega)","","");
				_p(cap_rww_c1,"Allowable strength of beam web rupture at weld","Ra=Rn/omega",_force + "/" + _length);		
			}
			_p(ratio_rww_c1, "Interaction ratio for beam web rupture at weld","P1/Ra","");			
			
		}
	}

	//connection 2 checks
	_h2("Connection 2 Checks");
	_p(P_c2, "Component of brace force along connection 2","P2=P*sin(theta)",_force);
	_p(Pb_c2, "Force per bolt in connection 2","Pb2=P2/n2",_force);
	
	_h3("Bolt shear check");
	_p(Rn_bv_c2,"Nominal strength in bolt shear (Rn)","",_force);
	if (met == LRFD){
		_p(phi_bv,"LRFD factor in bolt shear (phi)","","");
		_p(cap_bv_c2,"Allowable strength in bolt shear","Ra=phi*Rn",_force);
	}else{
		_p(omega_bv,"ASD factor in bolt shear (omega)","","");
		_p(cap_bv_c2,"Allowable strength in bolt shear","Ra=Rn/omega",_force);		
	}
	_p(ratio_bv_c2,"Interaction ratio in bolt shear","Pb2/Ra","");

	if (conn2 == SHEAR_PLATE){	
		_h3("Bolt bearing at shear tab check");
		_p(Rn_bbt_c2, "Nominal strength in bolt bearing at shear tab (Rn)","",_force);
		if (met == LRFD){
			_p(phi_bb,"LRFD factor in bolt bearing (phi)","","");
			_p(cap_bbt_c2,"Allowable strength in bolt bearing at shear tab","Ra=phi*Rn",_force);
		}else{
			_p(omega_bb,"ASD factor in bolt shear (omega)","","");
			_p(cap_bbt_c2,"Allowable strength in bolt bearing at shear tab","Ra=Rn/omega",_force);		
		}		
		_p(ratio_bbt_c2,"Interaction ratio in bolt bearing at shear tab","Pb2/Ra","");
	}
	
	if (conn2 == CLIP_ANGLE){
		_h3("Bolt bearing at clip angle check");
		_p(Rn_bbc_c2,"Nominal strength in bolt bearing at clip angle (Rn)","",_force);
		if (met == LRFD){
			_p(phi_bb,"LRFD factor in bolt bearing (phi)","","");
			_p(cap_bbc_c2,"Allowable strength in bolt bearing at clip angle","Ra=phi*Rn",_force);
		}else{
			_p(omega_bb,"ASD factor in bolt shear (omega)","","");
			_p(cap_bbc_c2,"Allowable strength in bolt bearing at clip angle","Ra=Rn/omega",_force);		
		}		
 		_p(ratio_bbc_c2,"Interaction ratio in bolt bearing at clip angle","Pb2/Ra","");

		_h3("Bolt bearing at beam web check");
		_p(Rn_bbw_c2,"Nominal strength in bolt bearing at beam web (Rn)","",_force);
		if (met == LRFD){
			_p(phi_bb,"LRFD factor in bolt bearing (phi)","","");
			_p(cap_bbw_c2,"Allowable strength in bolt bearing at beam web","Ra=phi*Rn",_force);
		}else{
			_p(omega_bb,"ASD factor in bolt shear (omega)","","");
			_p(cap_bbw_c2,"Allowable strength in bolt bearing at beam web","Ra=Rn/omega",_force);		
		}		
 		_p(ratio_bbw_c2,"Interaction ratio in bolt bearing at beam web","Pb2/Ra","");		
	}

	if (conn2 == BOTTOM_FLANGE){
		_h3("Bolt bearing at beam flange check");
		_p(Rn_bbf_c2,"Nominal strength in bolt bearing at beam flange (Rn)","",_force);
		if (met == LRFD){
			_p(phi_bb,"LRFD factor in bolt bearing (phi)","","");
			_p(cap_bbf_c2,"Allowable strength in bolt bearing at beam flange","Ra=phi*Rn",_force);
		}else{
			_p(omega_bb,"ASD factor in bolt shear (omega)","","");
			_p(cap_bbf_c2,"Allowable strength in bolt bearing at beam flange","Ra=Rn/omega",_force);		
		}		
 		_p(ratio_bbf_c2,"Interaction ratio in bolt bearing at beam flange","Pb2/Ra","");		
	}

	if ((conn2 == BOTTOM_FLANGE)||(conn2 == SHEAR_PLATE)){
		_h3("Bolt bearing at gusset check");
		_p(Rn_bbg_c2,"Nominal strength in bolt bearing at gusset (Rn)","",_force);
		if (met == LRFD){
			_p(phi_bb,"LRFD factor in bolt bearing (phi)","","");
			_p(cap_bbg_c2,"Allowable strength in bolt bearing at gusset","Ra=phi*Rn",_force);
		}else{
			_p(omega_bb,"ASD factor in bolt shear (omega)","","");
			_p(cap_bbg_c2,"Allowable strength in bolt bearing at gusset","Ra=Rn/omega",_force);		
		}		
 		_p(ratio_bbg_c2,"Interaction ratio in bolt bearing at gusset","Pb2/Ra","");		
		
	}
	
	_h3("Gusset block shear check");
	_p(Agv_bsg_c2,"Gross area in shear for block shear rupture","",_area);
	_p(Anv_bsg_c2,"Net area in shear for block shear rupture","",_area);
	_p(Ant_bsg_c2,"Net area in tension for block shear rupture","",_area);
	_p(Rn_bsg_c2, "Nominal strength in block shear at gusset (Rn)","",_area);
	if (met == LRFD){
		_p(phi_bs,"LRFD factor in BLOCK shear (phi)","","");
		_p(cap_bsg_c2,"Allowable strength in block shear at gusset plate","Ra=phi*Rn",_force);
	}else{
		_p(omega_bs,"ASD factor in block shear (omega)","","");
		_p(cap_bsg_c2,"Allowable strength in block shear at gusset plate","Ra=Rn/omega",_force);		
	}		
	_p(ratio_bsg_c2,"Interaction ratio in block shear at gusset plate","P2/Ra","");		
	
	if (conn2 != BOTTOM_FLANGE){
		if (conn1 == SHEAR_PLATE)
			_h3("Shear tab block shear check");
		else if (conn1 == CLIP_ANGLE)
			_h3("Clip angle block shear check");
		_p(Agv_bse_c2, "Gross area in shear for block shear rupture","",_area);
		_p(Anv_bse_c2, "Net area in shear for block shear rupture","",_area);
		_p(Ant_bse_c2, "Net area in tension for block shear rupture","",_area);
		_p(Rn_bse_c2, "Nominal strength in block shear at shear tab (Rn)","",_force);
		if (met == LRFD){
			_p(phi_bs,"LRFD factor in block shear (phi)","","");
			_p(cap_bse_c2,"Allowable strength in block shear at connecting element","Ra=phi*Rn",_force);
		}else{
			_p(omega_bs,"ASD factor in block shear (omega)","","");
			_p(cap_bse_c2,"Allowable strength in block shear at connecting element","Ra=Rn/omega",_force);		
		}
		_p(ratio_bse_c2,"Interaction ratio in block shear at connecting element","P2/Ra","");		
		
	}		

	_h3("Gusset shear yielding check");
	_p(Av_yg_c2,"Gusset plate shear area", "", _area);
	_p(Rn_yg_c2,"Nominal shear strength of gusset in yielding (Rn)", "", _force);
	if (met == LRFD){
		_p(phi_y,"LRFD factor in shear yielding (phi)","","");
		_p(cap_yg_c2,"Allowable shear strength of gusset in yielding","Ra=phi*Rn",_force);
	}else{
		_p(omega_y,"ASD factor in shear yielding (omega)","","");
		_p(cap_yg_c2,"Allowable shear strength of gusset in yielding","Ra=Rn/omega",_force);		
	}
	_p(ratio_yg_c2,"Interaction ratio in shear yielding at gusset", "P2/Ra","");  
	
	if (conn2 != CLIP_ANGLE){
		_h3("Gusset shear rupture check");
		_p(Agv_rg_c2,"Gusset gross area in shear", "", _area);
		_p(Anv_rg_c2,"Gusset net area in shear", "", _area);
		_p(Rn_rg_c2,"Nominal shear strength of gusset in rupture (Rn)", "", _force);
		if (met==LRFD){
			_p(phi_r,"LRFD factor in shear rupture (phi)","","");
			_p(cap_rg_c2,"Allowable shear strength of gusset in rupture","phi*Rn",_force);
		}else{
			_p(omega_r,"ASD factor in shear rupture (omega)","","");
			_p(cap_rg_c2,"Allowable shear strength of gusset in rupture","Rn/omega",_force);		
		}			
		_p(ratio_rg_c2, "Interaction ratio in shear rupture of gusset", "P2/Ra","");
	}
	
	if (conn2 != BOTTOM_FLANGE){
		if (conn2==SHEAR_PLATE)
			_h3("Shear tab shear yielding check");
		else
			_h3("Clip angle shear yielding check");
		_p(Agv_c2,"Gross area in shear", "", _area);
		_p(Rn_ye_c2,"Nominal shear yielding strength of connecting element (Rn)", "", _force);
		if (met==LRFD){
			_p(phi_y,"LRFD factor in shear yielding (phi)","","");
			_p(cap_ye_c2,"Allowable shear yielding strength of connecting element","Ra=phi*Rn",_force);
		}else{
			_p(omega_y,"ASD factor in shear yielding (omega)","","");
			_p(cap_ye_c2,"Allowable shear yielding strength of connecting element","Ra=Rn/omega",_force);		
		}				
		_p(ratio_ye_c2, "Interaction ratio in shear yielding of element","P2/Ra","");
		
		if(conn2==SHEAR_PLATE)
			_h3("Shear tab shear rupture check");
		else
			_h3("Clip angle shear rupture check");
		_p(Anv_c2,"Connecting element net area in shear","", _area);
		_p(Rn_re_c2,"Nominal shear strength of connecting element in rupture (Rn)", "",_force);
		if (met==LRFD){
			_p(phi_r,"LRFD factor in shear rupture (phi)","","");
			_p(cap_re_c2,"Allowable shear strength of connecting element in rupture","Ra=phi*Rn",_force);
		}else{
			_p(omega_r,"ASD factor in shear rupture (omega)","","");
			_p(cap_re_c2,"Allowable shear strength of connecting element in rupture","Ra=Rn/omega",_force);		
		}			
		_p(ratio_re_c2, "Interaction ratio in shear rupture of connecting element","P2/Ra","");

		_h3("Weld check");
		_p(f_w_c2,"Maximum stress in weld (f)","",_force + "/" + _length);
		_p(fn_w_c2,"Nominal weld strength (fn)", "", _force + "/" + _length);
		if (met == LRFD){
			_p(phi_w,"LRFD factor for weld strength(phi)","","");
			_p(cap_w_c2,"Allowable weld strength","fa=phi*fn",_force + "/" + _length);
		}else{
			_p(omega_w,"ASD factor for weld strength (omega)","","");
			_p(cap_w_c2,"Allowable weld strength","fa=fn/omega",_force + "/" + _length);		
		}
		_p(ratio_w_c2, "Interaction ratio for weld strength","f/fa","");
		
		if (conn2 == CLIP_ANGLE){
			_h3("Gusset rupture at weld check");
			_p(fn_rwg_c2, "Nominal strength of gusset at weld (Rn)","",_force);
			if (met == LRFD){
				_p(phi_r,"LRFD factor for rupture at weld (phi)","","");
				_p(cap_rwg_c2,"Allowable strength of gusset rupture at weld","Ra=phi*Rn",_force);
			}else{
				_p(omega_r,"ASD factor for rupture at weld (omega)","","");
				_p(cap_rwg_c2,"Allowable strength of gusset rupture at weld","Ra=Rn/omega",_force);		
			}
			_p(ratio_rwg_c2, "Interaction ratio for gusset rupture at weld","P2/Ra","");			
		}
		
		if (conn2 == SHEAR_PLATE){			
			_h3("Shear tab rupture at weld check");
			_p(fn_rwt_c2, "Nominal strength of shear tab rupture at weld (Rn)","",_force);
			if (met == LRFD){
				_p(phi_r,"LRFD factor for rupture at weld (phi)","","");
				_p(cap_rwt_c2,"Allowable strength of shear tab rupture at weld","Ra=phi*Rn",_force);
			}else{
				_p(omega_r,"ASD factor for rupture at weld (omega)","","");
				_p(cap_rwt_c2,"Allowable strength of shear tab rupture at weld","Ra=Rn/omega",_force);		
			}
			_p(ratio_rwt_c2, "Interaction ratio for shear tab rupture at weld","P2/Ra","");			
			
			_h3("Beam web rupture at weld check");
			_p(fn_rww_c2, "Nominal strength of beam web at weld (Rn)","",_force);
			if (met == LRFD){
				_p(phi_r,"LRFD factor for rupture at weld (phi)","","");
				_p(cap_rww_c2,"Allowable strength of beam web rupture at weld","Ra=phi*Rn",_force);
			}else{
				_p(omega_r,"ASD factor for rupture at weld (omega)","","");
				_p(cap_rww_c2,"Allowable strength of beam web rupture at weld","Ra=Rn/omega",_force);		
			}
			_p(ratio_rww_c2, "Interaction ratio for beam web rupture at weld","P2/Ra","");			
			
		}
	}
	return o;
}

#endif