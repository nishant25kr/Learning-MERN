import jwt from "jsonwebtoken"

const SECRET = "jsonwebtoken"
const user = {
    username: "nishant",
    fullname: "Nishant kumar",
    email: "nishant@gmail.com",
    uid: "212"
}

const generateToken = () => {
    const token = jwt.sign(
        {
            username: user.username,
            fullname: user.fullname,
            email: user.email,
            uid: user.uid
        },
        SECRET,
        {
            expiresIn: "1d"
        }
    )

    return token
}

const token = generateToken()

console.log("Token : ", token)

const decodedToken = jwt.verify(token,SECRET)

console.log("decoded token : ",decodedToken)