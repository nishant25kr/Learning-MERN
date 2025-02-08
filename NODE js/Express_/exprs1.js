const express=require('express')
const app=express()

const validator=(req,res,next)=>{
    if(!req.query.age){
        res.send("Age is required")
    }else if(req.query.age<18){
        res.send("Age is below 18")
    }else{
        next()
    }
}
app.use(validator)

app.get('/',(req,res)=>{
    req.send("Home page")
})
app.get('/about',(req,res)=>{
    req.send("Aboutnpm  page")
})

app.listen(3000,()=>console.log("server started"))