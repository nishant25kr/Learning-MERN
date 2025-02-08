import React, { Component } from "react"
import Data from './data.json'
import './style.css'
export default function App() {
  
  return (
    <div>

      
      {Data.map((item)=>(
        <div className="data_div">
          <div className="data_item">{item.name}</div>
          <div  className="data_item">{item.id}</div>
          <div  className="data_item"><img src="{item.place}" /></div>
        </div>
      ))}





    </div>
  )
}



