function f(x) {
  // return eval(this.fx);
  return (x - 2.5);
}

function findXm( xl, xr ) {
  return (xl + xr) / 2;
}

let answer = [];
    // let xl = xStart;
    // let xr = this.xEnd;
let xl = 0;
let xr = 5;
let xm;
let temp = xl;
let iteration = 0;
let tolerance = 0.00001;

while( true && iteration < 1000 ) {

  xm = findXm( xl, xr );
  
  if ( f(xm) * f(xl) > 0  && f(xm) * f(xr) > 0 ) {
    console.log( " case 1 ");
    answer.push("root of equation out of index");
    break;
  }
  
  if ( f(xm) == 0 || Math.abs( (f(xm) - f(temp)) / f(xm) ) < tolerance) {
    
    answer.push( xm.toString() );
    break;
  }
  
  console.log( `iteration = ${iteration}`);
  console.log(` xl = ${xl}, xr = ${xr}, xm = ${xm} `);
  console.log( ` f(xl) = ${f(xl)}, f(xr) = ${f(xr)}, f(xm) = ${f(xm)} \n` );

  if( f(xl) * f(xm) <= 0 )  {
    xr = xm;
  } 
  
  if ( f(xr) * f(xm) <= 0 ){
    xl = xm;
  }

  // console.log( `f${}` );

temp = xm;
// console.log( );
iteration += 1;
}
// console.log( f(xm) );

console.log( answer );