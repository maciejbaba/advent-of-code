import { input } from './data.js'

const inputArray = input.split('\n')

const xmas = "XMAS"

const rows = inputArray.length
const cols = inputArray[0].length

const matches = (row, col, rowStep, colStep) => {
  for (let i = 0; i < xmas.length; i++) {
    const rowIndex = row + i * rowStep
    const colIndex = col + i * colStep
    if (rowIndex < 0 || colIndex < 0) {
      return false
    }
    if (rowIndex >= rows || colIndex >= cols) {
      return false
    }
    if (inputArray[rowIndex][colIndex] !== xmas[i]) {
      return false
    }
  }
  return true
}

let count = 0
for (let row = 0; row < rows; row++) {
  for (let col = 0; col < cols; col++) {
    if (matches(row, col, 0, 1)) { // row right
      count++
    }
    if (matches(row, col, 1, 0)) { // col down
      count++
    }
    if (matches(row, col, 1, 1)) { // row down, col right
      count++
    }
    if (matches(row, col, 1, -1)) { // row down, col left
      count++
    }
    if (matches(row, col, -1, 1)) { // row up, col right
      count++
    }
    if (matches(row, col, -1, -1)) { // row up, col left
      count++
    }
    if (matches(row, col, -1, 0)) { // row up
      count++
    }
    if (matches(row, col, 0, -1)) { // col left
      count++
    }
  }
}
console.log(count)