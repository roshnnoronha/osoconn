<?php
require_once '../util/common.php';

?>
<!DOCTYPE html>
<html lang ="en">
<head>
    <?php
    printHeader();
    ?>
</head>
<body>
	<?php
	drawNavBar('doc');
	?>
    <div class="container">
    <div class="row">
    <div class="col-sm-3">
    <?php
    drawDocSidebar('vb001');
    ?>
    </div>
	<div class="container col-sm-9">	
		<h2>VB001AM10 <small>DOUBLE ANGLE BEAM-COLUMN VERTICAL BRACING CONNECTION</small></h2>
		<p>
Vertical bracing transfer the lateral loads in the structure to the
foundations. A well-designed vertical bracing system is critical to the
stability of the structure. While there are different configurations for
vertical bracing connections the calculations described in this section is for
the double angle vertical bracing connections at beam-column junctions. The
brace may frame into either the column flange or the column web.
		</p>
        <img src="images/VB001AM10.svg" class="img-rounded img-responsive" alt="vb001am10 support types" width="50%" >
        <h4>Validation record</h4>
		<p>
The design checks performed by the program are verified against a series of
manually performed calculations to verify the output. The complete validation
document for this connection can be downloaded <a href="validation_docs/vb001am10.pdf">here</a>.
		</p>
        <h4>Fit-up checks </h4>
        <p>
The following checks for fit-up of the connection are performed by the program.        
        <ul>
        <li>Checks for minimum bolt spacing as per AISC360.</li>
        <li>Checks for minimum bolt edge distance at brace as per AISC360.</li>
        <li>Checks for minimum bolt edge distance at gusset as per AISC360.</li>
        <li>Checks for minimum bolt edge distance at clip angle as per AISC360.</li>
        <li>Checks for minimum bolt edge distance on column flange as per AISC360.</li>
        <li>Checks for bolt clash with brace fillet area.</li>
        <li>Checks for bolt clash with clip fillet area.</li>
        <li>Checks for bolt clash with column fillet area.</li>
        <li>Checks for gusset clip angle clash with gusset to beam weld.</li>
        <li>Checks for beam clip angle clash with beam fillet area.</li>
        </ul>
        </p>
        <h4>Design checks </h4>
        <p>
The following design checks are performed by the program.
        <ul>
        <li>Checks for brace rupture</li>
        <li>Checks for bolt shear at brace</li>
        <li>Checks for bolt bearing at brace</li>
        <li>Checks for bolt bearing at gusset</li>
        <li>Checks for brace block shear</li>
        <li>Checks for gusset plate block shear</li>
        <li>Checks for gusset tension yielding</li>
        <li>Checks for gusset tension rupture</li>
        <li>Checks for gusset plate compression buckling</li>
        <li>Checks for bolt shear at beam to column connection</li>
        <li>Checks for bolt bearing on clip at beam to column connection</li>
        <li>Checks for bolt bearing on flange at beam to column connection</li>
        <li>Checks for weld at beam to column connection</li>
        <li>Checks for web rupture at beam to column connection weld</li>
        <li>Checks for bolt tension at beam to column connection</li>
        <li>Checks for clip angle prying at beam to column connection</li>
        <li>Checks for clip shear yielding at beam to column connection</li>
        <li>Checks for clip shear rupture at beam to column connection</li>
        <li>Checks for clip block shear at beam to column connection</li>
        <li>Checks for flange prying at beam to column connection</li>
        <li>Checks for column web yielding at beam to column connection</li>
        <li>Checks for column web crippling at beam to column connection</li>
        <li>Checks for column web shear at beam to column connection</li>
        <li>Checks for weld at gusset to beam connection</li>
        <li>Checks for gusset rupture at gusset to beam connection</li>
        <li>Checks for local web yielding at gusset to beam connection</li>
        <li>Checks for local web crippling at gusset to beam connection</li>
        <li>Checks for web shear at gusset to beam connection</li>
        <li>Checks for bolt shear at gusset to column connection</li>
        <li>Checks for bolt bearing on clip at gusset to column connection</li>
        <li>Checks for bolt bearing on column at gusset to column connection</li>
        <li>Checks for bolt tension at gusset to column connection</li>
        <li>Checks for clip angle prying at gusset to column connection</li>
        <li>Checks for weld at gusset to column connection</li>
        <li>Checks for gusset rupture at gusset to column connection weld</li>
        <li>Checks for block shear at gusset to column connection clip</li>
        <li>Checks for clip shear yielding at gusset to column connection</li>
        <li>Checks for clip shear rupture at gusset to column connection</li>
        <li>Checks for flange prying at gusset to column connection</li>
        <li>Checks for column web yielding at gusset to column connection</li>
        <li>Checks for column web crippling at gusset to column connection</li>
        </ul>
        </p>
        <h4>Assumptions in design</h4>
		<p>
