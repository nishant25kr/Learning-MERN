import { createRoot } from 'react-dom/client'
import Component1 from './components/Component1'
import Component2 from './components/Component2'
import Component3 from './components/Component3'
const css1={
  margin:'auto',
  height:'150px',
  backgroundColor:'green',
  width:'600px'
}
const css2={
  height:'150px',
  margin:'auto',
  backgroundColor:'lightgreen',
  width:'200px'
}
const css3={
  height:'150px',
  margin:'auto',
  backgroundColor:'blue',
  width:'400px'
}
const css4={
  height:'150px',
  margin:'auto',
  backgroundColor:'black',
  width:'600px'
}
const big={
  margin:'auto',
  width:'600px',
  display:'flex'
}
createRoot(document.getElementById('root')).render(
  <>

  <div style={css1}> <Component1/> </div>
  <div style={big} > <div style={css2} > <Component2/> </div>  <div style={css3}><Component3/> </div>   </div>
  <div  style={css4}> </div>
  
  </>
)




