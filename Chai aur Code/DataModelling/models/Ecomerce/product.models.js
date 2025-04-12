import mongoose from "mongoose"

const prodectSchema = new mongoose.Schema({
    description:{
        type:String,
        required:true,
    },
    name:{
        type:String,
        required:true,
    },
    productImages:{
        type:String
    },
    price:{
        type:Number,
        default:0,

    },
    stock:{
        type:Number,
        default:0
    },
    category:{
        type:mongoose.Schema.Types.ObjectId,
        ref:"category",
        required:true
    },
    owner:{
        type:mongoose.Schema.Types.ObjectId,
        ref:"User",
        required:true,
    }

},{timestamps:true})

export const Produce =  mongoose.model("Product",prodectSchema)