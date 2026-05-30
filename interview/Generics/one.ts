// "Generics are type variables — instead of hardcoding a specific type or using any,
//  we use T as a placeholder that gets replaced with the actual type when used. This makes
//  functions and interfaces flexible AND type safe — works with any type without losing type
//  checking!¯"

function getData<T>(arr: T[]) {
    console.log(typeof arr[0])
}

getData<string>(["hello","there","nishant"])


