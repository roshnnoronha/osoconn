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
    drawDocSidebar('web_app');
    ?>
    </div>
	<div class="container col-sm-9">	
		<h2>Osoconn Web App</h2>
		<p>
The web app provides an easy-to-use graphical interface. The user interface is
designed to be intuitive with diagrams provided to clarify the details of the
connection.		
		</p>
		<h4>Providing inputs</h4>
		<p>
Inputs are provided in the input tab using familiar input elements such as
text boxes and drop downs. These elements are grouped into various panes for
convenience. Inputs can be provided either using (Newton, mm) or (kip, in) as
the units of measurement. 
		</p>
		<h4>Running the connection design</h4>
		<p>
After providing the connection design input the connection is checked using
the Run button. The output produced from running the connection design is
displayed in the output tab. 
		</p>
		<h4>Exporting the connection data</h4>
		<p>
The connection data in the input pane can be exported to a cin input file
using the data>"Export as .cin file" option.
		</p>
        <img src="images/export_data.png" width="25%">
	</div>
	</div>
	</div>
    <?php
    drawFooter();
    ?>
</body>
</html>
