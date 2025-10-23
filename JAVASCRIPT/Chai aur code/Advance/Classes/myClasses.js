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

// console.log(Nishant)
// console.log(Nishant.encryptpassword())
// console.log(Nishant.callme())
// console.log(Nishant.SeeUsername)


// console.log(0 == "0");    //0      
// console.log(false == "false"); //0 
// console.log(false == "0");      //0
// console.log(null == undefined); //0
// console.log([] == "");          //1
// console.log([] == 0);           //1
// console.log([0] == 0);          //1
// console.log([1] == true);       //1
// console.log([1,2] == "1,2");    //1
// console.log([1,2] == "1,2,3");  //0  "1,2"!="1,2,3"

// console.log("1"==="a")


function outer(){
    console.log("hello outer")
    function inner(){
        console.log("inner")
    }
    inner()
}

outer()