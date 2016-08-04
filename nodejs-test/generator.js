function* get3(){
    var a = 1;
    yield a;
    while(true){
        yield a=a+2;
    }
}

var g3 = get3();

console.log(g3.next().value);
console.log(g3.next().value);
console.log(g3.next().value);
console.log(g3.next().value);
console.log(g3.next().value);
console.log(g3.next().value);
