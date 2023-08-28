function f(x) {
  return x - 5;
}

let xl = 0;
let xr = 7; 
let x1 = findX1(xl, xr);
let temp = 0;

function findX1( xl, xr ) {
  return (xl * f(xr) - xr * f(xl)) / (f(xr) - f(xl));
}

while ( Math.abs( f(x1) - f(temp) / f(x1) ) ) {
  x1 = findX1(xl, xr);

  temp = x1;  
  console.log( x1 );
}

console.log( x1 );