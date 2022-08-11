const stack = require("./stack");
const queue = require("./queue");

var st = [],
  qu = [];
st = stack.push(st, 20);
st = stack.push(st, 40);
st = stack.push(st, 30);
st = stack.pop(st);

qu = queue.enqueue(qu, 10);
qu = queue.enqueue(qu, 20);
qu = queue.enqueue(qu, 30);
qu = queue.dequeue(qu);

console.log(st);

console.log(qu);