The following assumptions are made while performing the design of the connection.
        <ul>
        <li>The forces in the connection are calculated using the Uniform Force Method (UFM) </li>
        <li>Beam forces and UFM forces are conservatively considered additive.</li>
        <li>The gusset plate is designed in tension assuming a 30deg dispersion angle or as is also known, the “Whitmore section”.</li>
        <li> Compression in the gusset plate is checked using an average unsupported buckling length calculated at three points: along the centreline of the brace and at the corners of the “Whitmore section” as described above. </li>
        <li> Osoconn also does not check gusset edge buckling. To prevent this mode of failure it is advised to provide stiffener plates or angles near the gusset edge when the free edge length becomes excessive. </li>
        <li>Bearing check assumes deformation at bolt hole is a service consideration.</li>
        <li>Local web crippling check conservatively assumes that the connection is near the edge of the column.</li>
        </ul>
		</p>
		<h3>Input parameters</h3>
		<p>
The input file for this connection requires the following parameters to run.
		</p>
        <table class ="table" style="font-family:monospace">
        <tr><th>Parameter</th><th>Acceptable value</th><th>Example</th></tr>
        <tr><td>CONNECTION_CODE</td><td>VB001AM10</td><td>CONNECTION_CODE VB001AM10</td></tr>
        <tr><td>CONNECTION_ID</td><td>Any alpha-numeric set of characters used to identify the connection.</td><td>CONNECTION_ID VERT_BR_54</td></tr>
        <tr><td>METHOD</td><td>ASD|LRFD</td><td>METHOD ASD</td></tr>
        <tr><td>UNITS</td><td>NEWTON_MM|KIP_IN</td><td>UNITS NEWTON_MM</td></tr>
        <tr><td>MODULUS_OF_ELASTICITY</td><td>A positive number.</td><td>MODULUS_OF_ELASTICITY 200000</td></tr>
        <tr><td>ANGLE_GRADE</td><td>A36|A992</td><td>ANGLE_GRADE A36</td></tr>
        <tr><td>BEAM_GRADE</td><td>A36|A992</td><td>BEAM_GRADE A992</td></tr>
        <tr><td>COLUMN_GRADE</td><td>A36|A992</td><td>COLUMN_GRADE A992</td></tr>
        <tr><td>PLATE_GRADE</td><td>A36</td><td>PLATE_GRADE A36</td></tr>
        <tr><td>WELD_ELECTRODE</td><td>E70</td><td>WELD_ELECTRODE E70</td></tr>
        <tr><td>BOLT_GRADE</td><td>A325|A490</td><td>BOLT_GRADE A325</td></tr>
        <tr><td>BRACE_FORCE</td><td>A numeric value.</td><td>BRACE_FORCE 750000</td></tr>
        <tr><td>BEAM_SHEAR_FORCE</td><td>A numeric value.</td><td>BEAM_SHEAR_FORCE 30000</td></tr>
        <tr><td>BEAM_TRANSFER_FORCE</td><td>A numeric value.</td><td>BEAM_TRANSFER_FORCE 15000</td></tr>
        <tr><td>BEAM_SECTION</td><td>A valid AISC W-section</td><td>BEAM_SECTION W14x53</td></tr>
        <tr><td>BRACE_SECTION</td><td>A valid AISC angle section</td><td>BRACE_SECTION L102X102X9.5</td></tr>
        <tr><td>COLUMN_SECTION</td><td>A valid AISC W-section</td><td>COLUMN_SECTION W14x82</td></tr>
        <tr><td>GUSSET_THICKNESS</td><td>A positive number.</td><td>GUSSET_THICKNESS 16</td></tr>
        <tr><td>BOLT_DIAMETER</td><td>If unit is set to NEWTON_MM:<br>M16|M20|M22|M24|M27|M30|M36.<br>If unit is set to KIP_IN:<br>1/2|5/8|3/4|7/8|1|1_1/8|1_1/4|1_3/8|1_1/2.</td><td>BOLT_DIAMETER M22</td></tr>
        <tr><td>BOLT_TYPE</td><td>BEARING|FRICTION</td><td>BOLT_TYPE BEARING</td></tr>
        <tr><td>THREAD_INCLUDED_IN_SHEAR</td><td>YES|NO</td><td>THREAD_INCLUDED_IN_SHEAR YES</td></tr>
        <tr><td>FAYING_SURFACE</td><td>CLASS_A|CLASS_B</td><td>FAYING_SURFACE CLASS_A</td></tr>
        <tr><td>BOLT_GAGE</td><td>A positive number.</td><td>BOLT_GAGE 140</td></tr>
        <tr><td>BOLT_GAGE_ON_BRACE</td><td>A positive number.</td><td>BOLT_GAGE_ON_BRACE 45</td></tr>
        <tr><td>BOLT_SPACING</td><td>A positive number.</td><td>BOLT_SPACING 70</td></tr>
        <tr><td>EDGE_DISTANCE_ON_BRACE</td><td>A positive number.</td><td>EDGE_DISTANCE_ON_BRACE 35</td></tr>
        <tr><td>EDGE_DISTANCE_ON_GUSSET</td><td>A positive number.</td><td>EDGE_DISTANCE_ON_GUSSET 35</td></tr>
        <tr><td>EDGE_DISTANCE_ON_CLIP</td><td>A positive number.</td><td>EDGE_DISTANCE_ON_CLIP 35</td></tr>
        <tr><td>NUMBER_OF_BOLTS_PER_ROW_ON_BRACE</td><td>An integer value greater or equal to 2.</td><td>NUMBER_OF_BOLTS_PER_ROW_ON_BRACE 5</td></tr>
        <tr><td>NUMBER_OF_BOLT_ROWS_ON_BRACE</td><td>1|2</td><td>NUMBER_OF_BOLT_ROWS_ON_BRACE 1</td></tr>
        <tr><td>BOLT_ROW_SPACING</td><td>A positive number.</td><td>BOLT_ROW_SPACING 60</td></tr>
        <tr><td>BRACE_ANGLE</td><td>A numeric value between 20 and 80 inclusive.</td><td>BRACE_ANGLE 35</td></tr>
        <tr><td>BRACE_OUTSTANDING_LEG</td><td>LONG_LEG|SHORT_LEG</td><td>BRACE_OUTSTANDING_LEG LONG_LEG</td></tr>
        <tr><td>BRACE_DIST_FROM_WP</td><td>A positive number.</td><td>BRACE_DIST_FROM_WP 800</td></tr>
        <tr><td>GUSSET_TO_BEAM_WELD</td><td>A positive number.</td><td>GUSSET_TO_BEAM_WELD 8</td></tr>
        <tr><td>GUSSET_LENGTH</td><td>A positive number.</td><td>GUSSET_LENGTH 450</td></tr>
        <tr><td>SUPPORT_TYPE</td><td>COLUMN_FLANGE|COLUMN_WEB</td><td>SUPPORT_TYPE COLUMN_FLANGE</td></tr>
        <tr><td>CLIP_SECTION</td><td>A valid AISC angle section</td><td>CLIP_SECTION L127X76X12.7</td></tr>
        <tr><td>CLIP_OUTSTANDING_LEG</td><td>LONG_LEG|SHORT_LEG</td><td>CLIP_OUTSTANDING_LEG LONG_LEG</td></tr>
        <tr><td>NUMBER_OF_BOLTS_GUSSET_CLIP</td><td>An integer value greater or equal to 2.</td><td>NUMBER_OF_BOLTS_GUSSET_CLIP 5</td></tr>
        <tr><td>NUMBER_OF_BOLT_BEAM_CLIP</td><td>An integer value greater or equal to 2.</td><td>NUMBER_OF_BOLT_BEAM_CLIP 3</td></tr>
        <tr><td>CLIP_ANGLE_WELD_THICKNESS</td><td>A positive number.</td><td>CLIP_ANGLE_WELD_THICKNESS 6</td></tr>
        <tr><td>GUSSET_CLIP_LOCATION</td><td>A positive number.</td><td>GUSSET_CLIP_LOCATION 50</td></tr>
        <tr><td>CONNECTION_SETBACK</td><td>A positive number.</td><td>CONNECTION_SETBACK 12</td></tr></table>
	</div>
	</div>
	</div>
    <?php
    drawFooter();
    ?>
</body>
</html>
