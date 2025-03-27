<?php
//function to create the top navigation bar for all pages.
//The variable $activeTab has the information of the page calling the function.
function drawNavBar($activeTab){
	echo('<nav class="navbar navbar-default">');
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
    if ($activeTab == 'webapp'){
        echo '<form class="navbar-form navbar-left" action="connections.php">';
        echo '<button type="submit" class="btn btn-primary">New Connection</button>'; 
        echo '</form>';
    }
	echo('<ul class="nav navbar-nav navbar-right">');
	echo('<li '.($activeTab == 'webapp'?'class="active"':'').'><a href="/app/webapp.php">Web App</a></li>');
	echo('<li '.($activeTab == 'cla'?'class="active"':'').'><a href="/download/download.php">CLA</a></li>');
	echo('<li '.($activeTab == 'doc'?'class="active"':'').'><a href="/doc/documentation.php">Documentation</a></li>');
	echo('</ul>');
	echo('</div>');
	echo('</div>');
	echo('</nav>');
}
//function to create the footer for all pages
function drawFooter(){
    echo ('<div style="min-height:100px"></div>');
	echo ('<div class="container" id="footer" style="text-align:center">');
	echo('<br><hr>');
	echo('<h6> Osoconn (c) 2025 Roshn Noronha.</h6>');
	echo('</div>');
}
//function to create the side bar for all document pages
function drawDocSidebar($active){

     echo('<ul class ="nav nav-pills nav-stacked">');
     echo('<ul class="list-group">');
     echo('<a class="list-group-item '.($active == 'about'?'active':'').'"  href="documentation.php">About Osoconn</a>');
     echo('<a class="list-group-item '.($active == 'terms'?'active':'').'"  href="doc_terms_of_use.php">Terms of Use</a>');
     echo('<a class="list-group-item '.($active == 'privacy'?'active':'').'"  href="doc_privacy.php">Privacy Policy</a>');
     echo('<li class="list-group-item list-group-item-info">Osoconn Documention</li>');
     echo('<a class="list-group-item '.($active == 'web_app'?'active':'').'" href="doc_osoconn_web_app.php">Web App</a>');	
     echo('<a class="list-group-item '.($active == 'cla'?'active':'').'" href="doc_osoconn_cla.php">CLA</a>');
     echo('<li class="list-group-item list-group-item-info">Connection Reference</li>');
     echo('<a class="list-group-item '.($active == 'sc001'?'active':'').'" href="doc_SC001.php">SC001AM10</a>');
     echo('<a class="list-group-item '.($active == 'mc001'?'active':'').'" href="doc_MC001.php">MC001AM10</a>');
     echo('<a class="list-group-item '.($active == 'hb001'?'active':'').'" href="doc_HB001.php">HB001AM10</a>');
     echo('<a class="list-group-item '.($active == 'vb001'?'active':'').'" href="doc_VB001.php">VB001AM10</a>');
     echo(' </ul>');

}
//function to generate the html header contents of all pages
function printHeader(){

	echo('<title>Osoconn</title>');
	echo('<meta charset="utf-8">');
	echo('<meta name="viewport" content="width=device-width, initial-scale=1">');
	echo('<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">');
	echo('<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>');
	echo('<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>');
}
