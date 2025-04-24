import { useState } from "react" 
import Header from './components/Header' 
import Products from './components/Products' 
import AddProduct from './components/AddProduct' 
import './App.css' 
 
function App() { 

  const deleteProduct = (id) => { 
    setProducts(products.filter((product) => product.id !== id)) 
    } 
  const addProduct = (product) => { 
    const id = products.length + 1 
    const newProduct = { id, ...product } 
    setProducts([...products, newProduct]) 
    } 

  const [products, setProducts] = useState( 
  [ 
    { 
        "id": 1, 
        "name": "mleko", 
        "category": "diary", 
        "quantity": 1 
    }, 
    { 
        "id": 2, 
        "name": "chleb", 
        "category": "bread", 
        "quantity": 1 
    }, 
    { 
        "id": 3, 
        "name": "jabłka", 
        "category": "fruit&vagetables", 
        "quantity": 2 
    } 
]) 
return ( 
  <div className="App"> 
    <Header title="Lista zakupów" /> 

    {products.length > 0 ? (
      <Products products={products} onDelete={deleteProduct} />
    ) : (
      <p>Brak produktów</p>
    )}

    <AddProduct onAdd={addProduct} /> 
  </div> 
)
} 
export default App 