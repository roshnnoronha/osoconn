<?php
require_once '../util/common.php';

$connectionCode = '';
$hasRunSuccessfully = false;
$inputFieldsFile = '';
$connectionDescription = '';
$connectionSpecification = '';
$connectionImage = '';
$connectionJs = '';
$inputFields = [];
$inputGroupExpanded = [];

//get connection details
if (isset($_GET['code'])){
    $connectionCode = $_GET['code'];
    $connectionJSON = file_get_contents('./connections.json');
    $connectionDetails = json_decode($connectionJSON, true);
    if (array_key_exists($connectionCode, $connectionDetails)){
        $inputFieldsFile = $connectionDetails[$connectionCode]['input_fields'];
        $connectionDescription = $connectionDetails[$connectionCode]['description'];
        $connectionSpecification = $connectionDetails[$connectionCode]['specification'];
        $connectionImage = $connectionDetails[$connectionCode]['image'];
        $connectionJs = $connectionDetails[$connectionCode]['javascript'];
    }
    //get details of the input fields
    $inputJSON = file_get_contents($inputFieldsFile);
    $inputData = json_decode($inputJSON, true);
    foreach ($inputData as $group){
        $inputGroupExpanded[$group['tab_name']] = $group['tab_expanded'];
        foreach ($group['tab_fields'] as $field){
            $inputFields[$field['name']] = $field;
        } 
    } 
    //check if the run button was pressed and generate the cin and run executable if so
    if (isset($_POST['run'])){
        $inputString = 'CONNECTION_CODE '.$connectionCode.';';
        foreach($inputGroupExpanded as $name => $isExpanded){
            if (isset($_POST[$name.'_expanded'])){
                $inputGroupExpanded[$name] = $_POST[$name.'_expanded'];
            }
        }
        foreach($inputFields as $name => $field){
            if (isset($_POST[$name])){
              $inputFields[$name]['value']=$_POST[$name];
              $inputString = $inputString.$inputFields[$name]['para'].' '.$inputFields[$name]['value'].';';
            }
        }
        exec('../bin/osoconn --web -p  -s "'.$inputString.'"', $out_arr);
        $outputString = '';
        foreach ($out_arr as $line){
            $outputString = $outputString."\n".$line;
        }
        $hasRunSuccessfully=true;
    }
}
//generates the html for a text field with 
//caption:$caption
//value:$value
//name:$name
//field type:$inputType [text/number]
//unit system:$unitType [length/force/stress]
//required:$isRequired [true/false]
//enabled?:$isEnabled [true/false]
function inputText($caption,$value,$name,$inputType,$unitType='',$isRequired=true,$isEnabled=true){
	echo '<div class="form-group">';
	echo '<label class="control-label col-sm-4" for="'.$name.'">'.$caption.($isRequired?'*':'').'</label>';
	echo '<div class="col-sm-5">';
    echo '<input type= "text" class="form-control '.$inputType.'-field '.($unitType!=''?$unitType.'-val ':'').($isRequired?'required-field ':'').'input" name="'.$name.'" id="'.$name.'" value="'.$value.'" '.($inputType == 'text'?'maxlength=35 ':'').'>';
	echo '</div>';
	echo '<div class="col-sm-3">';
	if ($unitType == 'length')
		echo '<span class="length-unit">mm</span>';
	else if ($unitType == 'force')
		echo '<span  class="force-unit">Newton</span>';
	else if ($unitType == 'stress')
		echo '<span  class="stress-unit">MPa</sup></span>';
	echo '</div>';				
	echo '</div>';
}

