
// const promisOne = new Promise(function(resolve,reject){
//     setTimeout(
//         function(){
//             // console.log("hi this is promis1")
//             resolve()
//         }
//     ,1000)
// })

// promisOne.then(function(){
//     // console.log("Promise resolved");
// })

// new Promise(function(resolve,reject){
//     setTimeout(() => {
//         // console.log("Async task is completed")
//         resolve()
//     }, 1000);
// }).then(()=>{
//     // console.log("Async 2 resolved");
// })


// new Promise(function (resolve, reject) {
//   setTimeout(() => {
//     resolve({ username: "Nishant", email: "nishant@gmail.com" });
//   }, 500);
// }).then((user) => {
// //   console.log(user);
// });


new Promise(function (resolve, reject) {
  let error = false;
  if (!error) {
    resolve({ username: "nishant", email: "n@gmail.com" });
  } else {
    reject("Error:something went wrong");
  }
})
  .then((user) => {
    console.log(user);
    return user.username;
  })
  .then((name) => {
    console.log(name);
  })
  .catch(() => {
    console.log("ERror was there");
  })
  .finally(() => {
    console.log("The promise is either resolved or rejected");
  })



// const promiseOne = new Promise((resolve, reject) => {
//   setTimeout(() => {
//     let error = false;
//     if (!error) {
//       resolve({ username: "Javascript", password: "123" });
//     } else {
//       console.log("Js went wrong");
//     }
//   }, 1000);
// });

// async function consumePromise() {
//   try {
//     const response = await promiseOne;
//     console.log(response);
//   } catch (error) {
//     console.log(error);
//   }
// }

// consumePromise();

