import { useState } from "react";
import axios from "axios";
import styles from "./styles.module.css";
import Users from "../Users/Users"; 
import User from "../User/User";   
import { set } from "mongoose";

const Main = () => {
  const [dane, ustawDane] = useState([]);
  const [tytul, ustawTytul] = useState(""); // tytuł
  const [userDetails, setUserDetails] = useState(null); // szczegóły zalogowanego usera

  // wyloguj
  const handleLogout = () => {
    localStorage.removeItem("token");
    window.location.reload();
  };

  // uzytkownicy
  const handleGetUsers = async (e) => {
    e.preventDefault();
    const token = localStorage.getItem("token");
    setUserDetails(null); 
    if (token) {
      try {
        const config = {
          method: "get",
          url: "http://localhost:8080/api/users",
          headers: { 
            "Content-Type": "application/json",
            "x-access-token": token 
          }
        };
        const { data: res } = await axios(config);
        ustawDane(res.data);
        ustawTytul(res.message || "Lista użytkowników");
      } catch (error) {
        if (error.response && error.response.status >= 400 && error.response.status <= 500) {
          localStorage.removeItem("token");
          window.location.reload();
        }
      }
    }
  };

  // moje konto
  const handleGetMyAccount = async (e) => {
    e.preventDefault();
    const token = localStorage.getItem("token");
    setUserDetails(null); // resetujemy szczegolow bo cos sie wywalalo inaczej (~user list w szczegolach)

    if (token) {
      try {
        const config = {
          method: "get",
          url: "http://localhost:8080/api/users/me", 
          headers: { 
            "Content-Type": "application/json",
            "x-access-token": token 
          }
        };
        const { data: res } = await axios(config);
        setUserDetails(res.data); // zapis danych usera
        ustawTytul(res.message || "Moje konto"); // ustawienie tytułu
        
      } catch (error) {
        if (error.response && error.response.status >= 400 && error.response.status <= 500) {
          localStorage.removeItem("token");
          window.location.reload();
        }
      }
    }
  };

  // usun konto
  const handleDeleteAccount = async (e) => {
    e.preventDefault();
    const confirmDelete = window.confirm("Czy na pewno chcesz usunąć swoje konto?");
    if (!confirmDelete) return;

    const token = localStorage.getItem("token");

    if (token) {
      try {
        const config = {
          method: "delete",
          url: "http://localhost:8080/api/users/me", // <- usuwamy siebie
          headers: { 
            "Content-Type": "application/json",
            "x-access-token": token 
          }
        };
        const { data: res } = await axios(config);
        alert(res.message || "Konto zostało usunięte");
        localStorage.removeItem("token");
        window.location.reload();
      } catch (error) {
        if (error.response && error.response.status >= 400 && error.response.status <= 500) {
          alert("Wystąpił błąd przy usuwaniu konta.");
        }
      }
    }
  };

  return (
    <div className={styles.main_container}>
      <nav className={styles.navbar}>
        <h1>MySite</h1>
        <button className={styles.white_btn} onClick={handleLogout}>
          Logout
        </button>
        <button className={styles.white_btn} onClick={handleGetUsers}>
          Użytkownicy
        </button>
        <button className={styles.white_btn} onClick={handleGetMyAccount}>
          Moje konto
        </button>
        <button className={styles.white_btn} onClick={handleDeleteAccount}>
          Usuń konto
        </button>
      </nav>

      {/* Tutaj wyświetlamy tytuł */}
      {tytul && <h2>{tytul}</h2>}

      {/* Wyświetlamy dane użytkownika */}
      {userDetails ? (
        <ul>
          <li>Imię: {userDetails.firstName}</li>
          <li>Nazwisko: {userDetails.lastName}</li>
          <li>Email: {userDetails.email}</li>
        </ul>
      ) : dane.length > 0 ? (
        <Users users={dane} />
      ) : (
        <p></p>
      )}
    </div>
  );
};

export default Main;
