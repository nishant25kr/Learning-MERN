import mongoose from "mongoose"

const TodoSchema = new mongoose.Schema({
    content:{
        type:String,
        required:true,
    },
    complete:{
        type:Boolean,
        required:true
    },
    CreatedBy:{
        type:mongoose.Schema.Types.ObjectId,
        ref:"User"
    },
    subTodos:[
        {
            type:mongoose.Schema.Types.ObjectId,
            ref:"subTodo"
        }
    ]
},{timestamps:true})

export const Todo= mongoose.model("Todo",TodoSchema)