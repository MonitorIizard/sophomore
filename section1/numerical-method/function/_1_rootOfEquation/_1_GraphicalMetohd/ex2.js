function f(x) {
  return x + 5;
}

let p = 1;
let x = 0;
let temp = x;
let temp1 = x;

if( f(x) > 0 ) {
  p *= -1;
}

// x  += p;

while( f(x) != 0 && Math.abs(f(x) - f(temp) / f(x)) > 0.00006 ) {

  // console.log( `temp ${temp} temp1 ${temp1} x${x}`);

  if( f(temp) / f(x) < 0) {
    x = temp;
    temp = temp1;
    p /= 10;

  } else {
    temp = x;
  }
  
  temp1 = temp;

  console.log(x);
  x += p;
}

console.log( f(x) );
