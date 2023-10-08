const { det } = require("mathjs");

class coordinate {
  constructor (x, y) {
    this.x = x;
    this.y = y;
  }
}

function findSigma (data) {
  let sigmaX = []; 

  for ( let i = 0; i < 2 * m; i++ ) {
    let sum = 0;
    
    for ( let j = 0; j < data.length; j++ ) {
      sum += Math.pow( data[j].x, i + 1);
    }

    sigmaX.push( sum );
  }

  return sigmaX;
}

function initialMatrixA( data, m, sigmaX ) {
  let matrixA = [];

  for ( i = 0; i < m + 1; i++ ) {
    
    if ( i == 0 ) {
      matrixA[i] = [ data.length, ...sigmaX.slice(0, 2) ];
      continue;
    }

    matrixA[i] = [ ...sigmaX.slice(i - 1, 2 + i) ]
  }

  return matrixA;
}

function initialMatrixB( data, m ) {
  let matrixB = [];

  for( let i = 0; i < m + 1; i++ ) {
    let sum = 0;

    if ( i == 0 ) {
      let sigmaY = 0;
      data.forEach(element => {
        sigmaY += element.y;
      });
      
      matrixB.push( sigmaY );
      continue;
    }
    
    for ( let j = 0; j < data.length; j++ ) {
      sum += data[j].y * Math.pow(data[j].x, i);  
    }

    matrixB.push( sum );
  }

  return matrixB;
}

function doCrammerRule( matrixA, matrixB ) {
  let detA = det( matrixA );
  console.log(`det a = ${detA}`)
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

let data = [ new coordinate(10,5), new coordinate(15,9), new coordinate(20,15), new coordinate(30,18), new coordinate(40,22), new coordinate(50,30), new coordinate(60,35), new coordinate(70,38), new coordinate(80,43)];
let m = 2;
let sigmaX = findSigma( data );
let matrixA = initialMatrixA( data, m, sigmaX );
let matrixB = initialMatrixB( data, m );
let matrixX = doCrammerRule( matrixA, matrixB );
let answer = findAnswer( matrixX, m, xTofind );

// console.log( sigmaX );
// console.log( matrixA );
// console.log( matrixB );
// console.log( matrixX );




