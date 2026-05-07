function curry(func){
    return function curried(...args){
        if(args.length() > func.length()){
            return func(...args)
        }
        return 

    }
}