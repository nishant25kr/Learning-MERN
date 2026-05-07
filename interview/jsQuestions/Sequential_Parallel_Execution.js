function fetchdata(url){
    return new Promise((resolve)=>{
        setTimeout(()=>{
            resolve(`fetched data from url: ${url}`)
        },1000)
    });
}

const urls = ['hello','there','world']

async function fetchSequestial(urls){
    const result = []
    for(const url of urls){
        const data = await fetchdata(url)
        result.push(data)

    }
    console.log(result)

}

async function fetchParallel(urls){
    const result = []
    
    const  promises = urls.map(u => fetchdata(u))

    const results = await Promise.all(promises);

    return results
}

// fetchSequestial(urls)
fetchParallel(urls).then(r => 
    console.log(r)
)
