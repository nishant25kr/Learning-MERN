/*
-->"this is 1 way of exporting the function for different files"<--

function add(a,b){
    return a+b
}

function sub(a,b){
    return a-b;
}

module.exports = {
    add,
    sub
}
*/

// ------------------->

/*
-->"another way is "<--

exports.add = (a,b) =>  a + b
exports.sub = (a,b) =>  a - b

*/
