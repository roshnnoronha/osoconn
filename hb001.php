<?php
require_once 'common.php';
session_start();
$outputString = "";
if (isset($_POST['run'])){
	$_SESSION['units'] = $_POST['units'];
	$_SESSION['method'] = $_POST['method'];
	$_SESSION['bolt_dia'] = $_POST['bolt_dia'];
	$_SESSION['bolt_type'] = $_POST['bolt_type'];
	$_SESSION['angle_grade'] = $_POST['angle_grade'];
	$_SESSION['beam_grade'] = $_POST['beam_grade'];
	$_SESSION['plate_grade'] = $_POST['plate_grade'];
	$_SESSION['weld_grade'] = $_POST['weld_grade'];
	$_SESSION['bolt_grade'] = $_POST['bolt_grade'];
	$_SESSION['brace_force'] = $_POST['brace_force'];
	$_SESSION['conn_type_1'] = $_POST['conn_type_1'];
	$_SESSION['conn_type_2'] = $_POST['conn_type_2'];
	$_SESSION['beam_section_1'] = $_POST['beam_section_1'];
	$_SESSION['beam_section_2'] = $_POST['beam_section_2'];
	$_SESSION['brace_angle'] = $_POST['brace_angle'];
	$_SESSION['brace_section'] = $_POST['brace_section'];
	$_SESSION['brace_orientation'] = $_POST['brace_orientation'];
	$_SESSION['brace_oustanding_leg'] = $_POST['brace_oustanding_leg'];
	$_SESSION['gusset_thickness'] = $_POST['gusset_thickness'];
	$_SESSION['gusset_length_1'] = $_POST['gusset_length_1'];
	$_SESSION['gusset_length_2'] = $_POST['gusset_length_2'];	
	$_SESSION['gusset_offset'] = $_POST['gusset_offset'];
	$_SESSION['clip_angle'] = $_POST['clip_angle'];
	$_SESSION['clip_oustanding_leg'] = $_POST['clip_oustanding_leg'];
	$_SESSION['tab_width'] = $_POST['tab_width'];
	$_SESSION['tab_thickness'] = $_POST['tab_thickness'];
	$_SESSION['cutout_1'] = $_POST['cutout_1'];
	$_SESSION['cutout_2'] = $_POST['cutout_2'];
	$_SESSION['setback_1'] = $_POST['setback_1'];
	$_SESSION['setback_2'] = $_POST['setback_2'];
	$_SESSION['location_1'] = $_POST['location_1'];
	$_SESSION['location_2'] = $_POST['location_2'];
	$_SESSION['bolt_number'] = $_POST['bolt_number'];
	$_SESSION['bolt_rows'] = $_POST['bolt_rows'];
	$_SESSION['bolt_number_1'] = $_POST['bolt_number_1'];
	$_SESSION['bolt_number_2'] = $_POST['bolt_number_2'];
	$_SESSION['bolt_spacing'] = $_POST['bolt_spacing'];
	$_SESSION['bolt_gage_brace'] = $_POST['bolt_gage_brace'];
	$_SESSION['bolt_gage_clip'] = $_POST['bolt_gage_clip'];
	$_SESSION['bolt_gage_tab'] = $_POST['bolt_gage_tab'];
	$_SESSION['edge_gusset'] = $_POST['edge_gusset'];
	$_SESSION['edge_brace'] = $_POST['edge_brace'];
	$_SESSION['edge_tab'] = $_POST['edge_tab'];
	$_SESSION['edge_clip'] = $_POST['edge_clip'];
	$_SESSION['edge_beam'] = $_POST['edge_beam'];
	$_SESSION['tab_weld'] = $_POST['tab_weld'];
	$_SESSION['clip_weld'] = $_POST['clip_weld'];
	$_SESSION['run'] = true;
	header('Location:hb001.php');
	return;
}
if (isset($_SESSION['run'])){	
	$inputString = 'CONNECTION_CODE HB001;';
	$inputString = $inputString.'CONNECTION_ID HB001;';
	$inputString = $inputString.'METHOD '.$_SESSION['method'].';';
	$inputString = $inputString.'UNITS '.$_SESSION['units'].';';
	$inputString = $inputString.'ANGLE_GRADE '.$_SESSION['angle_grade'].';';
	$inputString = $inputString.'BEAM_GRADE '.$_SESSION['beam_grade'].';';
	$inputString = $inputString.'PLATE_GRADE '.$_SESSION['plate_grade'].';';
	$inputString = $inputString.'WELD_ELECTRODE '.$_SESSION['weld_grade'].';';
	$inputString = $inputString.'BOLT_GRADE '.$_SESSION['bolt_grade'].';';
	$inputString = $inputString.'BRACE_FORCE '.$_SESSION['brace_force'].';';
	$inputString = $inputString.'BOLT_DIAMETER '.$_SESSION['bolt_dia'].';';
	$inputString = $inputString.'BOLT_TYPE '.$_SESSION['bolt_type'].';';
	$inputString = $inputString.'BOLT_SPACING '.$_SESSION['bolt_spacing'].';';
	$inputString = $inputString.'EDGE_DISTANCE_ON_GUSSET '.$_SESSION['edge_gusset'].';';
	$inputString = $inputString.'EDGE_DISTANCE_ON_BRACE '.$_SESSION['edge_brace'].';';
	$inputString = $inputString.'EDGE_DISTANCE_ON_TAB '.$_SESSION['edge_tab'].';';
	$inputString = $inputString.'EDGE_DISTANCE_ON_CLIP '.$_SESSION['edge_clip'].';';
	$inputString = $inputString.'EDGE_DISTANCE_ON_BEAM '.$_SESSION['edge_beam'].';';	
	$inputString = $inputString.'BOLT_GAGE_ON_BRACE '.$_SESSION['bolt_gage_brace'].';';
	$inputString = $inputString.'BOLT_GAGE_ON_CLIP '.$_SESSION['bolt_gage_clip'].';';
	$inputString = $inputString.'BOLT_GAGE_ON_TAB '.$_SESSION['bolt_gage_tab'].';';	
	$inputString = $inputString.'BRACE_ANGLE '.$_SESSION['brace_angle'].';';
	$inputString = $inputString.'BRACE_SECTION '.$_SESSION['brace_section'].';';
	$inputString = $inputString.'BRACE_TYPE DOUBLE_ANGLE;';
	$inputString = $inputString.'BACK_TO_BACK_LEG_ORIENTATION '.$_SESSION['brace_orientation'].';';
	$inputString = $inputString.'BRACE_OUTSTANDING_LEG '.$_SESSION['brace_oustanding_leg'].';';
	$inputString = $inputString.'BRACE_NUMBER_OF_BOLTS_PER_ROW '.$_SESSION['bolt_number'].';';
	$inputString = $inputString.'BRACE_NUMBER_OF_BOLT_ROWS '.$_SESSION['bolt_rows'].';';
	$inputString = $inputString.'GUSSET_THICKNESS '.$_SESSION['gusset_thickness'].';';
	$inputString = $inputString.'GUSSET_LENGTH_1 '.$_SESSION['gusset_length_1'].';';
	$inputString = $inputString.'GUSSET_LENGTH_2 '.$_SESSION['gusset_length_2'].';';
	$inputString = $inputString.'GUSSET_TOP_OFFSET '.$_SESSION['gusset_offset'].';';
	$inputString = $inputString.'CONNECTION1_TYPE '.$_SESSION['conn_type_1'].';';
	$inputString = $inputString.'CONNECTION2_TYPE '.$_SESSION['conn_type_2'].';';
	$inputString = $inputString.'CONNECTION1_NUMBER_OF_BOLTS '.$_SESSION['bolt_number_1'].';';
	$inputString = $inputString.'CONNECTION2_NUMBER_OF_BOLTS '.$_SESSION['bolt_number_2'].';';
	$inputString = $inputString.'CONNECTION1_LOCATION '.$_SESSION['location_1'].';';
	$inputString = $inputString.'CONNECTION2_LOCATION '.$_SESSION['location_2'].';';
	$inputString = $inputString.'TAB_WIDTH '.$_SESSION['tab_width'].';';
	$inputString = $inputString.'TAB_THICKNESS '.$_SESSION['tab_thickness'].';';
	$inputString = $inputString.'TAB_TO_BEAM_WELD '.$_SESSION['tab_weld'].';';
	$inputString = $inputString.'CLIP_SECTION '.$_SESSION['clip_angle'].';';
	$inputString = $inputString.'CLIP_OUTSTANDING_LEG '.$_SESSION['clip_oustanding_leg'].';';
	$inputString = $inputString.'CLIP_TO_GUSSET_WELD '.$_SESSION['clip_weld'].';';
	$inputString = $inputString.'CONNECTION1_CUTOUT '.$_SESSION['cutout_1'].';';
	$inputString = $inputString.'CONNECTION2_CUTOUT '.$_SESSION['cutout_2'].';';
	$inputString = $inputString.'CONNECTION1_SETBACK '.$_SESSION['setback_1'].';';
	$inputString = $inputString.'CONNECTION2_SETBACK '.$_SESSION['setback_2'].';';
	$inputString = $inputString.'BEAM1_SECTION '.$_SESSION['beam_section_1'].';';
	$inputString = $inputString.'BEAM2_SECTION '.$_SESSION['beam_section_2'].';';
	$outputString = execute($inputString);
	unset($_SESSION['run']);
}
$dUnits = 'NEWTON_MM';
$dClipAngle = 'L102X102X9.5';
$dBraceSection = 'L76X76X7.9';
$dBeamSection1 = 'W360X79';
$dBeamSection2 = 'W310X67';
$dBoltDia = 'M22';

