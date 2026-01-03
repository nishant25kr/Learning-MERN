//storing by values
let a = 10;
let b = a;
a=20

// console.log(a)
// console.log(b)

//string by referece

const user1 = {
    name: "Nishant",
    address:{
        state:"Punjab",
        city:"phagwara"
    }
}

const user2 = {...user1}

user2.name = "Nishant kumar";

// console.log(user2);
// console.log(user1);

/*

console.log("3" - "1") //calculation will be done because we are using "-" sigh here
console.log(3 + "1") // ->31, because there is no addition thre will be merging of two string here
console.log("abhi" - "2") // Nan beacuse we cannot convert abhi into interger so nan

*/

console.log(true + false);
console.log("3" + "2");
console.log(null + 1);
console.log(undefined + 2);