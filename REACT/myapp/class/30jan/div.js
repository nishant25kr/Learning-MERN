import ReactDom from'react-dom/client'
const root=ReactDom.createRoot(document.getElementById('root'))
const lpu=ReactDom.createRoot(document.getElementById('lpu'))
root.render(
    <div>
        <h1>Welcome to REACT</h1>
        <h1>Welcome to LPU</h1>
    </div>
)
lpu.render(
    <h1>Welcome to LPU</h1>
)