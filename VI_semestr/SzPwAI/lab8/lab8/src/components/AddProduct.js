import { useState } from "react" 
 
const AddProduct = ({ onAdd }) => { 
    const [name, setName] = useState('') 
    const [category, setCategory] = useState('fruit&vagetables') 
    const [quantity, setQuantity] = useState(1) 
    const add = (e) => { 
        e.preventDefault() 
 
        onAdd({ name, category, quantity }) 
        setName('') 
        setCategory('fruit&vagetables') 
        setQuantity(1) 
    } 
    return ( 
        <form className='add-list' onSubmit={add}> 
            <div className='input-div'> 
                <label>Produkt</label> 
                <input type='text' placeholder='Nazwa produktu' value={name} onChange={(e) => 
setName(e.target.value)} required /> 
            </div> 
            <div className='input-div'> 
                <label>Kategoria</label> 
                <select value={category} onChange={(e) => setCategory(e.target.value)}> 
                    <option value='fruits&vagetables'>Owoce i warzywa</option> 
                    <option value='diary'>Nabiał</option> 
                    <option value='bread'>Pieczywo</option> 
                </select> 
            </div> 
            <div className='input-div'> 
                <label>Ilość</label> 
                <input type='number' placeholder='0' value={quantity} min="0" onChange={(e) => 
setQuantity(e.target.value)} /> 
            </div> 
            <input type='submit' className='btn' value='Dodaj' /> 
        </form> 
    ) 
} 
export default AddProduct 