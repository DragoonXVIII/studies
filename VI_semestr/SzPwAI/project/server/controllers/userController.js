const { User } = require("../models/user");

// Pobierz dane zalogowanego użytkownika
const getMyAccount = async (req, res) => {
  try {
    if (!req.user || !req.user._id) {
      console.log("No user ID in request");
      return res.status(401).send({ message: "User not authenticated" });
    }

    const user = await User.findById(req.user._id).select("-password");
    if (!user) {
      console.log("User not found for ID:", req.user._id);
      return res.status(404).send({ message: "Użytkownik nie znaleziony" });
    }

    res.status(200).send({ 
      message: "Szczegóły twojego konta",
      data: user 
    });
  } catch (error) {
    console.error("Error in getMyAccount:", error);
    res.status(500).send({ message: "Wystąpił błąd serwera" });
  }
};

// Usuń konto zalogowanego użytkownika
const deleteMyAccount = async (req, res) => {
  try {
    const user = await User.findByIdAndDelete(req.user._id);
    if (!user) return res.status(404).send({ message: "Użytkownik nie znaleziony" });

    res.status(200).send({ message: "Konto zostało usunięte" });
  } catch (error) {
    res.status(500).send({ message: "Wystąpił błąd serwera" });
  }
};

module.exports = { getMyAccount, deleteMyAccount };
