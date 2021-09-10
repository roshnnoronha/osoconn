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
		<h2>Osoconn CLA</h2>
		<img src=".\images\cla.png" height="200px" class="img-rounded" style="display:block;margin-left:auto;margin-right:auto;margin-bottom:30px">
		<p>
		The Osoconn command line app runs on the windows command prompt and has distict advantages over the web app in its ablitity to run faster and design multiple connections at once. To learn more about the command line app see the documentation page. Click the below link to download.
		</p>
		
		<a href="osoconn-v1.0-win.zip" download class="btn btn-info" role="button">Download for Windows</a>
		<?php
		drawFooter();
		?>
	</div>
</body>
</html>