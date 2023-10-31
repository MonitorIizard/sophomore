class coordinate {
  constructor( x, y ) {
    this.x = x;
    this.y = y;
  }
}

let givenData1 = [ new coordinate(0, 9.81), new coordinate(80000, 9.5682) ];
let givenData2 = [ new coordinate(0, 9.81), new coordinate(40_000, 9.6879),  new coordinate(80000, 9.5682) ];
let givenData3 = [ new coordinate(0, 9.81), new coordinate(20_000, 9.7487), new coordinate(40_000, 9.6879), new coordinate(60_000, 9.6879),  new coordinate(80000, 9.5682) ];

let xToFind = 42_235;


function Lagange ( givenData, xToFind ) {
  let Llist = [];
  let fx = 0;
  for ( let i = 0; i < givenData.length; i++ ) {
    let l = 1;
    for ( let j = 0; j < givenData.length; j++ ) {
  
      if ( j == i ) continue;
  
      l *= (xToFind - givenData[j].x) / ( givenData[i].x - givenData[j].x );
    }
    fx += l * givenData[i].y;
  
    Llist[i] = l;
  }
  return fx;
}

console.log(`1.1 Aproximation of f(${xToFind}) in lagange method is ${Lagange(givenData1, xToFind)}`);
console.log(`1.2 Aproximation of f(${xToFind}) in lagange method is ${Lagange(givenData2, xToFind)}`);
console.log(`1.3 Aproximation of f(${xToFind}) in lagange method is ${Lagange(givenData3, xToFind)}`);