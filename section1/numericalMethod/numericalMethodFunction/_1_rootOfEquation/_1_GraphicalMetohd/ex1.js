function f(x) {
  return x - 0.0000090 ;
}

let x = 0;
let temp = f(x);
let mode = false;
let preciseIndicator = 1;

let i = 0;

while( f(x) != 0 ) {
    if ( f(temp) / f(x) < 0 ) {
      mode = true;
    }

    if( mode ) {
      mode = false;
      x = temp;
      preciseIndicator /= 10;
      x+= preciseIndicator;
      continue;
    }

    // if(i == 16) break;

    console.log( x );

    temp = x;
    x+= preciseIndicator;
    i++;
}

console.log( i );
console.log( f(x) );
// console.log( f(x) );
// console.log( Math.abs(temp - f(x)) / f(x) );