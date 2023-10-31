function f(x) {
  return  5 - Math.pow(x, 2) ;
}

let xNew;
let xOld = 0;
let x = 0;
let es = 0.0001;
// console.log( f(xStart) );

let i = 0;

while( i < 10 ) {
  xNew = f(xOld);
  let tol = Math.abs((xNew - xOld) / xNew) * 100;
  xOld = xNew
  
  if( tol < es ) break;
  console.log( xNew, xOld );
  i++;
}

console.log( xNew, xOld );