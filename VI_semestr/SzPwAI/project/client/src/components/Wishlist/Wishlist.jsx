import { useState } from "react";
import styles from "./styles.module.css";

const Wishlist = ({ entries = [], onAddEntry, onTogglePurchased, onDeleteEntry }) => {
  const [title, setTitle] = useState("");
  const [description, setDescription] = useState("");
  const [price, setPrice] = useState("");
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState("");
  const [showAddForm, setShowAddForm] = useState(false);

  // walidacja formularza
  const isFormValid = () => {
    return title.trim().length >= 2 && 
           title.trim().length <= 32 && 
           description.length <= 256;
  };
  const handleSubmit = async (e) => {
    e.preventDefault();
    setError("");
    
    
    if (!title.trim()) {
      setError("Title is required");
      return;
    }
    if (title.trim().length < 2) {
      setError("Title must be at least 2 characters long");
      return;
    }
    if (title.trim().length > 32) {
      setError("Title cannot exceed 32 characters");
      return;
    }
    
    
    if (description.trim().length > 256) {
      setError("Description cannot exceed 256 characters");
      return;
    }
    
    setLoading(true);
    try {
      await onAddEntry({ title: title.trim(), description: description.trim(), price: price ? Number(price) : undefined });
      setTitle("");
      setDescription("");
      setPrice("");
      setShowAddForm(false); // automatycznew ukrywanie formsa
    } catch (err) {
      setError("Error adding to wishlist");
    } finally {
      setLoading(false);
    }
  };

  return (
    <div className={styles.wishlist_container}>
      {/* Header */}
      <div className={styles.wishlist_header}>
        <h2>🎯 Your Wishlist</h2>
        <div className={styles.wishlist_stats}>
          <span className={styles.total_items}>
            {entries.length} {entries.length === 1 ? 'item' : 'items'}
          </span>
          <span className={styles.purchased_items}>
            {entries.filter(item => item.purchased).length} completed
          </span>
        </div>
      </div>

      {/* Add Item Card */}
      <div className={styles.add_item_card}>
        <div className={styles.card_header} onClick={() => setShowAddForm(!showAddForm)}>
          <h3>
            <span className={styles.card_icon}>➕</span>
            Add New Item
          </h3>
          <span className={`${styles.toggle_icon} ${showAddForm ? styles.expanded : ''}`}>
            ▼
          </span>
        </div>
        
        {showAddForm && (
          <div className={styles.card_content}>
            <form className={styles.add_form} onSubmit={handleSubmit}>              <div className={styles.form_grid}>
                <div className={styles.form_item}>
                  <label>
                    Title *
                    <span className={styles.char_count}>
                      {title.length}/32
                    </span>
                  </label>
                  <input
                    type="text"
                    placeholder="Enter item title..."
                    value={title}
                    onChange={e => setTitle(e.target.value)}
                    className={`${styles.input} ${title.length > 32 ? styles.input_error : ''} ${title.length >= 2 && title.length <= 32 ? styles.input_valid : ''}`}
                    maxLength={32}
                    required
                  />
                  {title.length > 0 && title.length < 2 && (
                    <div className={styles.validation_hint}>Title must be at least 2 characters</div>
                  )}
                </div>
                
                <div className={styles.form_item}>
                  <label>Price</label>
                  <input
                    type="number"
                    placeholder="0.00"
                    value={price}
                    min="0"
                    step="0.01"
                    onChange={e => setPrice(e.target.value)}
                    className={styles.input}
                  />
                </div>
              </div>
              
              <div className={styles.form_item}>
                <label>
                  Description
                  <span className={styles.char_count}>
                    {description.length}/256
                  </span>
                </label>
                <textarea
                  placeholder="Add description (optional)..."
                  value={description}
                  onChange={e => setDescription(e.target.value)}
                  className={`${styles.textarea} ${description.length > 256 ? styles.input_error : ''}`}
                  maxLength={256}
                  rows={3}
                />
                {description.length > 250 && (
                  <div className={styles.validation_hint}>
                    {256 - description.length} characters remaining
                  </div>
                )}
              </div>
              
              {error && <div className={styles.error_msg}>{error}</div>}
              
              <div className={styles.form_actions}>
                <button 
                  type="button" 
                  onClick={() => setShowAddForm(false)}
                  className={styles.cancel_btn}
                >
                  Cancel
                </button>                <button 
                  type="submit" 
                  disabled={loading || !isFormValid()}
                  className={styles.submit_btn}
                >
                  <span className={styles.btn_icon}>
                    {loading ? "⏳" : "✨"}
                  </span>
                  {loading ? "Adding..." : "Add to Wishlist"}
                </button>
              </div>
            </form>
          </div>
        )}
      </div>

      {/* Wishlist Items */}
      {entries.length > 0 ? (
        <div className={styles.items_container}>
          <h3 className={styles.section_title}>
            <span className={styles.section_icon}>📋</span>
            Your Items
          </h3>
          <div className={styles.items_grid}>
            {entries.map((item) => (
              <div 
                key={item._id} 
                className={`${styles.item_card} ${item.purchased ? styles.purchased : ''}`}
              >
                <div className={styles.item_header}>
                  <h4 className={styles.item_title}>{item.title}</h4>
                  <div className={styles.item_status}>
                    {item.purchased ? (
                      <span className={styles.status_purchased}>✓</span>
                    ) : (
                      <span className={styles.status_pending}>○</span>
                    )}
                  </div>
                </div>
                
                {item.description && (
                  <p className={styles.item_description}>{item.description}</p>
                )}
                  <div className={styles.item_footer}>
                  <div className={styles.item_meta}>
                    {typeof item.price === 'number' && !isNaN(item.price) && (
                      <span className={styles.item_price}>
                        💰 ${item.price.toFixed(2)}
                      </span>
                    )}
                    <span className={styles.item_date}>
                      📅 {new Date(item.createdAt).toLocaleDateString()}
                    </span>
                  </div>
                  
                  <div className={styles.item_actions}>
                    <button
                      onClick={() => onTogglePurchased && onTogglePurchased(item._id)}
                      className={`${styles.toggle_btn} ${item.purchased ? styles.purchased_btn : styles.pending_btn}`}
                      title={item.purchased ? "Mark as not purchased" : "Mark as purchased"}
                    >
                      {item.purchased ? "Mark Pending" : "Mark Purchased"}
                    </button>
                    
                    <button
                      onClick={() => onDeleteEntry && onDeleteEntry(item._id)}
                      className={styles.delete_btn}
                      title="Delete this item"
                    >
                      🗑️
                    </button>
                  </div>
                </div>
              </div>
            ))}
          </div>
        </div>
      ) : (
        <div className={styles.empty_state}>
          <div className={styles.empty_icon}>🎁</div>
          <h3>Your wishlist is empty</h3>
          <p>Add your first item to get started!</p>
          <button 
            onClick={() => setShowAddForm(true)}
            className={styles.empty_action_btn}
          >
            <span className={styles.btn_icon}>➕</span>
            Add First Item
          </button>
        </div>
      )}
    </div>
  );
};

export default Wishlist;
