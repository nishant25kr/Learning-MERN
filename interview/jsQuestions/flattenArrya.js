function func(arr) {
    var result = [];
    arr.map(function (item) {
        if (Array.isArray(item)) {
            func(item);
        }
        else {
            console.log(item);
            result.push(item);
        }
    });
    return result;
}
var arr = [1, 2, [3, 4, [5, 6]], 7, 8];
var newArr = func(arr);
console.log("newArray", newArr);
