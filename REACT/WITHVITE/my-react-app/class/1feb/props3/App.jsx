import React from "react"
import CompA from "../class/1feb/props3/CompA"

export default function App(){
  let uid="This is in compA"  
  return(
    <>
      <CompA/>
      <CompA data={uid}/>

    </>

  )
}



