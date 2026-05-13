const user1 = {
    name : "nishant",
    username(arg1,arg2){
        console.log(arg1+"username:",this.name + arg2)
    }
}

const user2 = {
    name : "nishant kumar"
}

// user1.username("hey","a;lksdjf")

const print = user1.username.bind(user2,"hello","from flipkart")
// print()

// user1.username.call(user2,"hello","from flipkart")
// user1.username.apply(user2,["hello","from flipkart"])

const obj =  {
    message: "hello world"
}

function logMessage(){
    console.log("inside log")
    console.log(this.message)
}

logMessage.call(obj)
logMessage.apply(obj)
const boundfunction = logMessage.bind(obj)
boundfunction()