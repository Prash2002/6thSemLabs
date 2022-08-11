// Write a javascript to implement a Calculator using prototype, which has add, subtract and getAnswer
// functions which supports chaining, that means we should be able to do new
// Calculator(2).add(2).add(2).subtract(3).getAnswer() to get 3 as the answer

function Calculator(n) {
  var ans = n;
  add = function (x) {
    ans += x;
    return this;
  };
  subtract = function (x) {
    ans -= x;
    return this;
  };
  getAnswer = function () {
    return ans;
  };
  return this;
}

var t = Calculator(2).add(2).add(2).subtract(3).getAnswer();

console.log(t);
