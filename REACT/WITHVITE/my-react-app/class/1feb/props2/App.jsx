import React from "react"
import Comp5 from "./components/Comp5"
import Comp6 from "./components/Comp6"
import Comp1 from "./components/Comp1"

export default function App(){
  let uid="Nishant"
  let place="Delhi"
  let student=['Nishant','Rohit','Virat']
  const person={
    name:'Nishant',
    age:21,
    place:'jalandhar'
  }
  return(
    <>
    <h1>App component</h1>
    <Comp5 data={uid} place={place}/>
    <Comp6 student={student}/>
    <Comp1 person={person}/>
    <Comp1 name="Nishant" age="21" isStudent={false}/>
    <Comp1 name="Peter" age="23" isStudent={true}/>
    <Comp1 name="Ravi" age="24" isStudent={false}/>
    </>

  )
}



