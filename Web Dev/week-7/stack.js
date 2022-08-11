const push = function (arr, i) {
  arr.push(i);
  return arr;
};
const pop = function (arr) {
  arr.pop();
  return arr;
};

module.exports = {
  push: push,
  pop: pop,
};
