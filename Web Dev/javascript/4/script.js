function calc(){
    var txt = document.getElementById("txt").value;
    document.getElementById("op").innerHTML = newSt(txt);
}

function newSt(txt) {
    var newtxt = "";
    for (let i = 0; i < txt.length; i++) {
        const c = txt[i];
        // console.log(c);
        if(c==='a' || c==='e' || c==='i' || c==='o' || c==='u' || c===' ' ) newtxt += c;
        else newtxt += c + 'o' + c;
    }
    // console.log(newtxt);
    return newtxt;
}