<?php
require_once '../util/common.php';

?>
<!DOCTYPE html>
<html lang ="en">
<head>
    <?php
    printheader();
    ?>
</head>
<body>
	<?php
	drawNavBar('cla');
	?>
	<div class="container" >	
    <div id="connection_image" class="jumbotron" style="text-align:center" onselectstart="return false">
    <h1>Osoconn <small>Command Line App</small></h1>
    <br><h5>More options. More flexibility.</h5>
    </div>
    <p>
The Osoconn Command Line App (CLA) runs on the Linux command line. The
advantages the CLA has over the web app is the ablitity to run faster and
design multiple connections at once. To learn more about the
command line app see the <a href = "doc_osoconn_cla.php">documentation</a>
page. 
    </p>
    <p> 
Osoconn CLA can be built from the source code provided in its Github
repository. Pre-compiled binaries can also be downloaded for the operating
system specified below.
    </p>
    <a href="osoconn-v1_1-ubuntu22_04.tar.gz" download >Ubuntu 22.04</a>
	</div>
    <?php
    drawFooter();
    ?>
</body>
</html>
