import React from 'react'
import CompC from './CompC'

export default function CompB(data) {
  return (
    <div>
        <CompC/>
        <CompC data={data}/>
      
    </div>
  )
}
