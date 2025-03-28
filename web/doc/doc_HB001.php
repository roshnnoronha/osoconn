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
    drawDocSidebar('hb001');
    ?>
    </div>
	<div class="container col-sm-9">	
		<h2>HB001AM10 <small>DOUBLE ANGLE HORIZONTAL BRACING CONNECTION</small></h2>
		<p>
Horizontal bracing transfer the lateral loads at a particular floor level of
the structure to the lateral force resisting systems. The double angle bracing
member is connected to two perpendicular beams using a gusset plate. The
gusset plate connections to the beam can be made using clip angles, shear tab
or by directly bolting the gusset plate to the bottom flange of the beam. 
		</p>
        <img src="images/HB001AM10_1.svg" class="img-rounded img-responsive" alt="hb001am10 gusset to beam connection configurations" width="50%" >
        <p>
The brace angles can be oriented with either their back to back legs horizontal or vertical.
        </p>
        <img src="images/HB001AM10.svg" class="img-rounded img-responsive" alt="hb001am10 brace orientations" width="50%" >
        <h4>Validation record</h4>
		<p>
The design checks performed by the program are verified against a series of
manually performed calculations to verify the output. The complete validation
document for this connection can be downloaded <a href="validation_docs/hb001am10.pdf">here</a>.
		</p>
        <h4>Fit-up checks </h4>
        <p>
The following checks for fit-up of the connection are performed by the program.        
        <ul>
        <li>Checks for minimum bolt edge distance on gusset as per AISC360.</li>
        <li>Checks for minimum bolt edge distance along brace line as per AISC360.</li>
        <li>Checks for minimum bolt edge distance perpendicular to brace line as per AISC360.</li>
        <li>Checks for minimum bolt horizontal and vertical edge distance on clip angle as per AISC360.</li>
        <li>Checks for minimum bolt edge distance on shear tab as per AISC360.</li>
        <li>Checks for minimum bolt edge distance on beam flange as per AISC360.</li>
        <li>Checks for bolt clash with beam fillet area.</li>
        <li>Checks for minimum bolt spacing as per AISC360.</li>
        <li>Checks for bolt clash with brace fillet area.</li>
        <li>Checks for clip angle weld space at connection</li>
        <li>Checks for bolt clearance from clip fillet area.</li>
        <li>Checks for clip angle clash with beam top fillet area.</li>
        <li>Checks for clip angle clash with beam bottom fillet area.</li>
        <li>Checks for bolt clash with shear tab clearance weld.</li>
        <li>Checks for connection bolting clearance from top flange.</li>
        <li>Checks for connection bolting clearance from bottom flange.</li>
        <li>Checks that the gusset top must equal to or greater than beam depth for bottom flange type connections.</li>
        </ul>
        </p>
        <h4>Design checks </h4>
        <p>
The following design checks are performed by the program.
        <ul>
        <li>Checks for bolt shear</li>
        <li>Checks for brace rupture</li>
        <li>Checks for bolt bearing at brace</li>
        <li>Checks for brace block shear</li>
        <li>Checks for gusset tension yielding</li>
        <li>Checks for gusset tension rupture</li>
        <li>Checks for bolt bearing at gusset</li>
        <li>Checks for block shear at gusset</li>
        <li>Checks for bolt shear at connection 1</li>
        <li>Checks for bolt bearing at shear tab at connection 1</li>
        <li>Checks for bolt bearing at clip at connection 1</li>
        <li>Checks for bolt bearing at beam web at connection 1</li>
        <li>Checks for bolt bearing at beam flange at connection 1</li>
        <li>Checks for bolt bearing at gusset at connection 1</li>
        <li>Checks for gusset block shear at connection 1</li>
        <li>Checks for gusset shear yielding at connection 1</li>
        <li>Checks for gusset flexure yielding at connection 1</li>
        <li>Checks for gusset shear rupture at connection 1</li>
        <li>Checks for element shear yielding at connection 1</li>
        <li>Checks for element shear rupture at connection 1</li>
        <li>Checks for element block shear at connection 1</li>
        <li>Checks for weld strength at connection 1</li>
        <li>Checks for gusset rupture at weld at connection 1</li>
        <li>Checks for shear tab rupture at weld at connection 1</li>
        <li>Checks for beam web rupture at weld at connection 1</li>
        <li>Checks for shear tab flexure yielding at connection 1</li>
        <li>Checks for bolt shear at connection 2</li>
        <li>Checks for bolt bearing at shear tab at connection 2</li>
        <li>Checks for bolt bearing at clip at connection 2</li>
        <li>Checks for bolt bearing at beam web at connection 2</li>
        <li>Checks for bolt bearing at beam flange at connection 2</li>
        <li>Checks for gusset block shear at connection 2</li>
        <li>Checks for gusset shear yielding at connection 2</li>
        <li>Checks for gusset shear rupture at connection 2</li>
        <li>Checks for element shear yielding at connection 2</li>
        <li>Checks for element shear rupture at connection 2</li>
        <li>Checks for element block shear at connection 2</li>
        <li>Checks for weld strength at connection 2</li>
        <li>Checks for gusset rupture at weld at connection 2</li>
        <li>Checks for shear tab rupture tab at weld at connection 2</li>
        <li>Checks for beam web rupture at weld at connection 2</li>
        <li>Checks for shear tab flexure yielding at connection 2</li>
        </ul>
        </p>
        <h4>Assumptions in design</h4>
		<p>
