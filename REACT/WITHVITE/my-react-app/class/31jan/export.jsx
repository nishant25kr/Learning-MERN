import { createRoot } from 'react-dom/client'
import name from './assets/data'
import {place,age,demo,user} from './assets/data'
createRoot(document.getElementById('root')).render(
  <>
  <h2>{name}</h2>
  <h2>{age}</h2>
  <h2>{place}</h2>
  <h1>{demo()}</h1>
  <h1>{user}</h1>
  </>
)




