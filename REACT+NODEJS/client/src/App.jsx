import React from 'react'
import Signup from '../Component/Signup'
import './App.css'
import Login from '../Component/Login'
import { BrowserRouter, Route,Routes } from 'react-router-dom'


export default function App() {
  return (
    <>
    <BrowserRouter>
      <Routes>
        <Route path='/register' element={<Signup/>} ></Route>
        <Route path='/login' element={<Login/>} ></Route>
      </Routes>
    </BrowserRouter>
    <Link to='/login'></Link>
    </>
  )
}
