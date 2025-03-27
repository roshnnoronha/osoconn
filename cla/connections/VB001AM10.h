/*
Vertical Bracing Connection Class
==================================================
By		:Roshn Noronha

This class contains the details and functions 
requried to design a vertical bracing connection 
at a beam column joint using uniform force method. 
==================================================
*/ 
#ifndef VBCONNECTION1_H
#define VBCONNECTION1_H
#define _p o=o+oso::format_p
#define _h1 o=o+oso::format_h1
#define _h2 o=o+oso::format_h2
#define _h3 o=o+oso::format_h3
#define _br o=o+oso::format_br()
#define _length us.lengthUnit()
#define _force us.forceUnit()
#define _area us.areaUnit()
#define _stress us.stressUnit()

class vbConnection1: public connection
{
public:
	enum design_method {LRFD,ASD};
	enum support_type {COLUMN_FLANGE,COLUMN_WEB};
	enum outstanding_leg_type {SHORT_LEG,LONG_LEG};
	//constructors
	vbConnection1();							
	vbConnection1(std::map<std::string,std::string>);
	//result functions
	double maxRatio(std::string&);
	//output functions
	std::string designInput();
	std::string designSummary();
	std::string designCalculation();
	bool pass();

private:
	//input variables
	design_method method;
	unit_system us;
	support_type supp_type;
	double E;
	double Fy_b;								//Yield strength of brace 
	double Fu_b;								//Tensile strength of brace 
	double Fy_g;								//Yield strength of gusset
	double Fu_g;								//Tensile strength of gusset
	double Fy_a;								//yield strength of clip angle
	double Fu_a;								//ultimate strenght of clip angle
	double Fy_bm;								//yield strength of beam
	double Fu_bm;								//ultimate strenght of beam
	double Fy_c;
	double Fu_c;								//tensile strength of column
	double Fu_w;								//weld tensile strength

	double P_br;								//axial force in brace
	double R_b;									//shear force in beam (+ve force is downward)
	double TF_b;								//transfer force in beam (+ve force is tension)

	double theta;								//angle of brace with the horizontal
	double Vc;									//vertical force at gusset to column connection
	double Hc;									//horizontal force at gusset to column connection
	double Vb;									//vertical force at gusset to beam connection
	double Hb;									//horizontal force at gusset to beam connection
	double Mb;									//moment at gusset to beam connection
	double Ab;									//required transverse force from adjecent bay
	double H;									//horizontal component of axial force
	
	int nb;										//Number of bolts in brace connection 
	int nr;										//Number of rows of bolts
	double gb;									//bolt gage (mm)
	double sb; 									//bolt spacing (mm)
	double sr; 									//bolt row spacing (mm)
	bolt blt;									//Bolt properties
    std::string bolt_type;                      //bolt type
	double ed1;									//Bolt edge distance to brace 
	double ed2;									//Bolt edge distance to gusset plate
	double ed3;									//Bolt edge distance to clip angle
	double g;									//Bolt gage on angle outstanding leg
	
	double n2;									//number of bolts in the gusset to column connection
	double n3;									//number of bolts in the beam to column connection
	double w1;									//gusset to beam weld thickness
	double w2;									//gusset to column weld thickness
	double w3;									//beam to column weld thickness
	double tg;									//thickness of gusset	
	double lgb;									//length of gusset at beam
	double l2;									//length of clip angle at gusset to column connction
	double a2;									//distance of botom of clip angle at connection 2 to top of beam
	double l3;									//length of clip angle at beam to column connection
	double c;									//setback of edge of weld from edge of clip angle
	
	section_property column;						//column section property
	section_property beam;						//beam section property
	section_property clip2;						//gusset to column clip angle
	section_property clip3;						//beam to column clip angle
	outstanding_leg_type clip2_oslg;			//outstanding leg of clip angle in case of unequal legs
	outstanding_leg_type clip3_oslg;
	section_property brace;						//Brace member
	outstanding_leg_type outstandingLeg;		//Long leg outstanding/ short leg outstanding
	section_property gusset;
	weld wld;
	
	//constants
	const double phi_r=0.75;					//LRFD factor for rupture
	const double omega_r=2.0;					//ASD factor for rupture
	const double phi_bv=0.75;					//LRFD factor for bolt shear
	const double omega_bv=2.0;					//ASD factor for bolt shear
	const double phi_bt=0.75;					//LRFD factor for bolt tension
	const double omega_bt=2.0;					//ASD factor for bolt tension
	const double phi_sl=1.0;					//LRFD factor for bolt slip resistance
	const double omega_sl=1.5;					//ASD factor for bolt slip resistance
	const double phi_b=0.75;					//LRFD factor for bolt bearing
	const double omega_b=2.0;					//ASD factor for bolt bearing
	const double phi_bl=0.75;					//LRFD factor for block shear
	const double omega_bl=2.0;					//ASD factor for block shear
	const double phi_y=0.90;					//LRFD factor for yielding
	const double omega_y=1.67;					//ASD factor for yielding
	const double phi_c = 0.9;					//LRFD factor in compression
	const double omega_c = 1.67;				//ASD factor in compression
	const double phi_w=0.75;					//LRFD factor for welds
	const double omega_w=2.0;					//ASD factor for welds
	const double phi_f=0.90;					//LRFD factor for flexure
	const double omega_f=1.67;					//ASD factor for flexure
	const double phi_vy=1.0;					//LRFD factor for shear yielding
	const double omega_vy=1.5;					//ASD factor for shear yielding
	const double phi_wy=1.0;					//LRFD factor for beam web yielding
	const double omega_wy=1.5;					//ASD factor for beam web yielding
	const double phi_wc=0.75;					//LRFD factor for beam web crippling
	const double omega_wc=2.0;					//ASD factor for beam web crippling
	const double phi_ws = 0.9;					//LRFD factor for web shear
	const double omega_ws = 1.67;				//ASD factor for web shear	
	
	//output variables
	//variables for gusset interface forces
	double ec;									//eccentricity at column connection
	double eb;									//eccentricity at beam connection
	double beta_bar;
	double alpha_bar;
	double K;
	double alpha;								//ideal alpha required for no moment 
	double beta;								//
	double r;		

	//variables for brace rupture check
	double Ag_br;								//Gross cross-section area of brace
	double ta_br;								//Brace leg thickness
	double dbh;									//Bolt hole diameter
	double An_br;								//Net cross-section area of brace
	double x_bar;								//Distance of connection from centroid
	double lc;									//Length of connection
	double U;									//Shear lag factor	
	double Ae_br;								//Effective cross-section area for tension rupture
	double Pn_rbr;								//Nominal strength of brace in tension rupture	
	double Pa_rbr;								//Allowable strength of brace in tension rupture 	
	double UR_rbr;								//Utility ratio for brace rupture

	//variables for bolt shear check
	double Pb_br;								//shear per bolt
	double Rn1_bo;								//Nominal shear strength of a single bolt with 2 slip/shear plane
	double Rn_bo;								//Nominal blot shear strength
	double Ra_bo;								//Capacity of bolt in shear
	double UR_bo;								//interaction ratio in bolt shear

	//variables for bolt bearing at brace check
	double lc_bbr;
	double Rn_bbr;								//Nominal strength of bolt bearing at brace leg
	double db;									//Bolt diameter
	double Rn_max_bbr;							//Maximum limit of nominal strength in bearing	
	double Ra_bbr;								//Capacity of bolt in bearing at brace leg
	double UR_bbr;								//interaction ratio in bolt bearing at brace leg

	//variables for bolt bearing at gusset check
	double lc_bg;
	double Rn_bg;								//Nominal strength of bolt bearing at gusset
	double Rn_max_bg;							//Maximum limit of nominal strength in bearing	
	double Ra_bg;								//Capacity of bolt in bearing at gusset
	double UR_bg;								//interaction ratio in bearing at gusset

	//variables for block shear at brace check
	double Agv;									//Gross area in shear
	double Anv;									//Net area in shear
	double li;									//Length of inside leg 
	double Ant;									//Net area in tension
	double Rn1_bl;								//Nominal strength in block shear of angle
	double Rn2_bl;	
	double Rn_bl;
	double Ra_bl;								//Capacity of bolt in bearing at gusset
	double UR_bl;								//interaction ratio in block shear

	//variables for block shear at gusset
	double Agv_g;								//gross area in shear for gusset block shear
	double Anv_g;								//net area in shear for gusset block shear
	double Ant_g;								//net area in tension for gusset block shear
	double Rn1_bl_g;
	double Rn2_bl_g;
	double Rn_bl_g;								//nominal strengt in gusset block shear
	double Ra_bl_g;								//allowable strenght in gussest block shear
	double UR_bl_g;								//interaction ratio in gusset block shear

	//variables for gusset yielding check
	double lgw;									//Length of Whitmore section
	double Agw;									//Gross area of gusset in tension
	double Pn_yg;								//Nominal strength in tension yeilding
	double Pa_yg;								//Capacity of gusset in tension yielding
	double UR_yg;								//interaction ratio in tension yielding of gusset

	//variable for gusset compression buckling strength
	double loc_br;								//location of brace edge from connection centroid
	double loc_bo;								//location of bolt from connection centroid
	double lb_1;								//buckling length 1
	double lb_2;								//buckling length 2
	double lb_3; 								//buckling length 3
	double lb_avg;								//average buckling length
	double kb=1.2;								//buckling factor for gusset
	double theta_rad;							//theta in radians
	double cos_theta;
	double sin_theta;
	double tan_theta;
	double l_con;
    double lb_c;
    double lb_b;
    double lb_offset;
	//double x1, x2, x3, y1, y2, y3;			//coordinates of points on gusset
	double rg;									//radius of gyration of gusset
	double klr;									//slenderness ratio of gusset
	double Fe;									//elastic buckling stress
	double Fcr;									//critical stress in compression buckling
	double Pn_c;								//nominal strength of gusset in compresion 
	double Pa_c;								//allowable strength in gusset compression
	double UR_c;								//interaction ratio in gusset compression

	//variables for gusset tension rupture check
	double Anw;									//Net area of gusset in tension
	double Pn_rg;								//Nominal strength of gusset in rupture
	double Pa_rg; 								//Capacity of gusset in tension yielding
	double UR_rg;								//interaction ratio in gusset rupture

	//***
	//Beam to column connection checks
	//connection forces
	double T;
	double Tb;									//Tension per bolt
	double R;
	double Rb;									//shear per bolt

	//variables for bolt shear check
	double Rn_bv;								//Nominal bolt shear strength
	double Ra_bv;								//allowable strength
	double UR_bv;								//interaction ratio in bolt shear
	
	//variables for bolt bearing at clip angle check
	double ed_cl;								//edge distance
	double edc_cl; 								//clear edge distance
	double sbc_c1;					 			//clear spacing b/n bolts
	double ta_clip;								//clip angle leg thickness
	double Rn_bc1;								//nominal strength of bearing at bolt hole
	double Rn1_bc1;
	double Ra_bc1;								//allowable strenght in bolt bearing 
	double UR_bc1;								//interaction ratio in bolt bearing at clip

	//variables for bolt bearing at column check
    double t_bco;                               //thickness for bearing calculation
    double tf_co;
	double lc_bco;								//clear distance between the edge of bolt and the edge of adjacent bolt
	double Rn_bco;								//nominal strength of bolt group in bearing
	double Rn1_bco;
	double Ra_bco;
	double UR_bco;

	//variables for weld check
    double li_clip;								//inside leg of clip
	double l_clip_1;							//clip angle length
	double b_wld_1;								//length of horizontal run of weld
	double x_wld_1;								//centroid of weld group
	double l_wld_1;								//total weld length
	double Ip_1;								//polar moment of inertia of weld group
	double ecc_1;								//eccentricity of force
	double fx_1;								//horizontal component of weld stress
	double fy_1;								//vertical componsnt o fweld stress
	double fw_1;								//maximum resultant stress in weld
	double Rn_w_1;								//nominal strength of weld
	double Ra_w_1;								//allowable strength of weld
	double UR_w_1;								//interaction ratio for weld strength

	//variables for beam web rupture at weld
	double Rn_rbw;								//nominal strength in beam web rupture at weld
	double Ra_rbw;								//allowable strength in beam web rupture at weld
	double UR_rbw;								//interaction ratio in beam web rupture at weld

	//Block shear at clip angle check
	double Agv_blc;								//gross area in shear for block shear at clip angle
	double Anv_blc;								//net area in shear for block shear at clip angle
	double Ant_blc; 							//net area in tension for block shear at clip angle
	double Rn_blc;								//nominal strenght in block shear at clip angle
	double Rn1_blc;
	double Ra_blc;								//allowable strength in block shear at clip angle
	double UR_blc;								//interaction ratio in blosck shear at clip angle

	//variables for bolt tension check
	double Rn_bt; 								//Nominal bolt tension strength
	double Ra_bt;								//allowable strength
	double UR_bt;								//Interaction ration in bolt tension

	//variables for clip prying check
	double ed;									//Edge distance from center of bolt
	double tw_b;								//beam web thickness
	double g1;									//distance of face of angle to bolt center
	double p_ed;								//pitch of edge bolt
	double p_mid;								//pitch of mid bolt
	double p;									//minimum pitch distance
	double B;									//available tension strength per bolt
	double lo_clip;								//clip angle outstanding leg length
	double a;									//distance of bolt centerline to edge of fitting
	double b;									//distance of bolt centerline to centerline of clip angle
	double a1;
	double b1;
	double rho;
	double beta_b;
	double delta;								//ratio of the net length at bolt line to gross length at the face of the stem or leg of angle
	double alpha1;							
	double tc;									//angle thickness required to develop available strength of the bolt B 
	double tr;
	double Q;									
	double UR_pry;
	
	//variables for column prying check
	double bf_co;
	double tw_co;
	double a_co;
	double b_co;
	double b1_co;
	double p_eff;								//bolt pitch
	double delta_co;							//ratio of net length at bolt line to gross length at face of stem
	double a1_co;
	double rho_co;
	double tc_co;								//flange thickness required to develop available strength of the bolt 
	double tr_co;
	double alpha1_co;
	double Q_co;
	double UR_pry_co;

