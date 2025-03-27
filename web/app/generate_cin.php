<?php

$outputString = 'Error downloading file.';
$fileName = 'err.cin';
if (isset ($_GET['code'])){
    $connectionCode = strtoupper($_GET['code']);
    $fileName = $connectionCode;
    $inputString = $_GET['data'];
    $connectionJSON = file_get_contents('./connections.json');
    $connectionDetails = json_decode($connectionJSON, true);
    if (array_key_exists($connectionCode, $connectionDetails)){
        $inputFieldsFile = $connectionDetails[$connectionCode]['input_fields'];
        $inputFieldJSON = file_get_contents($inputFieldsFile);
        $inputTabs = json_decode($inputFieldJSON, true);
        $outputString = 'CONNECTION CODE ' . strtoupper($connectionCode). "\r\n";
        $inputArr = explode(';',$inputString);
        foreach ($inputArr as $parameterStr){
            $paraPair = explode(':',$parameterStr);
            $paraName = $paraPair[0];
            $paraVal = $paraPair[1];
            $parameter = '';
            if (($paraName == 'conn_id')&&($paraVal != ''))
                $fileName = $fileName . '_' . $paraVal;
            if ($paraVal != ''){
                foreach ($inputTabs as $tab){
                    foreach($tab['tab_fields'] as $field){
                        if (strtoupper($field['name']) == strtoupper($paraName)){
                            $parameter = $field['para'];
                            break;
                        }
                    }
                } 
                $outputString = $outputString.$parameter . ' ' . $paraVal."\r\n";
            }
        }
    }
}

header('Content-Description: File Transfer');
header('Content-Disposition: attachment; filename='.$fileName.'.cin');
header('Expires: 0');
header('Cache-Control: must-revalidate');
header('Pragma: public');
header('Content-Length: ' . strlen($outputString));
header("Content-Type: text/plain");

echo $outputString;
?>
