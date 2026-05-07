class EventEmitter{
    constructor(){
    }

    on(){
        console.log("inside on")
    }

    off(){
        console.log("inside off")
    }

    emit(){
        console.log("inside emit")
    }
}