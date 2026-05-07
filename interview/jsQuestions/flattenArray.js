// function func(arr){   
//     arr.map((item) => {
//         if(Array.isArray(item)){
//             func(item)
//         }else{
//             newArr.push(item)
            
//         }
//     })
// }
// const arr= [1,2,[3,4,[5,6]],7,8]
// let newArr = [];
// func(arr);
// console.log("newArray",newArr)

function debounce(name = "hello", time = 3000){
    let timer ;
    return () => {
    clearTimeout(timer)
        timer = setTimeout(() => {
            console.log("now task is completed")
            console.log("args",name)
        }, time);

    }
}

const functioncall = debounce()

setInterval(() => {
    
    functioncall()
}, 1000);