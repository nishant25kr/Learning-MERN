import mongoose from "mongoose"

const orderItemSchema=new mongoose.Schema({
    productId:{
        type:mongoose.Schema.Types.orderId,
        ref:"Product"
    },
    quantity:{
        type:Number,
        required:true
    }
},{timestamps:true})


const orderSchema = new mongoose.Schema({
    orderprice:{
        type:Number,
        require:true,
    },
    customer:{
        type:mongoose.Schema.Types.orderId,
        ref:"User"
    },
    orderItems:{
        type:[orderItemSchema] 
    },
    status:{
        type:String,
        enum:["PENDING","CANCELLED","DELIVERED"],
        default:"PENDING",
    }

},{timestamps:true})

export const Order = mongoose.model("Order",orderSchema)