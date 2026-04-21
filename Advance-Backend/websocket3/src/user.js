
function generateId(){
    return Math.floor(Math.random())
}


export class User {
    #x;
    #y;
    #ws
    constructor(ws) {
        this.id = generateId();
        this.ws = ws;
        this.x = 0;
        this.y = 0;
        this.init()
    }

    init(){
        this.ws.send(JSON.stringify({
            type: "space-joined",
            payload:{
                x:this.x,
                y:this.y
            }
        }))
    }   

    onMove(x, y) {
        console.log('inside onMove')
        this.x = this.x + 1
        this.y = this.y + 1
        this.broadcast()
    }

    broadcast() {
        this.ws.send(JSON.stringify({
            type: "movement",
            payload:{
                x:this.x,
                y:this.y
            }
        }))
    }



}