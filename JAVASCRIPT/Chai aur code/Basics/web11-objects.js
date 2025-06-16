//singleton
//object.create
//object is created by constructor
console.log()




//object literals

const mysym = Symbol("key1")

const User={
    name:"Nishant",
    "full name":"nishant kumar",
    [mysym]: "myKey1",
    age:"18",
    location:"Bihar",
    gmail:"nishant@gmail.com",
    isLoggedin:false,
    lastLoggedIn:["Monday","Sunday"]
}
// console.log(User)
// console.log(User["full name"])

// console.log(User.mysym)
// console.log(User[mysym])

// User.greeting = function(){
//     console.log(`Hello ${this.name}, welcome to Google.`)
// }

// console.log(User.greeting())

const course = {
    coursename : "JavaScript",
    price : "999",
    courseInstructure : "nishant kumar"
}

const {courseInstructure : teacher , coursename : username} = course //taking data in react for node js

console.log(teacher)
console.log(username)

console.log(req.User)