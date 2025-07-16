function print(){
    console.log("Hello this is function");
}

// print()

function addtwonum(num1,num2){ //here num1 and num2 are parameters
    // console.log(num1+num2);
    return(num1+num2);
}

// const result1 = addtwonum(1,2);
// const result = addtwonum("a","a");  //here a is arguments

// console.log(typeof result1)
// console.log(typeof result)

function loginMessage(username){
    if(!username){
        console.log("username is not there");
        return;
    }
    console.log(typeof username)
    return`${username} welcome to the world of coding`
}

// console.log(loginMessage("nishant"));
console.log(loginMessage());