function isVowel(c) {
    if(c==='a' || c==='e' || c==='i'|| c==='o'||c==='u') return true;
    return false;
}

function calc(){

    var c = document.getElementById("char").value;
    if(isVowel(c)){
        document.getElementById("op").innerHTML = " its a vowel!!!";
    }
    else document.getElementById("op").innerHTML = " its not a vowel!!!";
}