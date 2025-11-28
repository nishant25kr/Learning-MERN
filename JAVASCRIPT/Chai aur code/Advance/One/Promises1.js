const promisOne = new Promise(function(resolve,reject){
    //do time consuming tasks here
    setTimeout(() => {
        console.log("Hello from inside of the timeout 1 ");
        resolve();
    }, 2000);
    
})

promisOne.then(()=>{
    console.log("Promis consummed 1");
})

new Promise(function(resolve, reject){
    setTimeout(() => {
        console.log("Inside the timeout 2 ");
        resolve()
    }, 2000);
}).then(()=>{
    console.log("Promise consumed 2 ");
})

