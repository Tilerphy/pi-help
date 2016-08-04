
function testLet(){
    "use strict";  
    console.log(x);
    
    var x = 10;
}

function testPromises(){
    "use strict"; 
    let pro = new Promise(function(resolve, reject){
            var rand = parseInt(Math.random()*2000);
            setTimeout(()=>{
                 if(rand > 1000){
               
                        resolve(`rand num more than 1000, ${rand}`);
                    }else{
                        reject(`suck: ${rand}`);
                    }
                }, rand);
            
        });
        
    pro.then(function(a){
            console.log(a);
            return a;
        }, function(a){
                return a;
            })
        .then(function(b){
                console.log(b);
                return b;
            })
        .then(function(b){
                console.log(b);
                return b;
            })
        .catch(function(e){
                console.log(e)
            });
}
 
 
 
 
 
function p0(val){  
    return 10;
}
testPromises();
testLet();   