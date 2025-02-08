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
    if(uid || pass){
        res.send("User id is"+uid+"Password is"+pass);
    }
    else{
        res.send("Invalid userid or password")
    }
});
app.listen(3000, () => console.log("Server started..."));
