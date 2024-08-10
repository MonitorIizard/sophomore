class coordinate {
  constructor (x,y) {
    this.x = x;
    this.y = y;
  }
}

function findSlope( x1, x2 ) {
  return (x1.y - x2.y) / (x1.x - x2.x);
}

function f(xTofind, yStart, xStart, slope) {
  return yStart + slope * ( xTofind - xStart );
}

let givenData = [ new coordinate(2, 9.5), new coordinate(4, 8), new coordinate(6, 10.5), new coordinate(8, 39.5), new coordinate(10, 72.5)];
let xTofind = 4.5; 
let previoueCoordinate = givenData[0];
let answer = null; 

for ( let i = 1; i < givenData.length; i++ ) {
  let currentCoordinate = givenData[i];

  if ( xTofind < currentCoordinate.x ) {
    let slope = findSlope( previoueCoordinate, currentCoordinate);
    answer = f( xTofind, previoueCoordinate.y, previoueCoordinate.x, slope );
    // console.log( slope );
    break;

  }
  previoueCoordinate = currentCoordinate;
}

console.log( answer );