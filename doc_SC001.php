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
		<h2>SC001 - Clip Angle Shear Connections</h2>
		<p>
		Double clip angles welded to the beam and bolted to the supporting member is a very common detail for beam shear connections. The popularity of this connection is due to its ease of fabrication and erection. The connection can be welded in the fabrication shop and bolted to the supporting member at site.
		</p>
		<p>
		Shear connections are assumed to transfer no moment across the connections. This rotational flexibility is assumed to be provided by the relative flexibility of the clip angle outstanding legs.
		</p>
		<h3>Input Parameters</h3>
		<p>
		The input file for this connection requires the following parameters to run.
		</p>
		<table class ="table" style="font-family:monospace"><tr><th>Parameter</th><th>Acceptable value</th><th>Example</th></tr><tr><td>CONNECTION_CODE</td><td>SC001</td><td>CONNECTION_CODE SC001</td></tr><tr><td>CONNECTION_ID</td><td>Any alpha-numeric set of characters used to identify the connection.</td><td>CONNECTION_ID SHEAR03</td></tr><tr><td>METHOD</td><td>ASD|LRFD</td><td>METHOD ASD</td></tr><tr><td>UNITS</td><td>NEWTON_MM|KIP_IN</td><td>UNITS NEWTON_MM</td></tr><tr><td>MODULUS_OF_ELASTICITY</td><td>A positive number</td><td>MODULUS_OF_ELASTICITY 200000</td></tr><tr><td>POISSON_RATIO</td><td>A positive number between 0 and 0.5</td><td>POISSON_RATIO 0.3</td></tr><tr><td>STEEL_GRADE_OF_ANGLE</td><td>A36|A992</td><td>STEEL_GRADE_OF_ANGLE A36</td></tr><tr><td>STEEL_GRADE_OF_BEAM</td><td>A36|A992</td><td>STEEL_GRADE_OF_BEAM A36</td></tr><tr><td>WELD_ELECTRODE</td><td>E70</td><td>WELD_ELECTRODE E70</td></tr><tr><td>BOLT_GRADE</td><td>A325|A490</td><td>BOLT_GRADE A325</td></tr><tr><td>TRANSFER_FORCE</td><td>Any numeric value</td><td>TRANSFER_FORCE 15000</td></tr><tr><td>SHEAR_FORCE</td><td>Any numeric value</td><td>SHEAR_FORCE 90000</td></tr><tr><td>BOLT_DIAMETER</td><td>If unit is set to NEWTON_MM:<br>M16|M20|M22|M24|M27|M30|M36.<br>If unit is set to KIP_IN:<br>1/2|5/8|3/4|7/8|1|1_1/8|1_1/4|1_3/8|1_1/2.</td><td>BOLT_DIAMETER M22</td></tr><tr><td>BOLT_TYPE</td><td>BEARING|FRICTION</td><td>BOLT_TYPE FRICTION</td></tr><tr><td>THREAD_INCLUDED_IN_SHEAR</td><td>YES|NO<br>Required for only bearing type bolts.</td><td>THREAD_INCLUDED_IN_SHEAR YES</td></tr><tr><td>FAYING_SURFACE</td><td>CLASS_A|CLASS_B<br>Required only for friction type bolts.</td><td>FAYING_SURFACE CLASS_A</td></tr><tr><td>NUMBER_OF_BOLTS_PER_ROW</td><td>Integer greater than or equal to 2</td><td>NUMBER_OF_BOLTS_PER_ROW 4</td></tr><tr><td>BOLT_GAGE</td><td>A positive number</td><td>BOLT_GAGE 140</td></tr><tr><td>BOLT_SPACING</td><td>A positive number</td><td>BOLT_SPACING 60</td></tr><tr><td>THICKNESS_OF_WELD</td><td>A positive number</td><td>THICKNESS_OF_WELD 8</td></tr><tr><td>BEAM_SECTION</td><td>A valid AISC W section</td><td>BEAM_SECTION W410X67</td></tr><tr><td>CONNECTION_SETBACK</td><td>A positive number</td><td>CONNECTION_SETBACK 12</td></tr><tr><td>COPE_LENGTH</td><td>A positive number</td><td>COPE_LENGTH 100</td></tr><tr><td>TOP_COPE_DEPTH</td><td>A positive number</td><td>TOP_COPE_DEPTH 35</td></tr><tr><td>BOTTOM_COPE_DEPTH</td><td>A positive number</td><td>BOTTOM_COPE_DEPTH 35</td></tr><tr><td>SUPPORT_SECTION</td><td>A valid AISC W section</td><td>SUPPORT_SECTION W410X67</td></tr><tr><td>SUPPORT_TYPE</td><td>BEAM|COLUMN_FLANGE|COLUMN_WEB</td><td>SUPPORT_TYPE BEAM</td></tr><tr><td>BACKING_BEAM</td><td>YES|NO</td><td>BACKING_BEAM YES</td></tr><tr><td>CLIP_ANGLE</td><td>A valid AISC angle section</td><td>CLIP_ANGLE L102X102X9.5</td></tr><tr><td>OUTSTANDING_LEG</td><td>LONG_LEG|SHORT_LEG</td><td>OUTSTANDING_LEG LONG_LEG</td></tr><tr><td>CLIP_ANGLE_LENGTH</td><td>A positive number</td><td>CLIP_ANGLE_LENGTH 240</td></tr><tr><td>CLIP_ANGLE_TOP</td><td>A positive number</td><td>CLIP_ANGLE_TOP 40</td></tr></table>

		<?php
		drawFooter();
		?>
	</div>
</body>
</html>