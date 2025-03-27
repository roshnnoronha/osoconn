//function to update image when support type is changed
function supportTypeOnChange(){
    $('#img_beam').attr('style','display:none');
    $('#img_col_web').attr('style','display:none');
    $('#img_col_flange').attr('style','display:none');
    switch($('#support_type').val()){
    case 'BEAM':
        $('#img_beam').attr('style','display:inline');
        break;
    case 'COLUMN_WEB':
        $('#img_col_web').attr('style','display:inline');
        break;
    case 'COLUMN_FLANGE':
        $('#img_col_flange').attr('style','display:inline');
        break;
    }
}
//function to change assosiated fields when bolt type is  changed
function boltTypeOnChange(){
    switch($('#bolt_type').val()){
    case 'BEARING':
        $('#faying_surface').attr('disabled','disabled');
        break;
    case 'FRICTION':
        $('#faying_surface').removeAttr('disabled');
        break;
    }
}
$(document).ready(function(){
	$('#support_type').change(function(){
        supportTypeOnChange();
	});
    supportTypeOnChange();
	$('#bolt_type').change(function(){
        boltTypeOnChange();
	});
    boltTypeOnChange();
});
