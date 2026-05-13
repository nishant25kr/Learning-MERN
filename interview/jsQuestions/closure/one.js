function counter(){
    let count = 0;
    function increment(){
        count++;
        message = `count is ${count}`
        console.log(count)
    }

    let message;

    function log(){
        console.log(message)

    }

    return [increment, log]
}

const [increment,log] = counter()
increment()
increment()
increment()
log()

