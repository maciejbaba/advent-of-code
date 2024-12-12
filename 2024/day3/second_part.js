import { input } from './data.js'

const regex = /(mul\(\d{0,3},\d{1,3}\))|(do\(\))|(don't\(\))/g

const inputArray = input.match(regex)

let res = 0
let skip = false

inputArray.forEach(item => {
  console.log(item)
  if (item.includes('do()')) {
    skip = false
  } else if (item.includes("don't()")) {
    skip = true
  }

  if (!skip && item.includes('mul')) {
    const [a, b] = item.match(/\d+/g)
    const sum = a * b
    res += sum
  }
})

console.log(res)