	//variables for clip angle shear yielding check
	double Rn_ycl;								//nominal strenght of clip angle in shear yielding
	double Ra_ycl;								//allowable strength in shear yielding of clip
	double UR_ycl;								//interaction ratio in clip shear yielding
	
	//variables for clip shear rupture check
	double Anet_cl;								//net area of clip angle in shear rupture
	double Rn_rcl;								//nominal strength of clip angle in shear rupture
	double Ra_rcl;								//allowable strength of clip angle in shear rupture
	double UR_rcl;								//interaction ratio in clip shear rupture
	
	//variables for column web yielding check
	double Rn_wyc;								//nominal strength in web yielding at beam to column connection
	double Ra_wyc;								//allowable strength in web yielding at beam to column connection
	double UR_wyc;								//interaction ratio in web yielding
	double l_clip;								//clip lenght at beam to column connection

	//variable column web crippling check
	double Rn_wcc;								//nominal strength in web crippling at beam to column connection
	double Ra_wcc;								//allowable strength in web crippling at beam to column connection
	double UR_wcc;								//interaction ratio in web crippling

	//variables for column web shear check
	double Rn_wsc;														//nominal strength in web shear at column
	double Ra_wsc;														//allowable strength in web shear at column
	double UR_wsc;														//interaction ratio in web shear at column

	//***
	//Gusset to beam connection checks
	//variables for weld check
	double Rn_wbm;														//nominal weld strength (N/mm)
	double Ra_wbm;														//allowable weld strength
	double ft_max_wbm;													//maximum stress transverse to the weld
	double ft_min_wbm;													//minimum stress transverse to the weld
	double fl_wbm;														//stress logitudinal to the weld
    double fw_max_wbm;					                                //maximum resulting stress in weld
    double fw_avg_wbm;                                                  //average stress in weld
	double fw_wbm;														//maximum resulting stress in weld
	double UR_wbm;														//interaction ratio
	
	//variables for rupture at gusset check
	double tp_min;														//minimum thickness of plate required to develop strength of weld
	double UR_rp;														//interaction ratio for plate rupture
	
	//variables for beam web yeilding check
	double d_b;															//beam member depth
	double k_b;
	double Rn_wyb;														//nominal strength in web yielding
	double Ra_wyb;														//allowable strength in web yielding
	double UR_wy;														//interaction ratio in web yielding
	double R_wyb;														//required strength at gusset to beam connection
	
	//variables for beam web crippling check
	double tf_b;
	double Rn_wcb;														//Nominal strength of beam in web crippling
	double Ra_wcb;														//Allowable strength of beam in web crippling
	double UR_wcb;
	
	double bf_b;														//beam flange width
	double d_co;														//depth of column
	double k_co;														//fillet dimension of column

	//variables for beam web shear check
	double Rn_wsb;														//nominal strength in web shear at beam
	double Ra_wsb;														//allowable strength in web shear at beam
	double UR_wsb;														//interaction ratio in web shear at beam	
	
	//***
	//Gusset to column connection checks
	double T2; 															//tension at gusset to column connection
	double Tb_2;														//tension per bolt at gusset to column connection
	double R2;															//shear at gusset to column connection
	double Rb_2;														//shear per bolt at gusset to column connection

	//variable for bolt shear strength at gusset to column connection
	double Rn_bv_2;														//nominal strength in bolt shear 
	double Ra_bv_2;														//allowable strength in bolt shear 
	double UR_bv_2;														//interaction ratio in bolt shear

	//variables for bolt bearing at clip angle
	double UR_bcl_2;													//interaction ratio in bolt bearing at clip

	//variables for bolt bearing at column flange
	double UR_bco_2;													//interaction ratio in bolt bearing at column

	//variables for bolt tension strength at clip angle
	double Rn_bt_2;														//nominal strength in bolt tension
	double Ra_bt_2;														//allowable strength in bolt tension
	double UR_bt_2;														//interaction ration in bolt tension

	//variables for clip angle prying check
	double g1_2;														//distance of face of angle to bolt center
	double p_ed_2;														//pitch of edge bolt
	double p_mid_2;														//pitch of mid bolt
	double p_2;															//minimum pitch distance
	double B_2;															//available tension strength per bolt
	double a_2;
	double a1_2;														//distance of bolt centerline to centerline of clip angle
	double b_2;
	double b1_2;
	double rho_2;
	double delta_2;
	double tc_2;
	double tr_2;
	double alpha1_2;
	double Q_2;															//bolt strength reduction factor for private
	double UR_pry_2;													//interaction ratio in clip angle prying

	//variables for column flange prying check
	double b_co_2;														//distance of bolt centerline to centerline of clip angle
	double b1_co_2;
	double a_co_2;														//distance of bolt centerline to edge of fitting
	double a1_co_2;
	double p_eff_2;														//effective pitch at column
	double delta_co_2;
	double rho_co_2;
	double tc_co_2;
	double tr_co_2;
	double alpha1_co_2;
	double Q_co_2;														//bolt strength reduction factor due to prying
	double UR_pry_co_2;													//interaction ratio for prying at column

	//variables for weld shear strength
	double l_clip_2;													//clip angle length
	double b_wld_2;														//length of horizontal run of weld
	double x_wld_2;														//centroid of weld group
	double l_wld_2;														//total weld length
	double Ip_2;														//polar moment of inertia of weld group
	double ecc_2;														//eccentricity of force
	double fx_2;														//horizontal component of weld stress
	double fy_2;														//vertical componsnt o fweld stress
	double fw_2;														//maximum resultant stress in weld
	double Rn_w_2;														//nominal strength of weld
	double Ra_w_2;														//allowable strength of weld
	double UR_w_2;														//interaction ratio for weld strength

	//variables for gusset rupture at weld check 
	double Rn_rbw_2;													//nominal strength in rupture of beam web at weld
	double Ra_rbw_2;													//nominal strength in rupture of beam web at weld
	double UR_rbw_2;													//interaction ratio in rupture of beam web at weld

	//variables for clip angle block shear check
	double Agv_blc_2;													//gross area in shear for block shear at clip angle
	double Anv_blc_2;													//net area in shear for block shear at clip angle
	double Ant_blc_2; 													//net area in tension for block shear at clip angle
	double Rn_blc_2;													//nominal strenght in block shear at clip angle
	double Rn1_blc_2;
	double Ra_blc_2;													//allowable strength in block shear at clip angle
	double UR_blc_2;													//interaction ratio in blosck shear at clip angle

	//variables for shear yielding of clip angle
	double Rn_ycl_2;													//nominal strength in shear yielding of clip
	double Ra_ycl_2;													//allowable strength in shear yielding of clip
	double UR_ycl_2;													//interaction ratio in clip shear yielding

	//variables for shear rupture of clip angle
	double Anet_cl_2;													//net area in shear 
	double Rn_rcl_2;													//nominal strength in shear rupture of clip
	double Ra_rcl_2;													//allowable strength in shear rupture of clip
	double UR_rcl_2;													//interaction ratio in clip shear rupture	

	//variables for column web yielding check
	double Rn_wyc_2;													//nominal strength in web yielding at gusset to column connection
	double Ra_wyc_2;													//allowable strength in web yielding at gusset to column connection
	double UR_wyc_2;													//interaction ratio in web yielding

	//variables for column web crippling check
	double Rn_wcc_2;													//nominal strength in web crippling at gusset to column connection
	double Ra_wcc_2;													//allowable strength in web crippling at gusset to column connection
	double UR_wcc_2;													//interaction ratio in web crippling

	double UR_max;														//maximum interaction ratio
	
	double kdet;														//fillet dimension of brace
	double kdet_clip;													//fillet dimension of clip
	double kdet_b;														//fillet dimension of beam
	double kdet_co;														//fillet dimension of column

	//design functions
	void checkFitup();
	void calc();
	//miscellaneous functions
	double min(double,double);
	double allowableStrength(double,double,double);
};


