
const matrixA = [[-2, 3, 1],
                 [3, 4, -5],
                 [1, -2, 1]];

const matrixL = [[1, 0, 0],
                 [0.1, 1, 0],
                 [0.3, 0, 1]];

const matrixU = [[0, 0, 0],
                 [0, 0, 0],
                 [0, 0, 0]];

const matrixB = [9, 0, -4];

function subDecompose( a, l, u, n ) {
  let k;

  for( k = 0; k < n; k++ ) {
    for ( i = k + 1; i < n; i++ ) {
      let factor = a[i][k] / a[k][k];
      a[i][k] = factor;
      l[i][k] = factor;
      
      // console.log( a[i][k] );
      // console.log( a[k][k] );
      // console.log("factor is" + factor + '\n');

      for ( j = 1; j < n; j++ ) {
        a[i][j] = a[i][j] - factor * a[k][j];
      }
    }
  }

  for( let i = 0 ; i < n; i++ ) {
    for( let j = i ; j < n; j++ ) {
      u[i][j] = a[i][j];
    }
  }
}

let matrixD = [ 0, 0, 0 ];
let matrixX = [ 0, 0, 0]; 

function subStitute( l, u, n, b , d, x ) {
  let i;
  for( i = 0; i < n; i++) {
    let sum = 0;
    for( j = 0; j < n; j++ ) {
      sum += l[i][j] * d[j];
    }
    // console.log( sum );
   d[i] = b[i] - sum;
  }

  // console.log(d);

  for( i = n - 1; i >= 0; i--) {
    let sum = 0;
    for( j = n - 1; j >= 0; j-- ) {
      sum += u[i][j] * x[j];
      // console.log( "log" );
      // console.log( ` sum is ${sum}` );
      // console.log( `u[i][j] = ${u[i][j]}  x[j] = ${x[j]}` );
      // console.log( "end\n" );
    }
    x[i] = (d[i] - sum) / u[i][i];
    // console.log( d[i] );
  }
}

function printMatrix (matrix) {
  for( let i = 0 ; i < matrix.length; i++ ) {
    console.log( matrix[i] );
  }
}

subDecompose( matrixA, matrixL, matrixU, 3 );

console.log("matrix A :");
printMatrix( matrixA );
// // console.log();

console.log("matrix L :");
printMatrix( matrixL );
// // console.log();

console.log("matrix U :");
printMatrix( matrixU );

subStitute( matrixL, matrixU, 3, matrixB, matrixD, matrixX );

// console.log(matrixD);

console.log("answer is :");
printMatrix(matrixX);