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