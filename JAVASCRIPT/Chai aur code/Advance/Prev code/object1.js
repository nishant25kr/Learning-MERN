function Person(fname, lname, contact){
    this.fname = fname;
    this.lname = lname;
    this.contact = contact

    this.getName = function(){
        console.log(`Hello, this is ${this.fname} ${this.lname}`);
    }

}

const p1 = new Person("Nishant","Kumar","1212121212")

console.log(p1.getName());