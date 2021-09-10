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
		<h2>Osoconn Web App</h2>
		<p>
		The web app provides an easy-to-use graphical interface. The user interface is designed to be intuitive with diagrams provided to clarify the details of the connection.		
		</p>
		<p>
		To limit the load on our servers there are certain limits to using the web app. These include the inability to run multiple connections at once and the inability to save a connection design. These limitations are not present in the Osoconn command line app.		
		</p>
		<h3>Providing inputs</h3>
		<img src="./images/input_pane.PNG" width ="50%">
		<p>
		Inputs are provided using familiar input elements such as text boxes and drop downs. These elements are grouped in the input pane into various tabs for convenience. Inputs can be provided either using (Newton, mm) or (kip, in) as the units of measurement. 
		</p>
		<p>
		Currently the user can only select American sections in the app. We are working towards expanding the list of available sections in the future.		</p>
		<p>
		Material grades for sections and connecting elements are based on the commonly used ASTM specifications. Steel sections may be either specified as ASTM A36 or ASTM A992. Plates can only be specified as ASTM A36. High strength bolts are as per ASTM F3125. It is worthwhile to note that the app refers to the older ASTM A325 and ASTM A490 specifications for high strength bolts these are basically equivalent to the grade 325 and grade 490 bolts in the newer specification. We are working to include more specifications in the future.
		</p>
		<p>
		Bolts can be specified either in inches or in their metric equivalent. Both bearing and friction (slip critical) bolts can be specified. A point to note here is that for friction bolts the surface preparation is considered as Class A as defined in the AISC specifications. For bearing type bolts is assumed that the thread is included in the shear plane. While calculating the bearing capacity it is assumed that deformations of the connection is a design consideration. These assumptions while simplifying the input also provide a conservative design.
		</p>
		<h3>Running the connection design</h3>
		<p>
		After providing the connection design input the connection is checked using the Run button. The output produced from running the connection design is displayed below this button. 
		</p>
		<?php
		drawFooter();
		?>
	</div>
</body>
</html>