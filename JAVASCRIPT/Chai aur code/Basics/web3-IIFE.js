//immedisately invoke functions expresstion
// (function chin(){
//     console.log(`DB CONNECTED`);
// })();

// (function chin(){
//     console.log(`connected to mangoDB`);
// })();

// ((name)=>{
//     console.log(`${name}`);
// })('Nishant')

(function cahi(){
    console.log("Db connected");
})();

( (username)=>{console.log(`this is iife, ${username}`)})("Nishant")