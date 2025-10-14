//FIND AND FINDLAST
const users = [
    { id: 3, name: "Anirban", age: 22 },
    { id: 2, name: "Priyanshu", age: 21 },
    { id: 1, name: "Nishant", age: 20 },
    { id: 4, name: "Shoaib", age: 23 },
    { id: 5, name: "Rahul", age: 24 }
];

const find = users.find((item) => item.age > 20) //start left to right and return 1st one
const findlast = users.findLast((item) => item.age > 20) //start right to left and return last one
// console.log(find)
// console.log(findlast)




//GENERATOR FUNCTIONS
/*
A generator function in JavaScript is a special kind of function that can be paused and 
resumed, allowing you to produce (or “yield”) multiple values over time, instead of 
returning them all at once.
*/
function* simpleGenerate() {
    console.log("function called")
    yield "hello1";
    yield console.log("hello2");
    yield console.log("hello3");

}
let SG = simpleGenerate()

// SG.next()
// SG.next()
// SG.next()


//  PROTOTYPE
/**
 * PROTOTYPE is a mechanism by which JavaScript object inherit features of another object
 * 
 */

let User = {
    getFullname() {
        return this.name + " " + this.lastname
    },
    getAge() {
        let age = new Date().getFullYear() - this.Birth
        return age
    }
}

let student = {

    name: "Nishant",
    lastname: "Kumar",
    Birth: 2012,

}

let teacher = {

    name: "Hello",
    lastname: "World",
    Birth: 2000,

}

teacher.__proto__ = User
student.__proto__ = User

// console.log(student.getFullname())
// console.log(teacher.getFullname())
// console.log(student.getAge())
// console.log(teacher.getAge())


//DEEPCOPY AND SHALLOW COPY
/**
 * When you copy an object or array in JavaScript, you’re not always creating a completely independent copy.
 * Depending on how you copy it, you might end up with a shallow copy (partially independent) or a deep copy (completely independent).
 */

const obj = {
    name: "Nishant"
}
let user = obj;  //here user have copy obj by reference
user.name = "Kumar"  //it will change the original value because it is changing in the memory of obj

const obj1 = {
    name: "Nishant Kumar"
}

//shalow copy example
const user1 = Object.assign({}, obj1) //it will not give you access of more then 1st level
const user2 = { ...obj }
user1.name = "kumar nishant"


// console.log(obj1)
// console.log(user1)

/**
 * OBJECTS
 * An object is a nonpremitive data type which stres data in the form of key and values.
 * keys can be a string or a symbol where as values can be any data type line number,function or even object.
 * we can create obj in three ways {}
 * 
 */



/**
 * Events and bubbling
 * When an event occurs on an element (like a button), that event bubbles up (propagates)
 * from the target element to its parent elements — all the way up to the document object — 
 * unless it’s explicitly stopped.
 * (child → parent → document).
 * Can be stopped using e.stopPropagation().
 */


/**
 * Private Property
 * → If you want to make any property private inside a class, use the "#" prefix.
 * → Private fields are only accessible within the same class body.
 * → Attempting to access them outside the class will cause a SyntaxError.
 */

class BankAccount {
    name = "Nishant Kumar";
    #pin = "232323"; // private property

    getName() {
        return this.name;
    }

    getSpecialAccess() {
        return {
            pin: this.#pin,  // must use # to access private field
            name: this.name,
        };
    }
}

const details = new BankAccount();
// console.log(details.getSpecialAccess());


