import { useState } from "react";
import axios from "axios";
import styles from "./styles.module.css";

const AddToWishlist = ({ onSuccess }) => {
  const [name, setName] = useState("");
  const [group, setGroup] = useState("");

  const handleSubmit = async (e) => {
    e.preventDefault();
    const token = localStorage.getItem("token");

    try {
      await axios.post("http://localhost:8080/api/wishlist", {
        name,
        group,
      }, {
        headers: {
          "Content-Type": "application/json",
          "x-access-token": token
        }
      });

      setName("");
      setGroup("");
      if (onSuccess) onSuccess();
    } catch (err) {
      alert("Błąd przy dodawaniu rzeczy do wishlisty.");
    }
  };

  return (
    <form className={styles.form_container} onSubmit={handleSubmit}>
      <h3>Dodaj do wishlisty</h3>
      <input
        type="text"
        placeholder="Nazwa rzeczy"
        value={name}
        onChange={(e) => setName(e.target.value)}
        required
        className={styles.input}
      />
      <input
        type="text"
        placeholder="Grupa (opcjonalna)"
        value={group}
        onChange={(e) => setGroup(e.target.value)}
        className={styles.input}
      />
      <button type="submit" className={styles.green_btn}>Dodaj</button>
    </form>
  );
};

export default AddToWishlist;
