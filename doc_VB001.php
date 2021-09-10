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
		<h2>VB001 – Vertical Bracing Connection at Beam-Column Junction</h2>
		<p>
		Vertical bracings transfer the lateral loads in the structure to the foundations. A well-designed vertical bracing system is critical to the stability of the structure. While there are different configurations for vertical bracing connections the calculations described in this section is for the double angle vertical bracing connections at beam-column junctions.
		</p>
		<p>	
		Double angle sections are commonly used for bracing members. These are connected at the beam column junctions using a gusset plate. The forces generated at the gusset to beam-column interfaces are complex and indeterminate. The general approach to design these connections, is to assume a set of forces that satisfy equilibrium and to design the connecting elements to these forces. It is assumed that due to the ductility of steel, forces in the connection will redistribute and result in a safe design. This is known as the lower bound theorem of limit analysis.
		</p>
		<p>
		There have been many design methods suggested over the years that satisfy the above criteria. The most used method is the Uniform Force Method (UFM) as it is described in the AISC Steel Manual. Osoconn follows UFM for the design of this connection. 		
		</p>
		<p>
		The gusset plate is designed in tension assuming a 30deg dispersion angle or as is also known, the “Whitmore section”. Compression in the gusset plate is checked using an average unsupported buckling length calculated at three points: along the centreline of the brace and at the corners of the “Whitmore section” as described above.  Osoconn also does not check gusset edge buckling. To prevent this mode of failure it is advised to provide stiffener plates or angles near the gusset edge when the free edge length becomes excessive. One rule that the author has seen being commonly used is providing stiffeners when the free edge length exceeds 52 times the gusset thickness. 
		</p>
		<h3>Input Parameters</h3>
		<p>
		The input file for this connection requires the following parameters to run.
		</p>
		<table class ="table" style="font-family:monospace"><tr><th>Parameter</th><th>Acceptable value</th><th>Example</th></tr><tr><td>CONNECTION_CODE</td><td>VB001</td><td>CONNECTION_CODE VB001</td></tr><tr><td>CONNECTION_ID</td><td>Any alpha-numeric set of characters used to identify the connection.</td><td>CONNECTION_ID VERT_BR_54</td></tr><tr><td>METHOD</td><td>ASD|LRFD</td><td>METHOD ASD</td></tr><tr><td>UNITS</td><td>NEWTON_MM|KIP_IN</td><td>UNITS NEWTON_MM</td></tr><tr><td>MODULUS_OF_ELASTICITY</td><td>A positive number.</td><td>MODULUS_OF_ELASTICITY 200000</td></tr><tr><td>ANGLE_GRADE</td><td>A36|A992</td><td>ANGLE_GRADE A36</td></tr><tr><td>BEAM_GRADE</td><td>A36|A992</td><td>BEAM_GRADE A992</td></tr><tr><td>COLUMN_GRADE</td><td>A36|A992</td><td>COLUMN_GRADE A992</td></tr><tr><td>PLATE_GRADE</td><td>A36</td><td>PLATE_GRADE A36</td></tr><tr><td>WELD_ELECTRODE</td><td>E70</td><td>WELD_ELECTRODE E70</td></tr><tr><td>BOLT_GRADE</td><td>A325|A490</td><td>BOLT_GRADE A325</td></tr><tr><td>BRACE_FORCE</td><td>A numeric value.</td><td>BRACE_FORCE 750000</td></tr><tr><td>BEAM_SHEAR_FORCE</td><td>A numeric value.</td><td>BEAM_SHEAR_FORCE 30000</td></tr><tr><td>BEAM_TRANSFER_FORCE</td><td>A numeric value.</td><td>BEAM_TRANSFER_FORCE 15000</td></tr><tr><td>BEAM_SECTION</td><td>A valid AISC W-section</td><td>BEAM_SECTION W14x53</td></tr><tr><td>BRACE_SECTION</td><td>A valid AISC angle section</td><td>BRACE_SECTION L102X102X9.5</td></tr><tr><td>COLUMN_SECTION</td><td>A valid AISC W-section</td><td>COLUMN_SECTION W14x82</td></tr><tr><td>GUSSET_THICKNESS</td><td>A positive number.</td><td>GUSSET_THICKNESS 16</td></tr><tr><td>BOLT_DIAMETER</td><td>If unit is set to NEWTON_MM:<br>M16|M20|M22|M24|M27|M30|M36.<br>If unit is set to KIP_IN:<br>1/2|5/8|3/4|7/8|1|1_1/8|1_1/4|1_3/8|1_1/2.</td><td>BOLT_DIAMETER M22</td></tr><tr><td>BOLT_TYPE</td><td>BEARING|FRICTION</td><td>BOLT_TYPE BEARING</td></tr><tr><td>BOLT_GAGE</td><td>A positive number.</td><td>BOLT_GAGE 140</td></tr><tr><td>BOLT_GAGE_ON_BRACE</td><td>A positive number.</td><td>BOLT_GAGE_ON_BRACE 45</td></tr><tr><td>BOLT_SPACING</td><td>A positive number.</td><td>BOLT_SPACING 70</td></tr><tr><td>EDGE_DISTANCE_ON_BRACE</td><td>A positive number.</td><td>EDGE_DISTANCE_ON_BRACE 35</td></tr><tr><td>DGE_DISTANCE_ON_GUSSET</td><td>A positive number.</td><td>EDGE_DISTANCE_ON_GUSSET 35</td></tr><tr><td>EDGE_DISTANCE_ON_CLIP</td><td>A positive number.</td><td>EDGE_DISTANCE_ON_CLIP 35</td></tr><tr><td>NUMBER_OF_BOLTS_PER_ROW_ON_BRACE</td><td>An integer value greater or equal to 2.</td><td>NUMBER_OF_BOLTS_PER_ROW_ON_BRACE 5</td></tr><tr><td>NUMBER_OF_BOLT_ROWS_ON_BRACE</td><td>1|2</td><td>NUMBER_OF_BOLT_ROWS_ON_BRACE 1</td></tr><tr><td>BRACE_ANGLE</td><td>A numeric value between 20 and 80 inclusive.</td><td>BRACE_ANGLE 35</td></tr><tr><td>GUSSET_TO_BEAM_WELD</td><td>A positive number.</td><td>GUSSET_TO_BEAM_WELD 8</td></tr><tr><td>GUSSET_LENGTH</td><td>A positive number.</td><td>GUSSET_LENGTH 450</td></tr><tr><td>SUPPORT_TYPE</td><td>COLUMN_FLANGE|COLUMN_WEB</td><td>SUPPORT_TYPE COLUMN_FLANGE</td></tr><tr><td>CLIP_SECTION</td><td>A valid AISC angle section</td><td>CLIP_SECTION L127X76X12.7</td></tr><tr><td>CLIP_OUTSTANDING_LEG</td><td>LONG_LEG|SHORT_LEG</td><td>CLIP_OUTSTANDING_LEG LONG_LEG</td></tr><tr><td>NUMBER_OF_BOLTS_GUSSET_CLIP</td><td>An integer value greater or equal to 2.</td><td>NUMBER_OF_BOLTS_GUSSET_CLIP 5</td></tr><tr><td>NUMBER_OF_BOLT_BEAM_CLIP</td><td>An integer value greater or equal to 2.</td><td>NUMBER_OF_BOLT_BEAM_CLIP 3</td></tr><tr><td>CLIP_ANGLE_WELD_THICKNESS</td><td>A positive number.</td><td>CLIP_ANGLE_WELD_THICKNESS 6</td></tr><tr><td>GUSSET_CLIP_ANGLE_CLEARANCE</td><td>A positive number.</td><td>GUSSET_CLIP_ANGLE_CLEARANCE 50</td></tr></table>
		<?php
		drawFooter();
		?>
	</div>
</body>
</html>