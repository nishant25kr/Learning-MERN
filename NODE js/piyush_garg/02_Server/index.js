import http from "http"
import fs from "fs"
import url from "url"
import express from "express"

const app = express()

app.get("/",(req,res))

const myServer = http.createServer((req, res) => {
    console.log("new req rec")
    const logs = `Date: ${Date.now()}, URL: ${req.url} \n`
    const myUrl = url.parse(req.url)
    console.log(myUrl)
    fs.appendFile('log.txt', logs, (err, data) => {
        switch (myUrl.pathname) {
            case "/":
                res.end("This is home page")
                break;

            case "/about":
                res.end("This is about page")
                break;

            default:
                res.end("404 error")
                break;
        }

    })

})

myServer.listen(3000, () => {
    console.log("Server started at : 3000")
});








