const mongoose = require("../db");

const StudentSchema = new mongoose.Schema({
    fullName: String,
    email: String,
    mobile: Number,
    city: String,
});

const Student = mongoose.model("Student", StudentSchema);

module.exports = Student;