const { exp } = require("mathjs");

function f(x) {
  return (x) * (exp(-x/4) * (2-x) - 1);
}

let xl = 0;
let xr = 2; 

function findX1( xl, xr ) {
  return (xl * f(xr) - xr * f(xl)) / (f(xr) - f(xl));
}

if ( f(xl) * f(xr) > 0 ) {
  console.log(" root is not in the given range ");
}

let x1old = xl;
let es = 0.01;
let i = 0;

while ( i < 20 ) {
  x1 = findX1( xl, xr );

  console.log(`x1 = ${x1}`);

  if ( f(x1) * f(xl) <= 0 ) {
    xl = x1;
  } else {
    xr = x1;
  }

  let fx1 = f(x1);
  let fx1old = f(x1old);
  let tol = Math.abs( fx1 - fx1old / fx1 ) * 100;
  
  if ( tol < es ) {
    console.log( "answer is " + x1 );
  }
  x1old = x1;
  i++;
}

// console.log( x1 );