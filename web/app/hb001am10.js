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
//function to update  the diagram and the associated 
//fields when the connection 1 type is changed
function connectionOneOnUpdate(){
    $('#conn1_clip').attr('style','display:none');
    $('#conn1_flange').attr('style','display:none');
    $('#conn1_tab').attr('style','display:none');
    $('#cut_1f2f').attr('style','display:none');
    $('#cut_1nf2f').attr('style','display:none');
    $('#cut_1f2nf').attr('style','display:none');
    $('#cut_1nf2nf').attr('style','display:none');
    switch($('#conn_type_1').val()){
    case 'CLIP_ANGLE':
        $('#conn1_clip').attr('style','display:inline;');
        switch($('#conn_type_2').val()){
        case 'CLIP_ANGLE':
        case 'SHEAR_TAB':
            $('#cut_1nf2nf').attr('style','display:inline');
            break;
        case 'BOTTOM_FLANGE':
            $('#cut_1nf2f').attr('style','display:inline');
        }
        enableSelect('clip_angle');
        enableSelect('clip_oustanding_leg');
        enableField('bolt_gage_clip');
        enableField('edge_clip');
        enableField('clip_weld');
        enableField('setback_1');
        disableField('extension_1');
        disableField('bolt_gage_beam1');
        break;
    case 'SHEAR_TAB':
        $('#conn1_tab').attr('style','display:inline;');
        switch($('#conn_type_2').val()){
        case 'CLIP_ANGLE':
        case 'SHEAR_TAB':
            $('#cut_1nf2nf').attr('style','display:inline');
            break;
        case 'BOTTOM_FLANGE':
            $('#cut_1nf2f').attr('style','display:inline');
        }
        enableField('tab_width');
        enableField('tab_thickness');
        enableField('bolt_gage_tab');
        enableField('edge_tab');
        enableField('tab_weld');
        enableField('setback_1');
        disableField('extension_1');
        disableField('bolt_gage_beam1');
        break;
    case 'BOTTOM_FLANGE':
        $('#conn1_flange').attr('style','display:inline;');
        switch($('#conn_type_2').val()){
        case 'CLIP_ANGLE':
        case 'SHEAR_TAB':
            $('#cut_1f2nf').attr('style','display:inline');
            break;
        case 'BOTTOM_FLANGE':
            $('#cut_1f2f').attr('style','display:inline');
        }
        enableField('extension_1');
        enableField('bolt_gage_beam1');
        disableField('setback_1');
        break;
    }
    if (($('#conn_type_1').val()!='CLIP_ANGLE')&&($('#conn_type_2').val()!='CLIP_ANGLE')){
        disableSelect('clip_angle');
        disableSelect('clip_oustanding_leg');
        disableField('bolt_gage_clip');
        disableField('edge_clip');
        disableField('clip_weld');
    }
    if (($('#conn_type_1').val()!='SHEAR_TAB')&&($('#conn_type_2').val()!='SHEAR_TAB')){
        disableField('tab_width');
        disableField('tab_thickness');
        disableField('bolt_gage_tab');
        disableField('edge_tab');
        disableField('tab_weld');
    }
    if (($('#conn_type_1').val()!='BOTTOM_FLANGE')&&($('#conn_type_2').val()!='BOTTOM_FLANGE')){
        disableField('bolt_gage_beam1');
        disableField('bolt_gage_beam2');
    }
}

