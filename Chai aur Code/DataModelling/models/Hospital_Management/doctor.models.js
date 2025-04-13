import  mongoose from "mongoose"

const doctorSchema = mongoose.Schema({
    name:{
        type:String,
        required:true       
    },
    salary:{
        type:Number,
        required:true
    },
    qualification:{
        type:String,
        required:true,

    },
    experience:{
        type:Number,
        default:0
    },
    worksInHospitals:{
        type:[{
            type:mongoose.Schema.Types.ObjectId,
            ref:"Hospitals"
        }],
      

    }
},{timespans:true})

export const Doctor = mongoose.model("Doctor",doctorSchema)