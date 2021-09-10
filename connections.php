<?php
require_once 'common.php';

$conData = file_get_contents('connections.json');
$conList = json_decode($conData,true);

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
<body >
	<?php
	drawNavBar('connections');
	?>

	<div class="container-fluid" style="max-width:992px; margin: 0 auto;">
		<div class="list-group">
			<?php
			foreach($conList as $con){
				echo('<a href="'.$con['link'].'" class="list-group-item">');
				echo('<div style="overflow:hidden">');
				echo('<img src="'.$con['image'].'" class="img-responsive img-thumbnail" style="float:left;margin-right:15px">');
				echo('<span>Description: '.$con['description'].'</span> <br>');
				echo('<span class="small">Type: '.$con['type'].'</span><br>');
				echo('<span class="small">Code: '.$con['code'].'</span><br>');
				echo('<span class="small">Specification: '.$con['specification'].'</span>');
				echo('</div>');
				echo('</a>');
			}
			?>
		</div>
		<?php
		drawFooter();
		?>
	</div>
</body>
</html>