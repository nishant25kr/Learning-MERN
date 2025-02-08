import React, { Component } from "react"

export default function App() {
  function handler() {
    alert("hello")
  }
  const students = ['Nisahnt', 'Rohit', 'virat', 'Dhoni']
  const numbers = [1, 2, 3, 4]
  return (
    <div>
      <h1>WElcome to Class Components</h1>
      <button onClick={handler}>chick me</button>
      <button onMouseOut={handler}>chick me</button>
      <button onMouseOver={handler}>chick me</button>


        <ul>
          {students.map((item,index) => {
            return (
              <li key={index}>{item}</li>
            )
          })}

        </ul>

    </div>

  )
}



