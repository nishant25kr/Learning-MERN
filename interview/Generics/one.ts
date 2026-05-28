function getData<T>(arr: T[]) {
    console.log(typeof arr[0])
}

getData<string>(["hello","there","nishant"])