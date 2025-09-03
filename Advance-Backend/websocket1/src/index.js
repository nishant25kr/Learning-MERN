import WebSocket, { WebSocketServer } from "ws";
import http, { IncomingMessage, ServerResponse } from "http";
const server = http.createServer((req, res) => {
    console.log(`${Date.now()} - Received request for ${req.url}`);
    res.end("Hi there");
});
const wss = new WebSocketServer({ server });
wss.on("connection", (ws, req) => {
    console.log("New client connected:", req.socket.remoteAddress);
    ws.on("error", (err) => {
        console.error("WebSocket error:", err);
        ws.close();
    });
    let usercount = 0;
    ws.on("message", (data, isBianry) => {
        console.log("Received:", data.toString());
        wss.clients.forEach((client) => {
            if (client.readyState === WebSocket.OPEN) {
                client.send(data, {binary: isBianry});
            }
        });
    });
    // ws.on("close", () => {
    //     console.log("Client disconnected");
    // });
    console.log("User count:", ++usercount)
    ws.send("Hello! Message from server");
});
server.listen(8001, () => {
    console.log(`🚀 Server is listening on http://localhost:8000`);
});
//# sourceMappingURL=index.js.map