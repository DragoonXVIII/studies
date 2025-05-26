const mongoose = require("mongoose");

module.exports = () => {
  const connectionParams = {
    useNewUrlParser: true,
    useUnifiedTopology: true,
  };
  try {
    //mongodb+srv://lotrofring:SOQEEjDNazqeq4Qm@szpwai.qh4kl.mongodb.net/?retryWrites=true&w=majority&appName=SzPwAI
    mongoose.connect("mongodb+srv://lotrofring:SOQEEjDNazqeq4Qm@szpwai.qh4kl.mongodb.net/?retryWrites=true&w=majority&appName=SzPwAI");
    console.log("Connected to database successfully");
  } catch (error) {
    console.log(error);
    console.log("Could not connect database!");
  }
};
