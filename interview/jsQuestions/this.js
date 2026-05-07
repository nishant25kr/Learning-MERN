const obj = {
    name:"nishant",
    greet: function() {console.log("hello",this.name )},
    arrowgreet: ()=>console.log("hello",this.name )
}

obj.greet()
obj.arrowgreet()