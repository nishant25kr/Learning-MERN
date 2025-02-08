const exp = require('constants');
const express = require('express');
const path = require('path');
// const bodyParser = require('body-parser');
const app = express();
// app.use(bodyParser.urlencoded({ extended: false }));
app.use(express.json())
app.use(express.urlencoded())
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'index.html'));
});
app.post('/', (req, res) => {
    let uid = req.body.uid;
    let pass = req.body.pass;
    // let sum = Number(num1) +Number(num2);
    if(uid=="Nishant"){
        res.send("username is correct")
    }
    if(pass=="1234565789"){
        res.send("password is correct")
    }
    else{
        res.send("Enter correct username and password")
    }
});
app.listen(3000, () => console.log("Server started..."));
