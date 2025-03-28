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
    drawDocSidebar('cla');
    ?>
    </div>
	<div class="container col-sm-9">	
		<h2>Osoconn CLA</h2>
		<p>
The Osoconn Command Line App (CLA) can be run on the Linux command line. It is
a simple utility that provides all the functionality of the Web App along with
the convenience of being able to run multiple connections at once along with
other useful features.  
		</p>
		<h4>Setup</h4>
		<p>
Setting up the utility is simple. Download the pre-compiled binary and save it
at the desired location. The CLA can also be compiled from the source files in
its Github repository. An optional additional step is to add the folder
location of the Osoconn app to the system path environmental variable. This
will allow the user to access the utility from any working folder in the
system. 
		</p>
        <h4>Running the App</h4>
		<p>
Open a command prompt and run the utility by typing out osoconn followed by
the path to the input file to be run. For example to run a file connection.cin
located in the examples folder in the current working folder enter:		
		</p>
		<pre>osoconn ./examples/connection.cin</pre>
		<h4>Flags</h4>
		<p>
The behavior of the utility can be modified by setting various flags while
running. Flags are represented by a hyphen followed by a character. All the
possible flags that can be set in osoconn are listed in the table below.
		</p>
		<table class="table" style="font-family:monospace">
		<tr>
			<th>Flag</th>
			<th>Description</th>
			<th>Example</th>
		</tr>
		<tr>
			<td>-p</td>
			<td>Display output  after running osoconn.</td>
			<td>osoconn  example.cin -p</td>
		</tr>
		<tr>
			<td>-s</td>
			<td>Input by string. </td>
			<td>osoconn -s “CONNECTION_CODE SC001; CONNECTION_ID;…”</td>
		</tr>
		<tr>
			<td>-u</td>
			<td>Input by string and updates the input file with the new values.</td>
			<td>osoconn example.cin -u “CONNECTION_CODE SC001; CONNECTION_ID;…”</td>
		</tr>
		<tr>
			<td>-o</td>
			<td>Specify the name of the output file.</td>
			<td>osoconn example.cin -o output_file.cou</td>
		</tr>
		</table>
		<h4>Input files</h4>
		<p>
Input files are text files with an extension of  *.cin that are provided to
the utility. It contains a collections of parameter value pairs that define the
connection details. Each parameter value pair is provided in a new line.
Different types of connections have different parameters that must be
provided. See the connection reference section to see a list of all the
parameters for that connection type.
		</p>
		<p>
An input file may also contain remark lines that are ignored by the utility.
These may be used to provide additional information to the user of the input
file. Remark lines are started with an asterisk (*). 
		</p>
		<p>
		An example of an input file is provided below.
		</p>
		<p>
		example.cin:
		</p>
		<pre>
CONNECTION_CODE SC001AM10
CONNECTION_ID SC002
METHOD ASD
UNITS NEWTON_MM

*MATERIAL PROPERTIES
MODULUS_OF_ELASTICITY 200000
POISSON_RATIO 0.3
STEEL_GRADE_OF_ANGLE A36
STEEL_GRADE_OF_BEAM A36
WELD_ELECTRODE E70
BOLT_GRADE A325
*CONNECTION FORCES
TRANSFER_FORCE 15000
SHEAR_FORCE 90000

*BOLT DETAILS
BOLT_DIAMETER M22
BOLT_TYPE FRICTION
NUMBER_OF_BOLTS_PER_ROW 4
BOLT_GAGE 140
BOLT_SPACING 60

*WELD DETAILS
THICKNESS_OF_WELD 8

*BEAM DETAILS
BEAM_SECTION W410X67
CONNECTION_SETBACK 12
COPE_LENGTH 100
TOP_COPE_DEPTH 35
BOTTOM_COPE_DEPTH 35

*SUPPORT DETAILS
SUPPORT_SECTION W410X67
SUPPORT_TYPE BEAM
BACKING_BEAM YES

*CLIP ANGLE DETAILS
CLIP_ANGLE L102X102X9.5
OUTSTANDING_LEG LONG_LEG
CLIP_ANGLE_LENGTH 240
CLIP_ANGLE_TOP 40
		</pre>
		<p>
Instead of a single input file the user may also provide the path to a folder,
in which case Osoconn runs all the available input files with the extension of
*.cin present in that folder. For example, to run all the files in folder
examples in the current working directory the user should enter:
		</p>
		<pre>osoconn ./examples/</pre>
		<h4>Input by strings</h4>
		<p>
