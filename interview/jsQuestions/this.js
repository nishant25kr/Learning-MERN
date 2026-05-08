const obj = {
    name:"nishant",
    greet: function() {console.log("hello",this.name )},
    arrowgreet: ()=>console.log("hello",this.name )
}

// obj.greet()
// obj.arrowgreet()

//another situation

const object = {
    "message" :  "Hello world",
    getMessage(){
        const message = "Hello Earth"
        console.log(this.message)
    }
}

object.getMessage()