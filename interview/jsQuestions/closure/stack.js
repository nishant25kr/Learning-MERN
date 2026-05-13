function CreateStack() {
    const items = [];
    return {
        push(item) {
            items.push(item)
            console.log(items)
        },
        pop() {
            return items.pop()
        }
    }
}

const stack = new CreateStack()

stack.push(4)
stack.push(5)
stack.push(6)
console.log(stack.items)
