const express=require('express')
const app=express()
app.set('view engine', 'ejs')

app.use('/',(req,res)=>{
    res.render('demo1',{uid:"nishant"})
})

app.listen(3000,()=>{
    console.log(
        "server started"
    )
})