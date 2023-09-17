
class coordinate {
  constructor( x, functionX ) {
    this.x = x;
    this.functionX = functionX;
  }
}

let givenData = [ new coordinate(0, 9.81), new coordinate(20000,9.7487), new coordinate(40000, 9.6879), new coordinate(60_000, 9.6879), new coordinate(80_000, 9.5682)]

let data = [givenData[0], givenData[4]];

let c = findC( 0, data.length - 1, data ) / (data[0].x  - data[1].x);

function findC ( start, end, givenData ) {
  if( Math.abs(start - end) == 1 ) {
    let deltaY = givenData[start].functionX - givenData[end].functionX;
    return deltaY;
  }

  let LeftNode = findC( start + 1, end) / ( givenData[start + 1].x + givenData[end].x );
  let RightNode = findC( start, end - 1 ) / ( givenData[start].x + givenData[end - 1].x );
  return LeftNode - RightNode;
}


console.log( c );
