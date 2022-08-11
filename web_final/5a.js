// Write a java script function named pluralize that:
// ● takes 2 arguments, a noun and a number.
// ● returns the number and pluralized form, like "5 cats" or "1 dog".
// ● Make it handle a few collective nouns like "sheep" and "geese"

function pluralize(n, s) {
  if (n != 1 && s != "sheep" && s != "geese") {
    return n + " " + s + "s";
  }
  return n + " " + s;
}

console.log(pluralize(5, "cat"));
console.log(pluralize(1, "dog"));
console.log(pluralize(5, "sheep"));
