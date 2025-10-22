function SetUsername(name){
    this.username = name
    console.log("called")
}

function createUser(name,password,email){
    SetUsername.call(this,name)

    this.password = password
    this.email = email

}

const user = new createUser("Nishant","abc@123","nishant@gmail.com")
console.log(user)