////////////////////CONSTRUCTORS/////////////////////////
vbConnection1::vbConnection1():
brace(section_property::MEMB_TYPE_L),clip2(section_property::MEMB_TYPE_L),clip3(section_property::MEMB_TYPE_L),gusset(section_property::MEMB_TYPE_PLATE){
}
vbConnection1::vbConnection1(std::map<std::string,std::string> data):
brace(section_property::MEMB_TYPE_L),clip2(section_property::MEMB_TYPE_L),clip3(section_property::MEMB_TYPE_L),gusset(section_property::MEMB_TYPE_PLATE){

	addParameter("CONNECTION_CODE");
	addParameter("CONNECTION_ID");
	addParameter("METHOD");
	param("METHOD").addAllowableValue("LRFD");
	param("METHOD").addAllowableValue("ASD");
	addParameter("UNITS");
	param("UNITS").addAllowableValue("NEWTON_MM");
	param("UNITS").addAllowableValue("KIP_IN");
	addParameter("SUPPORT_TYPE");
	param("SUPPORT_TYPE").addAllowableValue("COLUMN_FLANGE");
	param("SUPPORT_TYPE").addAllowableValue("COLUMN_WEB");
	addParameter("MODULUS_OF_ELASTICITY");
	param("MODULUS_OF_ELASTICITY").isPositiveNumber();
	addParameter("ANGLE_GRADE");
	param("ANGLE_GRADE").addAllowableValue("A36");
	param("ANGLE_GRADE").addAllowableValue("A992");
	addParameter("BEAM_GRADE");
	param("BEAM_GRADE").addAllowableValue("A36");
	param("BEAM_GRADE").addAllowableValue("A992");
	addParameter("COLUMN_GRADE");
	param("COLUMN_GRADE").addAllowableValue("A36");
	param("COLUMN_GRADE").addAllowableValue("A992");
	addParameter("PLATE_GRADE","A36");
	param("PLATE_GRADE").addAllowableValue("A36");
	addParameter("WELD_ELECTRODE","E70"); 
	param("WELD_ELECTRODE").addAllowableValue("E70");
	addParameter("BOLT_GRADE");
	param("BOLT_GRADE").addAllowableValue("A325");
	param("BOLT_GRADE").addAllowableValue("A490");	
	addParameter("BRACE_FORCE");
	param("BRACE_FORCE").isNumber();
	addParameter("BEAM_SHEAR_FORCE");
	param("BEAM_SHEAR_FORCE").isNumber();
	addParameter("BEAM_TRANSFER_FORCE");
	param("BEAM_TRANSFER_FORCE").isNumber();
	addParameter("BEAM_SECTION");
	addParameter("BRACE_SECTION");
	addParameter("BRACE_OUTSTANDING_LEG","SHORT_LEG");
	param("BRACE_OUTSTANDING_LEG").addAllowableValue("LONG_LEG");
	param("BRACE_OUTSTANDING_LEG").addAllowableValue("SHORT_LEG");
	addParameter("COLUMN_SECTION");
	addParameter("GUSSET_THICKNESS");
	param("GUSSET_THICKNESS").isPositiveNumber();
	addParameter("BOLT_DIAMETER");
	addParameter("BOLT_TYPE");
	param("BOLT_TYPE").addAllowableValue("FRICTION");
	param("BOLT_TYPE").addAllowableValue("BEARING");
	addParameter("THREAD_INCLUDED_IN_SHEAR","YES");
	param("THREAD_INCLUDED_IN_SHEAR").addAllowableValue("YES");
	param("THREAD_INCLUDED_IN_SHEAR").addAllowableValue("NO");
	if (data["BOLT_TYPE"] == "FRICTION"){
		addParameter("FAYING_SURFACE","CLASS_A");
        param("FAYING_SURFACE").addAllowableValue("CLASS_A");
        param("FAYING_SURFACE").addAllowableValue("CLASS_B");
	}
    addParameter("BOLT_GAGE");
	param("BOLT_GAGE").isPositiveNumber();
	addParameter("BOLT_GAGE_ON_BRACE");
	param("BOLT_GAGE_ON_BRACE").isPositiveNumber();
	addParameter("BOLT_SPACING");
	param("BOLT_SPACING").isPositiveNumber();
	addParameter("BOLT_ROW_SPACING","0");
	param("BOLT_ROW_SPACING").isPositiveNumber();
	addParameter("EDGE_DISTANCE_ON_BRACE");
	param("EDGE_DISTANCE_ON_BRACE").isPositiveNumber();
	addParameter("EDGE_DISTANCE_ON_GUSSET");
	param("EDGE_DISTANCE_ON_GUSSET").isPositiveNumber();
	addParameter("EDGE_DISTANCE_ON_CLIP");
	param("EDGE_DISTANCE_ON_CLIP").isPositiveNumber();
	addParameter("NUMBER_OF_BOLTS_PER_ROW_ON_BRACE");
	param("NUMBER_OF_BOLTS_PER_ROW_ON_BRACE").isInteger();
	param("NUMBER_OF_BOLTS_PER_ROW_ON_BRACE").setMinimumValue(2);
	addParameter("NUMBER_OF_BOLT_ROWS_ON_BRACE");	
	param("NUMBER_OF_BOLT_ROWS_ON_BRACE").isInteger();
	param("NUMBER_OF_BOLT_ROWS_ON_BRACE").setMinimumValue(1);
	param("NUMBER_OF_BOLT_ROWS_ON_BRACE").setMaximumValue(2);
	addParameter("BRACE_ANGLE");		
	param("BRACE_ANGLE").setMinimumValue(20);
	param("BRACE_ANGLE").setMaximumValue(80);
    addParameter("BRACE_DIST_FROM_WP");
    param("BRACE_DIST_FROM_WP").isPositiveNumber();
	addParameter("GUSSET_TO_BEAM_WELD");		
	param("GUSSET_TO_BEAM_WELD").isPositiveNumber();
	addParameter("GUSSET_LENGTH");			
	param("GUSSET_LENGTH").isPositiveNumber();
	addParameter("CLIP_SECTION");		
	addParameter("CLIP_OUTSTANDING_LEG","SHORT_LEG");
	param("CLIP_OUTSTANDING_LEG").addAllowableValue("LONG_LEG");
	param("CLIP_OUTSTANDING_LEG").addAllowableValue("SHORT_LEG");	
	addParameter("NUMBER_OF_BOLTS_GUSSET_CLIP");	
	param("NUMBER_OF_BOLTS_GUSSET_CLIP").isInteger();
	param("NUMBER_OF_BOLTS_GUSSET_CLIP").setMinimumValue(2);
	addParameter("NUMBER_OF_BOLT_BEAM_CLIP");	
	param("NUMBER_OF_BOLT_BEAM_CLIP").isInteger();
	param("NUMBER_OF_BOLT_BEAM_CLIP").setMinimumValue(2);
	addParameter("CLIP_ANGLE_WELD_THICKNESS");
	param("CLIP_ANGLE_WELD_THICKNESS").isPositiveNumber();
	addParameter("GUSSET_CLIP_LOCATION");
	param("GUSSET_CLIP_LOCATION").isPositiveNumber();
	addParameter("CONNECTION_SETBACK");
	param("CONNECTION_SETBACK").isPositiveNumber();

	validateParameters(data);

	connID = data["CONNECTION_ID"];
    connCode = data["CONNECTION_CODE"];

	if (data["METHOD"] == "LRFD"){
		method = LRFD;
		blt.setMethod(bolt::LRFD);
	}else{
		method = ASD;
		blt.setMethod(bolt::ASD);
	}
	if (data["UNITS"] == "NEWTON_MM"){
		us.setUnitSystem(unit_system::NEWTON_MM);
		blt.setUnitSystem(unit_system::NEWTON_MM);	
		column.setUnitSystem(unit_system::NEWTON_MM);							
		beam.setUnitSystem(unit_system::NEWTON_MM);							
		clip2.setUnitSystem(unit_system::NEWTON_MM);							
		clip3.setUnitSystem(unit_system::NEWTON_MM);							
		brace.setUnitSystem(unit_system::NEWTON_MM);							
		gusset.setUnitSystem(unit_system::NEWTON_MM);	
		wld.setUnitSystem(unit_system::NEWTON_MM);
	}else{ 
		us.setUnitSystem(unit_system::KIP_IN);
		blt.setUnitSystem(unit_system::KIP_IN);
		column.setUnitSystem(unit_system::KIP_IN);						
		beam.setUnitSystem(unit_system::KIP_IN);						
		clip2.setUnitSystem(unit_system::KIP_IN);						
		clip3.setUnitSystem(unit_system::KIP_IN);						
		brace.setUnitSystem(unit_system::KIP_IN);						
		gusset.setUnitSystem(unit_system::KIP_IN);
		wld.setUnitSystem(unit_system::KIP_IN);
	}
	if(data["SUPPORT_TYPE"] == "COLUMN_FLANGE")
		supp_type = COLUMN_FLANGE;
	else
		supp_type = COLUMN_WEB;
	//MATERIAL PROPERTIES
	E = atof(data["MODULUS_OF_ELASTICITY"].c_str());
	if (data["ANGLE_GRADE"] == "A36"){
		brace.setGrade(section_property::ASTM_A36);
		clip2.setGrade(section_property::ASTM_A36);
		clip3.setGrade(section_property::ASTM_A36);
	}else{
		brace.setGrade(section_property::ASTM_A992);
		clip2.setGrade(section_property::ASTM_A992);
		clip3.setGrade(section_property::ASTM_A992);
	}
	Fy_b = brace.yieldStrength();
	Fu_b = brace.tensileStrength();
	Fy_a = clip2.yieldStrength();
	Fu_a = clip2.tensileStrength();
	if (data["BEAM_GRADE"] == "A36")
		beam.setGrade(section_property::ASTM_A36);
	else
		beam.setGrade(section_property::ASTM_A992);
	Fy_bm = beam.yieldStrength();
	Fu_bm = beam.tensileStrength();
	if (data["COLUMN_GRADE"] == "A36")
		column.setGrade(section_property::ASTM_A36);
	else
		column.setGrade(section_property::ASTM_A992);
	Fy_c = column.yieldStrength();
	Fu_c = column.tensileStrength();
	gusset.setGrade(section_property::ASTM_A36);
	Fy_g = gusset.yieldStrength();
	Fu_g = gusset.tensileStrength();
	wld.setGrade(weld::FEXX70);
	Fu_w = wld.tensileStrength();
	if (data["BOLT_GRADE"] == "A325")
		blt.setBoltGrade(bolt::ASTM_A325);
	else
		blt.setBoltGrade(bolt::ASTM_A490);
	//CONNECTION FORCES
	P_br = atof(data["BRACE_FORCE"].c_str());
	R_b = atof(data["BEAM_SHEAR_FORCE"].c_str());
	TF_b = atof(data["BEAM_TRANSFER_FORCE"].c_str());
 	//SECTION PROPERTIES
	beam.setSection(data["BEAM_SECTION"]);
	d_b = beam.depth();		
	bf_b = beam.flangeWidth();
	tf_b = beam.flangeThickness();
	tw_b = beam.webThickness();		
	k_b = beam.filletDimension();
	kdet_b = beam.detFilletDimension();
	brace.setSection(data["BRACE_SECTION"]);
	if ((brace.leg1() != brace.leg2()) && (data.count("BRACE_OUTSTANDING_LEG") == 0))
		err.addError("Missing input parameter BRACE_OUTSTANDING_LEG.");
	if (data["BRACE_OUTSTANDING_LEG"] == "SHORT_LEG")
		outstandingLeg = SHORT_LEG;
	else
		outstandingLeg = LONG_LEG;				
	if (outstandingLeg == SHORT_LEG)
		li = brace.leg2();
	else
		li = brace.leg1();
	kdet = brace.detFilletDimension();
	column.setSection(data["COLUMN_SECTION"]);
	d_co = column.depth();
	bf_co = column.flangeWidth();
	tf_co = column.flangeThickness();
	tw_co = column.webThickness();
	k_co = column.filletDimension();
	kdet_co = column.detFilletDimension();
	tg = atof(data["GUSSET_THICKNESS"].c_str());
	//BOLT DETAILS
	blt.setBoltDiameter(data["BOLT_DIAMETER"]);
	db = blt.diameter();											
	dbh = blt.standardBoltHole();
    bolt_type = data["BOLT_TYPE"];
	if (bolt_type == "FRICTION")
		blt.setBoltType(bolt::FRICTION);
	else 
		blt.setBoltType(bolt::BEARING);
	if (data["THREAD_INCLUDED_IN_SHEAR"] == "NO")
		blt.setBoltThreadType(bolt::THREAD_EXCLUDED_FROM_SHEAR_PLANE);
	else 
		blt.setBoltThreadType(bolt::THREAD_INCLUDED_IN_SHEAR_PLANE);	
	if (data["FAYING_SURFACE"] == "CLASS_B")
		blt.setFayingSurface(bolt::CLASS_B);
	else 
		blt.setFayingSurface(bolt::CLASS_A);
	g = atof(data["BOLT_GAGE_ON_BRACE"].c_str());
	gb = atof(data["BOLT_GAGE"].c_str());
	sb = atof(data["BOLT_SPACING"].c_str());
    sr = atof(data["BOLT_ROW_SPACING"].c_str());
    if (sr == 0)
        sr = sb;
	ed1 = atof(data["EDGE_DISTANCE_ON_BRACE"].c_str());
	ed2 = atof(data["EDGE_DISTANCE_ON_GUSSET"].c_str());
	ed3 = atof(data["EDGE_DISTANCE_ON_CLIP"].c_str());
	//BRACE TO GUSSET CONNECTION DETAILS
	nb = atoi(data["NUMBER_OF_BOLTS_PER_ROW_ON_BRACE"].c_str()); 
	nr = atoi(data["NUMBER_OF_BOLT_ROWS_ON_BRACE"].c_str());
	theta = atof(data["BRACE_ANGLE"].c_str());
    loc_br = atof(data["BRACE_DIST_FROM_WP"].c_str());
	//GUSSET TO BEAM CONNECTION DETAILS
	w1 = atof(data["GUSSET_TO_BEAM_WELD"].c_str());
	lgb = atof(data["GUSSET_LENGTH"].c_str());	
	//COLUMN CONNECTION DETAILS
	clip2.setSection(data["CLIP_SECTION"]);
	clip3.setSection(data["CLIP_SECTION"]);
	ta_clip = clip2.thickness();		
	if ((clip2.leg1() != clip2.leg2()) && (data.count("CLIP_OUTSTANDING_LEG") == 0))
		err.addError("Missing input parameter CLIP_OUTSTANDING_LEG.");	
	if (data["CLIP_OUTSTANDING_LEG"] == "SHORT_LEG")
		clip2_oslg = SHORT_LEG;
	else
		clip2_oslg = LONG_LEG;		
	if (clip2_oslg == LONG_LEG){
		lo_clip = clip2.longLeg();
		li_clip = clip2.shortLeg();
	}else{
		lo_clip = clip2.shortLeg();
		li_clip = clip2.longLeg();
	}
	kdet_clip = clip2.detFilletDimension();
	n2 = atoi(data["NUMBER_OF_BOLTS_GUSSET_CLIP"].c_str());
	n3 = atoi(data["NUMBER_OF_BOLT_BEAM_CLIP"].c_str());
	w2 = atof(data["CLIP_ANGLE_WELD_THICKNESS"].c_str());
	w3 = w2;
	a2 = atof(data["GUSSET_CLIP_LOCATION"].c_str());
	c = atof(data["CONNECTION_SETBACK"].c_str());
	
	if (err.isError()) throw err.errorMessage();	
	//check fitup
	checkFitup();
	if (err.isError()) throw err.errorMessage();		
	
	calc();
	
}

