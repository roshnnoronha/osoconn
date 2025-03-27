<?php
require_once './util/common.php';

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
	drawNavBar('');
	?>
    <div class="container">
	<div class="jumbotron" style="text-align:center" onselectstart="return false">
	<h1 >Osoconn</h1>
	<br><h4>Free and open-source steel connection design</h4>
	<br><br><img src="./images/main.png" class="img-responsive img-circle" style="margin: 0 auto;">
    <br><br><form action="./app/webapp.php">
    <button type="submit" class="btn btn-lg btn-primary">Web App</button> 
    </form>

	</div>	
	</div>	
    <?php
    drawFooter();
    ?>
</body>
</html>

