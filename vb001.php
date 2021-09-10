<?php
require_once 'common.php';
session_start();
$outputString = "";
if (isset($_POST['run'])){
	$_SESSION['units'] = $_POST['units'];
	$_SESSION['method'] = $_POST['method'];
	$_SESSION['support_type'] = $_POST['support_type'];
	$_SESSION['youngs_modulus'] = $_POST['youngs_modulus'];
	$_SESSION['bolt_dia'] = $_POST['bolt_dia'];
	$_SESSION['bolt_type'] = $_POST['bolt_type'];
	$_SESSION['angle_grade'] = $_POST['angle_grade'];
	$_SESSION['beam_grade'] = $_POST['beam_grade'];
	$_SESSION['column_grade'] = $_POST['column_grade'];
	$_SESSION['plate_grade'] = $_POST['plate_grade'];
	$_SESSION['weld_grade'] = $_POST['weld_grade'];
	$_SESSION['bolt_grade'] = $_POST['bolt_grade'];
	$_SESSION['brace_force'] = $_POST['brace_force'];
	$_SESSION['shear_force'] = $_POST['shear_force'];
	$_SESSION['transfer_force'] = $_POST['transfer_force'];
	$_SESSION['beam_section'] = $_POST['beam_section'];
	$_SESSION['column_section'] = $_POST['column_section'];
	$_SESSION['brace_section'] = $_POST['brace_section'];
	$_SESSION['brace_oustanding_leg'] = $_POST['brace_oustanding_leg'];
	$_SESSION['clip_angle'] = $_POST['clip_angle'];
	$_SESSION['clip_oustanding_leg'] = $_POST['clip_oustanding_leg'];
	$_SESSION['clip_location'] = $_POST['clip_location'];
	$_SESSION['gusset_thickness'] = $_POST['gusset_thickness'];
	$_SESSION['brace_angle'] = $_POST['brace_angle'];
	$_SESSION['gusset_length'] = $_POST['gusset_length'];
	$_SESSION['brace_bolt_number'] = $_POST['brace_bolt_number'];
	$_SESSION['bolt_rows'] = $_POST['bolt_rows'];
	$_SESSION['gusset_clip_bolts'] = $_POST['gusset_clip_bolts'];
	$_SESSION['beam_clip_bolts'] = $_POST['beam_clip_bolts'];
	$_SESSION['bolt_spacing'] = $_POST['bolt_spacing'];
	$_SESSION['bolt_row_spacing'] = $_POST['bolt_row_spacing'];
	$_SESSION['bolt_gage_brace'] = $_POST['bolt_gage_brace'];
	$_SESSION['bolt_gage'] = $_POST['bolt_gage'];
	$_SESSION['edge_dist_brace'] = $_POST['edge_dist_brace'];
	$_SESSION['edge_dist_gusset'] = $_POST['edge_dist_gusset'];
	$_SESSION['edge_dist_clip'] = $_POST['edge_dist_clip'];
	$_SESSION['gusset_weld_thickness'] = $_POST['gusset_weld_thickness'];
	$_SESSION['clip_weld_thickness'] = $_POST['clip_weld_thickness'];
	$_SESSION['setback'] = $_POST['setback'];	
	$_SESSION['run'] = true;
	header('Location:vb001.php');
	return;
}
if (isset($_SESSION['run'])){	
	$inputString = 'CONNECTION_CODE VB001;';
	$inputString = $inputString.'CONNECTION_ID VB001;';
	$inputString = $inputString.'METHOD '.$_SESSION['method'].';';
	$inputString = $inputString.'UNITS '.$_SESSION['units'].';';
	$inputString = $inputString.'MODULUS_OF_ELASTICITY '.$_SESSION['youngs_modulus'].';';
	$inputString = $inputString.'SUPPORT_TYPE '.$_SESSION['support_type'].';';
	$inputString = $inputString.'ANGLE_GRADE '.$_SESSION['angle_grade'].';';
	$inputString = $inputString.'BEAM_GRADE '.$_SESSION['beam_grade'].';';
	$inputString = $inputString.'COLUMN_GRADE '.$_SESSION['column_grade'].';';
	$inputString = $inputString.'WELD_ELECTRODE '.$_SESSION['weld_grade'].';';
	$inputString = $inputString.'BOLT_GRADE '.$_SESSION['bolt_grade'].';';
	$inputString = $inputString.'BRACE_FORCE '.$_SESSION['brace_force'].';';	
	$inputString = $inputString.'BEAM_SHEAR_FORCE '.$_SESSION['shear_force'].';';	
	$inputString = $inputString.'BEAM_TRANSFER_FORCE '.$_SESSION['transfer_force'].';';
	$inputString = $inputString.'BEAM_SECTION '.$_SESSION['beam_section'].';';
	$inputString = $inputString.'BRACE_SECTION '.$_SESSION['brace_section'].';';
	$inputString = $inputString.'BRACE_OUTSTANDING_LEG '.$_SESSION['brace_oustanding_leg'].';';
	$inputString = $inputString.'COLUMN_SECTION '.$_SESSION['column_section'].';';
	$inputString = $inputString.'GUSSET_THICKNESS '.$_SESSION['gusset_thickness'].';';
	$inputString = $inputString.'BOLT_DIAMETER '.$_SESSION['bolt_dia'].';';
	$inputString = $inputString.'BOLT_TYPE '.$_SESSION['bolt_type'].';';
	$inputString = $inputString.'BOLT_GAGE '.$_SESSION['bolt_gage'].';';
	$inputString = $inputString.'BOLT_GAGE_ON_BRACE '.$_SESSION['bolt_gage_brace'].';';
	$inputString = $inputString.'BOLT_SPACING '.$_SESSION['bolt_spacing'].';';
	$inputString = $inputString.'EDGE_DISTANCE_ON_BRACE '.$_SESSION['edge_dist_brace'].';';
	$inputString = $inputString.'EDGE_DISTANCE_ON_GUSSET '.$_SESSION['edge_dist_gusset'].';';
	$inputString = $inputString.'EDGE_DISTANCE_ON_CLIP '.$_SESSION['edge_dist_clip'].';';
	$inputString = $inputString.'NUMBER_OF_BOLTS_PER_ROW_ON_BRACE '.$_SESSION['brace_bolt_number'].';';
	$inputString = $inputString.'NUMBER_OF_BOLT_ROWS_ON_BRACE '.$_SESSION['bolt_rows'].';';
	$inputString = $inputString.'BRACE_ANGLE '.$_SESSION['brace_angle'].';';
	$inputString = $inputString.'GUSSET_TO_BEAM_WELD '.$_SESSION['gusset_weld_thickness'].';';
	$inputString = $inputString.'GUSSET_LENGTH '.$_SESSION['gusset_length'].';';
	$inputString = $inputString.'CLIP_SECTION '.$_SESSION['clip_angle'].';';
	$inputString = $inputString.'CLIP_OUTSTANDING_LEG '.$_SESSION['clip_oustanding_leg'].';';
	$inputString = $inputString.'GUSSET_CLIP_LOCATION '.$_SESSION['clip_location'].';';
	$inputString = $inputString.'NUMBER_OF_BOLTS_GUSSET_CLIP '.$_SESSION['gusset_clip_bolts'].';';
	$inputString = $inputString.'NUMBER_OF_BOLT_BEAM_CLIP '.$_SESSION['beam_clip_bolts'].';';
	$inputString = $inputString.'CLIP_ANGLE_WELD_THICKNESS '.$_SESSION['clip_weld_thickness'].';';
	$inputString = $inputString.'CONNECTION_SETBACK '.$_SESSION['setback'].';';
	//echo $inputString;
	echo $_SESSION['clip_angle'];
	$outputString = execute($inputString);
	unset($_SESSION['run']);
}
$dUnits = 'NEWTON_MM';
$dClipAngle = 'L102X102X9.5';
$dBeamSection = 'W310X52';
$dColumnSection = 'W460X74';
$dBraceSection = 'L102X102X9.5';
$dBoltDia = 'M22';

