<?php
if (isset($_GET['convertto'])){
    if ($_GET['convertto'] == 'NEWTON_MM')
        $conversionFile = 'wSections_mm.json';
    else
        $conversionFile = 'wSections_in.json';
    $conversionJSON = file_get_contents($conversionFile);
    $conversionData = json_decode($conversionJSON, true);
    $valueToConvert = $_GET['value'];
    $returnVal['field_id'] = $_GET['fieldid'];
    $returnVal['value'] = $conversionData[$valueToConvert];
    echo json_encode($returnVal);
}

?>
