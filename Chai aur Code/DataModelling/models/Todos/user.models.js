import mongoose from "mongoose"

//-->This is first way of writing the strucure--<//

// const userSchema = new mongooseSchema({
//     username: String,
//     email: String,
//     idActive:Boolean
// })

//-->This is second way of writing the strucure--<//

const username = new mongoose.Schema({
    username:{
        type:String,
        require:true,
        unique:true
    },
    email:{
        type:String,
        require:true,
        unique:true,
        lowercase:true
    },
    password:{
        type:String,
        require:true,
        }
    },{timestamps:true}
)

export const User = mongoose.model("User",userSchema);
