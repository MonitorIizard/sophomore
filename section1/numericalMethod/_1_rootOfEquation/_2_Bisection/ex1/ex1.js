function f(x) {
  return  x - 5;
}

function findXm( xl, xr ) {
  return (xl + xr) / 2;
}

let xl = 0;
let xr = 7;
let xm = 0;
let temp = f(xl);

while( true ) {
  
  xm = findXm( xl, xr );

  if ( f(xm) == 0 || Math.abs( (f(xm) - f(temp)) / f(xm) ) < 0.00000000000000000006) {
    break;
  }

  if( f(xm) / f(xl) < 0 )  {
    console.log("case1");
    xr = xm;
  } 
  
  if ( f(xm) / f(xr) < 0 ){
    console.log("case2");
    xl = xm;
  }

  // console.log( `f${}` );

  temp = xm;

  console.log( );
  
}

console.log( f(xm) );