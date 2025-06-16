const arr = [1,2,3,4,5]
// const arr = [1,2,3,4,5,true,"nishant"]

// console.log(arr)

// arr.unshift(100)
// console.log(arr)
// arr.shift()
// console.log(arr)

// console.log(arr.length)
// const newArr = arr.join()
// console.log(newArr)
  
// console.log(newArr.length)

// slice and spice 
// console.log(arr.slice(1,3))
// console.log(arr)
// console.log(arr.splice(1,3))
// console.log(arr)


// const NewArr = {
//     name:"nishant kumar"
// }
// arr.push(NewArr)

// console.log(arr[5].name)

const newArr = [6,7,8,9,10]

const sumarr = arr.concat(newArr)

console.log(sumarr)

const allarr = [...arr,...newArr]
console.log(allarr)
