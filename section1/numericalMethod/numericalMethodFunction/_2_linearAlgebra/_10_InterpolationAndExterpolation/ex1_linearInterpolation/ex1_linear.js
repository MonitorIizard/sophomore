class coordinate {
  constructor( x, functionX ) {
    this.x = x;
    this.functionX = functionX;
  }
}

let givenData = [ new coordinate(0, 9.81), new coordinate(80000, 9.5682) ];

function approximateX ( givenData, xToFind ) {
  let answerOfC = [ givenData[0].functionX ];
  
  for( let i = 1; i < givenData.length; i++ ) {
    let currentData = givenData.slice(0, i+1);
    answerOfC[i] = findC( currentData, 0, 1 );
  }
  // console.log( answerOfC );
  let sum = answerOfC[0];
  for ( let i = 1; i < answerOfC.length; i++ ) {
    let currentSumThisTerm = 0;
    let coefficient = answerOfC[i];
      
  for ( let j = 0; j < i; j++ ) {
    currentSumThisTerm = coefficient * (xToFind - givenData[j].x);
  }   
    sum += currentSumThisTerm;
  }

  return sum;
}

let x42235 = approximateX(givenData, 42_235);

console.log( `f(x42235) = ${x42235}` );

// let start = 0;
// let end = givenData.length - 1;

function findC (givenData, start, end) {
  if( start == 0 && end == givenData.length-1 ) {
    if( Math.abs(start - end) == 1 ) {
      let deltaY = givenData[start].functionX - givenData[end].functionX;
      let deltaX = (givenData[start].x - givenData[end].x);
      return deltaY / deltaX;
    }

    return findC( start, end ) / (givenData[start].x - givenData[end].x);
  }

  if( Math.abs(start - end) == 1 ) {
    let deltaY = givenData[start].functionX - givenData[end].functionX;
    return deltaY;
  }

  let LeftNode = findC( start + 1, end ,givenData) / ( givenData[start + 1].x + givenData[end].x );
  let RightNode = findC( start, end - 1 , givenData ) / ( givenData[start].x + givenData[end - 1].x );
  return LeftNode - RightNode;
}