function drawInputForm(){
	//default values for input form
	global $dUnits;
	$dMethod = 'LRFD';
	global $dBoltDia;
	$dBoltType = 'BEARING';
	$dAngleGrade = 'A36';
	$dBeamGrade = 'A36';
	$dPlateGrade = 'A36';
	$dWeldGrade = 'E70';
	$dBoltGrade = 'A325';
	$dBraceForce = '0';
	$dConnType1 = 'CLIP_ANGLE';
	$dConnType2 = 'CLIP_ANGLE';
	global $dBeamSection1;
	global $dBeamSection2;
	global $dBraceSection;
	$dBraceAngle = '45';
	$dBraceType = 'DOUBLE_ANGLE';
	$dBraceOrientation = 'HORIZONTAL';
	$dBraceOutstandingLeg = 'LONG_LEG';
	$dGussetThickness = '12';
	$dGussetLength1 = '500';
	$dGussetLength2	= '500';
	$dGussetOffset = '150';
	global $dClipAngle;
	$dClipOutstandingLeg = 'LONG_LEG';
	$dTabWidth = '125';
	$dTabThickness = '12';
	$dCutout1 = '125';
	$dCutout2 = '125';
	$dSetback1 = '12';
	$dSetback2 = '12';
	$dLocation1 = '150';
	$dLocation2 = '150';
	$dBoltNumber = '5';
	$dBoltRows = '1';
	$dBoltNumber1 = '4';
	$dBoltNumber2 = '4';
	$dBoltSpacing = '75';
	$dBoltGageBrace = '45';
	$dBoltGageClip = '45';
	$dBoltGageTab = '60';
	$dEdgeGusset = '35';
	$dEdgeBrace = '35';
	$dEdgeTab = '35';
	$dEdgeClip = '35';
	$dEdgeBeam = '35';
	$dTabWeld = '6';
	$dClipWeld = '6';
	//check to see if values present in sessions
	if (isset($_SESSION['method'])){
		$dUnits = $_SESSION['units'];
		$dMethod = $_SESSION['method'];
		$dBoltDia = $_SESSION['bolt_dia'];
		$dBoltType = $_SESSION['bolt_type'];
		$dAngleGrade = $_SESSION['angle_grade'];
		$dBeamGrade = $_SESSION['beam_grade'];
		$dPlateGrade = $_SESSION['plate_grade'];
		$dWeldGrade = $_SESSION['weld_grade'];
		$dBoltGrade = $_SESSION['bolt_grade'];
		$dBraceForce = $_SESSION['brace_force'];
		$dConnType1 = $_SESSION['conn_type_1'];
		$dConnType2 = $_SESSION['conn_type_2'];
		$dBeamSection1 = $_SESSION['beam_section_1'];
		$dBeamSection2 = $_SESSION['beam_section_2'];
		$dBraceAngle = $_SESSION['brace_angle'];
		$dBraceSection = $_SESSION['brace_section'];
		$dBraceOrientation = $_SESSION['brace_orientation'];
		$dBraceOutstandingLeg = $_SESSION['brace_oustanding_leg'];
		$dGussetThickness = $_SESSION['gusset_thickness'];
		$dGussetLength1 = $_SESSION['gusset_length_1'];
		$dGussetLength2 = $_SESSION['gusset_length_2'];
		$dGussetOffset = $_SESSION['gusset_offset'];
		$dClipAngle = $_SESSION['clip_angle'];
		$dClipOutstandingLeg = $_SESSION['clip_oustanding_leg'];
		$dTabWidth = $_SESSION['tab_width'];
		$dTabThickness = $_SESSION['tab_thickness'];
		$dCutout1 = $_SESSION['cutout_1'];
		$dCutout2 = $_SESSION['cutout_2'];
		$dSetback1 = $_SESSION['setback_1'];
		$dSetback2 = $_SESSION['setback_2'];
		$dLocation1 = $_SESSION['location_1'];
		$dLocation2 = $_SESSION['location_2'];
		$dBoltNumber = $_SESSION['bolt_number'];
		$dBoltRows = $_SESSION['bolt_rows'];
		$dBoltNumber1 = $_SESSION['bolt_number_1'];
		$dBoltNumber2 = $_SESSION['bolt_number_2'];
		$dBoltSpacing = $_SESSION['bolt_spacing'];
		$dBoltGageBrace = $_SESSION['bolt_gage_brace'];
		$dBoltGageClip = $_SESSION['bolt_gage_clip'];
		$dBoltGageTab = $_SESSION['bolt_gage_tab'];
		$dEdgeGusset = $_SESSION['edge_gusset'];
		$dEdgeBrace = $_SESSION['edge_brace'];
		$dEdgeTab = $_SESSION['edge_tab'];
		$dEdgeClip = $_SESSION['edge_clip'];
		$dEdgeBeam = $_SESSION['edge_beam'];
		$dTabWeld = $_SESSION['tab_weld'];
		$dClipWeld = $_SESSION['clip_weld'];		
		unset($_SESSION['units']);
		unset($_SESSION['method']);
		unset($_SESSION['bolt_dia']);
		unset($_SESSION['bolt_type']);
		unset($_SESSION['angle_grade']);
		unset($_SESSION['beam_grade']);
		unset($_SESSION['plate_grade']);
		unset($_SESSION['weld_grade']);
		unset($_SESSION['bolt_grade']);
		unset($_SESSION['brace_force']);
		unset($_SESSION['conn_type_1']);
		unset($_SESSION['conn_type_2']);
		unset($_SESSION['beam_section_1']);
		unset($_SESSION['beam_section_2']);
		unset($_SESSION['brace_angle']);
		unset($_SESSION['brace_section']);
		unset($_SESSION['brace_orientation']);
		unset($_SESSION['brace_oustanding_leg']);
		unset($_SESSION['gusset_thickness']);
		unset($_SESSION['gusset_length_1']);
		unset($_SESSION['gusset_length_2']);
		unset($_SESSION['gusset_offset']);
		unset($_SESSION['clip_angle']);
		unset($_SESSION['clip_oustanding_leg']);
		unset($_SESSION['tab_width']);
		unset($_SESSION['tab_thickness']);
		unset($_SESSION['cutout_1']);
		unset($_SESSION['cutout_2']);
		unset($_SESSION['setback_1']);
		unset($_SESSION['setback_2']);
		unset($_SESSION['location_1']);
		unset($_SESSION['location_2']);
		unset($_SESSION['bolt_number']);
		unset($_SESSION['bolt_rows']);
		unset($_SESSION['bolt_number_1']);
		unset($_SESSION['bolt_number_2']);
		unset($_SESSION['bolt_spacing']);
		unset($_SESSION['bolt_gage_brace']);
		unset($_SESSION['bolt_gage_clip']);
		unset($_SESSION['bolt_gage_tab']);
		unset($_SESSION['edge_gusset']);
		unset($_SESSION['edge_brace']);
		unset($_SESSION['edge_tab']);
		unset($_SESSION['edge_clip']);
		unset($_SESSION['edge_beam']);
		unset($_SESSION['tab_weld']);
		unset($_SESSION['clip_weld']);
	}
	//draw input form
	echo('<div id="input_area">');
	echo('<form method="post" class="form-horizontal">');
	$tabList = array('General','Materials','Forces','Geometry','Details','Connection 1','Connection 2');
	$tabIDList = array('general_tab','material_tab','force_tab','geometry_tab','details_tab','connection1_tab','connection2_tab');
	startTabGroup($tabList,$tabIDList);
	startTab('general_tab',true);
		inputSelect('Unit system',array('NEWTON_MM','KIP_IN'), array('Newton,mm','kip,in'),$dUnits,'units');
		inputSelect('Design method',array('LRFD','ASD'),array('LRFD','ASD'),$dMethod,'method');
	endTab();
	startTab('material_tab');
		inputSelect('Angle grade',array('A36','A992'),array('ASTM A36','ASTM A992'),$dAngleGrade,'angle_grade');
		inputSelect('Beam grade',array('A36','A992'),array('ASTM A36','ASTM A992'),$dBeamGrade,'beam_grade');
		inputSelect('Plate grade',array('A36'),array('ASTM A36'),$dPlateGrade,'plate_grade');
		inputSelect('Weld grade',array('E70'),array('E70'),$dWeldGrade,'weld_grade');
		inputSelect('Bolt grade',array('A325','A490'),array('A325','A490'),$dBoltGrade,'bolt_grade');
	endTab();
	startTab('force_tab');
		inputText('Brace force',$dBraceForce,'brace_force','force');
	endTab();
	startTab('geometry_tab');
		inputText('Angle of brace (a)',$dBraceAngle,'brace_angle');
		inputSelect('Brace section','','','','brace_section');
		inputSelect('Orientation of double angle',array('HORIZONTAL','VERTICAL'),array('Back to back leg horizontal','Back to back leg vertical'),$dBraceOrientation,'brace_orientation');
		inputSelect('Brace outstanding leg',array('LONG_LEG','SHORT_LEG'),array('Long leg','Short leg'),$dBraceOutstandingLeg,'brace_oustanding_leg');
		inputText('Gusset plate thickness',$dGussetThickness,'gusset_thickness','length');
		inputText('Gusset offset from top (t)',$dGussetOffset,'gusset_offset','length');		
		inputSelect('Connection 1 type',array('CLIP_ANGLE','SHEAR_TAB','BOTTOM_FLANGE'),array('Clip angle','Shear tab','Beam bottom flange'),$dConnType1,'conn_type_1');
		inputSelect('Connection 2 type',array('CLIP_ANGLE','SHEAR_TAB','BOTTOM_FLANGE'),array('Clip angle','Shear tab','Beam bottom flange'),$dConnType2,'conn_type_2');
		inputSelect('Beam section at connection 1','','','','beam_section_1');
		inputSelect('Beam section at connection 2','','','','beam_section_2');	
		inputSelect('Clip angle section','','','','clip_angle');
		inputSelect('Clip outstanding leg',array('LONG_LEG','SHORT_LEG'),array('Long leg','Short leg'),$dClipOutstandingLeg,'clip_oustanding_leg');
		inputText('Shear tab width (ws)',$dTabWidth,'tab_width','length');
		inputText('Shear tab thickness',$dTabThickness,'tab_thickness','length');
		inputSelect('Bolt diameter','','','','bolt_dia');
		inputSelect('Bolt type',array('BEARING','FRICTION'),array('Bearing','Friction'),$dBoltType,'bolt_type');	
	endTab();
		startTab('details_tab');
		inputText('Number of bolts at brace (n)',$dBoltNumber,'bolt_number');
		inputText('Number of bolt rows (nr)',$dBoltRows,'bolt_rows');
		inputText('Bolt spacing (s)',$dBoltSpacing,'bolt_spacing','length');
		inputText('Bolt gage on brace (g)', $dBoltGageBrace,'bolt_gage_brace','length');
		inputText('Bolt gage on clip (gc)', $dBoltGageClip,'bolt_gage_clip','length');
		inputText('Bolt gage on tab (gs)', $dBoltGageTab,'bolt_gage_tab','length');
		inputText('Bolt edge distance on gusset (e1)',$dEdgeGusset,'edge_gusset','length');
		inputText('Bolt edge distance on brace (e2)',$dEdgeBrace,'edge_brace','length');
		inputText('Bolt edge distance on shear tab (e3)',$dEdgeTab,'edge_tab','length');
		inputText('Bolt edge distance on clip (e4)',$dEdgeClip,'edge_clip','length');
		inputText('Bolt edge distance on beam (e5)',$dEdgeBeam,'edge_beam','length');
		inputText('Shear tab weld thickness (w1)',$dTabWeld,'tab_weld','length');
		inputText('Clip angle weld thickness (w2)',$dClipWeld,'clip_weld','length');
	endTab();
	startTab('connection1_tab');
		inputText('Number of bolts (n1)',$dBoltNumber1,'bolt_number_1');
		inputText('Gusset plate length (G1)',$dGussetLength1, 'gusset_length_1','length');
		inputText('Gusset cutout (c1)',$dCutout1,'cutout_1','length');
		inputText('Gusset setback from beam (b1)',$dSetback1,'setback_1','length');
		inputText('Location of connection (L1)',$dLocation1, 'location_1','length');
	endTab();
	startTab('connection2_tab');
		inputText('Number of bolts (n2)',$dBoltNumber2,'bolt_number_2');
		inputText('Gusset plate length (G2)',$dGussetLength2, 'gusset_length_2','length');		
		inputText('Gusset cutout (c2)',$dCutout2,'cutout_2','length');
		inputText('Gusset setback from beam (b2)',$dSetback2,'setback_2','length');
		inputText('Location of connection (L2)',$dLocation2, 'location_2','length');
	endTab();
	endTabGroup();
	drawRunButton();
	echo('</form>');
	echo('</div>');
}


