function test(...a){
    console.log(a.length);
}

test(1,2,3,4,5);

var x = [1,2,3,4,5];
var [m,n] = x;

console.log([m,n]);