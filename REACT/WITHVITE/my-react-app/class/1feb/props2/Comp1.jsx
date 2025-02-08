import React from 'react'

export default function Comp1(props) {
  return (
    <div>
        <h1>comp1</h1>
        {/* <h2>{props.person.name}</h2> */}
        <p>Name:{props.name}</p>
        <p>Age:{props.age}</p>
        <p>student:{props.isStudent ? "Yes" : "No"}</p>
      
    </div>
  )
}
