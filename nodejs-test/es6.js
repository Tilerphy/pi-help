
function testLet(){
    "use strict";  
    console.log(x);
    
    var x = 10;
}

function testPromises(){
    "use strict"; 
    let pro = new Promise(function(resolve, reject){
            if(1===1){
                resolve("hey");
            }else{
                reject("suck");
            }
        });
    pro.then(function(a){
            console.log(a);
                return p0(val);
        }, function(a){
                
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