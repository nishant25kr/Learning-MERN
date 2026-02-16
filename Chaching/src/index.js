import express from "express"
import axios from "axios"

const app = express()
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

class Store {
    constructor() {
        this.store = new Map();
    }

    checkData(key) {
        const data = this.store.get(key)
        if (!data) {
            return null;
        }
        return data;
    }

    addData(key, value) {
        this.store.set(key, value);
    }

}

const store = new Store();
let lastTime = 0
const RATE_LIMIT = 10000;

app.get("/data", async (req, res) => {

    const time = Date.now();

    if (time - lastTime < RATE_LIMIT) {
        return res.status(429).json({
            message: `Wait for ${Math.ceil(
                (RATE_LIMIT - (time - lastTime)) / 1000
            )} seconds`,
        });
    }
    
    const { search } = req.body;

    if (!search) {
        res.send({
            message: "Empty search"
        })
    }

    const cachedData = store.checkData(search);

    if (cachedData) {
        console.log('we have cached data');
        return res.status(200).json({
            message: "Data fetched from CachedMemo",
            data: cachedData
        })
    }

    const response = await axios.get(`https://dummyjson.com/products/search?q=${search}`)

    store.addData(search, response.data);

    res.status(200).json({
        message: "Data fetched from API",
        data: response.data
    })

    lastTime = time;
})

app.listen(3030);