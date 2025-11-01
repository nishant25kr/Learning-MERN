
// const userid = 23
// const user_id = 24
// const user = {
//     username: "Nishant",
//     price: 999,

//     welcomeUser: function () {
//         // console.log(`${this.username},welcome to website`)
//         console.log(this)
//     }
// }

// user.welcomeUser()
// user.username = "sam"
// user.welcomeUser()

const addTwo1 = (num1, num2) => {
    return num1 + num2
}
/**
 * Explanation:
 * When you use {}, it's called a function block.
 * You must use return to give back a value.
 * Without return, it returns undefined.
 */

const addTwo2 = (num1, num2) => num1 + num2
/**
 * Explanation:
 * No {} means implicit return — it automatically returns the expression after =>.
 * You don’t need the word return.
 */

const addTwo3 = (num1, num2) => (
    { sum: num1 + num2 }
)
/**
 * Explanation:
 * Same as above (implicit return).
 * The parentheses don’t change behavior — they just group the expression (optional).
 * Commonly used for returning objects
 */

console.log(addTwo3(2, 3))