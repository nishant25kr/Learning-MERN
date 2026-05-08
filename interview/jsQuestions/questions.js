//rever each word of string 
const str ="hello there"
let ans = "";
const x = str.split(" ")
let rev = []
x.forEach( e => {
    const length = e.length
    let newstr = "";
    for(let i = length-1 ; i >= 0 ; i--){
        newstr = newstr + e[i]
    }
    ans = ans + " "+ newstr
})
// console.log(ans)

//how to chekc that it is array or not 
const arr = [1,2,3,4,5]

// console.log(Array.isArray(arr))


//how to empty an array
//console.log(arr)
arr.length = 0
//console.log(arr)

/**
 *how to check integer or not  
 */
const int = 20;
//one way 
// console.log(Number.isInteger(int))

// another way
// int % 1 === 0? console.log(true) : console.log(false)



/**
 *duplicate the array 
 */
const newarr = [1,2,3,4,5]
function duplicate(arr){
    return arr.concat(arr)
}

// console.log(duplicate(newarr));


/**
 *reverse a number
 */

const num = 123
console.log(num.toString().split("").reverse().join(""))

/**
 * count each char in word  
 */     







/**
 * remove which dont have gender male 
 */

const obj = [
    {
        name: "Nishant",
        gender: "male"
    },
    {
        name: "a;ldskfa",
        gender: "female"
    },
    {
        name: "1234a;ldskfa",
        gender: "female"
    }
]

const newobj = obj.filter(e => e.gender == 'female')
console.log(newobj)

