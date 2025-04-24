import Product from './Product' 
 
const Products = ({products, onDelete}) => { 
    return ( 
        <div className='products'> 
      {products.map((product) => (<Product key={product.id} product={product} onDelete={onDelete} 
/>))} 
     </div> 
    ) 
} 
export default Products