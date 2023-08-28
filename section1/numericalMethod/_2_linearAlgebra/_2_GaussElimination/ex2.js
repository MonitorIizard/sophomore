// const { matrix } = require("mathjs");

let a = [[-2, 3, 1],[3, 4, -5],[1, -2, 1]];

let matrixB = [9, 0, -4];

let answer = [0, 0, 0];

let n = a.length;

for( let i = 0; i < n; i++) {

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