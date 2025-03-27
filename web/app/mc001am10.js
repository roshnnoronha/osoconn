function disableField(fieldID){
    $('#'+fieldID).attr('disabled','disabled');
    $('#'+fieldID).val('');
    $('#'+fieldID).removeClass('required-field');
}
function disableSelect(fieldID){
    $('#'+fieldID).attr('disabled','disabled');
}
function enableField(fieldID){
    $('#'+fieldID).addClass('required-field');
    $('#'+fieldID).removeAttr('disabled');
}
function enableSelect(fieldID){
    $('#'+fieldID).removeAttr('disabled');
}
// function that updates corresponding fields whent the configuration
// of the connection is updated
function configurationOnUpdate(){
    $('#img_4bolt').attr('style','display:none');
    $('#img_4bolt_stiffened').attr('style','display:none');
    $('#img_8bolt_stiffened').attr('style','display:none');
    switch($('#configuration').val()){
    case '4_BOLTS':
        $('#img_4bolt').attr('style','display:inline');
        disableField('plate_stiffener_length');
        disableField('plate_stiffener_thickness');
        disableField('plate_stiffener_weld');
        disableField('bolt_spacing');
        break;
    case '4_BOLTS_STIFFENED':
        $('#img_4bolt_stiffened').attr('style','display:inline');
        enableField('plate_stiffener_length');
        enableField('plate_stiffener_thickness');
        enableField('plate_stiffener_weld');
        disableField('bolt_spacing');
        break;
    case '8_BOLTS_STIFFENED':
        $('#img_8bolt_stiffened').attr('style','display:inline');
        enableField('plate_stiffener_length');
        enableField('plate_stiffener_thickness');
        enableField('plate_stiffener_weld');
        enableField('bolt_spacing');
        break;
    }
}
// function that updates corresponding fields whent the requirement of 
// column stiffeners is updated
function columnStiffenerOnUpdate(){
    switch($('#column_stiffener').val()){
    case 'YES':
        enableField('column_stiffener_thickness');
        enableField('column_stiffener_width');
        enableField('column_stiffener_clip');
        enableField('stiffener_to_flange_weld');
        enableField('stiffener_to_web_weld');
        break;
     case 'NO':
        disableField('column_stiffener_thickness');
        disableField('column_stiffener_width');
        disableField('column_stiffener_clip');
        disableField('stiffener_to_flange_weld');
        disableField('stiffener_to_web_weld');
        break;
    }
}
// function that updates corresponding fields whent the requirement of 
// doubler plates is updated
function doublerOnUpdate(){
    switch($('#doubler_plate').val()){
    case 'YES':
        enableField('doubler_thickness');
        enableField('doubler_height');
        enableField('doubler_weld');
        break;
    case 'NO':
        disableField('doubler_thickness');
        disableField('doubler_height');
        disableField('doubler_weld');
        break;
    }
}
$(document).ready(function(){
	$('#configuration').change(function(){
        configurationOnUpdate();
    });
    
	$('#column_stiffener').change(function(){
        columnStiffenerOnUpdate();
    });
	$('#doubler_plate').change(function(){
        doublerOnUpdate();
    });
    configurationOnUpdate();
    columnStiffenerOnUpdate();
    doublerOnUpdate();
});
