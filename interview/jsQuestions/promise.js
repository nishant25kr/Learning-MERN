function calculate(num1,num2){
    return new Promise((resolve,reject)=>{
        if(!num1 || !num2){
            reject("validation failed")
        }
        resolve(`calculation done ${num1+num2}`)
    })
}

calculate(1,2).then(r => console.log(r)).catch(r => console.log(r))
calculate().then(r => console.log(r)).catch(r => console.log(r))