// const user={        
//     username:"Nishant",
//     logincount:8,
//     Logedin:true,
//     getUserDetail: function(){
//         console.log(`username: ${this.username}`);
//     }
// }

// console.log(user.username);
// user.getUserDetail()

//what is new keyword

function User(username,logincount,islogin){
    this.username=username,
    this.logincount=logincount,
    this.islogin=islogin

    this.greeting=function(){
        console.log(`Welcome ${this.username}`);
    }

    return this
}

const user1 = new User("Nishant",4,true);
const user2 = new User("Nishant kumar",5,false);

console.log(user1);
console.log(user2);

function createChai(type,price){
    this.type = type,
    this.price = price
}

createChai.prototype.printme = function(){
    console.log(`Chai type is ${this.type}`);
    console.log(`Chai price is ${this.price}`);
}

createChai.prototype.increment = function(){
    console.log(this.price);
    this.price++;
    console.log(this.price);
}

const chai1 = new createChai("greentea",20);
const chai2 = new createChai("blacktea",10);

chai1.printme();
chai1.increment();


//prototype advance

let myname="Nishant";
console.log(myname.length);

let myname1="Nishant       ";
console.log(myname1.trueLength);

