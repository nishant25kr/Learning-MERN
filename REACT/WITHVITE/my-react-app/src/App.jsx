import React, { Component } from "react"
import { useState } from "react"
import image1 from './images/image1.jpg'
import image2 from './images/image2.jpg'
export default function App() {
  const picture = [image1]
  const [state, setState] = useState(picture)
  const handler = () => {
    setState([...state, image2])
  };
  return (
    <div>
      {state.map((img, index) => (
        <img src={img} width="200px" alt={`Image ${index}`} />
      ))}
      <button onClick={handler}>Click me</button>
    </div>
  )
}



