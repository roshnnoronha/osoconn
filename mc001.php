<?php
require_once 'common.php';
session_start();
$outputString = "";
if (isset($_POST['run'])){
	$_SESSION['method'] = $_POST['method'];
	$_SESSION['units'] = $_POST['units'];
	$_SESSION['youngs_modulus'] = $_POST['youngs_modulus'];
	$_SESSION['plate_grade'] = $_POST['plate_grade'];
	$_SESSION['beam_grade'] = $_POST['beam_grade'];
	$_SESSION['column_grade'] = $_POST['column_grade'];
	$_SESSION['weld_grade'] = $_POST['weld_grade'];
	$_SESSION['bolt_grade'] = $_POST['bolt_grade'];
	$_SESSION['column_force'] = $_POST['column_force'];
	$_SESSION['shear_force'] = $_POST['shear_force'];
	$_SESSION['plate_width'] = $_POST['plate_width'];
	$_SESSION['plate_height'] = $_POST['plate_height'];
	$_SESSION['plate_thickness'] = $_POST['plate_thickness'];
	$_SESSION['configuration'] = $_POST['configuration'];
	$_SESSION['bolt_dia'] = $_POST['bolt_dia'];
	$_SESSION['bolt_gage'] = $_POST['bolt_gage'];
	$_SESSION['bolt_spacing'] = $_POST['bolt_spacing'];
	$_SESSION['inner_bolt'] = $_POST['inner_bolt'];
	$_SESSION['outer_bolt'] = $_POST['outer_bolt'];
	$_SESSION['web_weld'] = $_POST['web_weld'];
	$_SESSION['weld_reinforcement'] = $_POST['weld_reinforcement'];
	$_SESSION['column_section'] = $_POST['column_section'];
	$_SESSION['beam_section'] = $_POST['beam_section'];
	$_SESSION['plate_stiffener_length'] = $_POST['plate_stiffener_length'];
	$_SESSION['plate_stiffener_thickness'] = $_POST['plate_stiffener_thickness'];
	$_SESSION['plate_stiffener_weld'] = $_POST['plate_stiffener_weld'];
	$_SESSION['column_stiffener'] = $_POST['column_stiffener'];	
	$_SESSION['column_stiffener_thickness'] = $_POST['column_stiffener_thickness'];	
	$_SESSION['column_stiffener_width'] = $_POST['column_stiffener_width'];
	$_SESSION['column_stiffener_clip'] = $_POST['column_stiffener_clip'];
	$_SESSION['stiffener_to_flange_weld'] = $_POST['stiffener_to_flange_weld'];
	$_SESSION['stiffener_to_web_weld'] = $_POST['stiffener_to_web_weld'];
	$_SESSION['doubler_plate'] = $_POST['doubler_plate'];
	$_SESSION['doubler_thickness'] = $_POST['doubler_thickness'];
	$_SESSION['doubler_weld'] = $_POST['doubler_weld'];

	$_SESSION['run'] = true;
	header('Location:mc001.php');
	return;
}
if (isset($_SESSION['run'])){	
	$inputString = 'CONNECTION_CODE MC001;';
	$inputString = $inputString.'CONNECTION_ID MC001;';
	$inputString = $inputString.'METHOD '.$_SESSION['method'].';';
	$inputString = $inputString.'UNITS '.$_SESSION['units'].';';
	$inputString = $inputString.'MODULUS_OF_ELASTICITY '.$_SESSION['youngs_modulus'].';';
	$inputString = $inputString.'STEEL_GRADE_OF_PLATE '.$_SESSION['plate_grade'].';';
	$inputString = $inputString.'STEEL_GRADE_OF_BEAM '.$_SESSION['beam_grade'].';';
	$inputString = $inputString.'STEEL_GRADE_OF_COLUMN '.$_SESSION['column_grade'].';';
	$inputString = $inputString.'WELD_ELECTRODE '.$_SESSION['weld_grade'].';';
	$inputString = $inputString.'BOLT_GRADE '.$_SESSION['bolt_grade'].';';
	$inputString = $inputString.'SHEAR_FORCE '.$_SESSION['shear_force'].';';
	$inputString = $inputString.'COLUMN_AXIAL_FORCE '.$_SESSION['column_force'].';';
	$inputString = $inputString.'PLATE_WIDTH '.$_SESSION['plate_width'].';';
	$inputString = $inputString.'PLATE_HEIGHT '.$_SESSION['plate_height'].';';
	$inputString = $inputString.'PLATE_THICKNESS '.$_SESSION['plate_thickness'].';';
	$inputString = $inputString.'CONFIGURATION '.$_SESSION['configuration'].';';
	$inputString = $inputString.'BOLT_DIAMETER '.$_SESSION['bolt_dia'].';';
	$inputString = $inputString.'BOLT_GAGE '.$_SESSION['bolt_gage'].';';
	if ($_SESSION['configuration'] != '4_BOLTS')
		$inputString = $inputString.'BOLT_SPACING '.$_SESSION['bolt_spacing'].';';
	$inputString = $inputString.'INNER_BOLT_TO_FLANGE '.$_SESSION['inner_bolt'].';';
	$inputString = $inputString.'OUTER_BOLT_TO_FLANGE '.$_SESSION['outer_bolt'].';';
	$inputString = $inputString.'WEB_WELD '.$_SESSION['web_weld'].';';
	$inputString = $inputString.'FLANGE_WELD_REINFORCEMENT '.$_SESSION['weld_reinforcement'].';';
	$inputString = $inputString.'BEAM_SECTION '.$_SESSION['beam_section'].';';
	$inputString = $inputString.'COLUMN_SECTION '.$_SESSION['column_section'].';';
	if ($_SESSION['configuration'] != '4_BOLTS'){
		$inputString = $inputString.'PLATE_STIFFENER_LENGTH '.$_SESSION['plate_stiffener_length'].';';
		$inputString = $inputString.'PLATE_STIFFENER_THICKNESS '.$_SESSION['plate_stiffener_thickness'].';';
		$inputString = $inputString.'PLATE_STIFFENER_WELD '.$_SESSION['plate_stiffener_weld'].';';	
	}
	$inputString = $inputString.'COLUMN_STIFFENER '.$_SESSION['column_stiffener'].';';
	if ($_SESSION['column_stiffener'] == 'YES'){
		$inputString = $inputString.'COLUMN_STIFFENER_THICKNESS '.$_SESSION['column_stiffener_thickness'].';';	
		$inputString = $inputString.'COLUMN_STIFFENER_WIDTH '.$_SESSION['column_stiffener_width'].';';
		$inputString = $inputString.'COLUMN_STIFFENER_CLIP '.$_SESSION['column_stiffener_clip'].';';
		$inputString = $inputString.'COLUMN_STIFFENER_TO_FLANGE_WELD '.$_SESSION['stiffener_to_flange_weld'].';';
		$inputString = $inputString.'COLUMN_STIFFENER_TO_WEB_WELD '.$_SESSION['stiffener_to_web_weld'].';';
	}
	$inputString = $inputString.'DOUBLER_PLATE '.$_SESSION['doubler_plate'].';';
	if ($_SESSION['doubler_plate'] == 'YES'){
		$inputString = $inputString.'DOUBLER_PLATE_THICKNESS '.$_SESSION['doubler_thickness'].';';
		$inputString = $inputString.'DOUBLER_PLATE_WELD '.$_SESSION['doubler_weld'].';';
	}
	
	$outputString = execute($inputString);
	unset($_SESSION['run']);
}
$dUnits = 'NEWTON_MM';
$dBeamSection = 'W200X41.7';
$dColumnSection = 'W460X177';
$dBoltDia = 'M22';

