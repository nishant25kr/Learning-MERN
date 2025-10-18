// =====================
// 🧠 JavaScript Array Methods Notes
// =====================

// 1️⃣ forEach() — used for looping through arrays
// It DOES NOT return anything (undefined). Just executes a function for each element.

const coding = ['js', 'py', 'cpp', 'jsx', 'tsx'];

const value = coding.forEach(item => {
    //   console.log(item); // prints each element
});

// console.log(value); // undefined (forEach never returns a new array)

// ✅ Use when you only need to perform an action (like console.log, update count, etc.)
// ❌ Don't use forEach if you need to return or store values


// 2️⃣ filter() — used to filter values from array based on condition
// It RETURNS a new array containing only elements that pass the condition.

const nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

// short version (implicit return)
const newNums = nums.filter(item => item > 4);

// long version (explicit return)
const newNums1 = nums.filter(num => {
    return num > 4;
});

// console.log(newNums);  // [5,6,7,8,9,10]
// console.log(newNums1); // [5,6,7,8,9,10]

const books = [
    { title: 'Book One', genre: 'fiction', publish: 1981, edition: 2004 },
    { title: 'Book Two', genre: 'history', publish: 1992, edition: 2008 },
    { title: 'Book Three', genre: 'science', publish: 1999, edition: 2007 },
    { title: 'Book Four', genre: 'non-fiction', publish: 2001, edition: 2012 },
    { title: 'Book Five', genre: 'history', publish: 2005, edition: 2015 },
    { title: 'Book Six', genre: 'romance', publish: 2010, edition: 2020 },
    { title: 'Book Seven', genre: 'thriller', publish: 2015, edition: 2023 }
];

const userBooks = books.filter((bk) => bk.genre == 'history')
const userBooks1= books.filter((bk) => bk.publish > 2001 )
// console.log(userBooks1)

/**
 * map also return the value
 */

//chaning
const newNums2 = nums.map((num)=>num +10).map((num)=>num+1);
