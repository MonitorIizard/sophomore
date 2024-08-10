const { matrix, det } = require("mathjs");

class coordinate {
  constructor( arrayOfX , y ) { 
    this.y = y;
    this.x = [1];

    arrayOfX.forEach(element => {
      this.x.push( element );
    });
  }
}

let data = [];
data.push( new coordinate([1, 0, 1], 4) );
data.push( new coordinate([0, 1, 3], -5) );
data.push( new coordinate([2, 4, 1], -6) );
data.push( new coordinate([3, 2, 2], 0) );
data.push( new coordinate([4, 1, 5], -1) );
data.push( new coordinate([2, 3, 3], -7) );
data.push( new coordinate([1, 6, 4], -20) );

function initialMatrixA ( data ) {
  let matrixA = [];
  let numberOfX = data[0].x.length;

  for ( let i = 0; i < numberOfX; i++ ) {
    matrixA.push([]);
    for ( let j = 0; j < numberOfX; j++ ) {
      if ( i == 0 && j == 0 ) {
        matrixA[i].push( data.length );
        continue;
      }

      //symmetric matrix
      if ( j < i ) {
        matrixA[i][j] = matrixA[j][i];
        continue;
      }
      
      let sum = 0;
      for ( let k = 0; k < data.length; k++ ) {
        sum += data[k].x[j] * data[k].x[i];
        // iteration ++;
      }

      matrixA[i].push( sum );
    }
  }

  return matrixA;
}

function initialMatrixB ( data ) {
  let matrixB = [];
  let numberOfEquation = data[0].x.length;
  console.log(numberOfEquation);

  for( let i = 0; i < numberOfEquation; i++ ) {
    console.log(i);
    let sum = 0;
    for ( let j = 0; j < data.length; j++ ) {
      sum += data[j].y * data[j].x[i];
    }

    matrixB.push( sum );
  }

  console.log( matrixB );
  return matrixB;
}

function doCrammerRule ( matrixA, matrixB ) {
  let detA = det( matrixA );
  // console.log(`det a = ${detA}`)
  let matrixX = [];

  for ( let i = 0; i < matrixA.length; i++ ) {
    let tempMatrix = [];

    for ( let j = 0; j < matrixA.length ; j++ ) {
      tempMatrix[j] = [...matrixA[j]];
    }

    for ( let j = 0; j < matrixA.length; j++ ) {
      tempMatrix[j][i] = matrixB[j];
    }

    let answer = det( tempMatrix ) / detA;
    matrixX.push( answer );
  }

  return matrixX;
}

function findAnswer( matrixX, xTofind, m ) {
  let answer = 0;
  for ( let i = 0; i < m + 1; i++ ) {
    answer += matrixX[i] * Math.pow( xTofind, i );
  }

  return answer;
}

let matrixA = initialMatrixA( data );
let matrixB = initialMatrixB( data );
let matrixX = doCrammerRule( matrixA, matrixB );

console.log( matrixA );
