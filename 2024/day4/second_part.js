import { input } from "./data.js";

const inputArray = input.split("\n").map((line) => line.split(""));
const rows = inputArray.length;
const cols = inputArray[0].length;

// Check if a given pattern occurs starting at (row, col) in a certain direction
function matchesPattern(row, col, rowStep, colStep, pattern) {
  for (let i = 0; i < pattern.length; i++) {
    const r = row + i * rowStep;
    const c = col + i * colStep;
    if (r < 0 || r >= rows || c < 0 || c >= cols || inputArray[r][c] !== pattern[i]) {
      return false;
    }
  }
  return true;
}

// Check for either "MAS" or "SAM"
function matchesAnyOrder(row, col, rowStep, colStep) {
  return matchesPattern(row, col, rowStep, colStep, "MAS") ||
         matchesPattern(row, col, rowStep, colStep, "SAM");
}

let count = 0;

for (let row = 1; row < rows - 1; row++) {
  for (let col = 1; col < cols - 1; col++) {
    // The center of the X must be 'A'
    if (inputArray[row][col] === "A") {
      // Check diagonals for MAS/SAM
      const topLeft = matchesAnyOrder(row - 1, col - 1, 1, 1);     // ↘ from top-left
      const topRight = matchesAnyOrder(row - 1, col + 1, 1, -1);   // ↙ from top-right
      const bottomLeft = matchesAnyOrder(row + 1, col - 1, -1, 1); // ↗ from bottom-left
      const bottomRight = matchesAnyOrder(row + 1, col + 1, -1, -1); // ↖ from bottom-right

      // Forming an X requires two MAS diagonals intersecting at 'A'
      // Either top-left & top-right or bottom-left & bottom-right
      if ((topLeft && topRight) || (bottomLeft && bottomRight)) {
        count++;
      }
    }
  }
}

console.log(count);