function drawInputForm(){
	//default values for input form
	$dMethod = 'LRFD';
	global $dUnits;
	$dModulus = '200000';
	$dPlateGrade = 'A36';
	$dBeamGrade = 'A36';
	$dColumnGrade = 'A36';
	$dWeldGrade = 'E70';
	$dBoltGrade = 'A325';
	$dShearForce = '0';
	$dColumnForce = '0';
	$dConfiguration = '4_BOLTS_UNSTIFFENED';
	global $dBeamSection;
	global $dColumnSection;
	$dPlateWidth = '300';
	$dPlateHeight = '400';
	$dPlateThickness = '20';
	$dPlateStiffenerLength = '0';
	$dPlateStiffenerThickness = '0';
	$dPlateStiffenerWeld = '0';
	global $dBoltDia;
	$dBoltGage = '140';
	$dBoltSpacing = '70';
	$dInnerBolt = '35';
	$dOuterBolt = '35';
	$dWebWeld = '6';
	$dWeldReinforcement = '4';
	$dColumnStiffener = 'NO';
	$dColumnStiffenerThickness = '0';
	$dColumnStiffenerWidth = '0';
	$dColumnStiffenerClip = '0';
	$dStiffenerToFlangeWeld = '0';
	$dStiffenerToWebWeld = '0';
	$dDoublerPlate = 'NO';
	$dDoublerThickness = '0';
	$dDoublerWeld = '0';


	//check to see if values present in sessions
	if (isset($_SESSION['method'])){
		$dMethod = $_SESSION['method'];
		$dUnits = $_SESSION['units'];
		$dModulus = $_SESSION['youngs_modulus'];
		$dPlateGrade = $_SESSION['plate_grade'];
		$dBeamGrade = $_SESSION['beam_grade'];
		$dColumnGrade = $_SESSION['column_grade'];
		$dWeldGrade = $_SESSION['weld_grade'];
		$dBoltGrade = $_SESSION['bolt_grade'];
		$dShearForce = $_SESSION['shear_force'];
		$dColumnForce = $_SESSION['column_force'];
		$dConfiguration = $_SESSION['configuration'];
		$dBeamSection = $_SESSION['beam_section'];
		$dColumnSection = $_SESSION['column_section'];
		$dPlateWidth = $_SESSION['plate_width'];
		$dPlateHeight = $_SESSION['plate_height'];
		$dPlateThickness = $_SESSION['plate_thickness'];			
		$dPlateStiffenerLength = $_SESSION['plate_stiffener_length'];
		$dPlateStiffenerThickness = $_SESSION['plate_stiffener_thickness'];
		$dPlateStiffenerWeld = $_SESSION['plate_stiffener_weld'];
		$dBoltDia = $_SESSION['bolt_dia'];
		$dBoltGage = $_SESSION['bolt_gage'];		
		$dBoltSpacing = $_SESSION['bolt_spacing'];
		$dInnerBolt = $_SESSION['inner_bolt'];	
		$dOuterBolt = $_SESSION['outer_bolt'];
		$dWebWeld = $_SESSION['web_weld'];		
		$dWeldReinforcement = $_SESSION['weld_reinforcement'];
		$dColumnStiffener = $_SESSION['column_stiffener'];
		$dColumnStiffenerThickness = $_SESSION['column_stiffener_thickness'];
		$dColumnStiffenerWidth = $_SESSION['column_stiffener_width'];
		$dColumnStiffenerClip = $_SESSION['column_stiffener_clip'];
		$dStiffenerToFlangeWeld = $_SESSION['stiffener_to_flange_weld'];
		$dStiffenerToWebWeld = $_SESSION['stiffener_to_web_weld'];
		$dDoublerPlate = $_SESSION['doubler_plate'];
		$dDoublerThickness = $_SESSION['doubler_thickness'];
		$dDoublerWeld = $_SESSION['doubler_weld'];
		
		unset ($_SESSION['method']);
		unset ($_SESSION['units']);
		unset ($_SESSION['youngs_modulus']);
		unset ($_SESSION['plate_grade']);
		unset ($_SESSION['beam_grade']);
		unset ($_SESSION['column_grade']);
		unset ($_SESSION['weld_grade']);
		unset ($_SESSION['bolt_grade']);
		unset ($_SESSION['column_force']);
		unset ($_SESSION['shear_force']);
		unset ($_SESSION['plate_width']);
		unset ($_SESSION['plate_height']);
		unset ($_SESSION['plate_thickness']);
		unset ($_SESSION['configuration']);
		unset ($_SESSION['bolt_dia']);
		unset ($_SESSION['bolt_gage']);
		unset ($_SESSION['bolt_spacing']);
		unset ($_SESSION['web_weld']);
		unset ($_SESSION['weld_reinforcement']);
		unset ($_SESSION['column_section']);
		unset ($_SESSION['beam_section']);
		unset ($_SESSION['plate_stiffener_length']);
		unset ($_SESSION['plate_stiffener_thickness']);
		unset ($_SESSION['plate_stiffener_weld']);
		unset ($_SESSION['column_stiffener']);
		unset ($_SESSION['column_stiffener_thickness']);
		unset ($_SESSION['column_stiffener_width']);
		unset ($_SESSION['column_stiffener_clip']);
		unset ($_SESSION['stiffener_to_flange_weld']);
		unset ($_SESSION['stiffener_to_web_weld']);
		unset ($_SESSION['doubler_plate']);
		unset ($_SESSION['doubler_thickness']);
		unset ($_SESSION['doubler_weld']);
	}
	
	//draw input form
	echo('<div id="input_area">');
	echo('<form method="post" class="form-horizontal">');
	$tabList = array('General','Materials','Forces','Geometry','Details','Stiffeners');
	$tabIDList = array('general_tab','material_tab','force_tab','geometry_tab','details_tab','stiffener_tab');
	startTabGroup($tabList,$tabIDList);
	startTab('general_tab',true);
		inputSelect('Unit system',array('NEWTON_MM','KIP_IN'), array('Newton,mm','kip,in'),$dUnits,'units');
		inputSelect('Design method',array('LRFD','ASD'),array('LRFD','ASD'),$dMethod,'method');
	endTab();
	startTab('material_tab');
		inputSelect('Plate grade',array('A36'),array('ASTM A36'),$dPlateGrade,'plate_grade');
		inputSelect('Beam grade',array('A36','A992'),array('ASTM A36','ASTM A992'),$dBeamGrade,'beam_grade');
		inputSelect('Column grade',array('A36','A992'),array('ASTM A36','ASTM A992'),$dWeldGrade,'column_grade');
		inputSelect('Weld grade',array('E70'),array('E70'),'','weld_grade');
		inputSelect('Bolt grade',array('A325','A490'),array('A325','A490'),$dBoltGrade,'bolt_grade');
		inputText("Young's modulus for steel",$dModulus,'youngs_modulus','stress');
	endTab();
	startTab('force_tab');
		inputText('Shear force',$dShearForce,'shear_force','force');
		inputText('Column axial force',$dColumnForce,'column_force','force');
	endTab();
	startTab('geometry_tab');
		inputSelect('Connection configuration',array('4_BOLTS','4_BOLTS_STIFFENED','8_BOLTS_STIFFENED'),array('4 Bolts Unstiffened','4 Bolts Stiffened','8 Bolts Stiffened'),$dConfiguration,'configuration');
		inputSelect('Beam section','','','','beam_section');
		inputSelect('Column section','','','','column_section');
		inputSelect('Bolt diameter','','','','bolt_dia');
		inputText('End plate width (B)',$dPlateWidth,'plate_width','length');
		inputText('End plate height (H)',$dPlateHeight,'plate_height','length');
		inputText('End plate thickness (t)',$dPlateThickness,'plate_thickness','length');
		inputSelect('Provide column stiffener?',array('YES','NO'),array('Yes','No'),$dColumnStiffener,'column_stiffener');
		inputSelect('Provide doubler plate?',array('YES','NO'),array('Yes','No'),$dDoublerPlate,'doubler_plate');
	endTab();	
	startTab('details_tab');
		inputText('Bolt spacing (s)',$dBoltSpacing,'bolt_spacing','length');
		inputText('Inner bolt pitch (pi)',$dInnerBolt,'inner_bolt','length');
		inputText('Outer bolt pitch (po)',$dOuterBolt,'outer_bolt','length');
		inputText('Bolt gage (g)', $dBoltGage,'bolt_gage','length');
		inputText('Web weld thickness (w1)',$dWebWeld,'web_weld','length');
		inputText('Flange weld reinforcement (w2)',$dWeldReinforcement,'weld_reinforcement','length');
	endTab();
	startTab('stiffener_tab');
		inputText('Plate stiffener length (lp)',$dPlateStiffenerLength,'plate_stiffener_length','length');
		inputText('Plate stiffener thickness (tp)',$dPlateStiffenerThickness,'plate_stiffener_thickness','length');
		inputText('Plate stiffener weld (w3)',$dPlateStiffenerWeld,'plate_stiffener_weld','length');
		inputText('Column stiffener thickness (ts)',$dColumnStiffenerThickness,'column_stiffener_thickness','length');
		inputText('Column stiffener width (ws)',$dColumnStiffenerWidth,'column_stiffener_width','length');
		inputText('Column stiffener clip (c)',$dColumnStiffenerClip,'column_stiffener_clip','length');
		inputText('Stiffener to column flange weld (w4)',$dStiffenerToFlangeWeld,'stiffener_to_flange_weld','length');
		inputText('Stiffener to column web weld (w5)',$dStiffenerToWebWeld,'stiffener_to_web_weld','length');
		inputText('Doubler plate thickness (td)',$dDoublerThickness,'doubler_thickness','length');
		inputText('Doubler plate weld thickness (w6)',$dDoublerWeld,'doubler_weld','length');
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
		<h3>End Plate Moment Connection (Seismic applications)</h3>
		<p>Type: Beam Connection<br>
		Code: MC001<br>
		Specification: AISC 360-2010, AISC 341</p>
		<p>Moment connections are used in lateral force resisting systems to transfer moments and to provide stability to the structure. The bolted end plate moment connection is a very commonly used detail due to its ease of fabrication and erection. </p>
		<div id="connection_image"> 
			<img src="./images/mc001_1.svg" class="img-responsive" id="img_4_bolt_unstiffened" style="display:none;">
			<img src="./images/mc001_2.svg" class="img-responsive" id="img_4_bolt_stiffened" style="display:none;">
			<img src="./images/mc001_3.svg" class="img-responsive" id="img_8_bolt_stiffened" style="display:none;">
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
		oldValue = $('#column_section').val();
		if (curUnits == 'NEWTON_MM'){
			newValue = wSections_mm[oldValue];
			fillSelect('column_section',wSections_mm,newValue);
		}else{
			newValue = wSections_in[oldValue];
			fillSelect('column_section',wSections_in,newValue);
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
	$('#configuration').change(function(){
		$('#img_4_bolt_unstiffened').attr('style','display:none');
		$('#img_4_bolt_stiffened').attr('style','display:none');
		$('#img_8_bolt_stiffened').attr('style','display:none');
		switch($('#configuration').val()){
		case '4_BOLTS':
			$('#img_4_bolt_unstiffened').attr('style','display:block;margin-left:auto;margin-right:auto;');
			break;
		case '4_BOLTS_STIFFENED':
			$('#img_4_bolt_stiffened').attr('style','display:block;margin-left:auto;margin-right:auto;');
			break;
		case '8_BOLTS_STIFFENED':
			$('#img_8_bolt_stiffened').attr('style','display:block;margin-left:auto;margin-right:auto;');
			break;
		}
		if ($('#configuration').val() == '4_BOLTS'){
			$('#bolt_spacing').attr('disabled','disabled');		
			$('#plate_stiffener_length').attr('disabled','disabled');
			$('#plate_stiffener_thickness').attr('disabled','disabled');
			$('#plate_stiffener_weld').attr('disabled','disabled');			
		}else{
			$('#bolt_spacing').removeAttr('disabled');
			$('#plate_stiffener_length').removeAttr('disabled');
			$('#plate_stiffener_thickness').removeAttr('disabled');
			$('#plate_stiffener_weld').removeAttr('disabled');			
		}
	});
	$('#column_stiffener').change(function(){
		if ($('#column_stiffener').val() == 'YES'){
			$('#column_stiffener_thickness').removeAttr('disabled');
			$('#column_stiffener_width').removeAttr('disabled');
			$('#column_stiffener_clip').removeAttr('disabled');
			$('#stiffener_to_flange_weld').removeAttr('disabled');
			$('#stiffener_to_web_weld').removeAttr('disabled');			
		}else{
			$('#column_stiffener_thickness').attr('disabled','disabled');
			$('#column_stiffener_width').attr('disabled','disabled');
			$('#column_stiffener_clip').attr('disabled','disabled');
			$('#stiffener_to_flange_weld').attr('disabled','disabled');
			$('#stiffener_to_web_weld').attr('disabled','disabled');			
		}
	});
	$('#doubler_plate').change(function(){
		if ($('#doubler_plate').val() == 'YES'){
			$('#doubler_thickness').removeAttr('disabled');
			$('#doubler_weld').removeAttr('disabled');
		}else{
			$('#doubler_thickness').attr('disabled','disabled');
			$('#doubler_weld').attr('disabled','disabled');
		}	
	});
	
	//start-up code
	switch($('#configuration').val()){
	case '4_BOLTS':
		$('#img_4_bolt_unstiffened').attr('style','display:block;margin-left:auto;margin-right:auto;');
		break;
	case '4_BOLTS_STIFFENED':
		$('#img_4_bolt_stiffened').attr('style','display:block;margin-left:auto;margin-right:auto;');
		break;
	case '8_BOLTS_STIFFENED':
		$('#img_8_bolt_stiffened').attr('style','display:block;margin-left:auto;margin-right:auto;');
		break;
	}
	if ($('#configuration').val() == '4_BOLTS'){
		$('#bolt_spacing').attr('disabled','disabled');		
		$('#plate_stiffener_length').attr('disabled','disabled');
		$('#plate_stiffener_thickness').attr('disabled','disabled');
		$('#plate_stiffener_weld').attr('disabled','disabled');			
	}else{
		$('#bolt_spacing').removeAttr('disabled');		
		$('#plate_stiffener_length').removeAttr('disabled');
		$('#plate_stiffener_thickness').removeAttr('disabled');
		$('#plate_stiffener_weld').removeAttr('disabled');			
	}
	if ($('#column_stiffener').val() == 'YES'){
		$('#column_stiffener_thickness').removeAttr('disabled');
		$('#column_stiffener_width').removeAttr('disabled');
		$('#column_stiffener_clip').removeAttr('disabled');
		$('#stiffener_to_flange_weld').removeAttr('disabled');
		$('#stiffener_to_web_weld').removeAttr('disabled');			
	}else{
		$('#column_stiffener_thickness').attr('disabled','disabled');
		$('#column_stiffener_width').attr('disabled','disabled');
		$('#column_stiffener_clip').attr('disabled','disabled');
		$('#stiffener_to_flange_weld').attr('disabled','disabled');
		$('#stiffener_to_web_weld').attr('disabled','disabled');			
	}
	if ($('#doubler_plate').val() == 'YES'){
		$('#doubler_thickness').removeAttr('disabled');
		$('#doubler_weld').removeAttr('disabled');
	}else{
		$('#doubler_thickness').attr('disabled','disabled');
		$('#doubler_weld').attr('disabled','disabled');
	}	


});
</script>

</html>
