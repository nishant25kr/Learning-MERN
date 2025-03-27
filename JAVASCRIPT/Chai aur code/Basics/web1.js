const user={
    name:"Nishant",
    age:"23",
    place:"Bihar",
    "full name":"Nishant kumar",
    logindetails:{
        userid:"nishant25",
        password:12345678
    }
}

const obj1={1:"a",2:"b"}
const obj2={3:"a",4:"b"}
// const obj3=Object.assign({},obj1,obj2)
const obj3={...obj1, ...obj2}
// console.log(obj3)

// console.log(user[sym]);

const tinderuser=new Object()
tinderuser.id="123abc"
tinderuser.name="Nishantkumar"
tinderuser.islogedin="false"
// console.log(user);
console.log(Object.keys(tinderuser));
console.log(Object.values(tinderuser));
console.log(Object.values(tinderuser)[0]);

//in react we replace it with props
/* 
const navbar=({company})=>{

}
const{company}="Google"
*/