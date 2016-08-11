function test(...a){
    console.log(a.length);
}

test(1,2,3,4,5);

var x = [1,2,3,4,5];
var [m,n] = x;
((a)=>{
    console.log(a);
})("a");
console.log([m,n]);