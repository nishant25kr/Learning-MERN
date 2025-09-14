// const fs = require('fs')
import fs from "fs"

//sync
// fs.writeFileSync('./file1',"Hey file created")

//async
fs.writeFile('./file1',"Hey file created with write file," ,(err)=>console.log(err))
