function func(arr: (number | number[])[]): number[] {
    let result: number[] = []
    arr.map((item) => {
        if (Array.isArray(item)) {
            func(item)
        } else {
            console.log(item)
            result.push(item)
        }
    });
    return result;
}

const arr = [1, 2, [3, 4, [5, 6]], 7, 8];

const newArr = func(arr);

console.log("newArray", newArr)
