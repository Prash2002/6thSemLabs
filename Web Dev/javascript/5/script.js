function sum(arr) {
    var s = 0;
    arr.forEach(i => {
        var x = parseInt(i);
        s+=x;
    });
    return s;
}

function mul(arr) {
    var s = 1;
    arr.forEach(i => {

        var x = parseInt(i);
        s*=x;
    });
    return s;
}

function calc(s) {
    var a1 = document.getElementById("a1").value.split(" ");
    console.log(a1);
    var l ;
    if(s) l = mul(a1);
    else l = sum(a1);
    document.getElementById("op").innerHTML = l;
}