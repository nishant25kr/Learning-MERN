const obj = {
    name:"nishant",
    greet: function() {console.log("hello",this.name )},
    arrowgreet: ()=>console.log("hello",this.name )
}

// obj.greet()
// obj.arrowgreet()

//another situation


const numbers = {
    num1: 2,
    num2: 3,
    sum: function() {
        console.log("this inside numbers",this)
        
        const calculate = () =>{
            console.log('this inside calculate',this)
        }

        calculate()
    }
}
// numbers.sum()
