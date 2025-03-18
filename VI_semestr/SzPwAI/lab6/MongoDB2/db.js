const mongoose = require("mongoose");
const config = require("./config.js");

mongoose.connect(`mongodb+srv://${config.user}:${config.password}@szpwai.qh4kl.mongodb.net/?retryWrites=true&w=majority&appName=SzPwAI`)
    .then(() => {
        console.log("Polaczono z baza!");
    })
    .catch((err) => {
        console.log("Nie mozna się polaczyc z MongoDB, blad: " + err);
    });

module.exports = mongoose;