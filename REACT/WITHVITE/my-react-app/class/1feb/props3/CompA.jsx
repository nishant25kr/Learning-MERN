import React from 'react'
import CompB from './CompB'

export default function CompA({data}) {
  return (
    <div>
        <h1>Component A</h1>
        <CompB data={data}/>
    </div>
  )
}
