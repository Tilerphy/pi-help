var target = {};
var proxy_handler = {
        get: function(target, name){
            console.log(target.toString() + "'s "+ name.toString() +" has been called.");
            if(name.toString() == "Symbol(Symbol.iterator)"){
                console.log("shit yeah");
            }else{
                return target[name];
            }
        },
        
        has: function(target, name){
                return true;
        },
        a:"10"
    };
    
var real = new Proxy(target, proxy_handler);
real.name = "root";

console.log(real.name);
console.log("hello" in real);
console.log(real["hello"]);
for (var i of real){
        
}