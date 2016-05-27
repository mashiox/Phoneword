$(document).ready(function(){
    
    var appendPhoneNames = function( word ){
        $("ul#phoneNames").append(
            "<li>" + word + "</li>"
        )
    }
    
    var clearPhoneNames = function(){
        $("ul#phoneNames li").remove();
    }
    
    var showAlert = function(){
        $("div#inputAlert").show();
    }
    
    var hideAlert = function(){
        $("div#inputAlert").hide();
    }
    
    var main = function(evt){
        evt.preventDefault();
        var val = $("input#inputPhone").val()
                                       .replace( /[^\d]/g, '' );
        switch ( val ){
            case '':
            case 0:
                showAlert();
                return; 
        }
        hideAlert();
        
        Phoneword(val).forEach(appendPhoneNames);
        
    }
    
    $("button#submitBtn").click(main);
    
    $("input#inputPhone").keypress(function(evt){
        if ( evt.which === 13 ){
            clearPhoneNames();
            main(evt);
        }
        return; 
    })
    
    $("button#clearBtn").click(function(evt){
        evt.preventDefault();
        
        $("ul#phoneNames li").remove();
    })
    
})