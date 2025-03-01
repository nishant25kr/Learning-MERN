const mongoose = require('mongoose');
const express = require('express');
const cors = require('cors');
const app = express();
app.use(express.json());
app.use(cors());

const connectDB = async () => {
    try {
        await mongoose.connect('mongodb://127.0.0.1:27017/data', {
            useNewUrlParser: true,
            useUnifiedTopology: true,
        });
        console.log('Connected to MongoDB');
    } catch (err) {
        console.error('Error connecting to MongoDB:', err);
    }
};

connectDB();

const mySchema = new mongoose.Schema({
    username: { type: String, required: true },
    email: { type: String, required: true, unique: true },
    password: { type: String, required: true }
});

const myModel = mongoose.model('users', mySchema); 

app.listen(3000, () => console.log('Server started on port 3000'));

app.get('/', (req, res) => {
    res.send('Hello, World!');
});

app.post('/register', async (req, res) => {
    try {
        const newUser = new myModel(req.body);
        const savedUser = await newUser.save();
        res.json(savedUser);
    } catch (err) {
        res.status(500).json({ error: err.message });
    }
});

app.post('/login', async (req, res) => {
    try {
        const { email, password } = req.body; 
        const user = await myModel.findOne({ email: email }); 

        if (!user) {
            return res.status(400).json({ message: "User not found" });
        }

        if (user.password === password) { 
            return res.json("success");
        } else {
            return res.status(401).json({ message: "Incorrect password" });
        }

    } catch (err) {
        console.error("Error during login:", err);
        res.status(500).json({ message: "Server error" });
    }
});

