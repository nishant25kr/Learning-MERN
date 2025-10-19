function User(name) {
    this.name = name;
}

User.prototype.printName = function() {
    console.log(this.name.trim());
}

const str1 = new User("nishant      ");
const str2 = new User("kumar      ");

str1.printName(); // "nishant"
str2.printName(); // "kumar"
