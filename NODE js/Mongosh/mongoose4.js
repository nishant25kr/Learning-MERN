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

// mymodel.deleteOne({name:"Virat Kohli" })

// mymodel.updateOne({name:"Nishant Kumar"},{$set:{age:40}}) 
mymodel.find({name:'Nishant Kumar'})
.then((res)=>console.log(res))
.catch((err)=>console.log(err))