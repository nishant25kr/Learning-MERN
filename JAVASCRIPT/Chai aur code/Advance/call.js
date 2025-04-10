function setusername(username){
    this.username = username
    console.log("called")
}

function createUser(username,password,email){
    setusername.call(this, username);

    this.password = password;
    this.email = email;

}

const user = new createUser("Nishant","123456789","nishant@gmail.com")
console.log(user.username)
console.log(user);