function findC (givenData, start, end) {
  if( start == 0 && end == 1 ) {
    if( Math.abs(start - end) == 1 ) {
      let deltaY = givenData[start].functionX - givenData[end].functionX;
      let deltaX = (givenData[start].x - givenData[end].x);
      return deltaY / deltaX;
    }

    return findC( start, end ) / (givenData[start].x - givenData[end].x);
  }

  if( Math.abs(start - end) == 1 ) {
    let deltaY = givenData[start].functionX - givenData[end].functionX;
    return deltaY;
  }
  let LeftNode = findC( start + 1, end ,givenData) / ( givenData[start + 1].x + givenData[end].x );
  let RightNode = findC( start, end - 1 , givenData ) / ( givenData[start].x + givenData[end - 1].x );

  return LeftNode - RightNode;
}

export default function findC();
