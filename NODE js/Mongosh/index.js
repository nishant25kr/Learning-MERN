const mongoose = require('mongoose')
const express = require('express')
const app = express()
app.set('view engine', 'ejs')
app.use(express.json())
app.use(express.urlencoded())

const connectDB = async () => {
    try {
        await mongoose.connect('mongodb://127.0.0.1:27017/lpu')
        console.log('connected..')

    } catch (err) {
        console.log('error')
    }
}
connectDB()
const mySchema = new mongoose.Schema({
    name: String,
    place: String,
    age: Number
})
const myModel = new mongoose.model('about', mySchema)


app.get('/', (req, res) => {
    res.render('form1db')
})

app.post('/signup', (req, res) => {
    const data = myModel(req.body);
    data.save()
        .then((res) => console.log("data saved"))
        .catch((err) => console.log(err))
    res.redirect('show')
})

app.get('/show', async (req, res) => {
    const result = await myModel.find({}); 
    res.render('show', { result }); 
});

app.get('/delete/:id', async(req,res)=>{
    await myModel.findByIdAndDelete(req.params.id);
    res.redirect('/show'); 
})

app.get('/edit/:id', async(req,res)=>{
    const data=await myModel.findById(req.params.id);
    res.render('edit',{data}); 
})

app.post('/update/:id', async(req,res)=>{
    await myModel.findByIdAndUpdate(req.params.id, req.body);
    res.redirect('/show'); 
})

app.listen(3000, () => {
    console.log("Server started..")
})