let D = [0, 0, 0, 0];
let R = [0, 0, 0, 0];
let X = [0, 0, 0, 0];
let MatrixA = [[5, 2, 0, 0],
               [2, 5, 2, 0],
               [0, 2, 5, 2],
               [0, 0, 2, 5]];
let B = [12, 17, 14, 7];
let tolerent = 0.0001;

for ( let i = 0; i < MatrixA.length; i++ ) {
  let sum = 0;
  for ( let j = 0; j < MatrixA[i].length; j++ ) {
    sum += MatrixA[i][j] * X[j];
  }
  R[i] = sum - B[i];
  D[i] = R[i] * -1;
}

let lambda;
let i = 1;
while( true ) {
  lambda = 0;
  for ( let k = 0; k < D.length; k++ ) {
    lambda += D[k] * R[k];
  } 

  let tempSum = 0;
  for ( let k = 0; k < MatrixA.length; k++ ) {
    let sum = 0;

    for ( let j = 0; j < MatrixA[k].length; j++ ) {
      sum += MatrixA[j][k] * D[j];
    }
    sum *= D[k];
    tempSum += sum;

  }
  lambda /= ( -1 * tempSum);

  for ( let k = 0; k < X.length; k++ ) {
    X[k] = X[k] + lambda * D[k];
  }

  for ( let k = 0; k < MatrixA.length; k++ ) {
    let sum = 0;
    for ( let j = 0; j < MatrixA[k].length; j++ ) {
      sum += MatrixA[j][k] * X[j];
    }

    R[k] = sum - B[k];
  }

  let error = 0;
  let sum = 0;
  for ( let k = 0; k < R.length; k++ ) {
    sum += R[k] * R[k];
  }
  error = Math.sqrt(sum);

  //find alpha
  let tempSumTop = 0;
  let tempSumBot = 0;
  for ( let k = 0; k < MatrixA.length; k++ ) {
    let sum1 = 0;
    let sum2 = 0;
    for ( let j = 0; j < MatrixA[k].length; j++ ) {
      sum1 += MatrixA[j][k] * R[j];
      sum2 += MatrixA[j][k] * D[j];
    }
    sum2 *= D[k]; 
    tempSumBot += sum2;
    sum1 *= D[k];
    tempSumTop += sum1;
  }
  let alpha = tempSumTop / tempSumBot;

  for ( let k = 0; k < D.length; k++ ) {
    D[k] = (-1 * R[k]) + alpha * D[k];
  }


  if ( error < tolerent ) break;

  i++;
}

console.log(` i = ${i}`);
console.log(X);
