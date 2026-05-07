import fs from 'fs'

const stream = fs.createReadStream('hugefile.log', {
  encoding: 'utf8' 
});

let count = 0;

stream.on("data",(chunk)=>{
    const arr = chunk.split("\n")
    
    console.log(typeof arr)
    console.log("arr",arr)
    arr.forEach(e =>{
        if(e == 'you') count++;
    })
    console.log("count",count)
}) 

stream.on('close',()=>{
    console.log("end")
})
