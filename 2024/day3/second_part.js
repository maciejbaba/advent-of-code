import { input } from './data.js'

const regex = /(mul\(\d{0,3},\d{1,3}\))(do\(\))(\don't\(\))/g

const inputArray = input.match(regex)

let res = 0

console.log(inputArray)
