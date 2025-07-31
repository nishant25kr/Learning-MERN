class User{
    constructor(email,password){
        this.email=email,
        this.password=password
    }

    get email(){
        return `this is your email: ${this._email}`
    }

    set email(value){
        this._email = value 
    }


    get password(){
        return `${this._password}->this is passoword`;
    }
    
    set password(value){
        this._password = value; 
    }
}

const nishant = new User("nishant@gmail.com","123456789nishant");

console.log(nishant.password)
console.log(nishant.email)
