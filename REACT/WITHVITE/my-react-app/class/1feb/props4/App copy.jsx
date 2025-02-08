import React, { Component } from "react"
import Data from './data.json'
export default function App() {
  
  return (
    <div>
      <table border='2px'>
        <tr>
          <td>Name</td>
          <td>place</td>
        </tr>
      
      
      {Data.map((item)=>(
        <tr>
          <td>{item.name}</td>
          <td>{item.id}</td>
          <td>{item.place}</td>
        </tr>
      ))}



</table>

    </div>
  )
}



