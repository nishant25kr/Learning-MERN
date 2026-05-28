//this is throw dublicate error
// type User = {name: string }
// type User = {age: number}


//this will not throw dublicate error
interface User1 {name: string}
interface User1 {lname: string}




//for extending interface uses extends
// interface Animal { name : string}
// interface Dog extends Animal {breed: string}

//types use '&'
type Animal =  {name: string}
type Dog = Animal & { breed: string}



//type can do union touple function
type id = number | string 
type Point = [number, string ]
type callback = () => void