import React, { useState } from 'react';
import './Login.css';
import '../node_modules/bootstrap/dist/css/bootstrap.css';
import { Link, useNavigate } from 'react-router-dom';
import axios from 'axios';

export default function Login() {
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const navigate = useNavigate(); // Fixed variable name

  const handleSubmit = (e) => {
    e.preventDefault();
    axios
      .post("http://localhost:3000/login", { email, password })
      .then(result => {
        console.log(result);
        if (result.data === "success") {  // Fixed comparison (should be `===`)
          navigate('/home');
        } else {
          alert("Invalid credentials!");
        }
      })
      .catch((err) => console.log(err));
  };

  return (
    <div>
      <div className='border w-25 mx-auto mt-5 p-3'>
        <form onSubmit={handleSubmit} className='m-2'>
          <h2>Login Page</h2>

          <input 
            type="email" 
            name='email' 
            className='m-1 form-control' 
            placeholder='Email' 
            value={email}
            onChange={(e) => setEmail(e.target.value)}
          /> <br />

          <input 
            type="password" 
            name='password' 
            className='m-1 form-control' 
            placeholder='Password' 
            value={password}
            onChange={(e) => setPassword(e.target.value)}
          /> <br />

          <input type="submit" value='Login' className='btn m-1 btn-primary' />
          <Link to='/register' className='m-1 btn btn-secondary'>New User</Link>

        </form>
      </div>
    </div>
  );
}
