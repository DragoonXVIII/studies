const router = require("express").Router();
const { User, validate } = require("../models/user");
const { getMyAccount, deleteMyAccount } = require("../controllers/userController");
const tokenVerification = require("../middleware/tokenVerification");
const bcrypt = require("bcrypt");


// Dane konta
router.get("/me", tokenVerification, getMyAccount);

// Usuń konto
router.delete("/me", tokenVerification, deleteMyAccount);

// Get all users
router.get("/", tokenVerification, async (req, res) => {
  try {
    const users = await User.find().select("-password");
    res.status(200).send({ data: users, message: "Lista użytkowników" });
  } catch (error) {
    console.error("Error fetching users:", error);
    res.status(500).send({ message: error.message });
  }
});

router.post("/", async (req, res) => {
  try {
    const { error } = validate(req.body);
    if (error)
      return res.status(400).send({ message: error.details[0].message });

    const user = await User.findOne({ email: req.body.email });
    if (user)
      return res
        .status(409)
        .send({ message: "User with given email already Exist!" });

    const salt = await bcrypt.genSalt(Number(process.env.SALT));
    const hashPassword = await bcrypt.hash(req.body.password, salt);

    await new User({ ...req.body, password: hashPassword }).save();
    res.status(201).send({ message: "User created successfully" });
  } catch (error) {
    res.status(500).send({ message: "Internal Server Error" });
  }
});
module.exports = router;
