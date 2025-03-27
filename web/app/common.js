//function to fill a select field having id:id with data:data, and 
//set the active value to:activeValue 
function fillSelect(id,data,activeValue){
	$('#' + id).empty();
	if (data.length == undefined){
		for (i in data){
            if (data[i] == activeValue)
                $('#' + id).append('<option selected value="'+data[i]+'">'+data[i]+'</option>');
            else
                $('#' + id).append('<option value="'+data[i]+'">'+data[i]+'</option>');
		}
	}else{
		for (i of data){
            if (i == activeValue)
                $('#' + id).append('<option selected value="'+i+'">'+i+'</option>');
            else
                $('#' + id).append('<option value="'+i+'">'+i+'</option>');
            
		}		
	}
}
//function to validate the values provided in the form
//returns false if validation fails
function validateConnectionInputs(){
    valSuccess = true;
    firstErrField = '';
    errMessage = '';
    //check text fields have no special characters
    $('.text-field').each(function(){
        fieldVal = $(this).val();
        fieldId = $(this).attr('id');
        $('label[for='+fieldId+']').removeClass('text-danger');
        regEx = /^\w*$/;
        if (!regEx.test(fieldVal)){
            $('label[for='+fieldId+']').addClass('text-danger');
            if (valSuccess){
                firstErrField = fieldId;
                errMessage = 'The "'+ $('label[for='+fieldId+']').text() + '" field cannot have special characters.';
            }
            valSuccess = false;
        }

    });
    //check all required fields
    $('.required-field').each(function(){
        fieldVal = $(this).val();
        fieldId = $(this).attr('id');
        $('label[for='+fieldId+']').removeClass('text-danger');
        if ($('#'+fieldId).val()== ''){
            $('label[for='+fieldId+']').addClass('text-danger');
            if (valSuccess){
                firstErrField = fieldId;
                errMessage = 'The "'+ $('label[for='+fieldId+']').text() + '" field is required.';
            }
            valSuccess = false;

        }
    });
    //check all numeric fields
    $('.number-field').each(function(){
        fieldVal = $(this).val();
        fieldId = $(this).attr('id');
        if (fieldVal)
            $('label[for='+fieldId+']').removeClass('text-danger');
        regEx = /^[+|-]?\d+\.*\d*$/;
        if ((fieldVal) && (!regEx.test(fieldVal))){
            $('label[for='+fieldId+']').addClass('text-danger');
            if (valSuccess){
                firstErrField = fieldId;
                errMessage = 'The "'+ $('label[for='+fieldId+']').text() + '" field is expecting a number.';
            }
            valSuccess = false;
        }
    });
    if (!valSuccess){
        alert(errMessage);
        $('#'+firstErrField).focus();
    }
    return valSuccess;
}
//define the function to be called when the page is loaded
$(document).ready(function(){
    //define functionality for the expand all menu item
    $('#menu_expand_panes').click(function(){
        $('.panel-body').each(function(){
            $(this).addClass('in');       
        });
    });
    //define functionality for the collapse all menu item
    $('#menu_collapse_panes').click(function(){
        $('.panel-body').each(function(){
            $(this).removeClass('in');       
        });
    });
    //define functionality for the export cin menu item
    $('#menu_export_cin').click(function(){
        if (validateConnectionInputs()){
            let connectionCode = $('#connection_code').val();
            let inputString = '';
            $('.input').each(function(){
                let value = $(this).val();
                let name = $(this).attr('id');
                if (!($(this).is(':disabled')) && (value != ''))
                    inputString = inputString + name + ':' + value + ';';
            });
            let temp_element = document.createElement('a');
            temp_element.setAttribute('href', 'generate_cin.php?code='+ connectionCode +'&data='+inputString);
            let aj = $(temp_element);
            aj.appendTo('body');
            aj[0].click();
            aj.remove();
        }

    });
    //define the function to be called on change of units 	
	$('#units').change(function(){
		var curUnits = $('#units').val();
        //update the select fields in the input form
        if (curUnits == 'NEWTON_MM'){
            wSectionDataFile = 'wSection_list_mm.json';
            aSectionDataFile = 'aSection_list_mm.json';
            boltDataFile = 'bolt_list_mm.json';
        }else{
            wSectionDataFile = 'wSection_list_in.json';
            aSectionDataFile = 'aSection_list_in.json';
            boltDataFile = 'bolt_list_in.json';
        }
        $.getJSON(wSectionDataFile,function(data,status){
            $('.w_sections').each(function(){
                //get equivalant converted value
                oldValue = $(this).val();
                fieldId = $(this).attr('id');
                fillSelect(fieldId,data,'');
                $.get('equi_wSection.php?value='+oldValue+'&convertto=' + curUnits +'&fieldid='+fieldId,function(data){
                    let retObj= JSON.parse(data);
                    $('#'+retObj['field_id']).val(retObj['value']);
                });
            });
        });
        $.getJSON(aSectionDataFile,function(data){
            $('.angles').each(function(){
                //get equivalant converted value
                oldValue = $(this).val();
                fieldId = $(this).attr('id');
                fillSelect(fieldId,data,'');
                $.get('equi_aSection.php?value='+oldValue+'&convertto=' + curUnits + '&fieldid='+fieldId,function(data){
                    let retObj= JSON.parse(data);
                    $('#'+retObj['field_id']).val(retObj['value']);
                });
            });
        });
        $.getJSON(boltDataFile,function(data){
            $('.bolts').each(function(){
                //get equivalant converted value
                oldValue = $(this).val();
                fieldId = $(this).attr('id');
                fillSelect(fieldId,data,'');
                $.get('equi_bolt.php?value='+oldValue+'&convertto=' + curUnits + '&fieldid='+fieldId,function(data){
                    let retObj= JSON.parse(data);
                    $('#'+retObj['field_id']).val(retObj['value']);
                });
            });
        });
		//update units for all input fields
		$('.length-unit').empty();
		$('.force-unit').empty();
		$('.stress-unit').empty();
		var newVal = 0;
		if (curUnits == 'KIP_IN'){
			$(".length-unit").append('in');
			$('.length-val').each(function(){
                if ($(this).val()!=''){
                    newVal = $(this).val()/25.4000508001016;
                    $(this).val(Math.round(newVal*100000)/100000);
                }
			});
			$(".force-unit").append('kip');
			$('.force-val').each(function(){	
                if ($(this).val()!=''){
                    newVal = $(this).val()/4448.2216152605;
                    $(this).val(Math.round(newVal*100000)/100000);
                }
			});
			$(".stress-unit").append('ksi');
			$('.stress-val').each(function(){
                if ($(this).val()!=''){
                    newVal = $(this).val()/6.89475908677537;
                    $(this).val(Math.round(newVal*100000)/100000);
                }
			});			
		}else{
			$(".length-unit").append('mm');
			$('.length-val').each(function(){
                if ($(this).val()!=''){
                    newVal = $(this).val()*25.4000508001016;
                    $(this).val(Math.round(newVal*100000)/100000);
                }
			});
			$(".force-unit").append('Newton');
			$('.force-val').each(function(){				
                if ($(this).val()!=''){
                    newVal = $(this).val()*4448.2216152605;
                    $(this).val(Math.round(newVal*100000)/100000);
                }
			});
			$(".stress-unit").append('MPa');
			$('.stress-val').each(function(){				
                if ($(this).val()!=''){
                    newVal = $(this).val()*6.89475908677537;
                    $(this).val(Math.round(newVal*100000)/100000);
                }
			});			
			
		}
	});
	//update units on load
	$('.length-unit').empty();
	$('.force-unit').empty();
	$('.stress-unit').empty();
	if ($('#units').val() == 'KIP_IN'){
		$(".length-unit").append('in');
		$(".force-unit").append('kip');
		$(".stress-unit").append('ksi');
	}else{
		$(".length-unit").append('mm');
		$(".force-unit").append('Newton');
		$(".stress-unit").append('MPa');			
	}
    //reset the output form if any field value is changed
	$('.input').change(function(){
		$('#output_tab').addClass("disabled");
        $('#output_tab_link').removeAttr("data-toggle");
	});
});
