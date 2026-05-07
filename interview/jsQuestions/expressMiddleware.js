import express from 'express'
const app = express()

class Middleware{
    
    constructor(){
        this.middleware = []
    }

    use(fn){
        this.middleware.push(fn)
    }
    
    run(req,res){
        console.log("total middleware",this.middleware.length)
        console.log("functions",this.middleware)

        const next = (index) => {
            if(index >= this.middleware.length ) return;
            const fn = this.middleware[index];
            fn(req,res, ()=> next(index + 1));
        };

        next(0)
    }
}

const middleware = new Middleware()

function executeMiddleware(...args){
    args.forEach(e => middleware.use(e))
    middleware.run()
}

const m1 = (req,res,next) => {
    console.log('1st middleware')
    next()
}

const m2 = (req,res,next) => {
    console.log('2st middleware')
    next()
}

const m3 = (req,res,next) => {
    console.log('3st middleware')
    next()
}

executeMiddleware(m1,m2,m3)

app.get("/",(req,res)=>{
    res.send({message:"server is up"})
})

app.listen(3000)