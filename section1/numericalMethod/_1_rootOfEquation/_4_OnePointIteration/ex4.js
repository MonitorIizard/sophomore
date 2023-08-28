function f(x) {
  return  ( 5 + x )/ 2 ;
}

let xStart = 0;
let temp = 0;
let x = 0;
// console.log( f(xStart) );

let i = 0;

while( true ) {

  temp = xStart;
  xStart = f(xStart);

  // console.log( f(xStart) );
  // console.log( temp );

  // if( Math.abs( (f(x) - f(temp)) / f(temp) ) < 0.00006 ) break;


  if( f(xStart) - temp == 0 ) break;
  // if( i == 10 ) break;
  i++;

  // console.log( f(x) );
  // console.log( xStart );
}

console.log( xStart );