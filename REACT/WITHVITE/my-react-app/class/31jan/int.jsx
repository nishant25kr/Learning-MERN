
import { createRoot } from 'react-dom/client'
var uid="Lovely Professionsl University"

let person={
  name:'Nishant',
  age:23,
  place:'delhi'
}

let x=prompt("Enter in KILO")
let res=(x*1000)


createRoot(document.getElementById('root')).render(
  <>
   <h1>hello</h1>
   <h1>{uid}</h1>
   <h1>{person.name}</h1>
   <h1>{person.age}</h1>
   <h1>{person.place}</h1>
   <h1>weight in gram is,</h1>
   <h1>{res}</h1>
  </>
)




