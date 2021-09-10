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
		<h2>Osoconn Documentation</h2>
		<p>
		The objective of the Osoconn Project is to develop a calculation repository of the various types of connection details used in the steel construction industry, and to make them available free of cost to the engineering community. The project is licensed under the <a href="doc_license.php">MIT open-source license</a>. The program can be run either as a web app or a command line app each with its own set of benefits and limitations. 
		</p>
		<p>
		Developing a robust and useable app takes time and we are striving to improve the app by developing new connection designs and by including new specifications of design. Contributions to the program and suggestions for improvements are always welcome. The source code can be found at our <a href="https://github.com/roshnnoronha/osoconn" target="_blank">Github repository</a>.		
		</p>
		<h3>Contents</h3>
		<ul style ="list-style-type: none;">
		<li><a href="doc_license.php">License</a></li>
		<li><a href="doc_cookies.php">Cookies</a></li>
		<li><a href="doc_osoconn_web_app.php">Osoconn Web App</a></li>	
		<li><a href="doc_osoconn_cla.php">Osoconn CLA</a></li>
		<li><a href="doc_connection_reference.php">Connection Reference</a></li>
		</ul>
		<?php
		drawFooter();
		?>
	</div>
</body>
</html>