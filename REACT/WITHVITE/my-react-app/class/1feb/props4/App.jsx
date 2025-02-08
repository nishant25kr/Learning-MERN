import React, { Component } from "react"

export default function App() {
  const data = [
    { id: 2, name: 'nishat', email: 'nishant@gmail.com' },
    { id: 3, name: 'Rohit', email: 'rohit@gmail.com' },
    { id: 4, name: 'virat', email: 'virat@gmail.com' },
    { id: 5, name: 'viratkohli', email: 'viratkohli@gmail.com' }
  ]
  return (
    <div>
      <table border='2px'>
        <tr>
          <td>ID</td>
          <td>Name</td>
          <td>Email</td>
        </tr>
        {
          data.map((user) => (
            <tr>
              <td>{user.id}</td>
              <td>{user.name}</td>
              <td>{user.email}</td>
            </tr>

          ))
        }
      </table>
    </div>
  )
}



