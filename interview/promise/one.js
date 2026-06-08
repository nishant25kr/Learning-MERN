const p1 = new Promise((resolve, reject) => {
    if (true) {
        resolve('success')
        // console.log('success')
    } else {
        reject('reject')
    }
})

const p2 = new Promise((resolve, reject) => {
    if (true) {
        resolve('success')
        // console.log('success')
    } else {
        reject('reject')
    }
})

const p3 = new Promise((resolve, reject) => {
    // if (false) {
        // resolve('success')
    //     console.log('success')
    // } else {
        reject('reject')
    // }
})

// Promise.all([p1, p2, p3])
//     .then(res => console.log(res))
//     .catch(res => console.log(res))

Promise.allSettled([p1, p2, p3])
    .then(res => console.log(res))
    .catch(res => console.log(res))