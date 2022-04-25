function calc() {
    var v1 = parseInt(document.getElementsByTagName("input")[0].value);
    var v2 =  parseInt(document.getElementsByTagName("input")[1].value);   
    var v3 =  parseInt(document.getElementsByTagName("input")[2].value);    
    document.getElementById("op").innerHTML = v1>v2? (v1> v3? v1 : v3) : (v2> v3? v2 : v3);
}

