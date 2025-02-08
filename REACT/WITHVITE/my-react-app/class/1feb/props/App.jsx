import React from "react"
import Comp5 from "./components/Comp5"
import Comp6 from "./components/Comp6"

export default function App(){
  let uid="Nishant"
  let place="Delhi"
  let student=['Nishant','Rohit','Virat']
  return(
    <>
    <h1>App component</h1>
    <Comp5 data={uid} place={place}/>
    <Comp6 student={student}/>
    </>

  )
}



