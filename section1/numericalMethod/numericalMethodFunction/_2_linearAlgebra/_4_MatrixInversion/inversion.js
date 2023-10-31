function matrixInverse(matrix) {
  const n = matrix.length;
  if (n !== matrix[0].length) {
      throw new Error("Matrix must be square.");
  }

  // Create an augmented matrix [A | I], where A is the original matrix and I is the identity matrix.
  const augmentedMatrix = [];
  for (let i = 0; i < n; i++) {
      augmentedMatrix.push([...matrix[i], ...Array(n).fill(0)]);
  }

  // Perform Gauss-Jordan elimination to transform the left side (A) into the identity matrix
  for (let col = 0; col < n; col++) {
      // Find the pivot row for this column
      let maxRow = col;
      for (let i = col + 1; i < n; i++) {
          if (Math.abs(augmentedMatrix[i][col]) > Math.abs(augmentedMatrix[maxRow][col])) {
              maxRow = i;
          }
      }
      // Swap the current row and the pivot row
      [augmentedMatrix[col], augmentedMatrix[maxRow]] = [augmentedMatrix[maxRow], augmentedMatrix[col]];

      // Make the diagonal element 1
      const pivot = augmentedMatrix[col][col];
      for (let j = col; j < 2 * n; j++) {
          augmentedMatrix[col][j] /= pivot;
      }

      // Make the other rows 0 in this column
      for (let i = 0; i < n; i++) {
          if (i !== col) {
              const factor = augmentedMatrix[i][col];
              for (let j = col; j < 2 * n; j++) {
                  augmentedMatrix[i][j] -= factor * augmentedMatrix[col][j];
              }
          }
      }
  }

  // Extract the right side of the augmented matrix, which is the inverted matrix
  const invertedMatrix = augmentedMatrix.map(row => row.slice(n));

  return invertedMatrix;
}

// Example usage
const inputMatrix = [
  [2, 1],
  [1, 3]
];

const inverseMatrix = matrixInverse(inputMatrix);

console.log("Inverse Matrix:");
console.log(inverseMatrix);
