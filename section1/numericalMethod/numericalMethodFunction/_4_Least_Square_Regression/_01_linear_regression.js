const { det, matrix } = require("mathjs");

class coordinate {
  constructor (x, y) {
    this.x = x;
    this.y = y;
  }
}

let data = [ new coordinate(10,5), new coordinate(15,9), new coordinate(20,15), new coordinate(30,18), new coordinate(40,22), new coordinate(50,30), new coordinate(60,35), new coordinate(70,38), new coordinate(80,43)];
let sum_of_x = 0;
let sum_of_y = 0;
let sum_of_x_square = 0;
let sum_of_x_y = 0

for ( let element = 0; element < data.length; element++ ) {
  let curr_x = data[element].x;
  let curr_y = data[element].y;

  sum_of_x += curr_x;
  sum_of_y += curr_y;
  sum_of_x_square += Math.pow(curr_x, 2);
  sum_of_x_y += curr_x * curr_y;
  // console.log(`${curr_x} ${curr_y} ${sum_of_x} ${sum_of_y} ${sum_of_x_square} ${sum_of_x_y}`);
}

let MatrixA = [[data.length, sum_of_x],
               [sum_of_x, sum_of_x_square]];

let MatrixB = [ sum_of_y, sum_of_x_y ];

function doCrammerRule(MatrixA, MatrixB) {
  let detA = det(MatrixA);
  let answer = [];

  // console.log( detA );

  for ( let i = 0; i < MatrixA.length; i++ ) {
    let MatrixTemp = [];
    
    for ( let j = 0; j < MatrixA.length; j++ ) {
      MatrixTemp[j] = [...MatrixA[j]];
    }

    for ( let j = 0; j < MatrixA.length; j++ ) {
      MatrixTemp[j][i] = MatrixB[j];
    }
    
    let curr_det = det(MatrixTemp);
    answer.push( curr_det / detA );
  }

  return answer;
}

let MatrixX = doCrammerRule( MatrixA, MatrixB );

function findAnswer( MatrixX, x ) {
  return MatrixX[0] + MatrixX[1] * x;
}

let answer = findAnswer( MatrixX, 65 );

console.log(` answer = ${answer}`);



