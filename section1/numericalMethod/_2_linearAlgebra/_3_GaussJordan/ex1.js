let matrixA = [[-2, 3, 1],[3, 4, -5],[1, -2, 1]];
let answer = [9, 0, -4];
let length = matrixA.length;


function faceForward ( matrixA ) {
  for( let i = 0; i < length; i++ ) {
    
    for( let k = i + 1; k < length; k++ ) {
      let factor = matrixA[k][i] / matrixA[i][i];
      matrixA[k][i] = factor;

      for( let j = i + 1; j < length; j++ ) {
        matrixA[k][j] =  matrixA[k][j] - factor * matrixA[i][j];
      }
      console.log( `k = ${k}, i = ${i}, factor = ${factor}` );
      answer[k] = answer[k] - factor * answer[i];
    }

  }

  for( let i = 0; i < length; i++ ) {
    let divide = matrixA[i][i];
    for( let k = 0; k < length; k++ ) {
      if ( k < i ) {
        matrixA[i][k] = 0;
      } else {
        matrixA[i][k] /= divide;
      }
    }

    answer[i] /= divide;

  }

}

function backForward ( matrixA ) {
  for ( let i = length - 1; i >= 0; i-- ) {
    for ( let j = i - 1; j >= 0; j-- ) {
      let factor = matrixA[j][i] / matrixA[i][i];
      matrixA[j][i] = factor;
    
      // for( let k = length - 2; k >= 0; k-- ) {
      //   matrixA[j][k] = matrixA[j][k] - factor * matrixA[i][k] ;
      // }
      // console.log( `anser[j] = ${answer[j]}, anser[i] = ${answer[i]}` );
      answer[j] = answer[j] - factor * answer[i];
      // console.log( `result = ${answer[j]}` );
      console.log( `j = ${j}, i = ${i} , factor = ${factor}` );
      console.log(answer[j])
      console.log();
    }
  } 
}

faceForward( matrixA );
backForward( matrixA );

console.log( matrixA );
console.log( answer );