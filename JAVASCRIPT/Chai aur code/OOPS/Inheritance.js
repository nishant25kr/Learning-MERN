class Animal{
    speak(){
        console.log("Hi i am animal")
    }
}

class Dog extends Animal{
    speak(){
        console.log("Hi i am dog");
    }
}

const dog1 = new Dog()
const dog2 = new Animal()

dog1.speak();
dog2.speak();