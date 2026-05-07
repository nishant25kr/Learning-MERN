import express from 'express'
import os from "os"
import cluster from 'cluster'
const app = express()

if(cluster.isPrimary){
    const numCPUs = os.cpus().length;
    console.log("Master process",process.pid)
    for(let i = 0; i < numCPUs; i++){
        cluster.fork()
    }
    cluster.on('exit', (worker, code, signal) => {
    console.log(`Worker ${worker.process.pid} died. Forking a new worker...`);
    cluster.fork();
  });
}else{
    let count = 0 ;
    app.get("/",(req,res)=>{
        console.log(count++,req.ip)
        res.send({message: "hello there"})
    })

    app.listen(3000,()=> {
        console.log("server is running at 3000")
    })

}
