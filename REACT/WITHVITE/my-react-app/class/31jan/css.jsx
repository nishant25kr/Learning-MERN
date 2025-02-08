
import { createRoot } from 'react-dom/client'
import x from './assets/image.jpg'
const obj=new Date()
let h=obj.getHours()
let message
const css={
  fontFamily:'Arial',
  color:'yellow'
}

if(h<12){
  css.color='yellow'
  message="Good morning"
}
else{
  css.color='blue'
  message="Good nighnt"
}

createRoot(document.getElementById('root')).render(
  <>
   
  </>
)




