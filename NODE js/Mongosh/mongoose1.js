const mongoose=require('mongoose')

//creating a schema
const mySchema=mongoose.Schema({
    name:String,
    place:String,
    age:Number
})

//creating a model
const mymodel=mongoose.model('test',mySchema)
const data=mymodel({
    name:'Nishant',
    place:"KNE",
    age:22
})

console.log(data)


/*
conectiong to server as well as database
mongoose.connect("http://127.0.0.1:12717/test_db")
.....
connecting to collectioj 
mongoose.model('collection name',myschema)
.....
insert
save()
*/