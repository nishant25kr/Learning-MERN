const express=require('express')
const app=express()
app.set('view engine', 'ejs')

app.use('/',(req,res)=>{
    const student=['nishant','virat','rohit']
    res.render('demo2',{uid:student})
})

app.listen(3000,()=>{
    console.log(
        "server started"
    )
})