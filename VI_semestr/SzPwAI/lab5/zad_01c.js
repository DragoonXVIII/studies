const express = require('express') 
const path = require('path') 
const app = express() 
const hbs = require('hbs') 

app.set('view engine', 'hbs') 

app.set('views', path.join(__dirname, 'views')) 

app.get('/about', (req, res) => { 
    res.render('about', {name: 'Jan'}) 
}) 

//zad 1.15
app.get('/hello/:nazwisko-:email-:wiek', (req, res) => {
    const { nazwisko, email, wiek } = req.params;
    res.status(200).set('Content-Type', 'text/html');
    res.send(`
        <body>
            <p>Nazwisko: <b> ${nazwisko}</b></p>
            <p>Email: ${email}</p>
            <p>Wiek: ${wiek}</p>
        </body>
        `);
});

app.listen(3000, () => console.log('Serwer działa!'))