//generates the html for a select field with 
//caption:$caption
//list of items: $itemList
//export values: $valueList
//value:$defaultValue
//name:$name
//data type:$dataType [w_sections/angle/bolts] (this is used to fill select field with section or bolt data)
//unit type:$unitType [NEWTON_MM/KIP_IN] (this is used to fill section and bolt data)
//enabled:$isEnabled [true/false]
function inputSelect($caption,$valueList,$itemList,$defaultValue,$name,$dataType='',$unitType='',$isEnabled=true){
    switch ($dataType){
    case  'w_sections':
        switch($unitType){
        case  'NEWTON_MM':
            $dataFile ='wSection_list_mm.json'; 
            break;
        case 'KIP_IN':
            $dataFile ='wSection_list_in.json'; 
        }
        break;
    case 'angles':
        switch($unitType){
        case  'NEWTON_MM':
            $dataFile ='aSection_list_mm.json'; 
            break;
        case 'KIP_IN':
            $dataFile ='aSection_list_in.json'; 
        }
        break;
    case 'bolts':
        switch($unitType){
        case  'NEWTON_MM':
            $dataFile ='bolt_list_mm.json'; 
            break;
        case 'KIP_IN':
            $dataFile ='bolt_list_in.json'; 
        }
        break;
    default:
        $dataType='';
    }
    if ($dataFile != ''){
        $dataJSON = file_get_contents($dataFile);
        $selectItems = json_decode($dataJSON, true);
        $valueList = $selectItems;
        $itemList = $selectItems;
    }  
	echo('<div class="form-group">');
	echo('<label class="control-label col-sm-4 for="'.$name.'">'.$caption.'</label>');
	echo('<div class="col-sm-5">');
	echo('<select class="form-select form-control input '.$dataType.'" name="'.$name.'" id="'.$name.'">');
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
//gernerates an hidden text field with
//value:$value
//name:$name
function hiddenText($value,$name){
		echo '<input type= "hidden"  name="'.$name.'" id="'.$name.'" value="'.$value.'">';
}
//gernerates the input/ output pane
function drawForm(){
    global $inputData;
    global $inputFields;
    global $inputGroupExpanded;
    global $outputString;
    global $connectionCode;
    global $hasRunSuccessfully;
    if ($connectionCode == '') return;
    hiddenText($connectionCode,'connection_code');
    //draw the input and output tabs
    echo('<ul class="nav nav-tabs" >');
        echo('<li id="input_tab" '.($hasRunSuccessfully?'':'class="active"').'><a data-toggle="tab" href="#input_area">  Input  </a></li>');
        echo('<li id="output_tab" '.($hasRunSuccessfully?'class="active"':'class="disabled"').'><a id="output_tab_link" '.($hasRunSuccessfully?'data-toggle="tab"':'').' href="#output_area">  Output  </a></li>');
    echo('</ul>');
	echo('<div class="tab-content">');	
        //draw input area
        echo('<div id="input_area" class="tab-pane fade in '.($hasRunSuccessfully?'':'active').'">'); 
            echo('<form method="post" class="form-horizontal">');
            //draw the run button
            echo '<br><nav class="navbar navbar-default">';
            echo '<div class="container">';
            echo '<div class="btn-group">';
                echo '<button type="submit" class="btn btn-success navbar-btn" name="run" value="Run" onclick="return validateConnectionInputs()">Run</button>';
                echo '<div class="btn-group">';
                    echo '<button type="button" class="btn btn-primary navbar-btn dropdown-toggle" data-toggle="dropdown">Data <span class="caret"></span></button>';
                    echo '<ul class="dropdown-menu" role="menu">';
                        echo '<li><a id="menu_export_cin" href="#">Export as .cin file</a></li>';
                    echo '</ul>';
                echo '</div>';
                echo '<div class="btn-group">';
                    echo '<button type="button" class="btn btn-primary navbar-btn dropdown-toggle" data-toggle="dropdown">Panes <span class="caret"></span></button>';
                    echo '<ul class="dropdown-menu" role="menu">';
                        echo '<li><a id="menu_expand_panes" href="#">Expand all</a></li>';
                        echo '<li><a id="menu_collapse_panes" href="#">Collapse all</a></li>';
                    echo '</ul>';
                echo '</div>';
            echo '</div>';
            echo '</div>';
            echo '</nav>';
            //read the json file that has information of the vatious fields for a connection code 
            //and generate the fields and field groups.  
            foreach ($inputData as $group){
                $tabName = $group['tab_name'];
                $tabCaption = $group['tab_caption'];
                hiddenText($inputGroupExpanded[$tabName],$tabName.'_expanded');
                echo('<div class="panel panel-default">');
                echo('<div class="panel-heading">');
                    echo('<a href="#'.$tabName.'" data-toggle="collapse">'.$tabCaption.'<span class="caret"></span></a>');
                echo('</div>');
                if ($inputGroupExpanded[$group['tab_name']])
                    echo('<div class="panel-body collapse in" id="'.$tabName.'">');
                else
                    echo('<div class="panel-body collapse" id="'.$tabName.'">');
                $tabFields = $group['tab_fields'];
                $unitSystem = $inputFields['units']['value'];
                foreach ($tabFields as $field){
                    $fieldName = $field['name'];
                    $fieldCaption = $field['caption'];
                    $fieldValueList = $field['value_list'];
                    $fieldItemList = $field['item_list'];
                    $fieldType = $field['type'];
                    $fieldDataSource = $field['data_type'];
                    $fieldUnitType = $field['unit_type'];
                    $fieldValue = $inputFields[$fieldName]['value'];
                    $fieldRequired = ($field['required'] == "false"?false:true);
                    $fieldEnabled = ($field['enabled'] == "false"?false:true);
                    if ($fieldType == 'select') 
                       inputSelect($fieldCaption,$fieldValueList,$fieldItemList,$fieldValue,$fieldName,$fieldDataSource,$unitSystem,$fieldEnabled); 
                    else
                       inputText($fieldCaption,$fieldValue,$fieldName,$fieldType,$fieldUnitType,$fieldRequired,$fieldEnabled);
                }
                echo('</div>');
                echo('</div>');
            }
            echo('</form>');
        echo('</div>');
        //draw output area
        echo('<div id="output_area" class="tab-pane fade in '.($hasRunSuccessfully?'active':'').'">'); 
            echo ('<br>');
            echo ('<pre>'.htmlentities($outputString).'</pre>');	
        echo('</div>');
    echo('</div>');
}
//function to insert the title
function insertTitle(){
    global $connectionCode;
    global $connectionDescription;
    global $connectionSpecification;
    global $connectionCode;
    if ($connectionCode == '') return;
    echo '<div class="container">';
    echo '<h2>'.$connectionCode.' <small>'.$connectionDescription.' ['.$connectionSpecification.']</small></h2>';
    echo '</div>';
}
//function to insert the connection image
function insertImage(){
    global $connectionCode;
    global $connectionImage;
    if ($connectionCode == ''){
	    echo '<div id="connection_image" class="jumbotron" style="text-align:center" onselectstart="return false">';
        echo '<h1>Osoconn <small>Web App</small></h1>';
        echo '<br><h5>Simple and hassle-free connection design.</h5>';
	    echo '</div>';
        echo '<p>Click &ltNew Connection&gt to create a new connection.</p>';
        return;
    }
    echo '<div id="connection_image" >';
    echo '<div style="max-width:550px; margin: 0 auto;>';
	echo file_get_contents('..'.$connectionImage); 
	echo '</div>';
    echo '</div>';
}
?>
<!DOCTYPE html>
<html lang ="en">
<head>
    <?php
    printHeader();
    ?>
</head>
<body >
	<?php
	drawNavBar('webapp');
	?>
	<div class="container" >	
		<?php
        insertTitle();
        insertImage();
		drawForm();
		?>
	</div>
    <?php
	drawFooter();
    ?>
</body>
<script src="common.js"></script>
<?php
echo '<script src="'.$connectionJs.'"></script>';
?>
</html>
