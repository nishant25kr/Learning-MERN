const express=require('express')
const app=express()
const data=require('./data.js')

const cred={
    email:"lpu@gmail.com",
    uid:"lpu"
}
app.get('/api/login/:email',(req,res)=>{
    if(cred.email==req.params.email){
        res.send("Correct email");
    }
    else{
        res.send("Wrong eamil");
    }
})


app.listen(3000,()=>console.log("server started..."))