// function f(x) {
//   return Math.pow(x, 8)/8 + Math.pow(2, 4)/4 - x;
// }

function f(x) {
  return Math.pow(x, 7) +  2 * Math.pow(x, 3) - 1;
}

// console.log( f(-1) - f(8) );

let n = 2;
let range = [-1, 2];
let h = (range[1] - range[0]) / (n * 2);
let sum = 0;
let start = range[0];

for ( let i = 1; i <= n ; i++ ) {
  sum += f(start) + 4 * f(start + h) + f(start + 2 * h);
  start += 2 * h;
}

let ApproximatelyIntergral = h / 3 * sum;
console.log( `appro = ${ApproximatelyIntergral}`);
console.log( `sum = ${sum}`);
let error = (ApproximatelyIntergral - 28.875) / 28.875 * 100;
console.log(`error = ${error}`);