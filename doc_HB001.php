<?php
require_once 'common.php';

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
<body>
	<?php
	drawNavBar('');
	?>
	<div class="container-fluid" style="max-width:992px; margin: 0 auto;">	
		<h2>HB001 – Horizontal Bracing Connection</h2>
		<p>
		Horizontal bracings transfer the lateral loads at a particular floor level of the structure to the vertical bracings or other lateral force resisting systems. Horizontal bracings are typically single or double angle sections connected to two beams through a gusset plate. Since these bracing connections are concentric, each gusset to beam connection is assumed to transfer only shear force which is the component of the brace force in the direction of these connections. These connections can be made either by using clip angles, shear tab or by directly bolting the gusset plate to the bottom flange of the beam. 
		</p>
		<p>
		The gusset plate is designed in tension assuming a 30deg dispersion angle or as is also known, the “Whitmore section”.  Osoconn does not check the gusset in compression hence it is assumed that the brace extends as close as possible to the work point to avoid buckling in the gusset plate. To achieve this, additional bolts may be detailed in the drawing at nominal spacing above that which is required by design. Osoconn also does not check gusset edge buckling. To prevent this mode of failure it is advised to provide stiffener plates or angles near the gusset edge when the free edge length becomes excessive. One rule that the author has seen being commonly used is providing stiffeners when the free edge length exceeds 52 times the gusset thickness. 
		</p>
		<h3>Input Parameters</h3>
		<p>
		The input file for this connection requires the following parameters to run.
		</p>
		<table class ="table" style="font-family:monospace"><tr><th>Parameter</th><th>Acceptable value</th><th>Example</th></tr><tr><td>CONNECTION_CODE</td><td>HB001</td><td>CONNECTION_CODE HB001</td></tr><tr><td>CONNECTION_ID</td><td>Any alpha-numeric set of characters used to identify the connection.</td><td>CONNECTION_ID HOR_12</td></tr><tr><td>METHOD</td><td>ASD|LRFD</td><td>METHOD ASD</td></tr><tr><td>UNITS</td><td>NEWTON_MM|KIP_IN</td><td>UNITS NEWTON_MM</td></tr><tr><td>BEAM_GRADE</td><td>A36|A992</td><td>BEAM_GRADE A992</td></tr><tr><td>ANGLE_GRADE</td><td>A36|A992</td><td>ANGLE_GRADE A36</td></tr><tr><td>PLATE_GRADE</td><td>A36</td><td>PLATE_GRADE A36</td></tr><tr><td>WELD_ELECTRODE</td><td>E70</td><td>WELD_ELECTRODE E70</td></tr><tr><td>BOLT_GRADE</td><td>A325|A490</td><td>BOLT_GRADE A325</td></tr><tr><td>BRACE_FORCE</td><td>Any numeric value</td><td>BRACE_FORCE 450000</td></tr><tr><td>BOLT_DIAMETER</td><td>If unit is set to NEWTON_MM:<br>M16|M20|M22|M24|M27|M30|M36.<br>If unit is set to KIP_IN:<br>1/2|5/8|3/4|7/8|1|1_1/8|1_1/4|1_3/8|1_1/2.</td><td>BOLT_DIAMETER M24</td></tr><tr><td>BOLT_TYPE</td><td>FRICTION|BEARING</td><td>BOLT_TYPE FRICTION</td></tr><tr><td>BOLT_SPACING</td><td>A positive number. </td><td>BOLT_SPACING 75</td></tr><tr><td>EDGE_DISTANCE_ON_GUSSET</td><td>A positive number.</td><td>EDGE_DISTANCE_ON_GUSSET 30</td></tr><tr><td>EDGE_DISTANCE_ON_BRACE</td><td>A positive number.</td><td>EDGE_DISTANCE_ON_BRACE 30</td></tr><tr><td>EDGE_DISTANCE_ON_TAB</td><td>A positive number.</td><td>EDGE_DISTANCE_ON_TAB 30</td></tr><tr><td>EDGE_DISTANCE_ON_CLIP</td><td>A positive number.</td><td>EDGE_DISTANCE_ON_CLIP 30</td></tr><tr><td>EDGE_DISTANCE_ON_BEAM</td><td>A positive number.</td><td>EDGE_DISTANCE_ON_BEAM 40</td></tr><tr><td>BOLT_GAGE_ON_BRACE</td><td>A positive number.</td><td>BOLT_GAGE_ON_BRACE 60</td></tr><tr><td>BOLT_GAGE_ON_CLIP</td><td>A positive number.</td><td>BOLT_GAGE_ON_CLIP 25</td></tr><tr><td>BOLT_GAGE_ON_TAB</td><td>A positive number.</td><td>BOLT_GAGE_ON_TAB 50</td></tr><tr><td>BRACE_ANGLE</td><td>A numeric value between 20 and 70 degrees.</td><td>BRACE_ANGLE 30</td></tr><tr><td>BRACE_SECTION</td><td>A valid AISC angle section.</td><td>BRACE_SECTION L127X76X12.7</td></tr><tr><td>BRACE_TYPE</td><td>SINGLE_ANGLE|DOUBLE_ANGLE</td><td>BRACE_TYPE DOUBLE_ANGLE</td></tr><tr><td>BACK_TO_BACK_LEG_ORIENTATION</td><td>HORIZONTAL|VERTICAL</td><td>BACK_TO_BACK_LEG_ORIENTATION HORIZONTAL</td></tr><tr><td>BRACE_OUTSTANDING_LEG</td><td>SHORT_LEG|LONG_LEG</td><td>BRACE_OUTSTANDING_LEG SHORT_LEG</td></tr><tr><td>BRACE_NUMBER_OF_BOLTS_PER_ROW</td><td>An integer value greater than or equal to 2. </td><td>BRACE_NUMBER_OF_BOLTS_PER_ROW 5</td></tr><tr><td>BRACE_NUMBER_OF_BOLT_</td><td>1|2</td><td>BRACE_NUMBER_OF_BOLT_ROWS 1</td></tr><tr><td>GUSSET_THICKNESS</td><td>A positive number.</td><td>GUSSET_THICKNESS 12</td></tr><tr><td>GUSSET_LENGTH_1</td><td>A positive number.</td><td>GUSSET_LENGTH_1 500</td></tr><tr><td>GUSSET_LENGTH_2</td><td>A positive number.</td><td>GUSSET_LENGTH_2 500</td></tr><tr><td>GUSSET_TOP_OFFSET</td><td>A positive number.</td><td>GUSSET_TOP_OFFSET 150</td></tr><tr><td>CONNECTION1_TYPE</td><td>CLIP_ANGLE|SHEAR_TAB| BOTTOM_FLANGE</td><td>CONNECTION1_TYPE CLIP_ANGLE</td></tr><tr><td>CONNECTION2_TYPE</td><td>CLIP_ANGLE|SHEAR_TAB| BOTTOM_FLANGE</td><td>CONNECTION2_TYPE SHEAR_TAB</td></tr><tr><td>CONNECTION1_NUMBER_OF_BOLTS</td><td>An integer value greater than or equal to 2.</td><td>CONNECTION1_NUMBER_OF_BOLTS 4</td></tr><tr><td>CONNECTION2_NUMBER_OF_BOLTS</td><td>An integer value greater than or equal to 2.</td><td>CONNECTION2_NUMBER_OF_BOLTS 5</td></tr><tr><td>CONNECTION1_LOCATION</td><td>A numeric value greater than or equal to 0.</td><td>CONNECTION1_LOCATION 180</td></tr><tr><td>CONNECTION2_LOCATION</td><td>A numeric value greater than or equal to 0.</td><td>CONNECTION2_LOCATION 180</td></tr><tr><td>TAB_WIDTH</td><td>A positive number.<br>Required only if either connection 1 or 2 is a shear tab.</td><td>TAB_WIDTH 150</td></tr><tr><td>TAB_THICKNESS</td><td>A positive number.<br>Required only if either connection 1 or 2 is a shear tab.</td><td>TAB_THICKNESS 10</td></tr><tr><td>TAB_TO_BEAM_WELD</td><td>A positive number.<br>Required only if either connection 1 or 2 is a shear tab.</td><td>TAB_TO_BEAM_WELD 6</td></tr><tr><td>CLIP_SECTION</td><td>A valid AISC angle section.<br>Required only if either connection 1 or 2 is a clip angle.</td><td>CLIP_SECTION L89X89X7.9</td></tr><tr><td>CLIP_OUTSTANDING_LEG</td><td>LONG_LEG|SHORT_LEG</td><td>CLIP_OUTSTANDING_LEG LONG_LEG</td></tr><tr><td>CLIP_TO_GUSSET_WELD</td><td>A positive number.<br>Required only if either connection 1 or 2 is a clip angle.</td><td>CLIP_TO_GUSSET_WELD 6</td></tr><tr><td>CONNECTION1_CUTOUT</td><td>A numeric value greater than or equal to 0.</td><td>CONNECTION1_CUTOUT 125</td></tr><tr><td>CONNECTION2_CUTOUT</td><td>A numeric value greater than or equal to 0.</td><td>CONNECTION2_CUTOUT 125</td></tr><tr><td>CONNECTION1_SETBACK</td><td>A positive number.</td><td>CONNECTION1_SETBACK 12</td></tr><tr><td>CONNECTION2_SETBACK</td><td>A positive number.</td><td>CONNECTION1_SETBACK 12</td></tr><tr><td>BEAM1_SECTION</td><td>A valid AISC W-section</td><td>BEAM1_SECTION W21x83</td></tr><tr><td>BEAM2_SECTION</td><td>A valid AISC W-section</td><td>BEAM2_SECTION W10x39</td></tr></table>
		<?php
		drawFooter();
		?>
	</div>
</body>
</html>