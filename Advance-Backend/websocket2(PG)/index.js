import express from "express";
import http from "http";
import path from "path";
import { Server } from "socket.io";
import { fileURLToPath } from "url";


const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

const app = express();
const server = http.createServer(app);

const io = new Server(server)

//Socket.io
io.on("connection", (socket) => {
  console.log("A new user is connected ID:", socket.id);

  socket.on("disconnect", () => {
    console.log("User disconnected:", socket.id);
  });

  socket.on("user-message",(message)=>{
    console.log("New message:",message,"from:",socket.id)
    io.emit("message",message,"from:",socket.id)
  })
});



app.use(express.static(path.join(__dirname, "public")));

app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "public", "index.html"));
});

server.listen(9000, () => {
  console.log("Server started at port 9000");
});