?>
<!DOCTYPE html>
<html lang ="en">
<head>
	<title>Osoconn</title>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<!-- Latest compiled and minified CSS -->
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
	<!-- jQuery library -->
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
	<!-- Latest compiled JavaScript -->
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>

</head>
<body >
	<?php
	drawNavBar('connections');
	?>
	<div class="container-fluid" style="max-width:992px; margin: 0 auto;">	
		<h3>Horizontal Bracing Connection</h3>
		<p>Type: Bracing Connection<br>
		Code: HB001<br>
		Specification: AISC 360-2010</p>
		<p>Horizontal bracings act as 'collector elements' that transfer the lateral forces at each floor level to the lateral force resisting system of the structure. Connections for these horizontal bracing systems are typically made using gusset plates bolted to the two framing beams. Depending on the geometry of the connection this can be done using either clip angles, shear tabs, or by directly bolting the gusset to the beam flange.</p>
		<div id="connection_image"> 
			<div style="max-width:550px; margin: 0 auto;>
			<?php 
			echo file_get_contents('./images/hb001_1.svg'); 
			?>
			</div>
		</div>
		<?php
		drawInputForm();
		drawOutput($outputString);
		drawFooter();
		?>
	</div>
</body>
<script>

function fillSelect(id,data,activeValue){
	$('#' + id).empty();
	if (data.length == undefined){
		for (i in data){
			if (data[i] == activeValue)
				$('#' + id).append('<option selected value="'+data[i]+'">'+data[i]+'</option>');
			else
				$('#' + id).append('<option value="'+data[i]+'">'+data[i]+'</option>');
		}
	}else{
		for (i of data){
			if (i == activeValue)
				$('#' + id).append('<option selected value="'+i+'">'+i+'</option>');
			else
				$('#' + id).append('<option value="'+i+'">'+i+'</option>');
		}		
	}
}

