function f(x) {
  return (4*Math.pow(x, 5) - 3*Math.pow(x,4) + Math.pow(x,3) - 6*x + 2);
}

let n = 2;
let range = [2, 8];
let h = (range[1] - range[0]) / n;
let sum = f(range[0]) + f(range[1]);

for ( let i = 1; i < n; i++ ) {
  console.log( range[0] + i * h );
  sum += 2 * f(range[0] + i * h);
}

let ApproximatelyIntergral = h / 2 * sum;
console.log(`h = ${h}`);
console.log(`sum = ${sum}`);
console.log( `ApproximatelyIntergral = ${ApproximatelyIntergral}` );
console.log( `error = ${(ApproximatelyIntergral - 155930.4) / 155930.4}`)