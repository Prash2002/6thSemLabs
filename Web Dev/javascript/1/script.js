function calc() {
    var v1 = parseInt(document.getElementsByTagName("input")[0].value);
    var v2 =  parseInt(document.getElementsByTagName("input")[1].value);    
    document.getElementById("op").innerHTML = v1>v2? v1 : v2;
}

