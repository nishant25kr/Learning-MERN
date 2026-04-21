

// console.log(0.1 + 0.2 === 0.3) //false
// console.log(typeof (0.1 + 0.2)) //number

// const obj = {
//     a: 1,
//     b: 2
// }
// const obj1 = obj.toString()
// console.log(typeof(obj1)) //string


// const user1 = {
//     name: "nishant1",
//     age: "21"
// }

// const arr = [1,2,3,4,5];
// const res = arr.map((item)=> item = item > 2 )
// console.log(res);

// console.log( [] == [] ) //false -> in js array are also object and obj are compared with the memory not data in it
// console.log( [] === [] ) // same as above

// const arr1 = [1,2];
// const arr2 = arr1 || [1,2];
// console.log(arr1 === arr2)


// const string1 = null;
// const string2 = null

// console.log(string1 == string2)
// console.log(string2)


// console.log(typeof(string1) === null)

//console.log(
//    String.fromCharCode(97)
//)

// const newobj1 = {
// 	from:"a2",
// 	to:"a3"
// 	}

// console.log(typeof(JSON.stringify(obj)))

// const array = JSON.stringify(["hello","there"])
// console.log(typeof array , array)

// const array1 = JSON.parse(array)
// console.log(typeof array1, array1)


// const url  = "hello there";

// url.searchParams.append("name", "Nishant Kumar");

// const newUrl = url.toString().replace(/\+/g, "%20");
// const encoded = encodeURIComponent(url).replace(/\%20/g, "+")
// const decoded = decodeURIComponent(url)
// console.log(decoded);
// console.log(encoded)

// const User = new Map()

// User.set(1, {"name":"hello1"})
// User.set(2, {"name":"hello2"})
// User.set(3, {"name":"hello3"})

// console.log(User)

// User.filter((u))
	

// console.log("number",count)
// var count = 10;




console.log(one(4))
function one(x){
    return x+1;
}

console.log(two(4))

const two = function two(y){
    return y+2;
}



