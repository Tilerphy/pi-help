var name = "zbsun";
var age = 18;
var a = ["a", "c", "d"];

console.log(a[Symbol.iterator]);
for(var t of a){
    console.log(t);
}
console.log(`${name} is always being ${age}.` );