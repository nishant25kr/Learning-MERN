import WebSocket, { WebSocketServer } from "ws";
import http, { IncomingMessage, ServerResponse } from "http";

const server = http.createServer((req: IncomingMessage, res: ServerResponse) => {
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

    ws.on("message", (data) => {
        console.log("Received:", data.toString());
        wss.clients.forEach((client) => {
            if (client.readyState === WebSocket.OPEN) {
                client.send(data);
            }
        });
    });

    // ws.on("close", () => {
    //     console.log("Client disconnected");
    // });

    ws.send("Hello! Message from server");
});

server.listen(8001, () => {
    console.log(`🚀 Server is listening on http://localhost:8001`);
});