The following assumptions are made while performing the design of the connection.
        <ul>
        <li>The program does not check the gusset plate in compression. It is assumed that the brace extends as close as possible to the work point to avoid buckling.</li>
        <li>The program does not check gusset edge buckling. To prevent this mode of failure it is advised to provide stiffener plates the gusset edge when the free edge length becomes excessive. </li>
        <li>Bearing check assumes deformation at bolt hole is a service consideration.</li>
        </ul>
		</p>
		<h3>Input parameters</h3>
		<p>
The input file for this connection requires the following parameters to run.
		</p>
        <table class ="table" style="font-family:monospace">
        <tr><th>Parameter</th><th>Acceptable value</th><th>Example</th></tr>
        <tr><td>CONNECTION_CODE</td><td>HB001AM10</td><td>CONNECTION_CODE HB001AM10</td></tr>
        <tr><td>CONNECTION_ID</td><td>Any alpha-numeric set of characters used to identify the connection.</td><td>CONNECTION_ID HOR_12</td></tr>
        <tr><td>METHOD</td><td>ASD|LRFD</td><td>METHOD ASD</td></tr>
        <tr><td>UNITS</td><td>NEWTON_MM|KIP_IN</td><td>UNITS NEWTON_MM</td></tr>
        <tr><td>BEAM_GRADE</td><td>A36|A992</td><td>BEAM_GRADE A992</td></tr>
        <tr><td>ANGLE_GRADE</td><td>A36|A992</td><td>ANGLE_GRADE A36</td></tr>
        <tr><td>PLATE_GRADE</td><td>A36</td><td>PLATE_GRADE A36</td></tr>
        <tr><td>WELD_ELECTRODE</td><td>E70</td><td>WELD_ELECTRODE E70</td></tr>
        <tr><td>BOLT_GRADE</td><td>A325|A490</td><td>BOLT_GRADE A325</td></tr>
        <tr><td>BRACE_FORCE</td><td>Any numeric value</td><td>BRACE_FORCE 450000</td></tr>
        <tr><td>BOLT_DIAMETER</td><td>If unit is set to NEWTON_MM:<br>M16|M20|M22|M24|M27|M30|M36.<br>If unit is set to KIP_IN:<br>1/2|5/8|3/4|7/8|1|1_1/8|1_1/4|1_3/8|1_1/2.</td><td>BOLT_DIAMETER M24</td></tr>
        <tr><td>BOLT_TYPE</td><td>FRICTION|BEARING</td><td>BOLT_TYPE FRICTION</td></tr>
        <tr><td>BOLT_SPACING</td><td>A positive number. </td><td>BOLT_SPACING 75</td></tr>
        <tr><td>BOLT_ROW_SPACING</td><td>A positive number. </td><td>BOLT_ROW_SPACING 75</td></tr>
        <tr><td>EDGE_DISTANCE_ON_GUSSET</td><td>A positive number.</td><td>EDGE_DISTANCE_ON_GUSSET 30</td></tr>
        <tr><td>EDGE_DISTANCE_ON_BRACE</td><td>A positive number.</td><td>EDGE_DISTANCE_ON_BRACE 30</td></tr>
        <tr><td>EDGE_DISTANCE_ON_TAB</td><td>A positive number.</td><td>EDGE_DISTANCE_ON_TAB 30</td></tr>
        <tr><td>EDGE_DISTANCE_ON_CLIP</td><td>A positive number.</td><td>EDGE_DISTANCE_ON_CLIP 30</td></tr>
        <tr><td>BOLT_GAGE_ON_BRACE</td><td>A positive number.</td><td>BOLT_GAGE_ON_BRACE 60</td></tr>
        <tr><td>BOLT_GAGE_ON_CLIP</td><td>A positive number.</td><td>BOLT_GAGE_ON_CLIP 25</td></tr>
        <tr><td>BOLT_GAGE_ON_TAB</td><td>A positive number.</td><td>BOLT_GAGE_ON_TAB 50</td></tr>
        <tr><td>BOLT_GAGE_ON_BEAM1</td><td>A positive number.<br> Required if connection 1 type is BOTTOM_FLANGE</td><td>BOLT_GAGE_ON_BEAM1 50</td></tr>
        <tr><td>BOLT_GAGE_ON_BEAM2</td><td>A positive number.<br> Required if connection 2 type is BOTTOM_FLANGE</td><td>BOLT_GAGE_ON_BEAM2 50</td></tr>
        <tr><td>BRACE_ANGLE</td><td>A numeric value between 20 and 70 degrees.</td><td>BRACE_ANGLE 30</td></tr>
        <tr><td>BRACE_SECTION</td><td>A valid AISC angle section.</td><td>BRACE_SECTION L127X76X12.7</td></tr>
        <tr><td>BRACE_TYPE</td><td>SINGLE_ANGLE|DOUBLE_ANGLE</td><td>BRACE_TYPE DOUBLE_ANGLE</td></tr>
        <tr><td>BACK_TO_BACK_LEG_ORIENTATION</td><td>HORIZONTAL|VERTICAL</td><td>BACK_TO_BACK_LEG_ORIENTATION HORIZONTAL</td></tr
        <tr><td>BRACE_ANGLE_SPACING</td><td>A positive number. <br> Required if back to back leg of brace is vertical.</td><td>BRACE_ANGLE_SPACING 12</td></tr>
        <tr><td>BRACE_OUTSTANDING_LEG</td><td>SHORT_LEG|LONG_LEG</td><td>BRACE_OUTSTANDING_LEG SHORT_LEG</td></tr>
        <tr><td>BRACE_NUMBER_OF_BOLTS_PER_ROW</td><td>An integer value greater than or equal to 2. </td><td>BRACE_NUMBER_OF_BOLTS_PER_ROW 5</td></tr>
        <tr><td>BRACE_NUMBER_OF_BOLT_</td><td>1|2</td><td>BRACE_NUMBER_OF_BOLT_ROWS 1</td></tr>
        <tr><td>GUSSET_THICKNESS</td><td>A positive number.</td><td>GUSSET_THICKNESS 12</td></tr>
        <tr><td>GUSSET_LENGTH_1</td><td>A positive number.</td><td>GUSSET_LENGTH_1 500</td></tr>
        <tr><td>GUSSET_LENGTH_2</td><td>A positive number.</td><td>GUSSET_LENGTH_2 500</td></tr>
        <tr><td>GUSSET_TOP_OFFSET</td><td>A positive number.</td><td>GUSSET_TOP_OFFSET 150</td></tr>
        <tr><td>JOINT_TYPE</td><td>BEAM_JOINT|COLUMN_JOINT</td><td>JOINT_TYPE COLUMN_JOINT</td></tr>
        <tr><td>CONNECTION1_TYPE</td><td>CLIP_ANGLE|SHEAR_TAB| BOTTOM_FLANGE</td><td>CONNECTION1_TYPE CLIP_ANGLE</td></tr>
        <tr><td>CONNECTION2_TYPE</td><td>CLIP_ANGLE|SHEAR_TAB| BOTTOM_FLANGE</td><td>CONNECTION2_TYPE SHEAR_TAB</td></tr>
        <tr><td>CONNECTION1_NUMBER_OF_BOLTS</td><td>An integer value greater than or equal to 2.</td><td>CONNECTION1_NUMBER_OF_BOLTS 4</td></tr>
        <tr><td>CONNECTION2_NUMBER_OF_BOLTS</td><td>An integer value greater than or equal to 2.</td><td>CONNECTION2_NUMBER_OF_BOLTS 5</td></tr>
        <tr><td>CONNECTION1_LOCATION</td><td>A numeric value greater than or equal to 0.</td><td>CONNECTION1_LOCATION 180</td></tr>
        <tr><td>CONNECTION2_LOCATION</td><td>A numeric value greater than or equal to 0.</td><td>CONNECTION2_LOCATION 180</td></tr>
        <tr><td>TAB_WIDTH</td><td>A positive number.<br>Required only if either connection 1 or 2 is a shear tab.</td><td>TAB_WIDTH 150</td></tr>
        <tr><td>TAB_THICKNESS</td><td>A positive number.<br>Required only if either connection 1 or 2 is a shear tab.</td><td>TAB_THICKNESS 10</td></tr>
        <tr><td>TAB_TO_BEAM_WELD</td><td>A positive number.<br>Required only if either connection 1 or 2 is a shear tab.</td><td>TAB_TO_BEAM_WELD 6</td></tr>
        <tr><td>CLIP_SECTION</td><td>A valid AISC angle section.<br>Required only if either connection 1 or 2 is a clip angle.</td><td>CLIP_SECTION L89X89X7.9</td></tr>
        <tr><td>CLIP_OUTSTANDING_LEG</td><td>LONG_LEG|SHORT_LEG</td><td>CLIP_OUTSTANDING_LEG LONG_LEG</td></tr>
        <tr><td>CLIP_TO_GUSSET_WELD</td><td>A positive number.<br>Required only if either connection 1 or 2 is a clip angle.</td><td>CLIP_TO_GUSSET_WELD 6</td></tr>
        <tr><td>CONNECTION1_CUTOUT</td><td>A numeric value greater than or equal to 0.</td><td>CONNECTION1_CUTOUT 125</td></tr>
        <tr><td>CONNECTION2_CUTOUT</td><td>A numeric value greater than or equal to 0.</td><td>CONNECTION2_CUTOUT 125</td></tr>
        <tr><td>CONNECTION1_SETBACK</td><td>A positive number.</td><td>CONNECTION1_SETBACK 12</td></tr>
        <tr><td>CONNECTION2_SETBACK</td><td>A positive number.</td><td>CONNECTION1_SETBACK 12</td></tr>
        <tr><td>CONNECTION1_EXTENSION</td><td>A positive number.<br> Required only if connection 1 is of type BOTTOM_FLANGE</td><td>CONNECTION1_EXTENSION 25</td></tr>
        <tr><td>CONNECTION2_EXTENSION</td><td>A positive number.<br> Required only if connection 2 is of type BOTTOM_FLANGE</td><td>CONNECTION2_EXTENSION 25</td></tr>
        <tr><td>BEAM1_SECTION</td><td>A valid AISC W-section</td><td>BEAM1_SECTION W21x83</td></tr>
        <tr><td>BEAM2_SECTION</td><td>A valid AISC W-section</td><td>BEAM2_SECTION W10x39</td></tr>
        <tr><td>CONTINUOUS_BEAM_NUMBER</td><td>1|2. <br> Required if joint type is BEAM_JOINT.</td><td>CONTINUOUS_BEAM_NUMBER 1</td></tr>
        <tr><td>BEAM1_SETBACK</td><td>A numeric value greater than or equal to 0. <br> Required if continuous beam number is 2.</td><td>BEAM1_SETBACK 12</td></tr>
        <tr><td>BEAM2_SETBACK</td><td>A numeric value greater than or equal to 0. <br> Required if continuous beam number is 1.</td><td>BEAM2_SETBACK 12</td></tr>
        <tr><td>BEAM1_COPE_LENGTH</td><td>A numeric value greater than or equal to 0.</td><td>BEAM1_COPE_LENGTH 150</td></tr>
        <tr><td>BEAM2_COPE_LENGTH</td><td>A numeric value greater than or equal to 0.</td><td>BEAM2_COPE_LENGTH 150</td></tr>
        <tr><td>COLUMN_SECTION</td><td>A valid AISC W-section. <br>Required if joint type is COLUMN_JOINT</td><td>COLUMN_SECTION W10x39</td></tr>
        <tr><td>COLUMN_ORIENTATION</td><td> 0|90. <br>Required if joint type is COLUMN_JOINT</td><td>COLUMN_ORIENTATION 90</td></tr></table>
	</div>
	</div>
	</div>
    <?php
    drawFooter();
    ?>
</body>
</html>
