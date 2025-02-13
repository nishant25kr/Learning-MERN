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

