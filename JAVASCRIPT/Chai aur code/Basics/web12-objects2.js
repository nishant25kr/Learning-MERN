const tinderUser = new Object()
tinderUser.id = "abc123";
tinderUser.name = "nishant";
tinderUser.isLogedIn = false

// console.log(tinderUser)

const regularUser = {
    email : "some@gmail.com",
    fullname:{
        userfullname : {
            firstname:"nishant",
            lastname:"kumar"

        }
    }

}

// console.log(regularUser.fullname? 'hi':"bye")

const obj1 = {"1":"a","2":"b"}
const obj2 = {"3":"c","4":"d"}

const obj3 = {...obj1, ...obj2}

console.log(obj3)