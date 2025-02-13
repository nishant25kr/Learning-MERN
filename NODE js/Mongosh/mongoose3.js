const mongoose=require('mongoose')

const connectDB=async()=>{
    try {
        await mongoose.connect('mongodb://127.0.0.1:27017/lpu')
        console.log('connected..')
    } catch (err) {
        console.log('error')
    }
}
connectDB()

const mySchema=mongoose.Schema({
    name:String,
    place:String,
    age:Number
})


const mymodel=mongoose.model('about',mySchema)
const data=mymodel({
    name:'Virat ',
    place:"Delhi",
    age:34
})

data.save()
.then((res)=>console.log("Data inserted"))
.catch((err)=>console.log(err))