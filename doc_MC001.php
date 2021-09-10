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
		<h2>MC001 - End Plate Moment Connection</h2>
		<p>
		Moment connections are designed to transfer moments in the beam to the supporting columns. Moment connections play an important part in the stability and lateral force resistance of the structure. Extended end plate moment connections are very popular among engineers due to their relative ease of fabrication and as they require no field welding. There is also extensive literature available on these types of connections especially with regard to seismic performance. 
		</p>
		<p>
		Osoconn allows three configurations of extended end plate moment connections: four-bolt unstiffened, four-bolt stiffened and eight-bolt stiffened configurations. The design procedure for these connections is covered in AISC design guide 4. 
		</p>
		<p>
		The column side checks are important in moment connection design as the behaviour of the column will significantly affect the performance of the connection. Osoconn checks the column flange in yielding, column web panel shear, web yielding and web crippling. It is assumed that the column is not an interior column with moment connections on both sides, hence column web buckling check is not done. If any of these checks fails stiffener plates or a doubler plate may be provided. It is worth noting that while it may not be feasible to design a moment connection for seismic applications without stiffeners, a doubler plate is a relatively expensive detail to fabricate and should be avoided, if possible, by providing a larger column section. The design of column stiffeners and doubler plates is covered in AISC design guide 13.
		</p>
		<h3>Input Parameters</h3>
		<p>
		The input file for this connection requires the following parameters to run.
		</p>
		<table class ="table" style="font-family:monospace"><tr><th>Parameter</th><th>Acceptable value</th><th>Example</th></tr><tr><td>CONNECTION_CODE</td><td>MC001</td><td>CONNECTION_CODE MC001</td></tr><tr><td>CONNECTION_ID</td><td>Any alpha-numeric set of characters used to identify the connection.</td><td>CONNECTION_ID MOM#23</td></tr><tr><td>METHOD</td><td>ASD|LRFD</td><td>METHOD LRFD</td></tr><tr><td>UNITS</td><td>NEWTON_MM|KIP_IN</td><td>UNITS NEWTON_MM</td></tr><tr><td>MODULUS_OF_ELASTICITY</td><td>A positive number</td><td>MODULUS_OF_ELASTICITY 200000</td></tr><tr><td>STEEL_GRADE_OF_PLATE</td><td>A36</td><td>STEEL_GRADE_OF_PLATE A36</td></tr><tr><td>STEEL_GRADE_OF_BEAM</td><td>A36|A992</td><td>STEEL_GRADE_OF_BEAM A36</td></tr><tr><td>STEEL_GRADE_OF_COLUMN</td><td>A36|A992</td><td>STEEL_GRADE_OF_COLUMN A36</td></tr><tr><td>WELD_ELECTRODE</td><td>E70</td><td>WELD_ELECTRODE E70</td></tr><tr><td>BOLT_GRADE</td><td>A325|A490</td><td>BOLT_GRADE A325</td></tr><tr><td>SHEAR_FORCE</td><td>A positive number</td><td>SHEAR_FORCE 100000</td></tr><tr><td>COLUMN_AXIAL_FORCE</td><td>A positive number</td><td>COLUMN_AXIAL_FORCE 500000</td></tr><tr><td>PLATE_WIDTH</td><td>A positive number</td><td>PLATE_WIDTH 240</td></tr><tr><td>PLATE_HEIGHT</td><td>A positive number</td><td>PLATE_HEIGHT 540</td></tr><tr><td>PLATE_THICKNESS</td><td>A positive number</td><td>PLATE_THICKNESS 30</td></tr><tr><td>BOLT_DIAMETER</td><td>If unit is set to NEWTON_MM:<br>M16|M20|M22|M24|M27|M30|M36.<br>If unit is set to KIP_IN:<br>1/2|5/8|3/4|7/8|1|1_1/8|1_1/4|1_3/8|1_1/2.</td><td>BOLT_DIAMETER M30</td></tr><tr><td>CONFIGURATION</td><td>4_BOLTS|4_BOLTS_STIFFENED|8_BOLTS_STIFFENED</td><td>CONFIGURATION 4_BOLTS_STIFFENED</td></tr><tr><td>BOLT_GAGE</td><td>A positive number</td><td>BOLT_GAGE 160</td></tr><tr><td>INNER_BOLT_TO_FLANGE</td><td>A positive number</td><td>INNER_BOLT_TO_FLANGE 45</td></tr><tr><td>OUTER_BOLT_TO_FLANGE</td><td>A positive number</td><td>OUTER_BOLT_TO_FLANGE 50</td></tr><tr><td>WEB_WELD</td><td>A positive number</td><td>WEB_WELD 6</td></tr><tr><td>FLANGE_WELD_REINFORCEMENT</td><td>A positive number</td><td>FLANGE_WELD_REINFORCEMENT 4</td></tr><tr><td>BEAM_SECTION</td><td>A valid AISC W section</td><td>BEAM_SECTION W360X51</td></tr><tr><td>COLUMN_SECTION</td><td>A valid AISC W section</td><td>COLUMN_SECTION W360X196</td></tr><tr><td>PLATE_STIFFENER_LENGTH</td><td>A positive number.<br>Required only if configuration is 4-bolt stiffened or 8-bolt stiffened.</td><td>PLATE_STIFFENER_LENGTH 200</td></tr><tr><td>PLATE_STIFFENER_THICKNESS</td><td>A positive number.<br>Required only if configuration is 4-bolt stiffened or 8-bolt stiffened.</td><td>PLATE_STIFFENER_THICKNESS 12</td></tr><tr><td>PLATE_STIFFENER_WELD</td><td>A positive number. Required only if configuration is 4-bolt stiffened or 8-bolt stiffened.</td><td>PLATE_STIFFENER_WELD 6</td></tr><tr><td>COLUMN_STIFFENER</td><td>YES|NO</td><td>COLUMN_STIFFENER YES</td></tr><tr><td>COLUMN_STIFFENER_THICKNESS</td><td>A positive number.<br>Required only if column stiffener is provided.</td><td>COLUMN_STIFFENER_THICKNESS 10</td></tr><tr><td>COLUMN_STIFFENER_WIDTH</td><td>A positive number.<br>Required only if column stiffener is provided.</td><td>COLUMN_STIFFENER_WIDTH 100</td></tr><tr><td>COLUMN_STIFFENER_CLIP</td><td>A positive number.<br>Required only if column stiffener is provided</td><td>COLUMN_STIFFENER_CLIP 35</td></tr><tr><td>COLUMN_STIFFENER_TO_FLANGE_WELD</td><td>A positive number.<br>Required only if column stiffener is provided</td><td>COLUMN_STIFFENER_TO_FLANGE_WELD 6</td></tr><tr><td>COLUMN_STIFFENER_TO_WEB_WELD</td><td>A positive number. Required only if column stiffener is provided</td><td>COLUMN_STIFFENER_TO_WEB_WELD 6</td></tr><tr><td>DOUBLER_PLATE</td><td>YES|NO</td><td>DOUBLER_PLATE YES</td></tr><tr><td>DOUBLER_PLATE_THICKNESS</td><td>A positive number.<br>Required only if doubler plate is provided</td><td>DOUBLER_PLATE_THICKNESS 20</td></tr><tr><td>DOUBLER_PLATE_WELD</td><td>A positive number.<br>Required only if doubler plate is provided</td><td>DOUBLER_PLATE_WELD 6</td></tr></table>		
		<?php
		drawFooter();
		?>
	</div>
</body>
</html>