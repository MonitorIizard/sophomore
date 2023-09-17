function findC (givenData, start, end) {
  //console.log(`start = ${start}, end = ${end}`);
  if( Math.abs(start - end) == 1 ) {
    let deltaY = givenData[start].functionX - givenData[end].functionX;
    // console.log( deltaY );
    return deltaY;
  }

  let LeftNode = findC( givenData, start + 1, end) / ( givenData[start + 1].x - givenData[end].x );
  let RightNode = findC( givenData, start, end - 1 ) / ( givenData[start].x - givenData[end - 1].x );
  return RightNode - LeftNode;
}

class coordinate {
  constructor( x, functionX ) {
    this.x = x;
    this.functionX = functionX;
  }
}

let givenData = [ new coordinate(0, 9.81), new coordinate(40_000, 9.6879),  new coordinate(80000, 9.5682) ];

function approximateX ( givenData, xToFind ) {
  let answerOfC = [ givenData[0].functionX ];
  
  for( let i = 1; i < givenData.length; i++ ) {
    let currentData = givenData.slice(0, i+1);
    answerOfC[i] = findC( currentData, 0, currentData.length - 1) / (currentData[0].x - currentData[currentData.length-1].x);
    //console.log( currentData );
  }
  // console.log( answerOfC );
  let sum = answerOfC[0];
  for ( let i = 1; i < answerOfC.length; i++ ) {
    let currentSumThisTerm = 1;
    let coefficient = answerOfC[i];
      
  for ( let j = 0; j < i; j++ ) {
    currentSumThisTerm *= (xToFind - givenData[j].x);
    //console.log( `${coefficient} * (${xToFind} - ${ givenData[j].x })` );
  }   
    sum += currentSumThisTerm * coefficient;
  }

  return sum;
}

let x42235 = approximateX(givenData, 42_235);

console.log( `f(x42235) = ${x42235}` );

// let start = 0;
// let end = givenData.length - 1;


