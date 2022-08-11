const enqueue = function (arr, i) {
  arr.push(i);
  return arr;
};

const dequeue = function (arr) {
  console.log(arr[0]);
  arr.shift();
  return arr;
};

module.exports = {
  dequeue: dequeue,
  enqueue: enqueue,
};