$(document).ready(function(){

	let wSections_mm;
	let wSections_in;
	let aSections_mm;
	let aSections_in;
	let boltsConvertion2_mm = {"1/2":"M16","5/8":"M16","3/4":"M20","7/8":"M22","1":"M27","1_1/8":"M30","1_1/4":"M30","1_3/8":"M36","1_1/2":"M36"};
	let boltsConvertion2_in = {"M16_1":"1/2","M16":"5/8","M20":"3/4","M22":"7/8","M27":"1","M30":"1_1/8","M30_1":"1_1/4","M36":"1_3/8","M36_1":"1_1/2"};
	let bolts_mm = ["M16","M20","M22","M27","M30","M36"];
	let bolts_in = ["1/2","5/8","3/4","7/8","1","1_1/8","1_1/4","1_3/8","1_1/2"];

	var defUnits = <?= '"'.$dUnits.'"'?>;
	$.getJSON('wSections_mm.json',function(data){
		wSections_mm = data;
		if (defUnits == 'NEWTON_MM'){
			fillSelect('beam_section_1',wSections_mm,<?= '"'.$dBeamSection1.'"'?>);
			fillSelect('beam_section_2',wSections_mm,<?= '"'.$dBeamSection2.'"'?>);
		}
	});
	$.getJSON('wSections_in.json',function(data){
		wSections_in = data;
		if (defUnits == 'KIP_IN'){
			fillSelect('beam_section_1',wSections_in,<?= '"'.$dBeamSection1.'"'?>);
			fillSelect('beam_section_2',wSections_in,<?= '"'.$dBeamSection2.'"'?>);
		}
	});
	$.getJSON('aSections_mm.json',function(data){
		aSections_mm = data;
		if (defUnits == 'NEWTON_MM'){
			fillSelect('brace_section',aSections_mm,<?= '"'.$dBraceSection.'"'?>);
			fillSelect('clip_angle',aSections_mm,<?= '"'.$dClipAngle.'"'?>);
		}
	});	
	$.getJSON('aSections_in.json',function(data){
		aSections_in = data;
		if (defUnits == 'KIP_IN'){
			fillSelect('brace_section',aSections_in,<?= '"'.$dBraceSection.'"'?>);
			fillSelect('clip_angle',aSections_in,<?= '"'.$dClipAngle.'"'?>);
		}
	});

	if (defUnits == 'NEWTON_MM')
		fillSelect('bolt_dia',bolts_mm,<?= '"'.$dBoltDia.'"'?>);
	else
		fillSelect('bolt_dia',bolts_in,<?= '"'.$dBoltDia.'"'?>);
	$('#units').change(function(){
		var curUnits = $('#units').val();
		var oldValue;
		var newValue;
		//update beam sections
		oldValue = $('#beam_section_1').val();
		if (curUnits == 'NEWTON_MM'){
			newValue = wSections_mm[oldValue];
			fillSelect('beam_section_1',wSections_mm,newValue);
		}else{
			newValue = wSections_in[oldValue];
			fillSelect('beam_section_1',wSections_in,newValue);
		}
		oldValue = $('#beam_section_2').val();
		if (curUnits == 'NEWTON_MM'){
			newValue = wSections_mm[oldValue];
			fillSelect('beam_section_2',wSections_mm,newValue);
		}else{
			newValue = wSections_in[oldValue];
			fillSelect('beam_section_2',wSections_in,newValue);
		}
		
		//updated clip sections
		oldValue = $('#brace_section').val();
		if (curUnits == 'NEWTON_MM'){
			newValue = aSections_mm[oldValue];
			fillSelect('brace_section',aSections_mm,newValue);
		}else{
			newValue = aSections_in[oldValue];
			fillSelect('brace_section',aSections_in,newValue);
		}	
		oldValue = $('#clip_angle').val();
		if (curUnits == 'NEWTON_MM'){
			newValue = aSections_mm[oldValue];
			fillSelect('clip_angle',aSections_mm,newValue);
		}else{
			newValue = aSections_in[oldValue];
			fillSelect('clip_angle',aSections_in,newValue);
		}			
		//update bolt list
		oldValue = $('#bolt_dia').val();
		if (curUnits == 'NEWTON_MM'){
			newValue = boltsConvertion2_mm[oldValue];
			fillSelect('bolt_dia',bolts_mm,newValue);
		}else{
			newValue = boltsConvertion2_in[oldValue];
			fillSelect('bolt_dia',bolts_in,newValue);
		}		
		//update units
		$('.length-unit').empty();
		$('.force-unit').empty();
		$('.stress-unit').empty();
		var newVal = 0;
		if (curUnits == 'KIP_IN'){
			$(".length-unit").append('in');
			$('.length-val').each(function(){
				newVal = $(this).val()/25.4000508001016;
				$(this).val(Math.round(newVal*100000)/100000);
			});
			$(".force-unit").append('kip');
			$('.force-val').each(function(){	
				newVal = $(this).val()/4448.2216152605;
				$(this).val(Math.round(newVal*100000)/100000);
			});
			$(".stress-unit").append('ksi');
			$('.stress-val').each(function(){
				newVal = $(this).val()/6.89475908677537;
				$(this).val(Math.round(newVal*100000)/100000);
			});			
		}else{
			$(".length-unit").append('mm');
			$('.length-val').each(function(){
				newVal = $(this).val()*25.4000508001016;
				$(this).val(Math.round(newVal*100000)/100000);
			});
			$(".force-unit").append('N');
			$('.force-val').each(function(){				
				newVal = $(this).val()*4448.2216152605;
				$(this).val(Math.round(newVal*100000)/100000);
			});
			$(".stress-unit").append('MPa');
			$('.stress-val').each(function(){				
				newVal = $(this).val()*6.89475908677537;
				$(this).val(Math.round(newVal*100000)/100000);
			});			
			
		}

		
	});
	//update units on load
	$('.length-unit').empty();
	$('.force-unit').empty();
	$('.stress-unit').empty();
	if ($('#units').val() == 'KIP_IN'){
		$(".length-unit").append('in');
		$(".force-unit").append('kip');
		$(".stress-unit").append('ksi');
	}else{
		$(".length-unit").append('mm');
		$(".force-unit").append('N');
		$(".stress-unit").append('MPa');			
	}
	$('.input').change(function(){
		$('#output-area').remove();
	});
	$('#conn_type_1').change(function(){
		
		$('#conn1_clip').attr('style','display:none');
		$('#conn1_flange').attr('style','display:none');
		$('#conn1_tab').attr('style','display:none');
		switch($('#conn_type_1').val()){
		case 'CLIP_ANGLE':
			$('#conn1_clip').attr('style','display:inline;');
			break;
		case 'BOTTOM_FLANGE':
			$('#conn1_flange').attr('style','display:inline;');
			break;
		case 'SHEAR_TAB':
			$('#conn1_tab').attr('style','display:inline;');
			break;
		}
	});
	$('#conn1_clip').attr('style','display:none');
	$('#conn1_flange').attr('style','display:none');
	$('#conn1_tab').attr('style','display:none');
	switch($('#conn_type_1').val()){
	case 'CLIP_ANGLE':
		$('#conn1_clip').attr('style','display:inline;');
		break;
	case 'BOTTOM_FLANGE':
		$('#conn1_flange').attr('style','display:inline;');
		break;
	case 'SHEAR_TAB':
		$('#conn1_tab').attr('style','display:inline;');
		break;
	}
	
	$('#conn_type_2').change(function(){
		
		$('#conn2_clip').attr('style','display:none');
		$('#conn2_flange').attr('style','display:none');
		$('#conn2_tab').attr('style','display:none');
		switch($('#conn_type_2').val()){
		case 'CLIP_ANGLE':
			$('#conn2_clip').attr('style','display:inline;');
			break;
		case 'BOTTOM_FLANGE':
			$('#conn2_flange').attr('style','display:inline;');
			break;
		case 'SHEAR_TAB':
			$('#conn2_tab').attr('style','display:inline;');
			break;
		}
	});
	$('#conn2_clip').attr('style','display:none');
	$('#conn2_flange').attr('style','display:none');
	$('#conn2_tab').attr('style','display:none');
	switch($('#conn_type_2').val()){
	case 'CLIP_ANGLE':
		$('#conn2_clip').attr('style','display:inline;');
		break;
	case 'BOTTOM_FLANGE':
		$('#conn2_flange').attr('style','display:inline;');
		break;
	case 'SHEAR_TAB':
		$('#conn2_tab').attr('style','display:inline;');
		break;
	}
	
	$('#brace_orientation').change(function(){
		$('#brace_bblh').attr('style','display:none');
		$('#brace_bblv').attr('style','display:none');
		switch($('#brace_orientation').val()){
		case 'HORIZONTAL':
			$('#brace_bblh').attr('style','display:inline;');
			break;
		case 'VERTICAL':
			$('#brace_bblv').attr('style','display:inline;');
			break;
		}
	});	
	$('#brace_bblh').attr('style','display:none');
	$('#brace_bblv').attr('style','display:none');
	switch($('#brace_orientation').val()){
	case 'HORIZONTAL':
		$('#brace_bblh').attr('style','display:inline;');
		break;
	case 'VERTICAL':
		$('#brace_bblv').attr('style','display:inline;');
		break;
	}
});
</script>

</html>
