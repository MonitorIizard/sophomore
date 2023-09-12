const MatrixA = [[5, 2, 0, 0],
                 [2, 5, 2, 0],
                 [0, 2, 5, 2],
                 [0, 0, 2, 5]];
const VectorX = [0, 0, 0, 0];
const VectorXTemp = [0, 0, 0, 0];
const VectorB = [12, 17, 14, 7];
const tolerent = 0.000006;

function calError ( x, tempX ) {
  return Math.abs( (x - tempX) / x ) * 100;
}

while( true ) {
  process.stdout.write(`round ${i}`);

  for( let i = 0; i < VectorXTemp.length; i++ ) {
    process.stdout.write(` x${i} = ${VectorX[i].toFixed(6)}`);
    VectorXTemp[i] = VectorX[i];
  }

  console.log();
  for ( let j = 0; j < MatrixA.length; j++ ) {
    let sum = VectorB[j];
    
    for ( let i = 0; i < MatrixA[j].length; i++ ) {
      if( i == j ) continue;
      
      sum -= (MatrixA[j][i] * VectorX[i]);
      
      //console.log(`MatrixA[i][j] = ${ MatrixA[j][i] } vectorX = ${ VectorX[j]} sum = ${sum}`);
    }
    
    sum /= MatrixA[j][j];
  
    VectorX[j] = sum;
  }

  if( calError( VectorX[0], VectorXTemp[0] ) < tolerent &&
      calError( VectorX[1], VectorXTemp[1] ) < tolerent && 
      calError( VectorX[2], VectorXTemp[2] ) < tolerent &&
      calError( VectorX[3], VectorXTemp[3] ) < tolerent ) {
        break;
  }

  i++;
}

console.log(`number of round = ${i}`);