function drawInputForm(){
	//default values for input form
	global $dUnits;
	$dMethod = 'LRFD';
	$dSupportType = 'COLUMN_FLANGE';
	$dModulus = '200000';
	global $dBoltDia;
	$dBoltType = 'BEARING';
	$dAngleGrade = 'A36';
	$dBeamGrade = 'A36';
	$dColumnGrade = 'A36';
	$dPlateGrade = 'A36';
	$dWeldGrade = 'E70';
	$dBoltGrade = 'A325';
	$dBraceForce = '0';
	$dShearForce = '0';
	$dTransferForce = '0';
	global $dBeamSection;
	global $dColumnSection;
	global $dBraceSection;
	$dBraceOutstandingLeg = 'LONG_LEG';
	global $dClipAngle;
	$dClipOutstandingLeg = 'LONG_LEG';
	$dClipLocation = '50';
	$dGussetThickness = '12';
	$dBraceAngle = '45';
	$dGussetLength = '500';
	$dBraceBoltNumber = '4';
	$dBoltRows = '1';
	$dGussetClipBolts = '4';
	$dBeamClipBolts = '3';
	$dBoltSpacing = '75';
	$dBoltRowSpacing = '75';
	$dBoltGage = '140';
	$dBoltGageBrace = '45';
	$dEdgeDistBrace = '35';
	$dEdgeDistGusset = '35';
	$dEdgeDistClip = '35';
	$dGussetWeldThickness = '6';
	$dClipWeldThickness = '6';
	$dSetback = '12';

	//check to see if values present in sessions
	if (isset($_SESSION['method'])){
		$dUnits = $_SESSION['units'];
		$dMethod = $_SESSION['method'];
		$dSupportType = $_SESSION['support_type'];
		$dModulus = $_SESSION['youngs_modulus'];
		$dBoltDia = $_SESSION['bolt_dia'];
		$dBoltType = $_SESSION['bolt_type'];
		$dAngleGrade = $_SESSION['angle_grade'];
		$dBeamGrade = $_SESSION['beam_grade'];
		$dColumnGrade = $_SESSION['column_grade'];
		$dPlateGrade = $_SESSION['plate_grade'];
		$dWeldGrade = $_SESSION['weld_grade'];
		$dBoltGrade = $_SESSION['bolt_grade'];
		$dBraceForce = $_SESSION['brace_force'];
		$dShearForce = $_SESSION['shear_force'];
		$dTransferForce = $_SESSION['transfer_force'];
		$dBeamSection = $_SESSION['beam_section'];
		$dColumnSection = $_SESSION['column_section'];
		$dBraceSection = $_SESSION['brace_section'];
		$dBraceOutstandingLeg = $_SESSION['brace_oustanding_leg'];
		$dClipAngle = $_SESSION['clip_angle'];
		$dClipOutstandingLeg = $_SESSION['clip_oustanding_leg'];
		$dClipLocation = $_SESSION['clip_location'];
		$dGussetThickness = $_SESSION['gusset_thickness'];
		$dBraceAngle = $_SESSION['brace_angle'];
		$dGussetLength = $_SESSION['gusset_length'];
		$dBraceBoltNumber = $_SESSION['brace_bolt_number'];
		$dBoltRows = $_SESSION['bolt_rows'];
		$dGussetClipBolts = $_SESSION['gusset_clip_bolts'];
		$dBeamClipBolts = $_SESSION['beam_clip_bolts'];
		$dBoltSpacing = $_SESSION['bolt_spacing'];
		$dBoltRowSpacing = $_SESSION['bolt_row_spacing'];
		$dBoltGage = $_SESSION['bolt_gage'];
		$dBoltGageBrace = $_SESSION['bolt_gage_brace'];
		$dEdgeDistBrace = $_SESSION['edge_dist_brace'];
		$dEdgeDistGusset = $_SESSION['edge_dist_gusset'];
		$dEdgeDistClip = $_SESSION['edge_dist_clip'];
		$dGussetWeldThickness = $_SESSION['gusset_weld_thickness'];
		$dClipWeldThickness = $_SESSION['clip_weld_thickness'];
		$dSetback = $_SESSION['setback'];
		unset ($_SESSION['units']);
		unset ($_SESSION['method']);
		unset ($_SESSION['support_type']);
		unset ($_SESSION['youngs_modulus']);
		unset ($_SESSION['bolt_dia']);
		unset ($_SESSION['bolt_type']);
		unset ($_SESSION['angle_grade']);
		unset ($_SESSION['beam_grade']);
		unset ($_SESSION['column_grade']);
		unset ($_SESSION['plate_grade']);
		unset ($_SESSION['weld_grade']);
		unset ($_SESSION['bolt_grade']);
		unset ($_SESSION['brace_force']);
		unset ($_SESSION['shear_force']);
		unset ($_SESSION['transfer_force']);
		unset ($_SESSION['beam_section']);
		unset ($_SESSION['column_section']);
		unset ($_SESSION['brace_section']);
		unset ($_SESSION['brace_oustanding_leg']);
		unset ($_SESSION['clip_location']);
		unset ($_SESSION['clip_angle']);
		unset ($_SESSION['clip_oustanding_leg']);
		unset ($_SESSION['gusset_thickness']);
		unset ($_SESSION['brace_angle']);
		unset ($_SESSION['gusset_length']);
		unset ($_SESSION['brace_bolt_number']);
		unset ($_SESSION['bolt_rows']);
		unset ($_SESSION['gusset_clip_bolts']);
		unset ($_SESSION['beam_clip_bolts']);
		unset ($_SESSION['bolt_spacing']);
		unset ($_SESSION['bolt_row_spacing']);
		unset ($_SESSION['bolt_gage']);
		unset ($_SESSION['bolt_gage_brace']);
		unset ($_SESSION['edge_dist_brace']);
		unset ($_SESSION['edge_dist_gusset']);
		unset ($_SESSION['edge_dist_clip']);
		unset ($_SESSION['gusset_weld_thickness']);
		unset ($_SESSION['clip_weld_thickness']);
		unset ($_SESSION['setback']);
	}
	//draw input form
	echo('<div id="input_area">');
	echo('<form method="post" class="form-horizontal">');
	$tabList = array('General','Materials','Forces','Geometry','Details');
	$tabIDList = array('general_tab','material_tab','force_tab','geometry_tab','details_tab');
	startTabGroup($tabList,$tabIDList);
	startTab('general_tab',true);
		inputSelect('Unit system',array('NEWTON_MM','KIP_IN'), array('Newton,mm','kip,in'),$dUnits,'units');
		inputSelect('Design method',array('LRFD','ASD'),array('LRFD','ASD'),$dMethod,'method');
	endTab();
	startTab('material_tab');
		inputSelect('Angle grade',array('A36','A992'),array('ASTM A36','ASTM A992'),$dAngleGrade,'angle_grade');
		inputSelect('Beam grade',array('A36','A992'),array('ASTM A36','ASTM A992'),$dBeamGrade,'beam_grade');
		inputSelect('Column grade',array('A36','A992'),array('ASTM A36','ASTM A992'),$dColumnGrade,'column_grade');
		inputSelect('Plate grade',array('A36'),array('ASTM A36'),$dPlateGrade,'plate_grade');
		inputSelect('Weld grade',array('E70'),array('E70'),$dWeldGrade,'weld_grade');
		inputSelect('Bolt grade',array('A325','A490'),array('A325','A490'),$dBoltGrade,'bolt_grade');
		inputText("Young's modulus for steel",$dModulus,'youngs_modulus','stress');
	endTab();
	startTab('force_tab');
		inputText('Brace force',$dBraceForce,'brace_force','force');
		inputText('Beam shear force',$dShearForce,'shear_force','force');
		inputText('Transfer force',$dTransferForce,'transfer_force','force');
	endTab();
	startTab('geometry_tab');
		inputSelect('Support type',array('COLUMN_WEB','COLUMN_FLANGE'),array('Column web','Column flange'),$dSupportType,'support_type');
		inputText('Brace angle (a)',$dBraceAngle,'brace_angle');
		inputSelect('Beam section','','','','beam_section');
		inputSelect('Column section','','','','column_section');
		inputSelect('Brace section','','','','brace_section');
		inputSelect('Brace outstanding leg',array('LONG_LEG','SHORT_LEG'),array('Long leg','Short leg'),$dBraceOutstandingLeg,'brace_oustanding_leg');
		inputText('Gusset plate thickness',$dGussetThickness,'gusset_thickness','length');
		inputText('Gusset length (G)',$dGussetLength,'gusset_length','length');
		inputSelect('Clip angle section','','','','clip_angle');
		inputSelect('Clip outstanding leg',array('LONG_LEG','SHORT_LEG'),array('Long leg','Short leg'),$dClipOutstandingLeg,'clip_oustanding_leg');
		inputText('Gusset clip location (L)',$dClipLocation,'clip_location','length');		
		inputSelect('Bolt diameter','','','','bolt_dia');
		inputSelect('Bolt type',array('BEARING','FRICTION'),array('Bearing','Friction'),$dBoltType,'bolt_type');
		inputText('connection setback (b)',$dSetback,'setback','length');				
	endTab();	
	startTab('details_tab');
		inputText('Number of bolts per row on brace (n)',$dBraceBoltNumber,'brace_bolt_number');
		inputSelect('Number of bolt rows (nr)',array('1','2'),array('1','2'),$dBoltRows,'bolt_rows');
		inputText('Number of bolts at gusset clip (n1)',$dGussetClipBolts,'gusset_clip_bolts');
		inputText('Number of bolts at beam clip (n2)',$dBeamClipBolts,'beam_clip_bolts');	
		inputText('Bolt spacing (s)',$dBoltSpacing,'bolt_spacing','length');
		inputText('Bolt row spacing (sr)',$dBoltRowSpacing,'bolt_row_spacing','length');
		inputText('Bolt gage on brace (g)', $dBoltGageBrace,'bolt_gage_brace','length');
		inputText('Bolt gage on column (g1)', $dBoltGage,'bolt_gage','length');
		inputText('Bolt edge distance on brace (e1)',$dEdgeDistBrace,'edge_dist_brace','length');
		inputText('Bolt edge distance on gusset (e2)',$dEdgeDistGusset,'edge_dist_gusset','length');
		inputText('Bolt edge distance on clip (e3)',$dEdgeDistClip,'edge_dist_clip','length');
		inputText('Gusset weld thickness (w1)',$dGussetWeldThickness,'gusset_weld_thickness','length');
		inputText('Clip weld thickness (w2)',$dClipWeldThickness,'clip_weld_thickness','length');
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
		<h3>Beam Column Vertical Bracing Connection</h3>
		<p>Type: Bracing Connection<br>
		Code: VB001<br>
		Specification: AISC 360-2010</p>
		<p>Vertical bracings are used to transfer lateral loads in the structure to the foundations. There are many methods available for the design of the vertical bracing connections - the Uniform Force Method (UFM) is a popular method. UFM derives the forces in the connection such that equilibrium is maintained in the connection.</p>
		<div id="connection_image"> 
			<img src="./images/vb001_1.svg" class="img-responsive" id="img_col_web" style="display:none;">
			<img src="./images/vb001_2.svg" class="img-responsive" id="img_col_flange" style="display:none;">
			
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
			fillSelect('beam_section',wSections_mm,<?= '"'.$dBeamSection.'"'?>);
			fillSelect('column_section',wSections_mm,<?= '"'.$dColumnSection.'"'?>);
		}
	});
	$.getJSON('wSections_in.json',function(data){
		wSections_in = data;
		if (defUnits == 'KIP_IN'){
			fillSelect('beam_section',wSections_in,<?= '"'.$dBeamSection.'"'?>);
			fillSelect('column_section',wSections_in,<?= '"'.$dColumnSection.'"'?>);
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
		oldValue = $('#beam_section').val();
		if (curUnits == 'NEWTON_MM'){
			newValue = wSections_mm[oldValue];
			fillSelect('beam_section',wSections_mm,newValue);
		}else{
			newValue = wSections_in[oldValue];
			fillSelect('beam_section',wSections_in,newValue);
		}
		//update column sections
		oldValue = $('#column_section').val();
		if (curUnits == 'NEWTON_MM'){
			newValue = wSections_mm[oldValue];
			fillSelect('column_section',wSections_mm,newValue);
		}else{
			newValue = wSections_in[oldValue];
			fillSelect('column_section',wSections_in,newValue);
		}	
		//updated brace sections
		oldValue = $('#brace_section').val();
		if (curUnits == 'NEWTON_MM'){
			newValue = aSections_mm[oldValue];
			fillSelect('brace_section',aSections_mm,newValue);
		}else{
			newValue = aSections_in[oldValue];
			fillSelect('brace_section',aSections_in,newValue);
		}				
		//updated clip sections
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
	$('#support_type').change(function(){
		$('#img_col_web').attr('style','display:none');
		$('#img_col_flange').attr('style','display:none');
		switch($('#support_type').val()){
		case 'COLUMN_WEB':
			$('#img_col_web').attr('style','display:block;margin-left:auto;margin-right:auto;');
			break;
		case 'COLUMN_FLANGE':
			$('#img_col_flange').attr('style','display:block;margin-left:auto;margin-right:auto;');
			break;
		}
	});
	switch($('#support_type').val()){
	case 'COLUMN_WEB':
		$('#img_col_web').attr('style','display:block;margin-left:auto;margin-right:auto;');
		break;
	case 'COLUMN_FLANGE':
		$('#img_col_flange').attr('style','display:block;margin-left:auto;margin-right:auto;');
		break;
	}
});
</script>

</html>
