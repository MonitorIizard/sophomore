var math = require("mathjs");

class coordinate {
  constructor (x,y) {
    this.x = x;
    this.y = y;
  }
}

function f(x, a, b, c) {
  return a * (Math.pow(x, 2)) + b * x + c;
}

let data = [ new coordinate(2, 9.5), new coordinate(4, 8), new coordinate(6, 10.5), new coordinate(8, 39.5), new coordinate(10, 72.5)];

function initializeMatrixB( data ) {
  let matrixB = [];
  
  for ( let i = 1; i < data.length - 1; i++ ) {
    matrixB.push(data[i].y);
    matrixB.push(data[i].y);
  }
  
  matrixB.push(data[0].y);
  matrixB.push(data[data.length - 1].y);
  
  // n - 1 condition
  for ( let i = 1; i < data.length - 1; i++ ) {
    matrixB.push(0);
  }
  return matrixB;
}

function initializeMatrixA( data ) {
  let MatrixA = [];
  let n = data.length - 1;
  let lastIndexOfD = data.length - 1;
  for ( let i = 0; i < 3*n - 1; i++ ) {
    MatrixA.push([]);
    
    for ( let j = 0; j < 3*n - 1; j++ ) {
      MatrixA[i].push(0);
    }
  }

  let lastIndexOfM = MatrixA.length - 1;
  
  let coorBetweenStart_End = data.slice( 1, data.length - 1 );
  let k = 0;
  let x = 1;
  let currentLevel = 0;

  // between condition 
  for ( currentLevel = 0; currentLevel < 2*(n - 1); currentLevel++ ) {
    if ( x == 2 ) {
      k++;
      x = 0;
    }

    let j = (Math.ceil((currentLevel) / 2) * 3 ) - 1;
    let k =  Math.floor(currentLevel/2);
    
    if ( currentLevel == 0 ) {
      MatrixA[currentLevel][0] = coorBetweenStart_End[ k ].x;
      MatrixA[currentLevel][1] = 1;
      continue;
    }

    // console.log( j );
    MatrixA[currentLevel][j] = Math.pow(coorBetweenStart_End[k].x, 2);
    MatrixA[currentLevel][j+1] = coorBetweenStart_End[k].x, 2;
    MatrixA[currentLevel][j+2] = 1;
  }

  //last round of loop is still add 1 so we need to decrease the level.
  currentLevel--;

  // 2 close and end condition
  MatrixA[++currentLevel][0] = data[0].x;
  MatrixA[currentLevel][1] = 1;

  MatrixA[++currentLevel][lastIndexOfM - 2] = Math.pow(data[lastIndexOfD].x, 2);
  MatrixA[currentLevel][lastIndexOfM - 1] = data[lastIndexOfD].x;
  MatrixA[currentLevel++][lastIndexOfM] = 1;

  // console.log( currentLevel, lastIndexOfM - 2 );

  console.log( coorBetweenStart_End );
  //slope 
  let offSet = -1;
  for ( let f = 0; f < MatrixA.length - currentLevel; f++ ) {
    if ( f == 0 ) {
      MatrixA[currentLevel + f][0] = 1;
      MatrixA[currentLevel + f][2] = -2 * coorBetweenStart_End[f].x;
      MatrixA[currentLevel + f][3] = -1;
    } else {
      offSet += 3;
      MatrixA[currentLevel + f][offSet] = 2 * coorBetweenStart_End[f].x;
      MatrixA[currentLevel + f][offSet + 1] = 1;
      MatrixA[currentLevel + f][offSet + 3] = -2 * coorBetweenStart_End[f].x;
      MatrixA[currentLevel + f][offSet + 4] = -1;
    }
    // console.log(f);
  }

  return MatrixA;
}

//  atrixB( data );
let matrixA = initializeMatrixA( data );
let matrixB = initializeMatrixB( data );

let detA = math.det( matrixA );

function doCrammerRule( matrixA, matrixB ) {
  let matrixX = [];
  for ( let i = 0; i < matrixA.length; i++ ) {

    matrixTemp = [];
  
    for(let n = 0; n < matrixA.length; n++) {
      matrixTemp[n] = [...matrixA[n]];
    }
  
    for ( let j = 0; j < matrixA[i].length; j++) {
      matrixTemp[j][i] = matrixB[j];
    }
  
    matrixX.push( math.det(matrixTemp) / detA );
  } 
  return matrixX;
}

let matrixX = doCrammerRule( matrixA, matrixB );

console.log( matrixX );

