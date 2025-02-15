import React from 'react'
import './Signup.css'
import {Link} from 'react-router-dom'

export default function Signup() {
    return (
            <div class="form-container form_div">
                <h2 class="text-center mb-3">Signup</h2> 
                <form action="/signup" method="post">
                    <div class="mb-3">
                        <label for="name" class="form-label">Name</label>
                        <input type="text" class="form-control" name="name" id="name" placeholder="Enter your name" required/>
                    </div>
                    <div class="mb-3">
                        <label for="place" class="form-label">Email</label>
                        <input type="text" class="form-control" name="place" id="place" placeholder="Enter your place" required/>
                    </div>
                    <div class="mb-3">
                        <label for="age" class="form-label">Password</label>
                        <input type="number" class="form-control" name="age" id="age" placeholder="Enter your age" required/>
                    </div>
                    <button type="submit" class="btn btn-primary w-100">Submit</button>
                </form>
                <Link to="/Login" >Login</Link>
            </div>
    )
}
