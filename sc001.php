<?php
require_once 'common.php';
session_start();
$outputString = "";
if (isset($_POST['run'])){
	$_SESSION['method'] = $_POST['method'];
	$_SESSION['units'] = $_POST['units'];
	$_SESSION['youngs_modulus'] = $_POST['youngs_modulus'];
	$_SESSION['poisson'] = $_POST['poisson'];
	$_SESSION['angle_grade'] = $_POST['angle_grade'];
	$_SESSION['beam_grade'] = $_POST['beam_grade'];
	$_SESSION['column_grade'] = $_POST['column_grade'];
	$_SESSION['weld_grade'] = $_POST['weld_grade'];
	$_SESSION['bolt_grade'] = $_POST['bolt_grade'];
	$_SESSION['transfer_force'] = $_POST['transfer_force'];
	$_SESSION['shear_force'] = $_POST['shear_force'];
	$_SESSION['bolt_dia'] = $_POST['bolt_dia'];
	$_SESSION['bolt_type'] = $_POST['bolt_type'];
	$_SESSION['bolt_number'] = $_POST['bolt_number'];
	$_SESSION['bolt_gage'] = $_POST['bolt_gage'];
	$_SESSION['bolt_spacing'] = $_POST['bolt_spacing'];
	$_SESSION['weld_thickness'] = $_POST['weld_thickness'];
	$_SESSION['clip_angle'] = $_POST['clip_angle'];
	$_SESSION['oustanding_leg'] = $_POST['oustanding_leg'];
	$_SESSION['clip_length'] = $_POST['clip_length'];
	$_SESSION['clip_top'] = $_POST['clip_top'];
	$_SESSION['beam_section'] = $_POST['beam_section'];
	$_SESSION['setback'] = $_POST['setback'];
	$_SESSION['cope_length'] = $_POST['cope_length'];
	$_SESSION['top_cope'] = $_POST['top_cope'];
	$_SESSION['bottom_cope'] = $_POST['bottom_cope'];
	$_SESSION['support_section'] = $_POST['support_section'];
	$_SESSION['support_type'] = $_POST['support_type'];
	$_SESSION['backing_beam'] = $_POST['backing_beam'];
	$_SESSION['run'] = true;
	header('Location:sc001.php');
	return;
}
if (isset($_SESSION['run'])){	
	$inputString = 'CONNECTION_CODE SC001;';
	$inputString = $inputString.'CONNECTION_ID SC001;';
	$inputString = $inputString.'METHOD '.$_SESSION['method'].';';
	$inputString = $inputString.'UNITS '.$_SESSION['units'].';';
	$inputString = $inputString.'MODULUS_OF_ELASTICITY '.$_SESSION['youngs_modulus'].';';
	$inputString = $inputString.'POISSON_RATIO '.$_SESSION['poisson'].';';
	$inputString = $inputString.'STEEL_GRADE_OF_ANGLE '.$_SESSION['angle_grade'].';';
	$inputString = $inputString.'STEEL_GRADE_OF_BEAM '.$_SESSION['beam_grade'].';';
	$inputString = $inputString.'STEEL_GRADE_OF_SUPPORT '.$_SESSION['column_grade'].';';
	$inputString = $inputString.'WELD_ELECTRODE '.$_SESSION['weld_grade'].';';
	$inputString = $inputString.'BOLT_GRADE '.$_SESSION['bolt_grade'].';';
	$inputString = $inputString.'TRANSFER_FORCE '.$_SESSION['transfer_force'].';';
	$inputString = $inputString.'SHEAR_FORCE '.$_SESSION['shear_force'].';';
	$inputString = $inputString.'BOLT_DIAMETER '.$_SESSION['bolt_dia'].';';
	$inputString = $inputString.'BOLT_TYPE '.$_SESSION['bolt_type'].';';
	$inputString = $inputString.'NUMBER_OF_BOLTS_PER_ROW '.$_SESSION['bolt_number'].';';
	$inputString = $inputString.'BOLT_GAGE '.$_SESSION['bolt_gage'].';';
	$inputString = $inputString.'BOLT_SPACING '.$_SESSION['bolt_spacing'].';';
	$inputString = $inputString.'THICKNESS_OF_WELD '.$_SESSION['weld_thickness'].';';
	$inputString = $inputString.'CLIP_ANGLE '.$_SESSION['clip_angle'].';';
	$inputString = $inputString.'OUTSTANDING_LEG '.$_SESSION['oustanding_leg'].';';
	$inputString = $inputString.'CLIP_ANGLE_LENGTH '.$_SESSION['clip_length'].';';
	$inputString = $inputString.'CLIP_ANGLE_TOP '.$_SESSION['clip_top'].';';
	$inputString = $inputString.'BEAM_SECTION '.$_SESSION['beam_section'].';';
	$inputString = $inputString.'CONNECTION_SETBACK '.$_SESSION['setback'].';';
	$inputString = $inputString.'COPE_LENGTH '.$_SESSION['cope_length'].';';
	$inputString = $inputString.'TOP_COPE_DEPTH '.$_SESSION['top_cope'].';';
	$inputString = $inputString.'BOTTOM_COPE_DEPTH '.$_SESSION['bottom_cope'].';';
	$inputString = $inputString.'SUPPORT_SECTION '.$_SESSION['support_section'].';';
	$inputString = $inputString.'SUPPORT_TYPE '.$_SESSION['support_type'].';';
	$inputString = $inputString.'BACKING_BEAM '.$_SESSION['backing_beam'].';';
	$outputString = execute($inputString);
	unset($_SESSION['run']);
}
$dUnits = 'NEWTON_MM';
$dClipAngle = 'L102X102X9.5';
$dBeamSection = 'W310X74';
$dSupportSection = 'W460X74';
$dBoltDia = 'M22';

