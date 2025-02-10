const express=require('express')
const app=express()
app.set('view engine', 'ejs')

app.use('/',(req,res)=>{
    const person={
        id:1212,
        email:"nishant@gmail.com",
        name:'Nishant',
        place:"Delhi",
        age:10,
        
    }
    res.render('demo4',{person})
})

app.listen(3000,()=>{
    console.log(
        "server started"
    )
})
