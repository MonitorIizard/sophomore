const { matrix, abs } = require("mathjs");

function pivot( matrixA, matrixB, ip) {
  let A = [...matrixA];
  let B = [...matrixB];
  let max = abs( A[ip][ip] );
  let numofColumnThatBiggest = ip;
  let n = A.length;

  for(let i = ip+1 ; i < n ; i++) {
    if( max < abs( A[i][ip] ) ) {
      max = abs( A[i][ip]);
      numofColumnThatBiggest = i;
    }
  }

  if ( numofColumnThatBiggest > ip ) {
    let temp = [...A[ip]];
    A[ip] = [...A[numofColumnThatBiggest]];
    A[numofColumnThatBiggest] = [...temp];
  }

  return [A, B];
}

let a = [[1, 2, 3],[2, 3, 1],[3, 2, 1]];

let matrixB = [6, 6, 6];

let answer = [0, 0, 0];

let n = a.length;

for( let i = 0; i < n; i++) {

  [a, matrixB] = pivot(a, matrixB, i);

  for( let k = i + 1; k < n; k++ ) {
    let factor = a[k][i] / a[i][i];
    a[k][i] = factor;

    for( let j = 1; j < n; j++ ) {
      a[k][j] = a[k][j] - factor * a[i][j];
    }
    matrixB[k] = matrixB[k] - factor * matrixB[i];
  }
}

for ( let k = 0; k < n; k++ ) {
  for ( let j = 0; j < n; j++ ) {
    if( j < k ) {
      a[k][j] = 0;
    }
  }

  let divide = a[k][k];
  for ( let x = k; x < n; x++ ) {
    a[k][x] /= divide;
  }
  matrixB[k] /= divide;
}

for ( let k = n-1; k >= 0; k-- ) {
  let sum = 0;
  for ( let x = n-1; x >= 0; x-- ) {
    sum += a[k][x] * answer[x];
    console.log( `a[${k}][${x}] = ${ a[k][x] } answer[${x}] = ${answer[x]}` );
  }
  console.log( `sum at k = ${k} = ${sum}` );
  // sum /= a[k][k];
  answer[k] = (matrixB[k] - sum) / a[k][k];
  console.log( answer[k] );
}

// console.log(matrixB);
console.log(answer);
// console.log(a);

// function print(M, msg) {
//   console.log("======" + msg + "=========")
//   for(var k=0; k<M.length; ++k) {
//     console.log(M[k]);
//   }
//   console.log("==========================")
// }

// function diagonalize(M) {
//   var m = M.length;
//   var n = M[0].length;
//   for(var k=0; k<Math.min(m,n); ++k) {
//     // Find the k-th pivo
//     i_max = findPivot(M, k);
//     if (A[i_max, k] == 0)
//       throw "matrix is singular";
//     swap_rows(M, k, i_max);
//     // Do for all rows below pivot
//     for(var i=k+1; i<m; ++i) {
//       // Do for all remaining elements in current row:
//       var c = A[i][k] / A[k][k];
//       for(var j=k+1; j<n; ++j) {
//         A[i][j] = A[i][j] - A[k][j] * c;
//       }
//       // Fill lower triangular matrix with zeros
//       A[i][k] = 0;
//     }
//   }
// }

// function findPivot(M, k) {
//   var i_max = k;
//   for(var i=k+1; i<M.length; ++i) {
//     if (Math.abs(M[i][k]) > Math.abs(M[i_max][k])) {
//       i_max = i;
//     }
//   }
//   return i_max;
// }

// function swap_rows(M, i_max, k) {
//   if (i_max != k) {
//     var temp = A[i_max];
//     A[i_max] = A[k];
//     A[k] = temp;
//   }
// }

// function makeM(A, b) {
//   for(var i=0; i<A.length; ++i) {
//     A[i].push(b[i]);
//   }
// }

// function substitute(M) {
//   var m = M.length;
//   for(var i=m-1; i>=0; --i) {
//     var x = M[i][m] / M[i][i];
//     for(var j=i-1; j>=0; --j) {
//       M[j][m] -= x * M[j][i];
//       M[j][i] = 0;
//     }
//     M[i][m] = x;
//     M[i][i] = 1;
//   }
// }

// function extractX(M) {
//   var x = [];
//   var m = A.length;
//   var n = A[0].length;
//   for(var i=0; i<m; ++i){
//     x.push(A[i][n-1]);
//   }
//   return x;
// }

// function solve(A, b) {
//   //print(A, "A");
//   makeM(A,b);
//   //print(A, "M");
//   diagonalize(A);
//   //print(A, "diag");
//   substitute(A);
//   //print(A, "subst");
//   var x = extractX(A);
//   //print(x, "x");
//   return x;
// }

// var x = solve(A, b);