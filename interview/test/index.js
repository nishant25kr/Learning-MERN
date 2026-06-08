import express from 'express'
import fs from 'fs'
const app = express()
app.use(express.json())

let users = fs.readFileSync("users.txt","utf-8") || []

setInterval(()=>{
    console.log("users",users)
},2000)

app.post("/",(req,res)=>{
    console.log("api hit");
    const {username, password} = req.body;
    users.push({username,password});
    fs.writeFileSync("users.txt",JSON.stringify(users))
    return res.send({message:"data added"})
})

app.listen(3000,()=>{
    console.log("hello there")
})