//function to update  the diagram and the associated 
//fields when the connection 2 type is changed
function connectionTwoOnUpdate(){
    $('#conn2_clip').attr('style','display:none');
    $('#conn2_flange').attr('style','display:none');
    $('#conn2_tab').attr('style','display:none');
    $('#cut_1f2f').attr('style','display:none');
    $('#cut_1nf2f').attr('style','display:none');
    $('#cut_1f2nf').attr('style','display:none');
    $('#cut_1nf2nf').attr('style','display:none');
    switch($('#conn_type_2').val()){
    case 'CLIP_ANGLE':
        $('#conn2_clip').attr('style','display:inline;');
        switch($('#conn_type_1').val()){
        case 'CLIP_ANGLE':
        case 'SHEAR_TAB':
            $('#cut_1nf2nf').attr('style','display:inline');
            break;
        case 'BOTTOM_FLANGE':
            $('#cut_1f2nf').attr('style','display:inline');
        }
        enableSelect('clip_angle');
        enableSelect('clip_oustanding_leg');
        enableField('bolt_gage_clip');
        enableField('edge_clip');
        enableField('clip_weld');
        enableField('setback_2');
        disableField('extension_2');
        disableField('bolt_gage_beam2');
        break;
    case 'SHEAR_TAB':
        $('#conn2_tab').attr('style','display:inline;');
        switch($('#conn_type_1').val()){
        case 'CLIP_ANGLE':
        case 'SHEAR_TAB':
            $('#cut_1nf2nf').attr('style','display:inline');
            break;
        case 'BOTTOM_FLANGE':
            $('#cut_1f2nf').attr('style','display:inline');
        }
        enableField('tab_width');
        enableField('tab_thickness');
        enableField('bolt_gage_tab');
        enableField('edge_tab');
        enableField('tab_weld');
        enableField('setback_2');
        disableField('extension_2');
        disableField('bolt_gage_beam2');
        break;
    case 'BOTTOM_FLANGE':
        $('#conn2_flange').attr('style','display:inline;');
        switch($('#conn_type_1').val()){
        case 'CLIP_ANGLE':
        case 'SHEAR_TAB':
            $('#cut_1nf2f').attr('style','display:inline');
            break;
        case 'BOTTOM_FLANGE':
            $('#cut_1f2f').attr('style','display:inline');
        }
        enableField('extension_2');
        enableField('bolt_gage_beam2');
        disableField('setback_2');
        break;
    }
    if (($('#conn_type_1').val()!='CLIP_ANGLE')&&($('#conn_type_2').val()!='CLIP_ANGLE')){
        disableSelect('clip_angle');
        disableSelect('clip_oustanding_leg');
        disableField('bolt_gage_clip');
        disableField('edge_clip');
        disableField('clip_weld');
    }
    if (($('#conn_type_1').val()!='SHEAR_TAB')&&($('#conn_type_2').val()!='SHEAR_TAB')){
        disableField('tab_width');
        disableField('tab_thickness');
        disableField('bolt_gage_tab');
        disableField('edge_tab');
        disableField('tab_weld');
    }
    if (($('#conn_type_1').val()!='BOTTOM_FLANGE')&&($('#conn_type_2').val()!='BOTTOM_FLANGE')){
        disableField('bolt_gage_beam1');
        disableField('bolt_gage_beam2');
    }
}
//function to update  the diagram and the associated 
//fields when the brace orientation is changed
function braceOrientationOnUpdate(){
    $('#brace_bblh').attr('style','display:none');
    $('#brace_bblv').attr('style','display:none');
    switch($('#brace_orientation').val()){
    case 'HORIZONTAL':
        $('#brace_bblh').attr('style','display:inline;');
        disableField('brace_spacing');
        break;
    case 'VERTICAL':
        $('#brace_bblv').attr('style','display:inline;');
        enableField('brace_spacing');
        break;
    }
}
//function to update the associated 
//fields when the brace orientation is changed
function jointTypeOnUpdate(){
    switch($('#joint_type').val()){
    case 'BEAM_JOINT':
        disableSelect('column_section');
        disableSelect('column_orientation');
        enableSelect('continuous_beam_no');
        continuousBeamOnChange();
        break;
    case 'COLUMN_JOINT':
        disableSelect('continuous_beam_no');
        enableSelect('column_section');
        enableSelect('column_orientation');
        enableSelect('beam_1_setback');
        enableSelect('beam_2_setback');
        enableSelect('beam_1_cope');
        enableSelect('beam_2_cope');
        break;
    }
}
//function to update the associated 
//fields when the continuous beam number is changed
function continuousBeamOnChange(){
    switch($('#continuous_beam_no').val()){
    case '1':
        disableField('beam_1_setback');
        disableField('beam_1_cope');
        enableField('beam_2_setback');
        $('#beam_2_cope').removeAttr('disabled');
        break;
    case '2':
        disableField('beam_2_setback');
        disableField('beam_2_cope');
        enableField('beam_1_setback');
        $('#beam_1_cope').removeAttr('disabled');
        break;
    }

}
//function to change assosiated fields when number of 
//bolt rows are changed
function boltRowsOnChange(){
    switch($('#bolt_rows').val()){
    case '1':
        disableField('bolt_row_spacing');
        break;
    case '2':
        enableField('bolt_row_spacing');
        break;
    }
}
//function to change assosiated fields when bolt type 
//is  changed
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
	$('#conn_type_1').change(function(){
        connectionOneOnUpdate();
	});
    connectionOneOnUpdate();
	$('#conn_type_2').change(function(){
        connectionTwoOnUpdate();
	});
    connectionTwoOnUpdate();
    //update the brace orientation in the diagram when the field is changed
	$('#brace_orientation').change(function(){
        braceOrientationOnUpdate();	
    });	
    braceOrientationOnUpdate();
	$('#joint_type').change(function(){
        jointTypeOnUpdate();	
    });
    jointTypeOnUpdate();
	$('#continuous_beam_no').change(function(){
        continuousBeamOnChange();	
    });
    continuousBeamOnChange();
	$('#bolt_rows').change(function(){
        boltRowsOnChange()
    });
    boltRowsOnChange()
	$('#bolt_type').change(function(){
        boltTypeOnChange();
	});
    boltTypeOnChange();
});
