import { useState, useEffect } from "react";
import axios from "axios";
import styles from "./styles.module.css";
import Wishlist from "../Wishlist/Wishlist";

/**
 * @typedef {Object} WishlistEntry
 * @property {string} _id
 * @property {string} title
 * @property {string} description
 * @property {string} user
 * @property {string} createdAt
 */

const Main = () => {
  const [dane, ustawDane] = useState([]);
  const [tytul, ustawTytul] = useState(""); // dodajemy tytuł
  const [userDetails, setUserDetails] = useState(null); // szczegóły zalogowanego usera
  const [wishlistStats, setWishlistStats] = useState(null);
  const [wishlistLoading, setWishlistLoading] = useState(false);

  // Automatically load wishlist when component mounts
  useEffect(() => {
    handleGetWishlist();
  }, []);

  const handleLogout = () => {
    localStorage.removeItem("token");
    window.location.reload();
  };

  const handleGetWishlist = async (e) => {
    if (e) e.preventDefault();
    const token = localStorage.getItem("token");
    if (token) {
      try {
        setWishlistLoading(true);
        const config = {
          method: "get",
          url: "http://localhost:8080/api/wishlist/my",
          headers: {
            "Content-Type": "application/json",
            "x-access-token": token
          }
        };
        const { data: res } = await axios(config);        ustawDane(res.data); // dane to tablica WishlistEntry
        ustawTytul(""); // Remove title for wishlist
        setUserDetails(null); // Reset user details when viewing wishlist
      } catch (error) {
        if (error.response && error.response.status >= 400 && error.response.status <= 500) {
          localStorage.removeItem("token");
          window.location.reload();
        }
      } finally {
        setWishlistLoading(false);
      }
    }
  };

  const handleGetMyAccount = async (e) => {
    e.preventDefault();
    const token = localStorage.getItem("token");

    if (token) {
      try {
        // Fetch user details
        const userConfig = {
          method: "get",
          url: "http://localhost:8080/api/users/me",
          headers: {
            "Content-Type": "application/json",
            "x-access-token": token
          }
        };
        const { data: userRes } = await axios(userConfig);        setUserDetails(userRes.data);
        ustawTytul(""); // Remove title for account section

        // Fetch wishlist statistics
        const statsConfig = {
          method: "get",
          url: "http://localhost:8080/api/wishlist/stats",
          headers: {
            "Content-Type": "application/json",
            "x-access-token": token
          }
        };
        const { data: statsRes } = await axios(statsConfig);
        setWishlistStats(statsRes.data);
      } catch (error) {
        if (error.response && error.response.status >= 400 && error.response.status <= 500) {
          localStorage.removeItem("token");
          window.location.reload();
        }
      }
    }
  };

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

  const handleAddWishlistEntry = async ({ title, description, price }) => {
    const token = localStorage.getItem("token");
    if (!token) throw new Error("Brak tokena");
    await axios.post(
      "http://localhost:8080/api/wishlist/my",
      { title, description, price },
      {
        headers: {
          "Content-Type": "application/json",
          "x-access-token": token
        }
      }
    );
    // Refresh wishlist after adding
    await handleGetWishlist();
  };

  const handleToggleWishlistPurchased = async (id) => {
    const token = localStorage.getItem("token");
    if (!token) return;
    await axios.patch(
      `http://localhost:8080/api/wishlist/${id}/toggle`,
      {},
      {
        headers: {
          "Content-Type": "application/json",
          "x-access-token": token
        }
      }
    );
    await handleGetWishlist();
  };

  const handleDeleteWishlistEntry = async (id) => {
    const token = localStorage.getItem("token");
    if (!token) return;
    
    const confirmDelete = window.confirm("Are you sure you want to delete this item?");
    if (!confirmDelete) return;
    
    try {
      await axios.delete(
        `http://localhost:8080/api/wishlist/${id}`,
        {
          headers: {
            "Content-Type": "application/json",
            "x-access-token": token
          }
        }
      );
      await handleGetWishlist(); // Refresh the list
    } catch (error) {
      alert("Error deleting item");
    }
  };

  return (
    <div className={styles.main_container}>
      <nav className={styles.navbar}>
        <h1>Wishlist App</h1>
        <button className={styles.white_btn} onClick={handleGetWishlist}>
          📝 Wishlist
        </button>        <button className={styles.white_btn} onClick={handleGetMyAccount}>
          👤 Account
        </button>
      </nav>
      <div className={styles.content_container}></div>
        {tytul && <h2 className={styles.title}>{tytul}</h2>}        {userDetails ? (
          <div className={styles.account_section}>
            {/* Account Header */}
            <div className={styles.account_header}>
              <h2>👤 My Account</h2>
            </div>
            
            <div className={styles.account_container}>
            {/* Profile Header */}
            <div className={styles.profile_header}>
              <div className={styles.profile_avatar}>
                <div className={styles.avatar_circle}>
                  {userDetails.firstName.charAt(0).toUpperCase()}{userDetails.lastName.charAt(0).toUpperCase()}
                </div>
              </div>
              <div className={styles.profile_info}>
                <h2 className={styles.profile_name}>{userDetails.firstName} {userDetails.lastName}</h2>
                <p className={styles.profile_email}>{userDetails.email}</p>
              </div>
            </div>

            {/* Account Information Card */}
            <div className={styles.info_card}>
              <div className={styles.card_header}>
                <h3>Account Information</h3>
                <div className={styles.card_icon}>👤</div>
              </div>
              <div className={styles.info_grid}>
                <div className={styles.info_item}>
                  <label>First Name</label>
                  <span>{userDetails.firstName}</span>
                </div>
                <div className={styles.info_item}>
                  <label>Last Name</label>
                  <span>{userDetails.lastName}</span>
                </div>
                <div className={styles.info_item}>
                  <label>Email Address</label>
                  <span>{userDetails.email}</span>
                </div>
              </div>
            </div>
            
            {/* Statistics Card */}
            {wishlistStats && (
              <div className={styles.stats_card}>
                <div className={styles.card_header}>
                  <h3>Wishlist Analytics</h3>
                  <div className={styles.card_icon}>📊</div>
                </div>
                
                {/* Progress Bar */}
                <div className={styles.progress_section}>
                  <div className={styles.progress_info}>
                    <span>Completion Progress</span>
                    <span className={styles.progress_percentage}>{wishlistStats.accomplishedPercentage}%</span>
                  </div>
                  <div className={styles.progress_bar}>
                    <div 
                      className={styles.progress_fill} 
                      style={{ width: `${wishlistStats.accomplishedPercentage}%` }}
                    ></div>
                  </div>
                </div>

                {/* Stats Grid */}
                <div className={styles.stats_grid}>
                  <div className={styles.stat_card}>
                    <div className={styles.stat_icon}>📝</div>
                    <div className={styles.stat_content}>
                      <div className={styles.stat_value}>{wishlistStats.totalEntries}</div>
                      <div className={styles.stat_label}>Total Items</div>
                    </div>
                  </div>
                  <div className={styles.stat_card}>
                    <div className={styles.stat_icon}>✅</div>
                    <div className={styles.stat_content}>
                      <div className={styles.stat_value}>{wishlistStats.purchasedEntries}</div>
                      <div className={styles.stat_label}>Purchased</div>
                    </div>
                  </div>
                  <div className={styles.stat_card}>
                    <div className={styles.stat_icon}>💰</div>
                    <div className={styles.stat_content}>
                      <div className={styles.stat_value}>${wishlistStats.totalValue}</div>
                      <div className={styles.stat_label}>Total Value</div>
                    </div>
                  </div>
                  <div className={styles.stat_card}>
                    <div className={styles.stat_icon}>💸</div>
                    <div className={styles.stat_content}>
                      <div className={styles.stat_value}>${wishlistStats.totalSpent}</div>
                      <div className={styles.stat_label}>Total Spent</div>
                    </div>
                  </div>
                  <div className={styles.stat_card}>
                    <div className={styles.stat_icon}>💳</div>
                    <div className={styles.stat_content}>
                      <div className={styles.stat_value}>${wishlistStats.remainingValue}</div>
                      <div className={styles.stat_label}>Remaining</div>
                    </div>
                  </div>
                  <div className={styles.stat_card}>
                    <div className={styles.stat_icon}>📈</div>
                    <div className={styles.stat_content}>
                      <div className={styles.stat_value}>{wishlistStats.accomplishedPercentage}%</div>
                      <div className={styles.stat_label}>Completed</div>
                    </div>
                  </div>
                </div>
              </div>
            )}

            {/* Action Buttons */}
            <div className={styles.actions_card}>
              <div className={styles.card_header}>
                <h3>Account Actions</h3>
                <div className={styles.card_icon}>⚙️</div>
              </div>
              <div className={styles.actions_grid}>
                <button className={styles.action_btn_primary} onClick={handleLogout}>
                  <span className={styles.btn_icon}>🚪</span>
                  Logout
                </button>
                <button className={styles.action_btn_danger} onClick={handleDeleteAccount}>
                  <span className={styles.btn_icon}>🗑️</span>
                  Delete Account
                </button>
              </div>
            </div>            </div>
          </div>
        ) : (
          <div className={styles.users_section}>
            <Wishlist entries={dane} onAddEntry={handleAddWishlistEntry} onTogglePurchased={handleToggleWishlistPurchased} loading={wishlistLoading} onDeleteEntry={handleDeleteWishlistEntry} />
          </div>
        )}
      </div>
  );
};

export default Main;

/*<div className={styles.wishlist_section}>
              <h3>Wishlist</h3>
              <AddToWishlist onSuccess={() => alert("Dodano nową rzecz!")} />
              <Wishlist />
            </div>*/