const express=require('express')
const app=express()
app.use(express.json())
app.use(express.urlencoded())
app.set('view engine','ejs')

app.get('/',(req,res)=>{
    res.render('demo5')
})
app.post('/',(req,res)=>{
    const person={
        fn:req.body.fname,
        em:req.body.email
    }
    res.render('result',{person})
})

app.listen(3000,()=>{
    console.log(
        "server started"
    )
})