function drawInputForm(){
	//default values for input form
	$dMethod = 'LRFD';
	global $dUnits;
	$dModulus = '200000';
	$dPoisson = '0.3';
	$dAngleGrade = 'A36';
	$dBeamGrade = 'A36';
	$dColumnGrade = 'A36';
	$dWeldGrade = 'E70';
	$dBoltGrade = 'A325';
	$dTransferForce = '0';
	$dShearForce = '0';
	global $dBoltDia;
	$dBoltType = 'BEARING';
	$dBoltNumber = '3';
	$dBoltGage = '140';
	$dBoltSpacing = '70';
	$dWeldThickness = '6';
	global $dClipAngle;
	$dOutstandingLeg = 'LONG';
	$dClipLength = '210';
	$dClipTop = '40';
	global $dBeamSection;
	$dSetback = '12';
	$dCopeLength = '100';
	$dTopCope = '35';
	$dBottomCope = '0';
	global $dSupportSection;
	$dSupportType = 'BEAM';
	$dBackingBeam = 'YES';
	//check to see if values present in sessions
	if (isset($_SESSION['method'])){
		$dMethod = $_SESSION['method'];
		$dUnits = $_SESSION['units'];
		$dModulus = $_SESSION['youngs_modulus'];
		$dPoisson = $_SESSION['poisson'];
		$dAngleGrade = $_SESSION['angle_grade'];
		$dBeamGrade = $_SESSION['beam_grade'];
		$dColumnGrade = $_SESSION['column_grade'];
		$dWeldGrade = $_SESSION['weld_grade'];
		$dBoltGrade = $_SESSION['bolt_grade'];
		$dTransferForce = $_SESSION['transfer_force'];
		$dShearForce = $_SESSION['shear_force'];
		$dBoltDia = $_SESSION['bolt_dia'];
		$dBoltType = $_SESSION['bolt_type'];
		$dBoltNumber = $_SESSION['bolt_number'];
		$dBoltGage = $_SESSION['bolt_gage'];
		$dBoltSpacing = $_SESSION['bolt_spacing'];
		$dWeldThickness = $_SESSION['weld_thickness'];
		$dClipAngle = $_SESSION['clip_angle'];
		$dOutstandingLeg = $_SESSION['oustanding_leg'];
		$dClipLength = $_SESSION['clip_length'];
		$dClipTop = $_SESSION['clip_top'];
		$dBeamSection = $_SESSION['beam_section'];
		$dSetback = $_SESSION['setback'];
		$dCopeLength = $_SESSION['cope_length'];
		$dTopCope = $_SESSION['top_cope'];
		$dBottomCope = $_SESSION['bottom_cope'];
		$dSupportSection = $_SESSION['support_section'];
		$dSupportType = $_SESSION['support_type'];
		$dBackingBeam = $_SESSION['backing_beam'];
		unset ($_SESSION['method']);
		unset ($_SESSION['units']);
		unset ($_SESSION['youngs_modulus']);
		unset ($_SESSION['poisson']);
		unset ($_SESSION['angle_grade']);
		unset ($_SESSION['beam_grade']);
		unset ($_SESSION['column_grade']);
		unset ($_SESSION['weld_grade']);
		unset ($_SESSION['bolt_grade']);
		unset ($_SESSION['transfer_force']);
		unset ($_SESSION['shear_force']);
		unset ($_SESSION['bolt_dia']);
		unset ($_SESSION['bolt_type']);
		unset ($_SESSION['bolt_number']);
		unset ($_SESSION['bolt_gage']);
		unset ($_SESSION['bolt_spacing']);
		unset ($_SESSION['weld_thickness']);
		unset ($_SESSION['clip_angle']);
		unset ($_SESSION['oustanding_leg']);
		unset ($_SESSION['clip_length']);
		unset ($_SESSION['clip_top']);
		unset ($_SESSION['beam_section']);
		unset ($_SESSION['setback']);
		unset ($_SESSION['cope_length']);
		unset ($_SESSION['top_cope']);
		unset ($_SESSION['bottom_cope']);
		unset ($_SESSION['support_section']);
		unset ($_SESSION['support_type']);
		unset ($_SESSION['backing_beam']);
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
		inputSelect('Support grade',array('A36','A992'),array('ASTM A36','ASTM A992'),$dColumnGrade,'column_grade');
		inputSelect('Weld grade',array('E70'),array('E70'),$dWeldGrade,'weld_grade');
		inputSelect('Bolt grade',array('A325','A490'),array('A325','A490'),$dBoltGrade,'bolt_grade');
		inputText("Young's modulus for steel",$dModulus,'youngs_modulus','stress');
		inputText("Poisson's ratio for steel",$dPoisson,'poisson');
	endTab();
	startTab('force_tab');
		inputText('Shear force',$dShearForce,'shear_force','force');
		inputText('Transfer force',$dTransferForce,'transfer_force','force');
	endTab();
	startTab('geometry_tab');
		inputSelect('Support type',array('BEAM','COLUMN_FLANGE','COLUMN_WEB'),array('Beam','Column flange','Column web'),$dSupportType,'support_type');
		inputSelect('Beam section','','','','beam_section');
		inputSelect('Support section','','','','support_section');
		inputSelect('Clip angle section','','','','clip_angle');
		inputSelect('Outstanding leg',array('LONG_LEG','SHORT_LEG'),array('Long leg','Short leg'),$dOutstandingLeg,'oustanding_leg');
		inputText('Cope depth at beam top (t)',$dTopCope,'top_cope','length');
		inputText('Cope depth at beam bottom (b)',$dBottomCope,'bottom_cope','length');
		inputText('Cope length in beam (c)',$dCopeLength,'cope_length','length');
		inputSelect('Bolt diameter','','','','bolt_dia');
		inputSelect('Bolt type',array('BEARING','FRICTION'),array('Bearing','Friction'),$dBoltType,'bolt_type');
		inputSelect('Consider backing beam',array('YES','NO'),array('Yes','No'),$dBackingBeam,'backing_beam');

	endTab();	
	startTab('details_tab');
		inputText('Number of bolts (n)',$dBoltNumber,'bolt_number');
		inputText('Bolt spacing (s)',$dBoltSpacing,'bolt_spacing','length');
		inputText('Bolt gage (g)', $dBoltGage,'bolt_gage','length');
		inputText('Weld thickness (w)',$dWeldThickness,'weld_thickness','length');
		inputText('Clip angle length (L)',$dClipLength,'clip_length','length');
		inputText('Top of clip angle (a)',$dClipTop,'clip_top','length');
		inputText('Connection setback (e)',$dSetback,'setback','length');

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
		<h3>Clip Angle Shear Connection</h3>
		<p>Type: Beam Connection<br>
		Code: SC001<br>
		Specification: AISC 360-2010</p>
		<p>A shear connection is used to connect a beam to a column or another beam. It is assumed to transfer no moment across this joint. Clip angles shop welded to the beam and field bolted to the supporting member, is a common shear connection detail due to its ease of fabrication and erection.</p>
		<div id="connection_image"> 
			<img src="./images/sc001_1.svg" class="img-responsive" id="img_beam" style="display:none;">
			<img src="./images/sc001_2.svg" class="img-responsive" id="img_col_web" style="display:none;">
			<img src="./images/sc001_3.svg" class="img-responsive" id="img_col_flange" style="display:none;">
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
			fillSelect('support_section',wSections_mm,<?= '"'.$dSupportSection.'"'?>);
		}
	});
	$.getJSON('wSections_in.json',function(data){
		wSections_in = data;
		if (defUnits == 'KIP_IN'){
			fillSelect('beam_section',wSections_in,<?= '"'.$dBeamSection.'"'?>);
			fillSelect('support_section',wSections_in,<?= '"'.$dSupportSection.'"'?>);
		}
	});
	$.getJSON('aSections_mm.json',function(data){
		aSections_mm = data;
		if (defUnits == 'NEWTON_MM')
			fillSelect('clip_angle',aSections_mm,<?= '"'.$dClipAngle.'"'?>);
	});	
	$.getJSON('aSections_in.json',function(data){
		aSections_in = data;
		if (defUnits == 'KIP_IN')
			fillSelect('clip_angle',aSections_in,<?= '"'.$dClipAngle.'"'?>);
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
		//update support sections
		oldValue = $('#support_section').val();
		if (curUnits == 'NEWTON_MM'){
			newValue = wSections_mm[oldValue];
			fillSelect('support_section',wSections_mm,newValue);
		}else{
			newValue = wSections_in[oldValue];
			fillSelect('support_section',wSections_in,newValue);
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
		$('#img_beam').attr('style','display:none');
		$('#img_col_web').attr('style','display:none');
		$('#img_col_flange').attr('style','display:none');
		switch($('#support_type').val()){
		case 'BEAM':
			$('#img_beam').attr('style','display:block;margin-left:auto;margin-right:auto;');
			break;
		case 'COLUMN_WEB':
			$('#img_col_web').attr('style','display:block;margin-left:auto;margin-right:auto;');
			break;
		case 'COLUMN_FLANGE':
			$('#img_col_flange').attr('style','display:block;margin-left:auto;margin-right:auto;');
			break;
		}
	});
	switch($('#support_type').val()){
	case 'BEAM':
		$('#img_beam').attr('style','display:block;margin-left:auto;margin-right:auto;');
		break;
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
