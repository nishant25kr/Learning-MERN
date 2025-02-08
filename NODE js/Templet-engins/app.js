const express=require('express')
const app=express()
app.set('view engine', 'ejs')

app.get('/',(req,res)=>{
    res.render('demo')
})


app.listen(4000,()=>console.log("Server started"))