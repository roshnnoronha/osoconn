//function to update image when support type is changed
function supportTypeOnChange(){
    $('#img_col_web').attr('style','display:none');
    $('#img_col_flange').attr('style','display:none');
    switch($('#support_type').val()){
    case 'COLUMN_WEB':
        $('#img_col_web').attr('style','display:inline');
        break;
    case 'COLUMN_FLANGE':
        $('#img_col_flange').attr('style','display:inline');
        break;
    }
}
//function to change assosiated fields when number of bolt rows are changed
function boltRowsOnChange(){
    switch($('#bolt_rows').val()){
    case '1':
        $('#bolt_row_spacing').attr('disabled','disabled');
        $('#bolt_row_spacing').val('');
        $('#bolt_row_spacing').removeClass('required-field');
        break;
    case '2':
        $('#bolt_row_spacing').addClass('required-field');
        $('#bolt_row_spacing').removeAttr('disabled');
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
	$('#bolt_rows').change(function(){
        boltRowsOnChange();
	});
    boltRowsOnChange();
	$('#bolt_type').change(function(){
        boltTypeOnChange();
	});
    boltTypeOnChange();
});
