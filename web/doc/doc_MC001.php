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
    drawDocSidebar('mc001');
    ?>
    </div>
	<div class="container col-sm-9">	
		<h2>MC001AM10 <small>EXTENDED END PLATE SEISMIC MOMENT CONNECTION</small></h2>
		<p>
Moment connections are designed to transfer moments in the beam to the
supporting columns. Moment connections play an important part in the stability
and lateral force resistance of the structure. Extended end plate moment
connections are very popular among engineers due to their relative ease of
fabrication and as they require no field welding. Osoconn allows three
configurations of extended end plate moment connections: four-bolt
unstiffened, four-bolt stiffened and eight-bolt stiffened configurations.  
		</p>
        <img src="images/MC001AM10.svg" class="img-rounded img-responsive" alt="mc001am10 connection configurations" width="50%" >
        <h4>Validation record</h4>
		<p>
The design checks performed by the program are verified against a series of
manually performed calculations to verify the output. The complete validation
document for this connection can be downloaded <a href="validation_docs/mc001am10.pdf">here</a>.
		</p>
        <h4>Fit-up checks </h4>
        <p>
The following checks for fit-up of the connection are performed by the program.        
        <ul>
        <li>Checks the bolt vertical and horizontal edge distance on end plate as per the requirements of AISC360.</li>
        <li>Checks the bolt horizontal edge distance on column flange as per the requirements of AISC360.</li>
        <li>Checks the minimum bolt spacing as required by AISC360.</li>
        <li>Checks the clearance of the inner and outer bolts to the flange welds.</li>
        <li>Checks that the end plate width is not lesser than the beam flange width.</li>
        <li>Checks for bolt clash with column fillet area.</li>
        <li>Checks to ensure the the bolt  gage does not exceed beam flange.</li>
        <li>Checks to ensure sufficient length of end plate stiffener is provided to ensure proper forces distribution.</li>
        <li>Checks to ensure that the column transverse stiffener width does not exceed the flange width.</li>
        <li>Checks to ensure that column transverse stiffener clip does not clash with column fillet area.</li>
        <li>Checks to ensure that the column doubler plate thickness exceeds the column fillet area dimension.</li>
        </ul>
        </p>
        <h4>Design checks </h4>
        <p>
The following design checks are performed by the program.
        <ul>
        <li>Checks for bolt tension</li>
        <li>Checks for end plate yielding</li>
        <li>Checks for end plate shear yielding</li>
        <li>Checks for end plate shear rupture</li>
        <li>Checks for bolt shear</li>
        <li>Checks for bolt bearing on end plate</li>
        <li>Checks for bolt bearing on column</li>
        <li>Checks for web weld tension strength</li>
        <li>Checks for web weld shear strength</li>
        <li>Checks for end plate stiffener thickness requirement</li>
        <li>Checks for end plate stiffener to beam weld strength</li>
        <li>Checks for column flange yielding</li>
        <li>Checks for column local web yielding</li>
        <li>Checks for column local web crippling</li>
        <li>Checks for column web panel shear</li>
        <li>Checks for column web shear buckling</li>
        <li>Checks for column stiffener axial strength</li>
        <li>Checks for column stiffener shear strength</li>
        <li>Checks for column minimum stiffener thickness</li>
        <li>Checks for column stiffener to flange strength</li>
        <li>Checks for column stiffener to web strength</li>
        <li>Checks for doubler plate shear</li>
        <li>Checks for doubler plate height</li>
        <li>Checks for doubler minimum plate thickness</li>
        <li>Checks for doubler plate to flange weld strength</li>
        </ul>
        </p>
        <h4>Assumptions in design</h4>
		<p>
The following assumptions are made while performing the design of the connection.
        <ul>
        <li>The design is only applicable for exterior moment connections, ie for columns with moment connections only on one flange.</li>
        <li>Bolts are assumed to be bearing type which are pretensioned during installation.</li>
        </ul>
		</p>
		<h3>Input parameters</h3>
		<p>
        The cin input file for this connection requires the following parameters
