document.querySelector("button").onclick = function () {
    
    eel.predict()(function(crop){                   
        
        document.querySelector(".a").innerHTML = crop;
    })
    }
    
