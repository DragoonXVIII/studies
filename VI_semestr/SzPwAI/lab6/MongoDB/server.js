const express = require("express");
const path = require("path");
const handleBars = require("handlebars");
const exphbs = require("express-handlebars");
const {allowInsecurePrototypeAccess} = require("@handlebars/allow-prototype-access");
const mongoose = require("mongoose");

const config = require("./config.js");

async function insert(req, res) { 
    let student = new Student() 
    student.fullName = req.body.fullName 
    student.email = req.body.email 
    student.mobile = req.body.mobile 
    student.city = req.body.city 
    try { 
        await student.save() 
        res.redirect("/list") 
    } catch (err) { 
        console.log("Błąd podczas dodawania studenta: " + err) 
    } 
} 

async function update(req, res) { 
    try { 
        await Student.findOneAndUpdate({ _id: req.body._id }, req.body, { new: true }) 
        res.redirect("list") 
    } catch (err) { 
        console.log("Błąd podczas aktualizowania danych: " + err) 
    } 
} 


const StudentSchema = new mongoose.Schema({
    fullName: String,
    email: String,
    mobile: Number,
    city: String,
});
const Student = mongoose.model("Student", StudentSchema);
mongoose.connect(`mongodb+srv://${config.user}:${config.password}@szpwai.qh4kl.mongodb.net/?retryWrites=true&w=majority&appName=SzPwAI`, {useNewUrlParser: true})
    .then((result)=>{
        console.log("Polaczono z baza!");
    })
    .catch((err)=>{

        console.log("Nie mozna się polaczyc z MOngoDB, blad: " + err);
    });
    

const app = express() 
 
app.use(express.urlencoded({ 
    extended: true 
})) 
 
app.set("views", path.join(__dirname, "/")) 
 
app.engine( 
    "hbs", 
    exphbs.engine({ 
        handlebars: allowInsecurePrototypeAccess(handleBars), 
        extname: "hbs", 
        defaultLayout: "layout", 
        layoutsDir: __dirname, 
    })
)
 
app.set("view engine", "hbs") 


 
app.get("/", (req, res) => { 
    res.send(` 
    <h3 style="text-align:center">Baza danych studentów</h3> 
    <h4 style="text-align:center">Kliknij <a href="/list"> tutaj</a>, aby uzyskać dostęp do bazy.</h4>`) 
}) 
 
app.get("/list", (req, res) => { 
    Student.find().then((docs) => { 
        res.render("list", { 
            list: docs 
        }) 
    }).catch((err) => { 
        console.log("Błąd pobierania danych" + err) 
    }) 
}) 
    
app.get("/addOrEdit", (req, res) => { 
    res.render("addOrEdit", { 
        viewTitle: "Dodaj studenta" 
    }) 
}) 

app.post("/", (req, res) => { 
    if (req.body._id == "") { 
        insert(req, res) 
    } else { 
        update(req, res) 
    } 
}) 

app.get("/:id", (req, res) => { 
    Student.findById(req.params.id).then((doc) => { 
        res.render("addOrEdit", { 
            viewTitle: "Zaktualizuj dane studenta", 
            student: doc 
        }) 
    }).catch((err) => { 
        console.log("Błąd podczas akutalizowania danych" + err) 
    }) 
}) 

app.get("/delete/:id", (req, res) => { 
    Student.findByIdAndDelete(req.params.id).then((doc) => { 
        res.redirect("/list") 
    }).catch((err) => { 
        console.log("Błąd podczas usuwania: " + err) 
    }) 
}) 






app.listen(3000, () => { 
    console.log("Serwer nasłuchuje na porcie 3000") 
})