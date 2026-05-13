function outer() {
    let x = 10;
    console.log("outer exe")
    function inner() {
        console.log("inner", x)
    }
    return inner
}

function cache(func) {
    const memo = {}
    // console.log("inside cache,", func)
    return function (...args) {
        const key = JSON.stringify(args)
        if (memo[key]){
            console.log('already there')
            return memo[key]
        }
        memo[key] = func(...args)
        return memo[key]
    };
}

// const fn = outer()
// fn()

const expensiveCalc = cache((n) => n * n);
// console.log(expensiveCalc(5))
// console.log(expensiveCalc(5))
// console.log(expensiveCalc(5))
// console.log(expensiveCalc(5))
// console.log(expensiveCalc(5))

//another example
// function inner(){
//     let count = 0;
//     return function inner(){
//         count++;
//         console.log("from inner:",count)
//     }
// }

// const callfunction = inner()

// callfunction()
// callfunction()
// callfunction()
// callfunction()
// callfunction()
// callfunction()

/**
* another example
 */

function cart(){
    let count = 0;

    return{
        increment(){
            count++;
        },
        decrement(){
            count--;
        },
        cartvalue(){
            console.log(count)
        }
    }

}

const yourcart = cart()

yourcart.increment()
yourcart.increment()
yourcart.cartvalue()
yourcart.decrement()
yourcart.cartvalue()







////    

// for (let i = 0; i < 3; i++) {
//     function hello(x){
//         console.log(x); 
//     }
    
//     setTimeout(function log() {
//         hello(i)
//     }, 1000);
// }