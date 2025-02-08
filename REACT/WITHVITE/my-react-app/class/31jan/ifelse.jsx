
import { createRoot } from 'react-dom/client'
const obj=new Date()
let h=obj.getHours()
let m=obj.getMinutes()
let s=obj.getSeconds()
let message
if(h<12){
  message="Good morning"
}
else{
  message="Good nighnt"
}

createRoot(document.getElementById('root')).render(
  <>
   <h1>Welocme to react using Vite</h1>
   <h2>{h}:{m}:{s}</h2>
   <h1>{message}</h1>
  </>
)




