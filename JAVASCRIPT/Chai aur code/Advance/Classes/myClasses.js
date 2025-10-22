// class User {
//     constructor(username,email,password) {
//         this.username = username
//         this.email = email
//         this.password = password
//     }
//     encryptpassword(){
//         return `${this.password}12345`
//     };
//     callme(){
//         return `${this.username.toUpperCase()}`
//     };
// }

function User(name,email,password){
    this.username = name
    this.email = email
    this.password = password
}

const Nishant = new User("Nishant","nishant@gmail.com","nishant123")

console.log(Nishant)
// console.log(Nishant.encryptpassword())
// console.log(Nishant.callme())
// console.log(Nishant.SeeUsername)