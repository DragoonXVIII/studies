import { useState } from "react" 
import { FiX } from "react-icons/fi" 
import { GiMilkCarton, GiSlicedBread, GiShinyApple } from 'react-icons/gi' 

const Product = ({ product, onDelete }) => { 
    const [isChecked, setIsChecked] = useState(false) 
    
    // helper do wyboru ikonki wg kategorii
    const renderCategoryIcon = () => {
        switch(product.category) {
            case "diary":
                return <GiMilkCarton className="category" />
            case "bread":
                return <GiSlicedBread className="category" />
            case "fruit&vagetables":
                return <GiShinyApple className="category" />
            default:
                return null
        }
    }

    return ( 
        <div className='product'> 
            <div className='product-info'> 
                <div className='input-name'> 
                    <input 
                        type='checkbox' 
                        checked={isChecked}
                        onChange={() => setIsChecked(!isChecked)}  
                    /> 
                    <p className={isChecked ? 'checked' : ''}>
                        {product.name}
                        {renderCategoryIcon()}
                    </p> 
                </div> 
                <p>{product.quantity}</p> 
            </div> 
            <div className='product-icons'> 
                <FiX onClick={() => onDelete(product.id)} /> 
            </div> 
        </div> 
    ) 
} 

export default Product
