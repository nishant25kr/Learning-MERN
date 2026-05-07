import express from 'express'
const app = express()

class cache {
    constructor() {
        this.users = new Map()

        setInterval(() => {
            console.log("userIPs", this.users)
        }, 3000);

    }

    checkIp(ip) {
        if (this.users.has(ip)) {
            const user = this.users.get(ip)
            return user
        } else {
            return false
        }
    }

    addIp(ip) {
        if (this.checkIp(ip)) {
            const user = this.users.get(ip);
            const newobj = {
                ...user,
                count: ++user.count
            }
            this.users.set(ip, newobj)
            return;
        }
        const obj = {
            ip: ip,
            time: Date.now(),
            count: 1
        }
        this.users.set(ip, obj)
    }
}

const rateLimit = new cache()

const rateLimiter = (req, res, next) => {
    const ip = req.ipp
    const user = rateLimit.checkIp(ip)
    console.log('inside rete limiter')
    if (user) {
        if(user.count >= 2){
            res.send({message:"crossed your limit"})
        return;
        } 
        
    }
    rateLimit.addIp(ip)
    next()
}

app.use(rateLimiter)

app.get("/", (req, res) => {
    res.send("hello there")
})

app.listen(3001);