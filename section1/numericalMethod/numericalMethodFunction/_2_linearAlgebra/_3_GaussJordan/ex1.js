// function gaussJordan(matrix) {
//   const numRows = matrix.length;
//   const numCols = matrix[0].length;

//   for (let col = 0; col < numCols - 1; col++) {
//       let pivotRow = -1;
//       for (let i = col; i < numRows; i++) {
//           if (matrix[i][col] !== 0) {
//               pivotRow = i;
//               break;
//           }
//       }

//       if (pivotRow === -1) {
//           continue; // Skip this column, no pivot found
//       }

//       // Swap the pivot row with the current row
//       [matrix[col], matrix[pivotRow]] = [matrix[pivotRow], matrix[col]];

//       // Make the pivot element 1
//       const pivot = matrix[col][col];
//       for (let j = col; j < numCols; j++) {
//           matrix[col][j] /= pivot;
//       }

//       // Eliminate other rows
//       for (let i = 0; i < numRows; i++) {
//           if (i !== col) {
//               const factor = matrix[i][col];
//               for (let j = col; j < numCols; j++) {
//                   matrix[i][j] -= factor * matrix[col][j];
//               }
//           }
//       }
//   }

//   return matrix;
// }

// // Example usage
// const inputMatrix = [
//   [2, 1, -1, 8],
//   [-3, -1, 2, -11],
//   [-2, 1, 2, -3]
// ];

// const result = gaussJordan(inputMatrix);

// console.log(result);

 console.log("matrix inside gaussJordan");
    console.log(A);
    console.log(B);
    console.log(result);
    console.log("\n");

    function faceForward(matrixA : number[][], B : number[]) : {answer : number[], matrix : number[][]} {
      let answer = [...B];
      let matrix = [...matrixA];
      let length = matrixA.length;

      for( let i = 0; i < length; i++ ) {
    
        for( let k = i + 1; k < length; k++ ) {
          let factor = matrix[k][i] / matrix[i][i];
          matrix[k][i] = factor;
    
          for( let j = i + 1; j < length; j++ ) {
            matrix[k][j] =  matrix[k][j] - factor * matrix[i][j];
          }
          console.log( `k = ${k}, i = ${i}, factor = ${factor}` );
          answer[k] = answer[k] - factor * answer[i];
        }
    
      }
    
      for( let i = 0; i < length; i++ ) {
        let divide = matrix[i][i];
        for( let k = 0; k < length; k++ ) {
          if ( k < i ) {
            matrix[i][k] = 0;
          } else {
            matrix[i][k] /= divide;
          }
        }
    
        answer[i] /= divide;
      }

      console.log( `matrix inside faceforward` );
      console.log( matrix );
      return { answer, matrix};
    }

    // function backSubstitution(matrixA : number[][], matrixB : number[]) : {answer : number[], matrix : number[][]} {
    //   let answer = [...matrixB];
    //   let matrix = [...matrixA];
    //   let length = matrixA.length;

    //   for ( let i = length - 1; i >= 0; i-- ) {
    //     for ( let j = i - 1; j >= 0; j-- ) {
    //       let factor = matrixA[j][i] / matrixA[i][i];
    //       matrixA[j][i] = factor;
    //       answer[j] = answer[j] - factor * answer[i];
    //     }
    //   } 

    //   return { answer, matrix};
    // }
    
    const { answer : result1, matrix : matrixA1 } = faceForward(A, B);

    console.log("output from faceForward")
    console.log( faceForward(A, result));
    console.log("\n")
    console.log( matrixA1 )
    result = [...result1];
    matrix = [...matrixA1];

    console.log(`result from faceForward = ${result}`);
    console.log(`matrix from faceForward = ${matrix}`);

    const { answer : result2, matrix : matrixA2 } = backSubstitution(A, B);  
    result = result2;
    matrix = matrixA2;
    
    console.log(`result from backSubtitution = ${result}`);

    console.log( result );
