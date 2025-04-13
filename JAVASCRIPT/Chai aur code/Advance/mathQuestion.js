console.log(Math.PI)

const pi=Object.getOwnPropertyDescriptor(Math,"PI")

console.log(pi);

const user = {
    name:'Nishant kumar',
    height:23,
    gender:'male'

}

console.log(Object.getOwnPropertyDescriptor(user,"name"));

Object.defineProperty(user,'name',{
    writable: false,
    enumerable: false,
    configurable: true
})

console.log(Object.getOwnPropertyDescriptor(user,"name"));