Input to the utility may also be provided directly in the command line using
an input string. An input string is similar to the parameter value pair format
of the input file, but instead of providing the input on multiple lines the
parameter value pairs are provided in a single line separated by a semicolon
(;). String input is provided following the -s flag. For example, to run to
connection in the input file above without an input file the user would have
to run the following command:
		</p>
		<pre>osoconn -s “CONNECTION_CODE SC001AM10;CONNECTION_ID SC002;METHOD ASD;UNITS NEWTON_MM;MODULUS_OF_ELASTICITY 200000;POISSON_RATIO 0.3;STEEL_GRADE_OF_ANGLE A36;STEEL_GRADE_OF_BEAM A36;WELD_ELECTRODE E70;BOLT_GRADE A325;TRANSFER_FORCE 15000;SHEAR_FORCE 90000;BOLT_DIAMETER M22;BOLT_TYPE FRICTION;NUMBER_OF_BOLTS_PER_ROW 4;BOLT_GAGE 140;BOLT_SPACING 60;THICKNESS_OF_WELD 8;BEAM_SECTION W410X67;CONNECTION_SETBACK 12;COPE_LENGTH 100;TOP_COPE_DEPTH 35;BOTTOM_COPE_DEPTH 35;SUPPORT_SECTION W410X67;SUPPORT_TYPE BEAM;BACKING_BEAM YES;CLIP_ANGLE L102X102X9.5;OUTSTANDING_LEG LONG_LEG;CLIP_ANGLE_LENGTH 240;CLIP_ANGLE_TOP 40”</pre>
		<p>
If an input file is also provided along with an input string. The connection
in the input file is run with the values provided in the string superseding
the values provided in the input file. For example if the user wants to run
the file example.cin shown above, but wanted to try designing the connection
in LRFD instead of ASD the user may enter the following.
		</p>
		<pre>osoconn example.cin -s “METHOD LRFD”</pre>
		<p>
The input string may also be the path to any text file that contains these
input strings. When Osoconn detects that the string following the -s flag is a
valid file, it tries to read the content of that file. It expects a series of
lines where each line is a valid input string. Osoconn will then try each of
these strings from top to bottom till a qualifying connection is achieved.
This method of input is useful in specifying standard connection details as
Osoconn will automatically select the connection detail out of all the given
details. If none of the connections qualify Osoconn will generate the output
file with the last connection detail in the file.
		</p>
		<p>
For example, if there is an input file example2.cin, and if there is a file
standard.txt with the input strings of various standard clip angle
connections, to iteratively try these standard connections the user would
enter the following command:
		</p>
		<pre>osoconn example2.cin -s standard.txt</pre>
		<p>
		The contents of the two files are as follows.
		</p>
		<p>
		example2.cin:
		</p>
		<pre>
CONNECTION_CODE SC001AM10
CONNECTION_ID SC002
METHOD ASD
UNITS NEWTON_MM

*MATERIAL PROPERTIES
MODULUS_OF_ELASTICITY 200000
POISSON_RATIO 0.3
STEEL_GRADE_OF_ANGLE A36
STEEL_GRADE_OF_BEAM A36
WELD_ELECTRODE E70
BOLT_GRADE A325
*CONNECTION FORCES
TRANSFER_FORCE 15000
SHEAR_FORCE 90000

*BOLT DETAILS
BOLT_DIAMETER M22
BOLT_TYPE FRICTION
BOLT_GAGE 140
BOLT_SPACING 70

*BEAM DETAILS
BEAM_SECTION W410X67
CONNECTION_SETBACK 12
COPE_LENGTH 100
TOP_COPE_DEPTH 35
BOTTOM_COPE_DEPTH 35

*SUPPORT DETAILS
SUPPORT_SECTION W410X67
SUPPORT_TYPE BEAM
BACKING_BEAM YES

*CLIP ANGLE DETAILS
CLIP_ANGLE L102X102X9.5
OUTSTANDING_LEG LONG_LEG
CLIP_ANGLE_TOP 40		
		</pre>
		<p>
		standard.txt:
		</p>
		<pre>
NUMBER_OF_BOLTS_PER_ROW 2; CLIP_ANGLE_LENGTH 140; THICKNESS_OF_WELD 6
NUMBER_OF_BOLTS_PER_ROW 3; CLIP_ANGLE_LENGTH 210; THICKNESS_OF_WELD 6
NUMBER_OF_BOLTS_PER_ROW 4; CLIP_ANGLE_LENGTH 280; THICKNESS_OF_WELD 8	
		</pre>
		<h4>Update by string</h4>
		<p>
The update flag -u is used to update the parameter value pair in an input
file. The new value is provided as a input string similar to the one used by
input by string flag. For example, to update the transfer force parameter in
example.cin the user would enter:
		</p>
		<pre>osoconn example.cin -u “TRANSFER_FORCE 20000”</pre>
		<h4>Output files</h4>
		<p>
An output file is generated when the connection is run. By default, the file
is named the same as the input file name with an extension of *.cou. Another
filename can be for the output file using the -o flag. To write the output of
running example.cin to an output file name out.cou in a sub-folder named output
in the current working folder enter the following at the command line.
		</p>
		<pre>osoconn example.cin -o  ./output/out.cou</pre>
	</div>
	</div>
	</div>
    <?php
    drawFooter();
    ?>
</body>
</html>