/////////////////////DESIGN FUNCTIONS//////////////////////// 
void vbConnection1::checkFitup(){
	//bolt spacing check
	if (sb < blt.minBoltSpacing()) err.addError("Minimum bolt spacing not satisfied. Try increasing bolt spacing.");
	if (sr < blt.minBoltSpacing()) err.addError("Minimum bolt row spacing not satisfied. Try increasing bolt row spacing.");
	//bolt edge distance at brace
	double ed_min = blt.minEdgeDistance();
	if (ed1 < ed_min) err.addError("Inadequate edge distance at brace. Try increasing edge distance on brace.");
	//bolt edge distance at gusset check
	if (ed2 < ed_min) err.addError("Inadequate edge distance at gusset. Try increading edge distance on gusset."); 
	//bolt edge distance at clip angle check
	if (ed3 < ed_min) err.addError("Inadequate edge distance at clip angle. Try increasing edge distance on clip angle.");
	double ed4 = (2*lo_clip + tw_b - gb)/2;
    double ed5 = (2*lo_clip + tg - gb)/2;
	if ((ed4 < ed_min) || (ed5 < ed_min)) err.addError("Insufficient horizontal edge distance on clip angle. Try reducing the bolt gage or using a larger clip angle.");
	//bolt edge distance on brace perpendicular to brace
	if (li - (g + (nr - 1)*sr) < ed_min) err.addError("Inadequate edge distance perpendicular to brace. Try reducing bolt gage on brace.");
    //bolt edge distance on clip perpendicular to clip
	if ((tw_b + 2*lo_clip - g)/2 < ed_min) err.addError("Inadequate edge distance perpendicular to clip angle. Try reducing bolt gage.");
	//bolt edge distance on column flange
	if (supp_type == COLUMN_FLANGE)
		if ((bf_co - g)/2 < ed_min) err.addError("Inadequate edge distance on column flange. Try reducing bolt gage.");
	//bolt clash with brace fillet area 
	if (g < kdet + db) err.addError("Bolt clashes with brace fillet area. Try increasing bolt gage on brace.");
	//bolt clash with clip fillet area
	if (gb < tw_b + 2*kdet_clip + 2*db) err.addError("Bolt clashes with clip fillet area. Try increasing bolt gage.");
	//bolt clash with column fillet area
    if (supp_type == COLUMN_FLANGE)
        if (gb < tw_co + 2*(kdet_co - tf_co) + 2*db) err.addError("Bolt clashes with column fillet area. Try increasing bolt gage.");
	//gusset clip angle connection location check
	double wldGap;
	if (us.getUnitSystem() == unit_system::NEWTON_MM)
		wldGap = 2;
	else 
		wldGap = 0.1;
	if (a2 < w1 + w2 + wldGap) err.addError("Insufficient clearance of clip angle at gusset plate from the beam. Try increading gusset clip angle clearance.");
	//beam clip angle clash with beam fillet area checkFitup
	if (2*ed3 + (n3 - 1)*sb > d_b - 2*kdet_b - 2*wldGap - 2*w3) err.addError("Insufficient space for clip angle at beam connection. Try reducing the number of bolts, bolt spacing or edge distance at clip.");
	//check maximum connection setback
	if (c >= li_clip) err.addError("Value provided for connection setback is high. Try reducing the connection setback.");
}
void vbConnection1::calc(){	
	//UFM forces in connection
	l2 = (n2 - 1)*sb + 2.0*ed3;
	if (supp_type == COLUMN_FLANGE)
        ec = d_co/2.0;												//eccentricity at column connection
	else 
        ec = 0;
    eb = d_b/2.0;													//eccentricity at beam connection
	beta_bar = l2/2.0 + a2;
	alpha_bar = lgb/2.0;
	K = eb*tan(theta*PI/180) - ec;
	alpha = K + beta_bar*tan(theta*PI/180);							//ideal alpha required for no moment 
	beta = beta_bar;													
	r = sqrt((alpha_bar+ec)*(alpha_bar + ec) + (beta + eb)*(beta + eb));	
	Vc = beta/r*P_br;												//vertical force at column connection
	Hc = ec/r*P_br;													//horizontal force at column connection
	Vb = eb/r*P_br;													//vertical force at beam connection
	Hb = alpha_bar/r*P_br;											//horizontal force at beam connection
	Mb = Vb*(alpha - alpha_bar);									//moment at beam connection
	Mb = (Mb < 0) ? (-Mb) : Mb;
	//*
	//Gusset to brace connection checks
	//Brace rupture strength
	Ag_br = 2.0*brace.area();										//Gross cross-section area of brace
	ta_br = brace.thickness();										//Brace leg thickness
	An_br = Ag_br-2.0*nr*ta_br*dbh;									//Net cross-section area of brace
	if (outstandingLeg == LONG_LEG)
		x_bar = brace.centroidOnLongLeg();
	else	
		x_bar = brace.centroidOnShortLeg();	
	lc = (nb-1.0)*sb;												//Length of connection
	U = 1.0-x_bar/lc;												//Shear lag factor	
	Ae_br = U*An_br;												//Effective cross-section area for tension rupture
	Pn_rbr = Fu_b*Ae_br;											//Nominal strength of brace in tension rupture	
	Pa_rbr = allowableStrength(Pn_rbr,phi_r,omega_r);				//Allowable strength of brace in tension rupture 	
	UR_rbr = P_br/Pa_rbr;											//Utility ratio for brace rupture

	//Bolt shear strength
	Pb_br = P_br/(nr*nb);											//shear per bolt
	Rn_bo = blt.nominalShearStrength(2);							//Nominal shear strength of a single bolt with 2 slip/shear plane
    if (bolt_type == "BEARING")
        Ra_bo = allowableStrength(Rn_bo,phi_bv,omega_bv);			//Capacity of bolt in shear
	else
        Ra_bo = allowableStrength(Rn_bo,phi_sl,omega_sl);	
    UR_bo = Pb_br/Ra_bo;											//interaction ratio in bolt shear
	
	//Bolt bearing strength at brace
	lc_bbr = min(ed1 - dbh/2, sb - dbh);
	Rn_bbr = 1.2 *lc_bbr *ta_br *Fu_b;								//Nominal strength of bolt bearing at brace leg
	Rn_max_bbr = 2.4 *db *ta_br *Fu_b;								//Maximum limit of nominal strength in bearing	
	Rn_bbr = min(Rn_bbr,Rn_max_bbr);
	Ra_bbr = allowableStrength(Rn_bbr,phi_b,omega_b);				//Capacity of bolt in bearing at brace leg
	UR_bbr = Pb_br / (2*Ra_bbr);									//interaction ratio in bolt bearing at brace leg 

	//Bolt bearing strength at gusset
	lc_bg = min(ed2 - dbh/2, sb - dbh);
	Rn_bg = 1.2 *lc_bg * tg *Fu_g;									//Nominal strength of bolt bearing at gusset
	Rn_max_bg = 2.4 * db *tg *Fu_g;									//Maximum limit of nominal strength in bearing	
	Rn_bg = min(Rn_bg,Rn_max_bg);
	Ra_bg = allowableStrength(Rn_bg,phi_b,omega_b);					//Capacity of bolt in bearing at gusset
	UR_bg = Pb_br/Ra_bg;											//interaction ratio in bearing at gusset
	
	//Block shear strength at brace
	Agv = 2.0*((nb - 1.0)*sb + ed1)*ta_br;							//Gross area in shear
	Anv = Agv - 2.0*(nb -0.5)*dbh*ta_br;							//Net area in shear	
	Ant = 2.0*(li - g - (nr - 0.5)*dbh)*ta_br;						//Net area in tension
	Rn1_bl = (0.6*Fu_b*Anv + Fu_b*Ant);							    //Nominal strength in block shear of brace
	Rn2_bl = (0.6*Fy_b*Agv + Fu_b*Ant);	
	Rn_bl = min(Rn1_bl,Rn2_bl);
	Ra_bl = allowableStrength(Rn_bl,phi_bl,omega_bl);				//Allowable strength in block shear
	UR_bl = P_br/Ra_bl;												//interaction ratio
	
	//Block shear at gusset
	if (nr == 2){
		Agv_g = 2.0*((nb-1)*sb + ed2)*tg;
		Anv_g = Agv_g - 2.0*dbh*(nb-0.5)*tg;
		Ant_g = (sr - dbh)*tg;
		Rn1_bl_g = (0.6*Fu_g*Anv_g + Fu_g*Ant_g);				//Nominal strength in block shear of gusset
		Rn2_bl_g = (0.6*Fy_g*Agv_g + Fu_g*Ant_g);	
		Rn_bl_g = min(Rn1_bl_g,Rn2_bl_g);
		Ra_bl_g = allowableStrength(Rn_bl_g,phi_bl,omega_bl);		//Allowable strenght in block shear
		UR_bl_g = P_br/Ra_bl_g;										//interaction ratio in block shear
	}
	
	//Gusset yield strength
	lgw = 2.0 *(nb -1.0) *sb *tan(30.0 *PI /180.0) + (nr-1)*sr; 	//Length of Whitmore section
	Agw = lgw *tg;													//Gross area of gusset in tension
	Pn_yg = Fy_g *Agw;												//Nominal strength in tension yeilding
	Pa_yg = allowableStrength(Pn_yg,phi_y,omega_y);					//Capacity of gusset in tension yielding
	UR_yg = P_br/Pa_yg;												//interaction ratio
	
	//Gusset tension rupture strength
    Anw = Agw - nr*dbh*tg;                                          //Net area in tension
    Pn_rg = Fu_g*Anw;                                               //Nominal strength in tension rupture  
    Pa_rg = allowableStrength(Pn_rg,phi_r,omega_r);                 //Allowable strength in tension rupture 
    UR_rg = P_br/Pa_rg;                                             //Interaction ratio in tension rupture
        
        
	//Gusset compression buckling strength
	theta_rad = theta*PI/180.;										//theta in radians
	cos_theta = cos(theta_rad);
	sin_theta = sin(theta_rad);
	tan_theta = tan(theta_rad);
	l_con = (nb - 1)*sb;
	loc_bo = loc_br + ed1;
	/*
    if (eb > ec*tan(theta_rad))										//centerline of bolts intersect the bottom edge of the gusset
		lb_1 = loc_bo - eb/sin_theta;
	else
		lb_1 = loc_bo - ec/cos_theta;
	lb_1 = lb_1 < 0? 0: lb_1;
	x1 = loc_bo*cos_theta - 0.577*l_con*sin_theta;
	y1 = loc_bo*sin_theta + 0.577*l_con*cos_theta;
	x2 = ec;
	y2 = tan_theta*(ec - x1) + y1;
	x3 = (tan_theta*x1 - y1 + eb)/tan_theta;
	y3 = eb;
	if (y2 > y3)
		lb_2 = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	else
		lb_2 = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1));
	lb_2 = lb_2 < 0? 0: lb_2;
	x1 = loc_bo*cos_theta + 0.577*l_con*sin_theta;
	y1 = loc_bo*sin_theta - 0.577*l_con*cos_theta;
	x2 = ec;
	y2 = tan_theta*(ec - x1) + y1;
	x3 = (tan_theta*x1 - y1 + eb)/tan_theta;
	y3 = eb;
	if (y2 > y3)
		lb_3 = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	else
		lb_3 = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1));	
	lb_3 = lb_3 < 0? 0: lb_3;
    */
    lb_c = loc_bo - ec/cos_theta;
    lb_b = loc_bo - eb/sin_theta;
    lb_offset = 0.5*lgw*tan_theta;
    lb_1 = (lb_c < lb_b)?lb_c:lb_b;
    lb_1 = (lb_1 > 0)?lb_1:0;
    lb_2 = ((lb_c - lb_offset)<(lb_b + lb_offset))? (lb_c - lb_offset):(lb_b + lb_offset);
    lb_2 = (lb_2 > 0)?lb_2:0;
    lb_3 = ((lb_c + lb_offset)<(lb_b - lb_offset))? (lb_c + lb_offset):(lb_b - lb_offset);
    lb_3 = (lb_3 > 0)?lb_3:0;    
	lb_avg = (lb_1 + lb_2 + lb_3)/3;
	rg = tg/3.464;
	klr = kb*lb_avg/rg;
	Fe = PI*PI*E/(klr*klr);
	if (Fy_g/Fe <= 2.25)
		Fcr = pow(0.658,(Fy_g/Fe))*Fy_g;
	else
		Fcr = 0.877*Fe;
	Pn_c = Fcr*lgw*tg;
	Pa_c = allowableStrength(Pn_c,phi_c,omega_c);
	UR_c = P_br/Pa_c;
	
	//***
	//Beam to column connection checks
	T = (TF_b + Hc);
	Tb = T/(2*n3);														//Tension per bolt
	R = (R_b + Vb);
	Rb = R/(2*n3);														//Shear per bolt
	
	//Bolt shear strength at clip angle
	Rn_bv = blt.nominalShearStrength(Tb);		
    if (bolt_type == "BEARING")
        Ra_bv = allowableStrength(Rn_bv,phi_bv,omega_bv);				//allowable strength in bolt shear
	else
        Ra_bv = allowableStrength(Rn_bv,phi_sl,omega_sl);
    UR_bv = Rb / Ra_bv;													//interaction ratio in bolt shear
		
	//Bolt bearing at clip angle
	edc_cl = ed3 - dbh/2; 												//clear edge distance
	sbc_c1 = sb - dbh;													//clear spacing b/n bolts
	Rn_bc1 = 1.2*min(edc_cl,sbc_c1)*ta_clip*Fu_a;
	Rn1_bc1 = 2.4*db*ta_clip*Fu_a;
	Rn_bc1 = min(Rn_bc1,Rn1_bc1);										//nominal strength of bearing at bolt hole
	Ra_bc1 = allowableStrength(Rn_bc1,phi_b,omega_b);					//allowable strenght in bolt bearing 
	UR_bc1 = Rb / Ra_bc1;												//interation ratio in bolt bearing at clip 

	//Bolt bearing at column
    if(supp_type == COLUMN_FLANGE)
        t_bco = tf_co;
    else
        t_bco = tw_co;
    lc_bco = (sb-dbh);													//clear distance between the edge of bolt and the edge of adjacent bolt
	Rn_bco = 1.2*lc_bco*t_bco*Fu_c;										//nominal strength of bolt group in bearing
	Rn1_bco = 2.4*db*t_bco*Fu_c;
	Rn_bco = min(Rn_bco,Rn1_bco);
	Ra_bco = allowableStrength(Rn_bco,phi_b,omega_b);
	UR_bco = Rb / Ra_bco;
			
	//Bolt tension strength at clip angle
	Rn_bt = blt.nominalTensionStrength(Rb);
	Ra_bt = allowableStrength(Rn_bt,phi_bt,omega_bt);					//allowable strength
	UR_bt = Tb / Ra_bt;													//interaction ratio in bolt tension

	//Clip angle prying	check
	B = Ra_bt;															//available tension strength per bolt
	a = lo_clip - (gb/2.0 - tw_b/2.0);									//distance of bolt centerline to edge of fitting
	b = (gb - tw_b - ta_clip)/2.0;      								//distance of bolt centerline to centerline of clip angle
	p = min(2*b, b + ed3);												//minimum pitch distance
    p = min(p, sb);
	a1 = a + db/2.0;
	if (a1 > (1.25*b + db/2.0)) 
		a1 = 1.25*b + db/2.0;
	b1 = b-db/2.0;
	rho = b1/a1;
	delta = 1.0 - dbh/p;															
	if (method == LRFD)
		tc = sqrt(4.0*B*b1 / (phi_f*p*Fu_a));							//eqn. 9-30a, AISC Manual
	else
		tc = sqrt(omega_f*4.0*B*b1 / (p*Fu_a));							//eqn. 9-30b, AISC Manual
	tr = tc / ta_clip;
	alpha1 = 1/(delta*(1+rho)) * ((tr*tr) - 1);							//eqn. 9-29, AISC Manual
	if (alpha1 < 0.0)	
		Q = 1;
	else if ((alpha1 >= 0.0) && (alpha1 <= 1.0))
		Q = 1/(tr*tr) * (1 + alpha1*delta);									
	else
        Q = 1/(tr*tr) * (1 + delta);	
    UR_pry = Tb / (B*Q);												//interaction ratio for bolt tension including prying

	//Column flange prying check
	b_co = (gb - tw_co) / 2.0;
	b1_co = b_co - db / 2.0;
	p_eff = ((n3 - 1)*sb + PI*b_co + (bf_co - gb)) / n3;				//effective pitch at column
	delta_co = 1.0 - dbh / p_eff;										//ratio of net length at bolt line to gross length at face of stem
	a_co = min((bf_co - gb) / 2.0, (2*lo_clip +tw_b -gb)/2.0);
	a1_co = min(a_co, 1.25*b_co) + db/2.0;
	rho_co = b1_co / a1_co;
	if (method == LRFD)
		tc_co = sqrt((4.0 * B * b1_co) / (phi_f * p_eff * Fu_c));
	else
		tc_co = sqrt((omega_f * 4.0 *B * b1_co)/(p_eff * Fu_c));
	tr_co = tc_co / tf_co;
	alpha1_co = 1/(delta_co*(1+rho_co)) * (tr_co*tr_co - 1);
	if (alpha1_co < 0.0)	
		Q_co = 1;
	else if ((alpha1_co >= 0) && (alpha1_co <= 1.0))
		Q_co = 1/(tr_co*tr_co) * (1 + alpha1_co*delta_co);
	else
        Q_co = 1/(tr_co*tr_co) * (1 + delta_co);
    UR_pry_co = Tb / (B * Q_co);
	//Weld shear strength
    l_clip_1 = (n3-1)*sb + 2*ed3;																			//clip angle length	
	b_wld_1 = li_clip - c;																					//length of horizontal run of weld
	x_wld_1 = (b_wld_1*b_wld_1) / (2.0*b_wld_1 + l_clip_1);													//cetroid of weld group
	l_wld_1 = 2.0*b_wld_1 + l_clip_1;																		//total weld length
    Ip_1 = (l_wld_1*l_wld_1*l_wld_1)/12.0 - b_wld_1*b_wld_1*(l_clip_1+b_wld_1)*(l_clip_1+b_wld_1)/l_wld_1 ;	//polar moment of inertia of weld group
	ecc_1 = li_clip - x_wld_1;																				//eccentricity of force
	fx_1 = T/(2.0*l_wld_1) + (R*ecc_1)*l_clip_1/(4.0*Ip_1);												    //horizontal component of the stress
	fy_1 = R/(2.0*l_wld_1) + (R*ecc_1)*(b_wld_1 - x_wld_1)/(2.0*Ip_1);									    //vertical component of the stress
	fw_1 = sqrt(fx_1*fx_1 + fy_1*fy_1);																		//maximum stress in weld
	Rn_w_1 = 0.707*w2*0.6*Fu_w;																				//Nominal strength of weld
	Ra_w_1 = allowableStrength(Rn_w_1,phi_w,omega_w);														//allowable strength
	UR_w_1 = fw_1/Ra_w_1;
	
	//Beam web rupture at weld 
	Rn_rbw = 0.6*Fu_bm*tw_b;
	Ra_rbw = allowableStrength(Rn_rbw,phi_r,omega_r);
	UR_rbw = 2*fw_1/Ra_rbw;
	
	//Block shear at clip angle check
	Agv_blc = 2*ta_clip*((n3 - 1)*sb + ed3);
	Anv_blc = Agv_blc - 2*(n3 - 0.5)*dbh*ta_clip;
	Ant_blc = ta_clip*(2*lo_clip + tw_b - gb - dbh);
	Rn_blc = 0.6*Fu_a*Anv_blc + Fu_a*Ant_blc;
	Rn1_blc = 0.6*Fy_a*Agv_blc + Fu_a*Ant_blc;
	Rn_blc = min(Rn_blc, Rn1_blc);
	Ra_blc = allowableStrength(Rn_blc, phi_bl, omega_bl);
	UR_blc = R/Ra_blc;
		
	
	//Shear yielding of clip angle
    l3 = (n3 - 1)*sb + 2*ed3;
	Rn_ycl = 2.0*0.60*Fy_a*ta_clip*l3;									//eqn. J4-3, AISC 360-14
	Ra_ycl = allowableStrength(Rn_ycl, phi_vy, omega_vy);				//allowable strength
	UR_ycl = sqrt(R*R + T*T)/Ra_ycl;									//interaction ratio in clip shear yielding
    
	//Shear rupture of clip angle
	Anet_cl = 2.0*(ta_clip*l3 - n3*dbh*ta_clip);						//net area in shear 
	Rn_rcl = 0.60*Fu_a*Anet_cl;											//eqn. J4-4, AISC 360-14
	Ra_rcl = allowableStrength(Rn_rcl, phi_r, omega_r);					//allowable strength
	UR_rcl = sqrt(R*R + T*T)/Ra_rcl;									//interaction ratio in clip shear rupture

	//Column web yielding check
	l_clip = (n3 - 1)*sb + 2*ed3;	
	Rn_wyc = Fy_c*tw_co*(2.5*k_co + l_clip);							//nominal strength in web yielding
	Ra_wyc = allowableStrength(Rn_wyc, phi_wy, omega_wy);				//allowable strength in web yielding
	UR_wyc = T/Ra_wyc;	
	
	//Column web crippling check
	if (l_clip/d_co <= 0.2)
		Rn_wcc = 0.40*tw_co*tw_co*(1.0 + 3.0*l_clip/d_co*pow(tw_co/tf_co,1.5))*sqrt(E*Fy_c*tf_co/tw_co);
	else
		Rn_wcc = 0.40*tw_co*tw_co*(1.0 + (4.0*l_clip/d_co - 0.2)*pow(tw_co/tf_co,1.5))*sqrt(E*Fy_c*tf_co/tw_co);
	Ra_wcc = allowableStrength(Rn_wcc, phi_wc, omega_wc);				//Allowable strength of column in web crippling
	UR_wcc = T/Ra_wcc;								
	
	//Column web shear check
	Rn_wsc = 0.6*Fy_c*d_co*tw_co;
	Ra_wsc = allowableStrength(Rn_wsc, phi_ws, omega_ws);
	UR_wsc = Hc/Ra_wsc;
	

	//***
	//TODO:Wing plate checks
	
	
	//***
	//Gusset to beam connection checks
	//Weld strength at gusset to beam connection
	Rn_wbm=0.6*Fu_w*0.707*w1;											                                    //nominal weld strength (N/mm)
	Ra_wbm=allowableStrength(Rn_wbm,phi_w,omega_w);						                                    //allowable weld strength
	ft_max_wbm=Vb/(2.0*lgb)+3*Mb/(lgb*lgb);								                                    //maximum stress transverse to the weld
	ft_min_wbm=Vb/(2.0*lgb)-3*Mb/(lgb*lgb);	                                                                //minimum stress transverse to the weld
    fl_wbm=Hb/(2.0*lgb);												                                    //stress logitudinal to the weld
	fw_max_wbm=sqrt(ft_max_wbm*ft_max_wbm+fl_wbm*fl_wbm);					                                //maximum resulting stress in weld
    fw_avg_wbm=0.5*(sqrt(ft_max_wbm*ft_max_wbm+fl_wbm*fl_wbm)+sqrt(ft_min_wbm*ft_min_wbm+fl_wbm*fl_wbm));   //average stress in weld
	fw_wbm=(fw_max_wbm>1.25*fw_avg_wbm)?fw_max_wbm:1.25*fw_avg_wbm;                                         //required strength of weld
    UR_wbm=fw_wbm/Ra_wbm;												                                    //interaction ratio

	//Plate rupture at gusset to beam weld
	tp_min=1.414*Fu_w/Fu_g*w1;											//minimum thickness of plate required to develop strength of weld
	UR_rp=tp_min/tg;													//interaction ratio for plate rupture
	
	//Beam web yielding
	Rn_wyb = (0.25*lgb > d_b)?Fy_bm*tw_b*(5*k_b + lgb):Fy_bm*tw_b*(2.5*k_b + lgb);	//nominal strength in web yielding
	Ra_wyb = allowableStrength(Rn_wyb, phi_wy, omega_wy);				            //allowable strength in web yielding
	R_wyb = 4*Mb/lgb + Vb;												            //required strength
	UR_wy = R_wyb/Ra_wyb;												            //interaction ratio
	//Beam web crippling
	if (0.25*lgb >= 0.5*d_b)
        Rn_wcb = 0.80*tw_b*tw_b*(1.0 + 3.0*lgb/d_b*pow(tw_b/tf_b, 1.5))*sqrt(E*Fy_bm*tf_b/tw_b);
    else if (lgb/d_b <= 0.2)
		Rn_wcb = 0.40*tw_b*tw_b*(1.0 + 3.0*lgb/d_b*pow(tw_b/tf_b, 1.5))*sqrt(E*Fy_bm*tf_b/tw_b);
	else
		Rn_wcb = 0.40*tw_b*tw_b*(1.0 + (4.0*lgb/d_b - 0.2)*pow(tw_b/tf_b, 1.5))*sqrt(E*Fy_bm*tf_b/tw_b);
	Ra_wcb = allowableStrength(Rn_wcb, phi_wc, omega_wc);				//Allowable strength of beam in web crippling
	UR_wcb = R_wyb/Ra_wcb;												//interaction ratio
	
	//Beam web shear check
	Rn_wsb = 0.6*Fy_b*d_b*tw_b;
	Ra_wsb = allowableStrength(Rn_wsb, phi_ws, omega_ws);
	UR_wsb = R_wyb/Ra_wsb;
	
	//***
	//Gusset to column connection checks
	//NOTE: connection forces are Hc and Vc
	T2 = Hc;
	Tb_2 = T2 / (2*n2);													//tension per bolt
	R2 = Vc;
	Rb_2 = R2 / (2*n2);													//shear per bolt

	//Bolt shear strength at gusset to column connection
	Rn_bv_2 = blt.nominalShearStrength(Tb_2);		
    if (bolt_type == "BEARING")
        Ra_bv_2 = allowableStrength(Rn_bv_2,phi_bv,omega_bv);				
	else
       Ra_bv_2 = allowableStrength(Rn_bv_2,phi_sl,omega_sl);			//allowable strength in bolt shear
	UR_bv_2 = Rb_2 / Ra_bv_2;											//interaction ratio in bolt shear

	//Bolt bearing at clip angle
	UR_bcl_2 = Rb_2 / Ra_bc1;											//interaction ratio in bolt bearing at clip 

	//Bolt bearing at column
	UR_bco_2 = Rb_2 / Ra_bco;											//interaction ratio in bolt bearing at column
		
	//Bolt tension strength at clip angle
	Rn_bt_2 = blt.nominalTensionStrength(Rb_2);
	Ra_bt_2 = allowableStrength(Rn_bt_2,phi_bt,omega_bt);				//allowable strength
	UR_bt_2 = Tb_2 / Ra_bt_2;											//interaction ratio in bolt tension

	//Clip angle prying	check
	B_2 = Ra_bt_2;														//available tension strength per bolt
	b_2 = (gb - tg - ta_clip)/2;						    			//distance of bolt centerline to centerline of clip angle
	p_2 = min(2*b_2, b_2+ed3);											//minimum pitch distance
    p_2 = min(p_2, sb);
	a_2 = lo_clip - b_2 - ta_clip/2;									//distance of bolt centerline to edge of fitting
	a1_2 = a_2 + db/2.0;
	if (a1_2 > (1.25*b_2 + db/2.0)) 
		a1_2 = 1.25*b_2 + db/2.0;
	b1_2 = b_2 - db/2.0;
	rho_2 = b1_2 / a1_2;
	delta_2 = 1.0 - dbh/p_2;															
	if (method == LRFD)
		tc_2 = sqrt(4.0*B_2*b1_2 / (phi_f*p_2*Fu_a));					//eqn. 9-30a, AISC Manual
	else
		tc_2 = sqrt(omega_f*4.0*B_2*b1_2 / (p_2*Fu_a));					//eqn. 9-30b, AISC Manual
	tr_2 = tc_2 / ta_clip;
	alpha1_2 = 1/(delta_2*(1+rho_2)) * ((tr_2*tr_2) - 1);				//eqn. 9-29, AISC Manual
	if (alpha1_2 < 0.0)	
		Q_2 = 1;
	else if ((alpha1_2 >= 0) && (alpha1_2 <= 1))
		Q_2 = 1/(tr_2*tr_2) * (1 + alpha1_2*delta_2);	
    else
        Q_2 = 1/(tr_2*tr_2) * (1 + delta_2);	
	UR_pry_2 = Tb_2/(B_2*Q_2);											//interaction ratio for bolt tension including prying
	
	//Column flange prying check
	b_co_2 = b_co;														//distance of bolt centerline to centerline of clip angle
	b1_co_2 = b1_co;
	a_co_2 = min((bf_co - gb) / 2.0, (2*lo_clip + tg - gb)/2.0);		//distance of bolt centerline to edge of fitting
	a1_co_2 = min(a_co_2, 1.25*b_co_2) + db/2.0;
	p_eff_2 = ((n2 - 1)*sb + PI*b_co_2 + (bf_co - gb)) / n2;			//effective pitch at column
	delta_co_2 = 1.0 - dbh / p_eff_2;									//ratio of net length at bolt line to gross length at face of stem
	rho_co_2 = b1_co_2 / a1_co_2;
	if (method == LRFD)
		tc_co_2 = sqrt((4.0 * B_2 * b1_co_2) / (phi_f * p_eff_2 * Fu_c));
	else
		tc_co_2 = sqrt((omega_f * 4.0 *B_2 * b1_co_2)/(p_eff_2 * Fu_c));
    tr_co_2 = tc_co_2 / tf_co;
	alpha1_co_2 = 1/(delta_co_2*(1+rho_co_2)) * (tr_co_2*tr_co_2 - 1);	
	if (alpha1_co_2 < 0.0)	
		Q_co_2 = 1;
	else if ((alpha1_co_2 >= 0.0) && (alpha1_co_2 <= 1.0))
		Q_co_2 = 1/(tr_co_2*tr_co_2) * (1 + alpha1_co_2*delta_co_2);
    else
        Q_co_2 = 1/(tr_co_2*tr_co_2) * (1 + delta_co_2);
	UR_pry_co_2 = Tb_2/(B_2 * Q_co_2);
    
	//Weld shear strength
	l_clip_2 = (n2-1)*sb + 2*ed3;																			//clip angle length	
	b_wld_2 = li_clip - c;																					//length of horizontal run of weld
	x_wld_2 = (b_wld_2*b_wld_2) / (2.0*b_wld_2 + l_clip_2);													//cetroid of weld group
	l_wld_2 = 2.0*b_wld_2 + l_clip_2;																		//total weld length
    Ip_2 = (l_wld_2*l_wld_2*l_wld_2)/12.0 - b_wld_2*b_wld_2*(l_clip_2+b_wld_2)*(l_clip_2+b_wld_2)/l_wld_2 ;	//polar moment of inertia of weld group
	ecc_2 = li_clip-x_wld_2;																				//eccentricity of force
	fx_2 = T2/(2.0*l_wld_2) + (R2*ecc_2)*l_clip_2/(4.0*Ip_2);												//horizontal component of the stress
	fy_2 = R2/(2.0*l_wld_2) + (R2*ecc_2)*(b_wld_2 - x_wld_2)/(2.0*Ip_2);									//vertical component of the stress
	fw_2 = sqrt(fx_2*fx_2 + fy_2*fy_2);																		//maximum stress in weld
	Rn_w_2 = 0.707*w2*0.6*Fu_w;																				//Nominal strength of weld
	Ra_w_2 = allowableStrength(Rn_w_2,phi_w,omega_w);														//allowable strength
	UR_w_2 = fw_2/Ra_w_2;


	//Gusset rupture at weld check
	Rn_rbw_2 = 0.6*Fu_g*tg;
	Ra_rbw_2 = allowableStrength(Rn_rbw_2, phi_r,omega_r);				
	UR_rbw_2 = 2*fw_2/Ra_rbw_2;
    
	//Clip angle block shear check
	Agv_blc_2 = 2*ta_clip*((n2 - 1)*sb + ed3);
	Anv_blc_2 = Agv_blc_2 - 2*(n2 - 0.5)*dbh*ta_clip;
	Ant_blc_2 = ta_clip*(2*lo_clip +tg - gb - dbh);
	Rn_blc_2 = 0.6*Fu_a*Anv_blc_2 + Fu_a*Ant_blc_2;
	Rn1_blc_2 = 0.6*Fy_a*Agv_blc_2 + Fu_a*Ant_blc_2;
	Rn_blc_2 = min(Rn_blc_2, Rn1_blc_2);
	Ra_blc_2 = allowableStrength(Rn_blc_2, phi_bl, omega_bl);
	UR_blc_2 = R2/Ra_blc_2;
	
	//Shear yielding of clip angle
	Rn_ycl_2 = 2.0*0.60*Fy_a*ta_clip*l_clip_2;							//eqn. J4-3, AISC 360-14
	Ra_ycl_2 = allowableStrength(Rn_ycl_2,phi_vy,omega_vy);				//allowable strength
	UR_ycl_2 = sqrt(R2*R2 + T2*T2)/Ra_ycl_2;							//interaction ratio in clip shear yielding

	//Shear rupture of clip angle
	Anet_cl_2 = 2.0 * (ta_clip*l_clip_2 - n2*dbh*ta_clip);				//net area in shear 
	Rn_rcl_2 = 0.60 * Fu_a * Anet_cl_2;									//eqn. J4-4, AISC 360-14
	Ra_rcl_2 = allowableStrength(Rn_rcl_2,phi_r,omega_r);				//allowable strength
	UR_rcl_2 = sqrt(R2*R2 + T2*T2) / Ra_rcl_2;							//interaction ratio in clip shear rupture

	//Column web yielding check (new)
	Rn_wyc_2 = Fy_c*tw_co*(2.5*k_co + l_clip_2);						//nominal strength in web yielding
	Ra_wyc_2 = allowableStrength(Rn_wyc_2, phi_wy, omega_wy);			//allowable strength in web yielding
	UR_wyc_2 = T2/Ra_wyc_2;	

	//Column web crippling check (new)
	if (l_clip_2/d_co <= 0.2)
		Rn_wcc_2 = 0.40*tw_co*tw_co*(1.0 + 3.0*l_clip_2/d_co*pow(tw_co/tf_co,1.5))*sqrt(E*Fy_c*tf_co/tw_co);
	else
		Rn_wcc_2 = 0.40*tw_co*tw_co*(1.0 + (4.0*l_clip_2/d_co - 0.2)*pow(tw_co/tf_co,1.5))*sqrt(E*Fy_c*tf_co/tw_co);
	Ra_wcc_2 = allowableStrength(Rn_wcc_2, phi_wc, omega_wc);			//Allowable strength of column in web crippling
	UR_wcc_2 = T2/Ra_wcc_2;								
	
	//maximum interaction ratio
	UR_max = 0;
	UR_max = UR_rbr > UR_max ? UR_rbr : UR_max;								//Utility ratio for brace rupture
	UR_max = UR_bo > UR_max ? UR_bo : UR_max;								//interaction ratio in bolt shear
	UR_max = UR_bbr > UR_max ? UR_bbr : UR_max;								//interaction ratio in bolt bearing at brace leg
	UR_max = UR_bg > UR_max ? UR_bg : UR_max;								//interaction ratio in bearing at gusset
	UR_max = UR_bl > UR_max ? UR_bl : UR_max;								//interaction ratio in block shear
	if (nr == 2)
		UR_max = UR_bl_g > UR_max ? UR_bl_g : UR_max;						//interaction ratio in block shear
	UR_max = UR_yg > UR_max ? UR_yg : UR_max;								//interaction ratio in tension yielding of gusset
	UR_max = UR_rg > UR_max ? UR_rg : UR_max;								//interaction ratio in tension rupture of gusset   
	UR_max = UR_c > UR_max ? UR_c : UR_max;									//interaction ratio in compression buckling of gusset
	UR_max = UR_bv > UR_max ? UR_bv : UR_max;								//interaction ratio in bolt shear
	UR_max = UR_bc1 > UR_max ? UR_bc1 : UR_max;								//interaction ratio in bolt bearing at clip
	UR_max = UR_bco > UR_max ? UR_bco : UR_max;								//interaction ratio in bolt bearing at column
	UR_max = UR_w_1 > UR_max ? UR_w_1 : UR_max;									//interaction ratio for weld check
	UR_max = UR_rbw > UR_max ? UR_rbw : UR_max;								//interaction ratio for beam rupture at weld
	UR_max = UR_bt > UR_max ? UR_bt : UR_max;								//Interaction ration in bolt tension
	UR_max = UR_pry > UR_max ? UR_pry : UR_max;								//interaction ratio in clip prying
	UR_max = UR_pry_co > UR_max ? UR_pry_co : UR_max;						//interaction ratio in column prying
	UR_max = UR_ycl > UR_max ? UR_ycl : UR_max;								//interaction ratio in clip shear yielding
	UR_max = UR_rcl > UR_max ? UR_rcl : UR_max;								//interaction ratio in clip shear rupture
	UR_max = UR_blc > UR_max ? UR_blc : UR_max;								//interaction ratio in clip block shear
	UR_max = UR_wyc > UR_max ? UR_wyc : UR_max;								//interaction ratio column web yielding
	UR_max = UR_wcc > UR_max ? UR_wcc : UR_max;								//interaction ratio column web crippling
	UR_max = UR_wsc > UR_max ? UR_wsc : UR_max;								//interaction ratio column web shear
	UR_max = UR_wbm > UR_max ? UR_wbm : UR_max;								//interaction ratio weld at gusset to beam connection
	UR_max = UR_rp > UR_max ? UR_rp : UR_max;								//interaction ratio for plate rupture
	UR_max = UR_wy > UR_max ? UR_wy : UR_max;								//interaction ratio in web yielding
	UR_max = UR_wcb > UR_max ? UR_wcb : UR_max;								//interaction ratio in web crippling
	UR_max = UR_wsb > UR_max ? UR_wsb : UR_max;								//interaction ratio in web shear	
	UR_max = UR_bv_2 > UR_max ? UR_bv_2 : UR_max;							//interaction ratio in bolt shear
	UR_max = UR_bcl_2 > UR_max ? UR_bcl_2 : UR_max;							//interaction ratio in bolt bearing at clip
	UR_max = UR_bco_2 > UR_max ? UR_bco_2 : UR_max;							//interaction ratio in bolt bearing at column
	UR_max = UR_bt_2 > UR_max ? UR_bt_2 : UR_max;							//interaction ration in bolt tension
	UR_max = UR_pry_2 > UR_max ? UR_pry_2 : UR_max;							//interaction ratio in clip angle prying
	UR_max = UR_pry_co_2 > UR_max ? UR_pry_co_2 : UR_max;					//interaction ratio for prying at column
	UR_max = UR_w_2 > UR_max ? UR_w_2 : UR_max;								//interaction ratio for weld strength
	UR_max = UR_rbw_2 > UR_max ? UR_rbw_2 : UR_max;							//interaction ratio for gusset rupture at weld
	UR_max = UR_blc_2 > UR_max ? UR_blc_2 : UR_max;							//interaction ratio for block shear at clip
	UR_max = UR_ycl_2 > UR_max ? UR_ycl_2 : UR_max;							//interaction ratio in clip shear yielding
	UR_max = UR_rcl_2 > UR_max ? UR_rcl_2 : UR_max;							//interaction ratio in clip shear rupture
	UR_max = UR_wyc_2 > UR_max ? UR_wyc_2 : UR_max;							//interaction ratio in web yielding
	UR_max = UR_wcc_2 > UR_max ? UR_wcc_2 : UR_max;							//interaction ratio in web crippling

	
	
}

