require("dotenv").config();
const express = require("express");
const app = express();
const cors = require("cors");
const connection = require("./db");
const userRoutes = require("./routes/users");
const authRoutes = require("./routes/auth");
const tokenVerification = require("./middleware/tokenVerification");
var jwt = require("jsonwebtoken");
//podpis domyślnie szyfrowany algorytmem HMAC SHA256
const token = jwt.sign({ _id: this._id }, process.env.JWTPRIVATEKEY, {
  expiresIn: "7d",
});

connection();
//middleware
app.use(express.json());
app.use(cors());
//routes
app.get("/api/users/", tokenVerification);
app.use("/api/users", userRoutes);
app.use("/api/auth", authRoutes);

const port = process.env.PORT || 8080;

app.listen(port, () => console.log(`Nasłuchiwanie na porcie ${port}`));
