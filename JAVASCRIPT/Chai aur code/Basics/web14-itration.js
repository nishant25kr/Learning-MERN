// for (let i = 0; i < 10; i++) {
//     const element = i;
//     console.log(element)

// }

// const greeting = "Nishant kumar"
// for(const val of greeting){
//     console.log(`char is ${val}`);
// }

//Maps

const map = new Map()

map.set('IN',"INDIA")
map.set('US',"USA")
map.set('CH',"china")

for (const [key,val] of map){
    console.log("Key is", key, "value is",val);
}

