// const fs = require('fs');

// console.log('1. Start');

// setTimeout(() => console.log('2. setTimeout (0ms)'), 0);
// setImmediate(() => console.log('3. setImmediate'));

// fs.readFile(__filename, () => {
//     setTimeout(() => console.log('4. fs setTimeout'), 0);
//     setImmediate(() => console.log('5. fs setImmediate'));
//     process.nextTick(() => console.log('6. fs nextTick'));
// });

// process.nextTick(() => console.log('7. nextTick'));
// Promise.resolve().then(() => console.log('8. Promise'));

// console.log('9. End');

setTimeout(() => {
    console.log('Timeout 1');
}, 0);

setImmediate(() => {
    console.log('Immediate 1');
});

