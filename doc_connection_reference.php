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
		<h2>Connection Reference</h2>
		<p>
		Osoconn currently allows the design of the following types of connections. We are striving to include new connections and design specifications. Stay tuned for updates on that front.
		</p>
		<ul style ="list-style-type: none;">
		<li><a href="doc_SC001.php">SC001 - Clip Angle Shear Connections</a></li>
		<li><a href="doc_MC001.php">MC001 - End Plate Moment Connections</a></li>
		<li><a href="doc_HB001.php">HB001 - Horizontal Bracing Connections</a></li>
		<li><a href="doc_VB001.php">VB001 - Vertical Bracing Connection at Beam-Column Junction</a></li>
		</ul>
		<?php
		drawFooter();
		?>
	</div>
</body>
</html>