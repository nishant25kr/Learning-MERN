import {WebSocketServer} from "ws"
import { User } from "./user.js"

const wss = new WebSocketServer({port: 3030})

wss.on("connection",(ws)=>{
    console.log("Client connected")

    ws.on("error",(data)=>{
        console.log("error",data)
    })

    let user = new User(ws)
    let data;
    ws.on("message",(msg)=>{
        console.log("message received",JSON.parse(msg))
        data = JSON.parse(msg.toString())
        switch (data.type) {
            case "move":
                console.log("user moved")
                user.onMove(data.payload.x, data.payload.y)
                break;
        
            default:
                break;
        }
    })

    ws.send('message from ws server')
})