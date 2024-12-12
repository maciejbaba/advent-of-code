import { input } from './data.js'

const regex = /mul\(\d{0,3},\d{1,3}\)/g

const inputArray = input.match(regex)

let res = 0

inputArray.forEach(item => {
  const [a, b] = item.match(/\d+/g)
  const sum = a * b
  res += sum
})

console.log(res)
