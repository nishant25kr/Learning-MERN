import express from "express"
import http from "http"

const app = express()
const PORT = 3000

app.get('/',(req,res)=>{
    res.send("Hello from server")
})


app.listen(PORT,()=>{
    console.log(`Server running at ${PORT}`)
})