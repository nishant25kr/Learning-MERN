import React from 'react'
import Signup from '../Component/Signup'
import './App.css'
import Login from '../Component/Login'
import Home from '../Component/Home'
import { BrowserRouter, Router, Route, Routes } from 'react-router-dom'


export default function App() {
  return (
    <div>
      <BrowserRouter>
        <Routes>
          <Route path='/register' element={<Signup />} />
          <Route path='/login' element={<Login />} />
          <Route path='/home' element={<Home />} />
        </Routes>
      </BrowserRouter>
    </div>

  )
}
