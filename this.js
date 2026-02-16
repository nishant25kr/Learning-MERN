const name = 'hello from here'

const obj = {
    name: 'nishant',
    place: "India",
    age: "25",
    print: ()=> {
        console.log(this.name);
    }
}

obj.print(); 