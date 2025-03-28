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
    drawDocSidebar('sc001');
    ?>
    </div>
	<div class="container col-sm-9">	
		<h2>SC001AM10 <small>SHOP-WELDED, FIELD-BOLTED CLIP ANGLE SHEAR CONNECTION</small></h2>
		<p>
This connection detail refers to the shop-welded, field bolted clip angle beam
connections designed to AISC 360 2010 specifications.  The popularity of this
connection is due to its ease of fabrication and erection.  The connection can
be welded in the fabrication shop and bolted to the supporting member at site.
The supporting member can be either a beam web, column flange or column web.
		</p>
        <img src="images/SC001AM10.svg" class="img-rounded img-responsive" alt="sc001am10 support types" width="50%" >
        <p>
Shear connections are assumed to transfer no moment across the
connections. This rotational flexibility is assumed to be provided by the
relative flexibility of the clip angle outstanding legs.
        </p>
        <h4>Validation record</h4>
		<p>
The design checks performed by the program are verified against a series of
manually performed calculations to verify the output. The complete validation
document for this connection can be downloaded <a href="validation_docs/sc001am10.pdf">here</a>.
		</p>
        <h4>Fit-up checks </h4>
        <p>
The following checks for fit-up of the connection are performed by the program.        
        <ul>
        <li> Checks the minimum bolt spacing requirement as per AISC360.  </li>
        <li> Checks the horizontal and vertical bolt edge dist on clip angle in accordance with AISC360.  </li>
        <li> Checks the horizontal bolt edge dist on column flange in accordance with AISC360.  </li>
        <li> Checks bolt nut clash with column fillet area.  </li>
        <li> Checks bolt nut clash with clip angle fillet area.  </li>
        <li> Checks clearance for weld at top of clip angle.  </li>
        <li> Checks clearance for weld at bottom of clip angle.  </li>
        <li> Checks minimum top cope depth.  </li>
        <li> Checks minimum bottom cope depth.  </li>
        <li> Checks minimum cope length.  </li>
        </ul>
        </p>
        <h4>Design checks </h4>
        <p>
The following design checks are performed by the program.
        <ul>
        <li> Checks for bolt shear </li>
        <li> Checks for bolt tension </li>
        <li> Checks for bolt bearing at clip </li>
        <li> Checks for bolt bearing at support </li>
        <li> Checks for weld shear </li>
        <li> Checks for web rupture at weld </li>
        <li> Checks for clip angle prying </li>
        <li> Checks for clip angle shear yielding </li>
        <li> Checks for clip angle shear rupture </li>
        <li> Checks for clip angle block shear </li>
        <li> Checks for column flange prying </li>
        <li> Checks for column web yielding </li>
        <li> Checks for column web crippling </li>
        <li> Checks for column web flexure yielding </li>
        <li> Checks for flexure strength of coped section </li>
        <li> Checks for compression strength of coped section </li>
        <li> Checks for shear strength of coped section </li>
        </ul>
        </p>
        <h4>Assumptions in design</h4>
		<p>
