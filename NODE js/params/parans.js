const express=require('express')
const app=express()
const data=require('./data.js')

app.get('/api:id',(req,res)=>{
    res.send("id is "+req.params.id)
})
app.get('/product',(req,res)=>{
    res.send(data)
})
app.get('/product/:id',(req,res)=>{
    let result=data.find(x=>x.id==req.params.id)
    res.send(result);
})
app.listen(3000,()=>console.log("server started..."))