double vbConnection1::allowableStrength(double nominalStrength,double phi,double omega)
{
	if (method==LRFD) 	return nominalStrength*phi;
	else				return nominalStrength/omega;
}
double vbConnection1::min(double a,double b)
{
	if(a<b) return a; 
	else return b;
}


///////////////////OUTPUT FUNCTIONS///////////////////////
bool vbConnection1::pass(){
	if (UR_max > 1)
		return false;
	else 
		return true;
}

std::string vbConnection1::designInput(){
	std::string o ="";
	_h1("Design Input");
	_p(method==LRFD?"LRFD":"ASD","Design method");
	_p(P_br,"Brace axial force (P)","",_force);
	_p(R_b, "Shear force in beam (Rb)","",_force);
	_p(TF_b, "Transfer force in connection (Tf)","",_force);
	_br;
	_p(brace.getGrade(),"Angle steel grade");
	_p(Fy_a,"Yield strength of angle section","",_stress);
	_p(Fu_a,"Tensile strength of angle section","",_stress);
	_br;
	_p(beam.getGrade(),"Beam steel grade");
	_p(Fy_bm, "Yield strength of beam section","",_stress);
	_p(Fu_bm,"Tensile strength of beam section","",_stress);
	_br;
	_p(column.getGrade(),"Column steel grade");
	_p(Fy_c, "Yield strength of column section","",_stress);
	_p(Fu_c, "Tensile strength of column section","",_stress);
	_br;
	_p(gusset.getGrade(),"Plate steel grade");
	_p(Fy_g,"Yield strength of plate","",_stress);
	_p(Fu_g,"Tensile strength of plate","",_stress);
	_br;
	_p(blt.boltGrade(),"Bolt grade");
	_p(blt.boltType() == bolt::BEARING?"Bearing":"Friction","Bolt type");
	if (blt.boltType() == bolt::BEARING)
		_p(blt.boltThreadInShearPlane()?"Yes":"No","Bolt thread in shear plane");
	_p(blt.diameter(),"Bolt diameter","",_length);
	_p(gb, "Bolt gage","",_length);
	_p(sb, "Bolt spacing","",_length);
	_p(ed1, "Bolt edge distance to brace edge","",_length);
	_p(ed2, "Bolt edge distance to gusset edge","",_length);
	_p(ed3, "Bolt edge distance to clip angle edge","",_length);
	_br;
	_p(wld.getGrade(),"Weld electrode");
	_p(wld.tensileStrength(),"Weld tensile strength","",_stress);
	_br;
	_p(brace.getSection(),"Brace section");
	_p(theta,"Brace angle with beam","","deg");
	_p(tg, "Gusset plate thickness (tg)","",_length);
	_p(w1, "Gusset to beam weld thickness","",_length);
	_p(lgb, "Gusset length at connection to beam","",_length);
	_p(nb, "Number of bolts per row at brace (nb)","","","",0);
	_p(nr, "Number of bolt rows at brace","","","",0);
	_p(clip2.getSection(),"Clip angle section");
	_p(n3, "Number of bolts at beam to column connection (n1)","","","",0);
	_p(n2, "Number of bolts at gusset to column connection (n2)","","","",0);
	_p(w2, "Weld thickness at clip angle","",_length);
	_p(beam.getSection(),"Beam section property");
	_p(d_b, "   Depth","",_length);
	_p(bf_b,"   Flange width","",_length);
	_p(tw_b,"   Web thickness","",_length);
	_p(tf_b,"   Flange thickness","",_length);
	_p(column.getSection(),"Column section property");
	_p(d_co, "   Depth","",_length);
	_p(bf_co,"   Flange width","",_length);
	_p(tw_co,"   Web thickness","",_length);
	_p(tf_co,"   Flange thickness","",_length);	
	return o;
}
std::string vbConnection1::designSummary(){
	std::string o ="";
	if (UR_rbr > 1) _p("","Fails in brace rupture");
	if (UR_bo > 1) _p("","Fails in bolt shear at brace");
	if (UR_bbr > 1) _p("","Fails in bolt bearing at brace");
	if (UR_bg > 1) _p("","Fails in bolt bearing at gusset");
	if (UR_bl > 1) _p("","Fails in brace block shear");
	if (nr == 2)
		if (UR_bl_g > 1) _p("","Fails in gusset plate block shear");
	if (UR_yg > 1) _p("","Fails in gusset tension yielding");
	if (UR_rg > 1) _p("","Fails in gusset tension rupture");    
	if (UR_c > 1) _p("","Fails in gusset plate compression buckling");
	if (UR_bv > 1) _p("","Fails in bolt shear at beam to column connection");
	if (UR_bc1 > 1) _p("","Fails in bolt bearing on clip at beam to column connection");
	if (UR_bco > 1) _p("","Fails in bolt bearing on flange at beam to column connection");
	if (UR_w_1 > 1) _p("","Fails in weld at beam to column connection");
	if (UR_rbw > 1) _p("","Fails in web rupture at beam to column connection weld");
	if (UR_bt > 1) _p("","Fails in bolt tension at beam to column connection");
	if (UR_pry > 1) _p("","Fails in clip angle prying at beam to column connection");	
	if (UR_ycl > 1) _p("","Fails in clip shear yielding at beam to column connection");
	if (UR_rcl > 1) _p("","Fails in clip shear rupture at beam to column connection");
	if (UR_blc > 1) _p("","Fails in clip block shear at beam to column connection");
	if (supp_type == COLUMN_FLANGE){
		if (UR_pry_co > 1) _p("","Fails in flange prying at beam to column connection");	
		if (UR_wyc > 1) _p("","Fails in column web yielding at beam to column connection");
		if (UR_wcc > 1) _p("","Fails in column web crippling at beam to column connection");
		if (UR_wsc > 1) _p("","Fails in column web shear at beam to column connection");
	}
	if (UR_wbm > 1) _p("","Fails in weld at gusset to beam connection");
	if (UR_rp > 1) _p("","Fails in gusset rupture at gusset to beam connection");
	if (UR_wy > 1) _p("","Fails in local web yiedling at gusset to beam connection");
	if (UR_wcb > 1) _p("","Fails in local web crippling at gusset to beam connection");
	if (UR_wsb > 1) _p("","Fails in web shear at gusset to beam connection");
	if (UR_bv_2 > 1) _p("","Fails in bolt shear at gusset to column connection");
	if (UR_bcl_2 > 1) _p("","Fails in bolt bearing on clip at gusset to column connection");
	if (UR_bco_2 > 1) _p("","Fails in bolt bearing on column at gusset to column connection");
	if (UR_bt_2 > 1) _p("","Fails in bolt tension at gusset to column connection");
	if (UR_pry_2 > 1) _p("","Fails in clip angle prying at gusset to column connection");
	
	if (UR_w_2 > 1) _p("","Fails in weld at gusset to column connection");
	if (UR_rbw_2 > 1) _p("","Fails in gusset rupture at gusset to column connection weld");
	if (UR_blc_2 > 1) _p("","Fails in block shear at gusset to column connection clip");
	if (UR_ycl_2 > 1) _p("","Fails in clip shear yielding at gusset to column connection");
	if (UR_rcl_2 > 1) _p("","Fails in clip shear rupture at gusset to column connection");
	if (supp_type == COLUMN_FLANGE){
		if (UR_pry_co_2 > 1) _p("","Fails in flange prying at gusset to column connection");
		if (UR_wyc_2 > 1) _p("","Fails in column web yielding at gusset to column connection");
		if (UR_wcc_2 > 1) _p("","Fails in column web crippling at gusset to column connection");
	}
	o = oso::format_p(UR_max,"Maximum interaction ratio") + o;
	if (UR_max > 1)
		o = oso::format_p("","Connection is NOT OK") + o;
	else 
		o = oso::format_p("","Connection is OK") + o;
	
	o = oso::format_h1("Design Summary") + o;
	
	return o;
}
std::string vbConnection1::designCalculation(){
	std::string o ="";
	_h1("Design Calculation");
	
	_h3("Bolt shear check at brace");
        _p(Pb_br, "Shear per bolt (Pb)","",_force);
		_p(Rn_bo, "Nominal bolt shear strength (Rn)","",_force);
		if (method == LRFD){
            if (bolt_type == "BEARING")
                _p(phi_bv, "LRFD factor in bolt shear (phi)");
            else
                _p(phi_sl, "LRFD factor in bolt slip (phi)");
			_p(Ra_bo, "Allowable strength of bolt in shear","Ra=Rn*phi",_force);
		}else{
            if (bolt_type == "BEARING")
                _p(omega_bv, "ASD factor in bolt shear (omega)");
            else
                _p(omega_sl, "ASD factor in bolt slip (omega)");
			_p(Ra_bo, "Allowable strength of bolt in shear","Ra=Rn/omega",_force);
		}
		_p(UR_bo, "Interaction ratio for bolt shear","Pb/Ra","");
	
	_h3("Bolt bearing at brace check");
		_p(Rn_bbr, "Nominal strength of bolt bearing at brace (Rn)","",_force);
		if (method == LRFD){
			_p(phi_b, "LRFD factor in bolt bearing (phi)");
			_p(Ra_bbr, "Allowable strength of bolt bearing at brace","Ra=Rn*phi",_force);
		}else{
			_p(omega_b, "ASD factor in bolt bearing (omega)");
			_p(Ra_bbr, "Allowable strength of bolt bearing at brace","Ra=Rn/omega",_force);
		}
		_p(UR_bbr, "Interaction ratio for bolt bearing at brace","Pb/2*Ra","");

	_h3("Bolt bearing at gusset check");
		_p(Rn_bg, "Nominal strength in bolt bearing at gusset (Rn)","",_force);	
		if (method == LRFD){
			_p(phi_b, "LRFD factor in bolt bearing (phi)");
			_p(Ra_bg, "Allowable strength of bolt bearing at gusset","Ra=Rn*phi",_force);
		}else{
			_p(omega_b, "ASD factor in bolt bearing (omega)");
			_p(Ra_bg, "Allowable strength of bolt bearing at gusset","Ra=Rn/omega",_force);
		}
		_p(UR_bg, "Interaction ratio for bolt bearing at gusset","Pb/Ra","");

	_h3("Brace rupture check");
		_p(An_br,"Net cross-section area of brace (An)","",_area);
		_p(U,"Shear lag factor (U)","","");
		_p(Ae_br, "Effective cross-section area for tension rupture","Ae=U*An",_area);
		_p(Pn_rbr, "Nominal strength of brace in tension rupture (Pn)","",_force);
		if (method == LRFD){
			_p(phi_r, "LRFD factor in tension rupture (phi)","","");
			_p(Pa_rbr, "Allowable strength of brace in tension rupture","Pa=Pn*phi",_force);
		}else{
			_p(omega_r, "ASD factor in tension rupture (omega)");
			_p(Pa_rbr, "Allowable strength of brace in tension rupture","Pa=Pn/omega",_force);		
		}
		_p(UR_rbr, "Interaction ratio in brace rupture","P/Pa","");

	_h3("Block shear at brace check");
		_p(Agv, "Gross area in shear","",_area);
		_p(Anv, "Net area in shear","",_area);
		_p(Ant, "Net area in tension","",_area);
		_p(Rn_bl, "Nominal strength in block shear at brace (Rn)","",_force);
		if (method == LRFD){
			_p(phi_bl, "LRFD factor in block shear (phi)");
			_p(Ra_bl, "Allowable strength in block shear at brace","Ra=Rn*phi",_force);
		}else{
			_p(omega_bl, "ASD factor in bolt bearing (omega)");
			_p(Ra_bl, "Allowable strength in block shear at brace","Ra=Rn/omega",_force);
		}
		_p(UR_bl, "Interaction ratio in block shear at brace","P/Ra","");

	_h3("Gusset tension yielding check");
		_p(lgw, "Length of Whitmore section","",_length);
		_p(Agw, "Gross area of gusset in tension","",_area);
		_p(Pn_yg, "Nominal strength of gusset in tension yielding (Pn)","",_force);
		if (method == LRFD){
			_p(phi_y, "LRFD factor in tension yielding (phi)");
			_p(Pa_yg, "Allowable strength of gusset in tension yielding","Pa=Pn*phi",_force);
		}else{
			_p(omega_y, "ASD factor in tension yielding (omega)");
			_p(Pa_yg, "Allowable strength of gusset in tension yielding","Ra=Rn/omega",_force);
		}
		_p(UR_yg, "Interaction ratio in tension yielding of gusset","P/Pa","");

	_h3("Gusset tension rupture check");
		_p(Anw, "Net area of gusset in tension","",_area);
		_p(Pn_rg, "Nominal strength of gusset in tension rupture (Pn)","",_force);
		if (method == LRFD){
			_p(phi_r, "LRFD factor in tension rupture (phi)");
			_p(Pa_rg, "Allowable strength of gusset in tension rupture","Pa=Pn*phi",_force);
		}else{
			_p(omega_r, "ASD factor in tension rupture (omega)");
			_p(Pa_rg, "Allowable strength of gusset in tension rupture","Ra=Rn/omega",_force);
		}
		_p(UR_rg, "Interaction ratio in tension rupture of gusset","P/Pa","");
		
	_h3("Gusset compression buckling check");
		_p(lb_1,"Buckling lenght at connection centerline (l1)","",_length);
		_p(lb_2,"Buckling lenght at top most point of whitmore section (l2)","",_length);
		_p(lb_3,"Buckling length at bottom most point of whitmore section (l3)","",_length);
		_p(lb_avg,"Average buckling length of gusset plate","lb=(l1+l2+l3)/3",_length);
		_p(Pn_c,"Nominal strength of gusset plate in compression (Pn)","",_force);
		if (method == LRFD){
			_p(phi_c, "LRFD factor in compression (phi)");
			_p(Pa_c, "Allowable strength of gusset in compression","Pa=Pn*phi",_force);		
		}else{
			_p(omega_c, "ASD factor in compression (omega)");
			_p(Pa_c, "Allowable strength of gusset in compression","Pa=Pn/omega",_force);			
		}
		_p(UR_c, "Interaction ratio in compression of gusset","P/Pa","");

	if (nr == 2){
		_h3("Block shear at gusset check");
		_p(Agv_g, "Gross area in shear","",_area);
		_p(Anv_g, "Net area in shear","",_area);
		_p(Ant_g, "Net area in tension","",_area);
		_p(Rn_bl_g, "Nominal strength in block shear at brace (Rn)","",_force);
		if (method == LRFD){
			_p(phi_bl, "LRFD factor in block shear (phi)");
			_p(Ra_bl_g, "Allowable strength in block shear at brace","Ra=Rn*phi",_force);
		}else{
			_p(omega_bl, "ASD factor in bolt bearing (omega)");
			_p(Ra_bl_g, "Allowable strength in block shear at brace","Ra=Rn/omega",_force);
		}
		_p(UR_bl_g, "Interaction ratio in block shear at brace","P/Ra","");				
	}
	
	_h2("UFM forces at gusset interface");
		_p(Hc,"Horizontal force at gusset to column interface (Hc)","",_force);
		_p(Vc,"Vertical force at gusset to column interface (Vc)","",_force);
		_p(Hb,"Horizontal force at gusset to beam interface (Hb)","",_force);
		_p(Vb,"Vertical force at gusset to beam interface (Vb)","",_force);
		_p(Mb,"Moment at gusset to beam interface (Mb)","",us.momentUnit());
	
	//***
	_h2("Gusset to beam connection checks");
	
	_h3("Gusset to beam weld check");
		_p(fw_wbm, "Required strength of weld (fw)","",_force + "/" + _length);
		_p(Rn_wbm, "Nominal strength of weld (fn)","",_force + "/" + _length);
		if (method == LRFD){
			_p(phi_w, "LRFD factor for weld strength (phi)");
			_p(Ra_wbm, "Allowable strength of weld","fa=fn*phi",_force + "/" + _length);
		}else{
			_p(omega_w, "ASD factor for weld strength (omega)");
			_p(Ra_wbm, "Allowable strength of weld","fa=fn/omega",_force + "/" + _length);			
		}
		_p(UR_wbm, "Interaction ratio for weld","fw/fa","");

	_h3("Rupture of gusset at weld check");
		_p(tp_min, "Minimum thickness of plate required for rupture (tg`)","",_length);
		_p(UR_rp, "Interaction ratio for gusset rupture at weld","tg`/tg");

	_h3("Beam web yielding check");
		_p(Rn_wyb, "Nominal strength in web yielding (Rn)","",_force);
		if (method == LRFD){
			_p(phi_wy, "LRFD factor in web yielding (phi)");
			_p(Ra_wyb, "Allowable strength in web yielding","Ra=Rn*phi",_force);
		}else{
			_p(omega_wy, "ASD factor in web yielding (omega)");
			_p(Ra_wyb, "Allowable strength in web yielding","Ra=Rn/omega",_force);			
		}		
		_p(UR_wy, "Interaction ratio for web yielding","(Vb+4*Mb/lg)/Ra");

	_h3("Beam web crippling check");
		_p(Rn_wcb, "Nominal strength of beam in web crippling (Rn)","",_force);
		if (method == LRFD){
			_p(phi_wc,"LRFD factor for web crippling (phi)");
			_p(Ra_wcb, "Allowable strength of beam in web crippling","Ra=Rn*phi",_force);
		}else{
			_p(omega_wc,"ASD factor for web crippling (omega)");
			_p(Ra_wcb, "Allowable strength of beam in web crippling","Ra=Rn/omega",_force);
		
		}
		_p(UR_wcb, "Interaction ratio in web crippling","(Vb+4*Mb/lg)/Ra");

	//***
	_h2("Gusset to column connection checks");
		_p(Tb_2, "Tension per bolt (without prying)","T2=Hc/(2*n2)",_force);
		_p(Rb_2, "Shear force per bolt","R2=Vc/(2*n2)",_force);
	
	_h3("Bolt shear check");
		_p(Rn_bv_2, "Nominal strength of bolt in shear (Rn)","",_force);
		if (method == LRFD){
            if (bolt_type == "BEARING")
                _p(phi_bv,"LRFD factor in bolt shear (phi)");
            else
                _p(phi_sl,"LRFD factor in bolt slip (phi)");
			_p(Ra_bv_2,"Allowable strength of bolt in shear","Ra=Rn*phi",_force);
		}else{
            if (bolt_type == "BEARING")
                _p(omega_bv,"ASD factor in bolt shear (omega)");
            else
                 _p(omega_sl,"ASD factor in bolt slip (omega)");
			_p(Ra_bv_2,"Allowable strength of bolt in shear","Ra=Rn/omega",_force);
		}
		_p(UR_bv_2,"Interaction ratio in bolt shear","R2/Ra");

		
	_h3("Bolt bearing at clip angle check");
		_p(Rn_bc1,"Nominal strength in bolt bearing at clip angle (Rn)","",_force);
		if (method == LRFD){
			_p(phi_b,"LRFD factor in bolt bearing (phi)");
			_p(Ra_bc1,"Allowable strength in bolt bearing at clip angle","Ra=Rn*phi",_force);
		}else{
			_p(phi_b,"ASD factor in bolt bearing (omega)");
			_p(Ra_bc1,"Allowable strength in bolt bearing at clip angle","Ra=Rn/omega",_force);
		}
		_p(UR_bcl_2, "Interaction ratio in bolt bearing at clip angle","R2/Ra");

	_h3("Bolt bearing at column check");
		_p(Rn_bco , "Nominal strength in bolt bearing at column (Rn)","",_force);
		if (method == LRFD){
			_p(phi_b,"LRFD factor in bolt bearing (phi)");
			_p(Ra_bco, "Allowable strength in bolt bearing at column","Ra=Rn*phi",_force);
		}else{
			_p(omega_b,"ASD factor in bolt bearing (omega)");
			_p(Ra_bco, "Allowable strength in bolt bearing at column","Ra=Rn/omega",_force);
		}
		_p(UR_bco_2, "Interaction ratio in bolt bearing at column","R2/Ra");
		

	_h3("Clip angle shear yielding check");
		_p(Rn_ycl_2, "Nominal shear yieldind strength of clip angle (Rn)","",_force);
		if (method == LRFD){
			_p(phi_vy, "LRFD factor in shear yielding (phi)");
			_p(Ra_ycl_2, "Allowable shear yield strength of clip angle","Ra=Rn*phi",_force);
		}else{
			_p(omega_vy, "ASD factor in shear yielding (omega)");
			_p(Ra_ycl_2, "Allowable shear yield strength of clip angle","Ra=Rn/omega",_force);
		}
		_p(UR_ycl_2, "Interaction ratio in clip shear yielding","sqrt(Hc^2+Vc^2)/Ra");

	_h3("Clip angle shear rupture check");
		_p(Rn_rcl_2, "Nominal shear rupture strength of clip angle (Rn)","",_force);
		if (method == LRFD){
			_p(phi_r, "LRFD factor in shear rupture (phi)");			
			_p(Ra_rcl_2, "Allowable shear rupture strength of clip angle","Ra=Rn*phi",_force);
		}else{
			_p(omega_r, "ASD factor in shear yielding (omega)");
			_p(Ra_rcl_2, "Allowable shear rupture strength of clip angle","Ra=Rn/omega",_force);			
		}
		_p(UR_rcl_2,"Interaction ratio in clip shear rupture","sqrt(Hc^2+Vc^2)/Ra");

    _h3("Block shear at clip angle check");
		_p(Agv_blc_2, "Gross area in shear","",_area);
		_p(Anv_blc_2, "Net area in shear","",_area);
		_p(Ant_blc_2, "Net area in tension","",_area);
		_p(Rn_blc_2, "Nominal strength in block shear at clip angle (Rn)","",_force);
		if (method == LRFD){
			_p(phi_bl, "LRFD factor in block shear (phi)");
			_p(Ra_blc_2, "Allowable strength in block shear at clip angle","Ra=Rn*phi",_force);
		}else{
			_p(omega_bl, "ASD factor in bolt bearing (omega)");
			_p(Ra_blc_2, "Allowable strength in block shear at clip angle","Ra=Rn/omega",_force);
		}
		_p(UR_blc_2, "Interaction ratio in block shear at clip angle","Vc/Ra","");
	
    
	_h3("Bolt tension check (without prying)");
		_p(Rn_bt_2, "Nominal strength of bolt in tension (Rn)","",_force);
		if (method == LRFD){
			_p(phi_bt,"LRFD factor in bolt tension (phi)");
			_p(Ra_bt_2,"Allowable strength of bolt in tension","B=Rn*phi",_force);
		}else{
			_p(omega_bt,"ASD factor in bolt tension (omega)");
			_p(Ra_bt_2,"Allowable strength of bolt in tension","B=Rn/omega",_force);		
		}
		_p(UR_bt_2,"Interaction ratio in bolt tension","T2/B");
        
	_h3("Clip angle prying action check");
		_p(Q_2,"Bolt strength reduction factor due to clip prying (Q)");
		_p(UR_pry_2, "Interaction ratio in clip prying","T2/(Q*B)","");

	if (supp_type == COLUMN_FLANGE){
		_h3("Column flange prying action check");
			_p(Q_co_2,"Bolt strength reduction factor due to column flange prying (Q)");
			_p(UR_pry_co_2, "Interaction ratio in column flange prying","T2/(Q*B)","");
    }
    
	_h3("Weld check");
		_p(Ip_2, "Polar moment of inertia of weld group","",_length + "^3");
		_p(fw_2, "Maximum stress in weld (fw)","",_force + "/" +_length);
		_p(Rn_w_2, "Nominal strength of weld (fn)","",_force + "/" + _length);
		if (method == LRFD){
			_p(phi_w, "LRFD factor for weld strength (phi)");
			_p(Ra_w_2, "Allowable strength of weld","fa=fn*phi",_force + "/" + _length);
		}else{
			_p(omega_w, "ASD factor for weld strength (omega)");
			_p(Ra_w_2, "Allowable strength of weld","fa=fn/omega",_force + "/" + _length);		
		}
		_p(UR_w_2, "Interaction ratio in weld strength","fw/fa");

	_h3("Gusset rupture at weld check");
		_p(Rn_rbw_2, "Nominal strength of gusset in rupture at weld (fn)","",_force + "/" + _length);
		if (method == LRFD){
			_p(phi_r, "LRFD factor for rupture (phi)");
			_p(Ra_rbw_2, "Allowable strength of gusset in rupture at weld","fa=fn*phi",_force + "/" + _length);
		}else{
			_p(omega_r, "ASD factor for rupture (omega)");
			_p(Ra_rbw_2, "Allowable strength of gusset in rupture at weld","fa=fn/omega",_force + "/" + _length);		
		}
		_p(UR_rbw_2, "Interaction ratio in gusset rupture at weld","2*fw/fa");		

	
	if (supp_type == COLUMN_FLANGE){

		_h3("Column web yielding check");
			_p(Rn_wyc_2,"Nominal strength of column web yielding (Rn)","",_force);
			if (method == LRFD){
				_p(phi_wy, "LRFD factor in web yielding (phi)");			
				_p(Ra_wyc_2, "Allowable strength of column in web yielding","Ra=Rn*phi",_force);
			}else{
				_p(omega_wy, "ASD factor in web yielding (omega)");
				_p(Ra_wyc_2, "Allowable strength of column in web yielding","Ra=Rn/omega",_force);
			}
			_p(UR_wyc_2,"Interaction ratio in column web yielding","Hc/Ra");
			
		_h3("Column web crippling check");
			_p(Rn_wcc_2,"Nominal strength of column in web crippling (Rn)","",_force);
			if (method == LRFD){
				_p(phi_wc, "LRFD factor in web crippling (phi)");			
				_p(Ra_wcc_2, "Allowable strength of column in web crippling","Ra=Rn*phi",_force);
			}else{
				_p(omega_wc, "ASD factor in web crippling (omega)");
				_p(Ra_wcc_2, "Allowable strength of column in web crippling","Ra=Rn/omega",_force);
			}
			_p(UR_wcc_2,"Interaction ratio in column web crippling","Hc/Ra");
	}
	//***
	_h2("Beam to column connection checks");
		_p(Tb, "Tension per bolt (without prying)","T1=(Tf+Hc)/(2*n1)",_force);
		_p(Rb, "Shear force per bolt","R1=(Rb+Vb)/(2*n1)",_force);
	
	_h3("Bolt shear check");
		_p(Rn_bv, "Nominal strength of bolt in shear (Rn)","","N");
		if (method == LRFD){
            if (bolt_type == "BEARING")
                _p(phi_bv,"LRFD factor in bolt shear (phi)");
            else
                _p(phi_sl,"LRFD factor in bolt slip (phi)");
			_p(Ra_bv,"Allowable strength of bolt in shear","Ra=Rn*phi",_force);
		}else{
            if (bolt_type == "BEARING")
                _p(omega_bv,"ASD factor in bolt shear (omega)");
            else
                _p(omega_sl,"ASD factor in bolt slip (omega)");
			_p(Ra_bv,"Allowable strength of bolt in shear","Ra=Rn/omega",_force);
		}
		_p(UR_bv,"Interaction ratio in bolt shear","R1/Ra");

		
	_h3("Bolt bearing at clip angle check");
		_p(Rn_bc1,"Nominal strength in bolt bearing at clip angle (Rn)","",_force);
		if (method == LRFD){
			_p(phi_b,"LRFD factor in bolt bearing (phi)");
			_p(Ra_bc1,"Allowable strength in bolt bearing at clip angle","Ra=Rn*phi",_force);
		}else{
			_p(phi_b,"ASD factor in bolt bearing (omega)");
			_p(Ra_bc1,"Allowable strength in bolt bearing at clip angle","Ra=Rn/omega",_force);
		}
		_p(UR_bc1, "Interaction ratio in bolt bearing at clip angle","R1/Ra");

	_h3("Bolt bearing at column check");
		_p(Rn_bco , "Nominal strength in bolt bearing at column (Rn)","",_force);
		if (method == LRFD){
			_p(phi_b,"LRFD factor in bolt bearing (phi)");
			_p(Ra_bco, "Allowable strength in bolt bearing at column","Ra=Rn*phi",_force);
		}else{
			_p(omega_b,"ASD factor in bolt bearing (omega)");
			_p(Ra_bco, "Allowable strength in bolt bearing at column","Ra=Rn/omega",_force);
		}
		_p(UR_bco, "Interaction ratio in bolt bearing at column","R1/Ra");
		
	_h3("Clip angle shear yielding check");
		_p(Rn_ycl, "Nominal shear yieldind strength of clip angle (Rn)","",_force);
		if (method == LRFD){
			_p(phi_vy, "LRFD factor in shear yielding (phi)");
			_p(Ra_ycl, "Allowable shear yield strength of clip angle","Ra=Rn*phi",_force);
		}else{
			_p(omega_vy, "ASD factor in shear yielding (omega)");
			_p(Ra_ycl, "Allowable shear yield strength of clip angle","Ra=Rn/omega",_force);
		}
		_p(UR_ycl, "Interaction ratio in clip shear yielding","sqrt((Hc+Tf)^2+(Vb+Rb)^2)/Ra");

	_h3("Clip angle shear rupture check");
		_p(Rn_rcl, "Nominal shear rupture strength of clip angle (Rn)","",_force);
		if (method == LRFD){
			_p(phi_r, "LRFD factor in shear rupture (phi)");			
			_p(Ra_rcl, "Allowable shear rupture strength of clip angle","Ra=Rn*phi",_force);
		}else{
			_p(omega_r, "ASD factor in shear yielding (omega)");
			_p(Ra_rcl, "Allowable shear rupture strength of clip angle","Ra=Rn/omega",_force);			
		}
		_p(UR_rcl,"Interaction ratio in clip shear rupture","sqrt((Hc+Tf)^2+(Vb+Rb)^2)/Ra");

	_h3("Block shear at clip angle check");
		_p(Agv_blc, "Gross area in shear","",_area);
		_p(Anv_blc, "Net area in shear","",_area);
		_p(Ant_blc, "Net area in tension","",_area);
		_p(Rn_blc, "Nominal strength in block shear at clip angle (Rn)","",_force);
		if (method == LRFD){
			_p(phi_bl, "LRFD factor in block shear (phi)");
			_p(Ra_blc, "Allowable strength in block shear at clip angle","Ra=Rn*phi",_force);
		}else{
			_p(omega_bl, "ASD factor in bolt bearing (omega)");
			_p(Ra_blc, "Allowable strength in block shear at clip angle","Ra=Rn/omega",_force);
		}
		_p(UR_blc, "Interaction ratio in block shear at clip angle","(Rb+Vb)/Ra","");
        
	_h3("Bolt tension check (without prying)");
		_p(Rn_bt, "Nominal strength of bolt in tension (Rn)","",_force);
		if (method == LRFD){
			_p(phi_bt,"LRFD factor in bolt tension (phi)");
			_p(Ra_bt,"Allowable strength of bolt in tension","B=Rn*phi",_force);
		}else{
			_p(omega_bt,"ASD factor in bolt tension (omega)");
			_p(Ra_bt,"Allowable strength of bolt in tension","B=Rn/omega",_force);		
		}
		_p(UR_bt,"Interaction ratio in bolt tension","T1/B");

	_h3("Clip angle prying action check");
		_p(Q,"Bolt strength reduction factor due to clip prying (Q)");
		_p(UR_pry, "Interaction ratio in clip prying","T1/(Q*B)","");

	if (supp_type == COLUMN_FLANGE){
		_h3("Column flange prying action check");
			_p(Q_co,"Bolt strength reduction factor due to column flange prying (Q)");
			_p(UR_pry_co, "Interaction ratio in column flange prying","T1/(Q*B)","");
    }

	_h3("Weld check");
		_p(Ip_1, "Polar moment of inertia of weld group","",_length + "^3");
		_p(fw_1, "Maximum stress in weld (fw)","",_force + "/" +_length);
		_p(Rn_w_1, "Nominal strength of weld (fn)","",_force + "/" + _length);
		if (method == LRFD){
			_p(phi_w, "LRFD factor for weld strength (phi)");
			_p(Ra_w_1, "Allowable strength of weld","fa=fn*phi",_force + "/" + _length);
		}else{
			_p(omega_w, "ASD factor for weld strength (omega)");
			_p(Ra_w_1, "Allowable strength of weld","fa=fn/omega",_force + "/" + _length);		
		}
		_p(UR_w_1, "Interaction ratio in weld strength","fw/fa");

	_h3("Beam rupture at weld check");
		_p(Rn_rbw,"Nominal strength of beam web in rupture at weld (fn)","",_force + "/" + _length);
		if (method == LRFD){
			_p(phi_r, "LRFD factor for rupture (phi)");
			_p(Ra_rbw, "Allowable strength of beam web in rupture at weld","fa=fn*phi",_force + "/" + _length);
		}else{
			_p(omega_r, "ASD factor for rupture (omega)");
			_p(Ra_rbw, "Allowable strength of beam web in rupture at weld","fa=fn/omega",_force + "/" + _length);
		}
		_p(UR_rbw, "Interaction ratio in rupture of beam web at weld","2*fw/fa");		
		

	if (supp_type == COLUMN_FLANGE){

		_h3("Column web yielding check");
			_p(Rn_wyc,"Nominal strength of column web yielding (Rn)","",_force);
			if (method == LRFD){
				_p(phi_wy, "LRFD factor in web yielding (phi)");			
				_p(Ra_wyc, "Allowable strength of column in web yielding","Ra=Rn*phi",_force);
			}else{
				_p(omega_wy, "ASD factor in web yielding (omega)");
				_p(Ra_wyc, "Allowable strength of column in web yielding","Ra=Rn/omega",_force);
			}
			_p(UR_wyc,"Interaction ratio in column web yielding","(Hc+Tf)/Ra");
			
		_h3("Column web crippling check");
			_p(Rn_wcc,"Nominal strength of column in web crippling (Rn)","",_force);
			if (method == LRFD){
				_p(phi_wc, "LRFD factor in web crippling (phi)");			
				_p(Ra_wcc, "Allowable strength of column in web crippling","Ra=Rn*phi",_force);
			}else{
				_p(omega_wc, "ASD factor in web crippling (omega)");
				_p(Ra_wcc, "Allowable strength of column in web crippling","Ra=Rn/omega",_force);
			}
			_p(UR_wcc,"Interaction ratio in column web crippling","(Hc+Tf)/Ra");
	}
	

	
	return o;
}

#endif






