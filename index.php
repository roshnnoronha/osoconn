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
	<div class="jumbotron">
	<h1 style="text-align:center">Osoconn</h1>
	<p style="text-align:center">A free and open-source steel connection design app.</p>
	<br>
	<div id="connection_image" style="text-align:center"> 
		<img src="./images/sc001_tmb.svg" class="img-responsive img-thumbnail">
		<img src="./images/vb001_tmb.svg" class="img-responsive img-thumbnail">

	</div>
	</div>	
	<div class="container-fluid" style="max-width:992px; margin: 0 auto;">	
		<?php
		drawFooter();
		?>
	</div>
</body>
</html>