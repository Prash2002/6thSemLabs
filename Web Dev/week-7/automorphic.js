const automr = function (n) {
  var sq = n * n;
  while (n) {
    console.log((sq % 10) + " " + (n % 10));
    if (sq % 10 !== n % 10) return false;
    sq = Math.floor(sq / 10);
    n = Math.floor(n / 10);
  }
  return true;
};

exports.automr = automr;
