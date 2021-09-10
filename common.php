<?php
function inputText($caption,$value,$name,$unitType=''){
	echo '<div class="form-group">';
	echo '<label class="control-label col-sm-3" for="'.$name.'">'.$caption.'</label>';
	echo '<div class="col-sm-5">';
	if ($unitType == 'length')
		echo '<input type= "text" class="form-control length-val input" name="'.$name.'" id="'.$name.'" value="'.$value.'">';
	else if ($unitType == 'force')
		echo '<input type= "text" class="form-control force-val input" name="'.$name.'" id="'.$name.'" value="'.$value.'">';
	else if ($unitType == 'stress')
		echo '<input type= "text" class="form-control stress-val input" name="'.$name.'" id="'.$name.'" value="'.$value.'">';
	else
		echo '<input type= "text" class="form-control input" name="'.$name.'" id="'.$name.'" value="'.$value.'">';
	echo '</div>';
	echo '<div class="col-sm-2">';
	if ($unitType == 'length')
		echo '<span class="length-unit">mm</span>';
	else if ($unitType == 'force')
		echo '<span  class="force-unit">N</span>';
	else if ($unitType == 'stress')
		echo '<span  class="stress-unit">MPa</sup></span>';
	echo '</div>';				
	
	echo '</div>';
}

function inputSelect($caption,$valueList,$itemList,$defaultValue,$name){
	echo('<div class="form-group">');
	echo('<label class="control-label col-sm-3 for="'.$name.'">'.$caption.'</label>');
	echo('<div class="col-sm-5">');
	echo('<select class="form-select form-control input" name="'.$name.'" id="'.$name.'">');
	if ($itemList != ''){
		for ($i=0;$i<count($itemList);$i++){
			if($valueList == '')
				echo('<option value="'.$i.'">'.$itemList[$i].'</option>');
			else{
				if ($defaultValue == $valueList[$i])
					echo('<option selected value="'.$valueList[$i].'">'.$itemList[$i].'</option>');
				else
					echo('<option value="'.$valueList[$i].'">'.$itemList[$i].'</option>');
			}
		}
	}
	echo('</select></div></div>');
}
function startTab($name,$isActive = false){
	echo('<div id="'.$name.'" class="tab-pane fade in'.($isActive?' active':'').'">');
	echo('<br>');
}
function endTab(){
	echo('</div>');
}
function startTabGroup($tabList,$tabIDList){
	echo('<ul class="nav nav-tabs">');	
	echo('<li class="active"><a data-toggle="tab" href="#'.$tabIDList[0].'">'.$tabList[0].'</a></li>');
	for($i=1;$i<count($tabList);$i++)			
		echo('<li><a data-toggle="tab" href="#'.$tabIDList[$i].'">'.$tabList[$i].'</a></li>');
	echo('</ul>');
	echo('<div class="tab-content">');	
}
function endTabGroup(){
	echo('</div>');
}
function drawNavBar($activeTab){
	echo('<nav class="navbar navbar-inverse">');
	echo('<div class="container-fluid">');
	echo('<div class="navbar-header">');
    echo('<button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#myNavbar">');
    echo('<span class="icon-bar"></span>');
    echo('<span class="icon-bar"></span>');
    echo('<span class="icon-bar"></span>');                        
    echo('</button>');	
	echo('<b class="navbar-brand">Osoconn</b>');
	echo('</div>');
	echo('<div class="collapse navbar-collapse" id="myNavbar">');
	echo('<ul class="nav navbar-nav">');
	echo('<li ' .($activeTab == 'home'?'class="active"':'') . '><a href="index.php">Home</a></li>');
	echo('<li '.($activeTab == 'connections'?'class="active"':'').'><a href="connections.php">Connections</a></li>');
	echo('<li '.($activeTab == 'download'?'class="active"':'').'><a href="download.php">Download</a></li>');
	echo('<li '.($activeTab == 'documentation'?'class="active"':'').'><a href="documentation.php">Documentation</a></li>');
	echo('</ul>');
	echo('</div>');
	echo('</div>');
	echo('</nav>');
}
function drawFooter(){
	echo ('<div id="footer">');
	echo('<br><hr>');
	echo('<p class="text-justify small">The Osoconn Project (c) 2021. The objective of the Osoconn Project is to develop a calculation repository of the various types of connection details used in the steel construction industry, and to make them available free of cost to the engineering community. This app is licensed under the <a href="doc_license.php">MIT open-source license</a>. The source code is available at <a href="https://github.com/roshnnoronha/osoconn" target="_blank">Github</a>.</p>');
	//echo('<p class="text-justify small">To stay updated with the latest developments at Osoconn <a href="#">subscribe</a> to our newsletter.</p>');
	echo('</div>');
}
function drawOutput($os){
	echo('<div id="output-area">');
	if ($os!=''){
		//echo ('<h5> Output:</h5>');
		echo ('<pre>'.htmlentities($os).'</pre>');	
	}	
	echo('</div>');
}
function drawRunButton(){
	echo('<div class="form-group">');
	echo('<input type="submit" class="btn btn-success" style= "margin-left:20px" name="run" value="Run">');
	echo('</div>');
}
function execute($inputString){
	return shell_exec('./osoconn -i -d -c -o output_file.cou -s "'.$inputString.'"');
}