The following assumptions are made while performing the design of the connection.
        <ul>
        <li>For bolt bearing checks, it is assumed that deformation at service load is a design considerations When there is a backing beam present, conservatively only half the bearing strength is considered.  If both flanges are coped top and bottom cope shall be of equal length.</li>
        <li>For cope checks it is conservatively assumed that moments due to shear force and transfer force are additive.</li>
        <li>For cope checks top flange is assumed to be in compression.</li>
        <li>For column web local yielding check, it is conservatively assumed that the beam is near the edge of the column.</li>
        </ul>
		</p>
		<h4>Input parameters</h4>
		<p>
        The cin input file for this connection requires the following parameters
        to run.
		</p>
        <table class ="table" style="font-family:monospace">
        <tr><th>Parameter</th><th>Acceptable value</th><th>Example</th></tr>
        <tr><td>CONNECTION_CODE</td><td>SC001AM10</td><td>CONNECTION_CODE SC001AM10</td></tr>
        <tr><td>CONNECTION_ID</td><td>Any alpha-numeric set of characters used to identify the connection.</td><td>CONNECTION_ID SHEAR03</td></tr>
        <tr><td>METHOD</td><td>ASD|LRFD</td><td>METHOD ASD</td></tr>
        <tr><td>UNITS</td><td>NEWTON_MM|KIP_IN</td><td>UNITS NEWTON_MM</td></tr>
        <tr><td>MODULUS_OF_ELASTICITY</td><td>A positive number</td><td>MODULUS_OF_ELASTICITY 200000</td></tr>
        <tr><td>POISSON_RATIO</td><td>A positive number between 0 and 0.5</td><td>POISSON_RATIO 0.3</td></tr>
        <tr><td>STEEL_GRADE_OF_ANGLE</td><td>A36|A992</td><td>STEEL_GRADE_OF_ANGLE A36</td></tr>
        <tr><td>STEEL_GRADE_OF_BEAM</td><td>A36|A992</td><td>STEEL_GRADE_OF_BEAM A36</td></tr>
        <tr><td>STEEL_GRADE_OF_SUPPORT</td><td>A36|A992</td><td>STEEL_GRADE_OF_SUPPORT A992</td></tr>
        <tr><td>WELD_ELECTRODE</td><td>E70</td><td>WELD_ELECTRODE E70</td></tr>
        <tr><td>BOLT_GRADE</td><td>A325|A490</td><td>BOLT_GRADE A325</td></tr>
        <tr><td>TRANSFER_FORCE</td><td>Any numeric value</td><td>TRANSFER_FORCE 15000</td></tr>
        <tr><td>SHEAR_FORCE</td><td>Any numeric value</td><td>SHEAR_FORCE 90000</td></tr>
        <tr><td>BOLT_DIAMETER</td><td>If unit is set to NEWTON_MM:<br>M16|M20|M22|M24|M27|M30|M36.<br>If unit is set to KIP_IN:<br>1/2|5/8|3/4|7/8|1|1_1/8|1_1/4|1_3/8|1_1/2.</td><td>BOLT_DIAMETER M22</td></tr>
        <tr><td>BOLT_TYPE</td><td>BEARING|FRICTION</td><td>BOLT_TYPE FRICTION</td></tr>
        <tr><td>THREAD_INCLUDED_IN_SHEAR</td><td>YES|NO<br>Required for only bearing type bolts.</td><td>THREAD_INCLUDED_IN_SHEAR YES</td></tr>
        <tr><td>FAYING_SURFACE</td><td>CLASS_A|CLASS_B<br>Required only for friction type bolts.</td><td>FAYING_SURFACE CLASS_A</td></tr>
        <tr><td>NUMBER_OF_BOLTS_PER_ROW</td><td>Integer greater than or equal to 2</td><td>NUMBER_OF_BOLTS_PER_ROW 4</td></tr>
        <tr><td>BOLT_GAGE</td><td>A positive number</td><td>BOLT_GAGE 140</td></tr>
        <tr><td>BOLT_SPACING</td><td>A positive number</td><td>BOLT_SPACING 60</td></tr>
        <tr><td>THICKNESS_OF_WELD</td><td>A positive number</td><td>THICKNESS_OF_WELD 8</td></tr>
        <tr><td>BEAM_SECTION</td><td>A valid AISC W section</td><td>BEAM_SECTION W410X67</td></tr>
        <tr><td>CONNECTION_SETBACK</td><td>A positive number</td><td>CONNECTION_SETBACK 12</td></tr>
        <tr><td>COPE_LENGTH</td><td>A positive number</td><td>COPE_LENGTH 100</td></tr>
        <tr><td>TOP_COPE_DEPTH</td><td>A positive number</td><td>TOP_COPE_DEPTH 35</td></tr>
        <tr><td>BOTTOM_COPE_DEPTH</td><td>A positive number</td><td>BOTTOM_COPE_DEPTH 35</td></tr>
        <tr><td>SUPPORT_SECTION</td><td>A valid AISC W section</td><td>SUPPORT_SECTION W410X67</td></tr>
        <tr><td>SUPPORT_TYPE</td><td>BEAM|COLUMN_FLANGE|COLUMN_WEB</td><td>SUPPORT_TYPE BEAM</td></tr>
        <tr><td>BACKING_BEAM</td><td>YES|NO</td><td>BACKING_BEAM YES</td></tr>
        <tr><td>CLIP_ANGLE</td><td>A valid AISC angle section</td><td>CLIP_ANGLE L102X102X9.5</td></tr>
        <tr><td>OUTSTANDING_LEG</td><td>LONG_LEG|SHORT_LEG</td><td>OUTSTANDING_LEG LONG_LEG</td></tr>
        <tr><td>CLIP_ANGLE_LENGTH</td><td>A positive number</td><td>CLIP_ANGLE_LENGTH 240</td></tr>
        <tr><td>CLIP_ANGLE_TOP</td><td>A positive number</td><td>CLIP_ANGLE_TOP 40</td></tr></table>

	</div>
	</div>
	</div>
    <?php
    drawFooter();
    ?>
</body>
</html>
