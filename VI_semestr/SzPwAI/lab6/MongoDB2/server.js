
const express = require("express");
const path = require("path");
const handleBars = require("handlebars");
const exphbs = require("express-handlebars");
const { allowInsecurePrototypeAccess } = require("@handlebars/allow-prototype-access");
const studentController = require("./controllers/StudentController");

const app = express();
app.use(express.urlencoded({  extended: true }));

app.set("views", path.join(__dirname, "views"));

app.engine(
    "hbs",
    exphbs.engine({
        handlebars: allowInsecurePrototypeAccess(handleBars),
        extname: "hbs",
        defaultLayout: "layout",
        layoutsDir: path.join(__dirname, "views/layouts"),
    })
);

app.set("view engine", "hbs");

app.get('/favicon.ico', (req, res) => res.status(404));
app.use('/', require('./controllers/StudentController')) 



app.listen(3000, () => {
    console.log("Serwer nasłuchuje na porcie 3000");
});