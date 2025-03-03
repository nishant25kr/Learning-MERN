function saymyname(){
    console.log("My name is:");
    console.log("Nishant Kumar");
    
}
// saymyname();
function add(num1,num2){
    console.log(num1+num2)
    return (num1+num2)
}
// add(1,2);
// const sum=add(5,4)
// console.log(sum);

function message(username="Ram"){
    if(!username){
        console.log("Enter your name");
        return;
    }
    else
        return `hello ${username},How are you?`
}

// console.log(message("Nishant"));
// console.log(message());


//here 200 and 300 are going in val1 and val2 rest are going in num1
function calculatesum(val1,val2, ...num1){
    return num1;
}

// console.log(calculatesum(200,300,400,400,500,600))


//passing the object in functions
const user={
    name:"nishant kumar ",
    age:23
}
function handleuser(users){
    console.log(`${users.name} hello how are you?`)
}
handleuser(user);