//ES6

// class user{
//     constructor(username,email,password){
//         this.username=username
//         this.email=email
//         this.password=password
//     }
//     encryptPassword(){
//         return `${this.password.to}abc`
//     }
//     changeUsername(){
//         return `${this.username.toUpperCase()}`
//     }
// }

// const user1=new user('Nishant','email.com','nishant')

// console.log(user1);
// console.log(user1.encryptPassword());
// console.log(user1.changeUsername());


//inheritance in classes using extent keyword

class person{
    constructor(name,sname,place){
        this.name=name;
        this.sname=sname;
        this.place=place;

    }
    logMe(){
        console.log(`Name is ${this.name}`);
    }
}

class head extends person{
    constructor(name,degree){
        super(name);
        this.degree=degree
    }
    addpatner(){
        console.log(`courses added to ${this.name}`);
    }
}

const user2 = new head("Nisahnt", "B.Tech");
user2.addpatner();