to run.
		</p>
        <table class ="table" style="font-family:monospace">
        <tr><th>Parameter</th><th>Acceptable value</th><th>Example</th></tr>
        <tr><td>CONNECTION_CODE</td><td>MC001AM10</td><td>CONNECTION_CODE MC001AM10</td></tr>
        <tr><td>CONNECTION_ID</td><td>Any alpha-numeric set of characters used to identify the connection.</td><td>CONNECTION_ID MOM#23</td></tr>
        <tr><td>METHOD</td><td>ASD|LRFD</td><td>METHOD LRFD</td></tr>
        <tr><td>UNITS</td><td>NEWTON_MM|KIP_IN</td><td>UNITS NEWTON_MM</td></tr>
        <tr><td>MODULUS_OF_ELASTICITY</td><td>A positive number</td><td>MODULUS_OF_ELASTICITY 200000</td></tr>
        <tr><td>STEEL_GRADE_OF_PLATE</td><td>A36</td><td>STEEL_GRADE_OF_PLATE A36</td></tr>
        <tr><td>STEEL_GRADE_OF_BEAM</td><td>A36|A992</td><td>STEEL_GRADE_OF_BEAM A36</td></tr>
        <tr><td>STEEL_GRADE_OF_COLUMN</td><td>A36|A992</td><td>STEEL_GRADE_OF_COLUMN A36</td></tr>
        <tr><td>WELD_ELECTRODE</td><td>E70</td><td>WELD_ELECTRODE E70</td></tr>
        <tr><td>BOLT_GRADE</td><td>A325|A490</td><td>BOLT_GRADE A325</td></tr>
        <tr><td>SHEAR_FORCE</td><td>A positive number</td><td>SHEAR_FORCE 100000</td></tr>
        <tr><td>COLUMN_AXIAL_FORCE</td><td>A positive number</td><td>COLUMN_AXIAL_FORCE 500000</td></tr>
        <tr><td>PLATE_WIDTH</td><td>A positive number</td><td>PLATE_WIDTH 240</td></tr>
        <tr><td>PLATE_HEIGHT</td><td>A positive number</td><td>PLATE_HEIGHT 540</td></tr>
        <tr><td>PLATE_THICKNESS</td><td>A positive number</td><td>PLATE_THICKNESS 30</td></tr>
        <tr><td>BOLT_DIAMETER</td><td>If unit is set to NEWTON_MM:<br>M16|M20|M22|M24|M27|M30|M36.<br>If unit is set to KIP_IN:<br>1/2|5/8|3/4|7/8|1|1_1/8|1_1/4|1_3/8|1_1/2.</td><td>BOLT_DIAMETER M30</td></tr>
        <tr><td>CONFIGURATION</td><td>4_BOLTS|4_BOLTS_STIFFENED|8_BOLTS_STIFFENED</td><td>CONFIGURATION 4_BOLTS_STIFFENED</td></tr>
        <tr><td>BOLT_GAGE</td><td>A positive number</td><td>BOLT_GAGE 160</td></tr>
        <tr><td>INNER_BOLT_TO_FLANGE</td><td>A positive number</td><td>INNER_BOLT_TO_FLANGE 45</td></tr>
        <tr><td>OUTER_BOLT_TO_FLANGE</td><td>A positive number</td><td>OUTER_BOLT_TO_FLANGE 50</td></tr>
        <tr><td>BOLT_SPACING</td><td>A positive number</td><td>BOLT_SPACING 70</td></tr>
        <tr><td>WEB_WELD</td><td>A positive number</td><td>WEB_WELD 6</td></tr>
        <tr><td>FLANGE_WELD_REINFORCEMENT</td><td>A positive number</td><td>FLANGE_WELD_REINFORCEMENT 4</td></tr>
        <tr><td>BEAM_SECTION</td><td>A valid AISC W section</td><td>BEAM_SECTION W360X51</td></tr>
        <tr><td>COLUMN_SECTION</td><td>A valid AISC W section</td><td>COLUMN_SECTION W360X196</td></tr>
        <tr><td>DISTANCE_TO_COLUMN_TOP</td><td>A positive number.</td><td>DISTANCE_TO_COLUMN_TOP 200</td></tr>
        <tr><td>PLATE_STIFFENER_LENGTH</td><td>A positive number.<br>Required only if configuration is 4-bolt stiffened or 8-bolt stiffened.</td><td>PLATE_STIFFENER_LENGTH 200</td></tr>
        <tr><td>PLATE_STIFFENER_THICKNESS</td><td>A positive number.<br>Required only if configuration is 4-bolt stiffened or 8-bolt stiffened.</td><td>PLATE_STIFFENER_THICKNESS 12</td></tr>
        <tr><td>PLATE_STIFFENER_WELD</td><td>A positive number. Required only if configuration is 4-bolt stiffened or 8-bolt stiffened.</td><td>PLATE_STIFFENER_WELD 6</td></tr>
        <tr><td>COLUMN_STIFFENER</td><td>YES|NO</td><td>COLUMN_STIFFENER YES</td></tr>
        <tr><td>COLUMN_STIFFENER_THICKNESS</td><td>A positive number.<br>Required only if column stiffener is provided.</td><td>COLUMN_STIFFENER_THICKNESS 10</td></tr>
        <tr><td>COLUMN_STIFFENER_WIDTH</td><td>A positive number.<br>Required only if column stiffener is provided.</td><td>COLUMN_STIFFENER_WIDTH 100</td></tr>
        <tr><td>COLUMN_STIFFENER_CLIP</td><td>A positive number.<br>Required only if column stiffener is provided</td><td>COLUMN_STIFFENER_CLIP 35</td></tr>
        <tr><td>COLUMN_STIFFENER_TO_FLANGE_WELD</td><td>A positive number.<br>Required only if column stiffener is provided</td><td>COLUMN_STIFFENER_TO_FLANGE_WELD 6</td></tr>
        <tr><td>COLUMN_STIFFENER_TO_WEB_WELD</td><td>A positive number. Required only if column stiffener is provided</td><td>COLUMN_STIFFENER_TO_WEB_WELD 6</td></tr>
        <tr><td>DOUBLER_PLATE</td><td>YES|NO</td><td>DOUBLER_PLATE YES</td></tr>
        <tr><td>DOUBLER_PLATE_THICKNESS</td><td>A positive number.<br>Required only if doubler plate is provided</td><td>DOUBLER_PLATE_THICKNESS 20</td></tr>
        <tr><td>DOUBLER_PLATE_HEIGHT</td><td>A positive number.<br>Required only if doubler plate is provided</td><td>DOUBLER_PLATE_HEIGHT 600</td></tr>
        <tr><td>DOUBLER_PLATE_WELD</td><td>A positive number.<br>Required only if doubler plate is provided</td><td>DOUBLER_PLATE_WELD 6</td></tr></table>		
	</div>
	</div>
	</div>
    <?php
    drawFooter();
    ?>
</body>
</html>
