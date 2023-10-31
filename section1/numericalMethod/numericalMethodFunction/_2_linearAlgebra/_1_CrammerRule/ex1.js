var math = require("mathjs");

const matrixA = [[4, -4, 0], [-1, 4, -2],[0, -2, 4]];
let matrixB = [ ];
const answerVector = [400, 400, 400];

let detA = math.det( matrixA );

console.log( detA );

for ( let i = 0; i < matrixA.length; i++ ) {

  matrixB = [];

  for(let n = 0; n < matrixA.length; n++) {
    matrixB[n] = [...matrixA[n]];
  }

  for ( let j = 0; j < matrixA[i].length; j++) {
    matrixB[j][i] = answerVector[j];
  }

  console.log( math.det(matrixB) / detA );
} 

console.log( matrixB );