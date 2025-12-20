function throttle(fn,delay){
    let lastcall = 0;
    
    return function(...args){
        const now = Date.now()
        if(now - lastcall < delay){
            return;
        }
        lastcall = now;
        return fn(...args);
    };
}

function sendchatmessage(msg){
    console.log(`sending message ${msg}`)
}

const sendchatmessage_with_delay = throttle(sendchatmessage, 2000)

sendchatmessage_with_delay("hello")
sendchatmessage_with_delay("hello sir")
sendchatmessage_with_delay("hello sir ji")
sendchatmessage_with_delay("hello nishant")
sendchatmessage_with_delay("hello nishant kumar")
