import { useState } from 'react'

function App() {
  const [task, setTask] = useState();
  const [all, setAll] = useState([]);

  function addTask(t) {
    setAll((prev) => [...prev, t]);
  }

  function updateTask(task, update){
    setAll(
      prev =>{
        prev.map( t => t === task ? update : t)
      }
    )
  }

  // //delteTask
  // function deleteTask(id){
  // 	all.filter( ()=>(
  // 		if(obj.id == id){

  // 		}
  // 	)  )
  // }

  return (
    <>
      {all}
      <input
        type="text"
        value={task}
        onChange={(e) => setTask(e.target.value)}
      />

      <button onClick={() => addTask(task)} >Save</button>

      <button onClick={()=> updateTask( gym, movie)} >Update</button>


    </>
  )
}

export default App




/**
 * 
import React from "react";

export default app = () =>{

  const [task, setTask] = useState('');
  const [all, setAll] = useState([]);


function addTask( taskToAdd ){
  setAll( (prev) => [...prev, task] );
}

//updateTask
//obj{
// 	“id” : “1”,
// 	“value” : “gym”
// }

return (
  <>

  <input type="text" className="border" onChange={(e) => setTask(e.target.value)} />
  <button className="border" onClick={addTask(taskToAdd)} >Save</button>
  </>

  // <div>
    // <input  onChange((e)=> (setTask(e.target.value) )>
  //   <Button>SAVE </Button>
  // </div>
	
)

}

*/


