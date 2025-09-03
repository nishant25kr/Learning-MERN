import { useEffect, useState } from 'react'
import './App.css'

function App() {
  const [socket, setSocket] = useState(null)
  const [messages, setMessages] = useState([])

  useEffect(() => {
    const socket = new WebSocket("ws://localhost:8001")
    socket.onopen = () => {
      console.log("Connected")
      setSocket(socket)
    }
    socket.onmessage = (message) => {
      setMessages(m => [...m, message.data])
      console.log("Recieved message", message.data)

    }
    setSocket(socket)
  }, [])

  if (!socket) {
    return <h1>Loading...</h1>
  }


  return (
    <>
      {messages} <br />

      <button onClick={() => {
        socket.send("Hello this is from browser")
      }}>send</button>
    </>
  )
}

export default App
