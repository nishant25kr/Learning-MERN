const input = document.getElementById("input")

const debounce = (fn, delay = 1000) => { 
    let timer;
    return (...args) => {
        clearTimeout(timer)
        timer = setTimeout(()=>{
            fn(...args)
        },delay)
    }
}

const search = async(e) => {
    const response = await fetch(`https://dummyjson.com/products/search?q=${e.target.value}`)
    const data = await response.json()
    console.log("data",data.products)
    console.log(e.target.value)
}

const debounced = debounce(search,1000)

input.addEventListener('input',debounced)