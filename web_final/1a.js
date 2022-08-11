//  Write a function translate() that will translate a text i.e, double every consonant and place an occurrence
// of "o" in between. For example, translate("this is fun") should return the string "tothohisos isos fofunon"

function translate(s) {
  var news = "";
  for (var i = 0; i < s.length; i++) {
    if (
      s[i] == "a" ||
      s[i] == "e" ||
      s[i] == "i" ||
      s[i] == "o" ||
      s[i] == "u" ||
      s[i] == " "
    ) {
      news += s[i];
    } else news += s[i] + "o" + s[i];
  }
  return news;
}

console.log(translate("this is fun"));
