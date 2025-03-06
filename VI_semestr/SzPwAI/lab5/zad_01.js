const express = require('express') 
const path = require('path') 
const app = express() 
const reactEngine = require ('express-react-views') 
const getDate = require('./server-files/getDate');


app.set('view engine', 'jsx') 
app.engine('jsx', reactEngine.createEngine()) 

//middleware dla zad 1.16
app.use((req, res, next) => {
    console.log(`${getDate()} - ${req.method} ${req.url}`);
    next();
});


app.use(express.static(path.join(__dirname, 'public')));

// Routes for the HTML files
app.get('/strona1', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'strona1.html'));
});
app.get('/strona2', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'strona2.html'));
});
app.get('/strona3', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'strona3.html'));
});
app.get('/strona4', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'strona4.html'));
});
app.get('/strona5', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'strona5.html'));
});


app.get('/about', (req, res) => { 
    res.render('about', {nazwisko: 'Kowalski', email: 'jan@kowalski.pl', wiek: 40}) 
});


function convert(value, toRad) {
    if (toRad) {
        return value * (Math.PI / 180);
    } else {
        return value * (180 / Math.PI);
    }
}
//http://localhost:3000/convert?value=180&toRad=true
app.get('/convert', (req, res) => {
    const value = parseFloat(req.query.value);
    const toRad = req.query.toRad === 'true';
    const result = convert(value, toRad);
    res.send(`${value} stopni to ${result} radianow`);
});


//http://localhost:3000/color?bg=red
app.get('/color', (req, res) => {
    const bgColor = req.query.bg || 'white';
    res.send(`
        <!DOCTYPE html>
        <html>
        <head>
            <title>Dynamic Background Color</title>
            <style>
                body {
                    background-color: ${bgColor};
                }
            </style>
        </head>
        <body>
            <h1>Dynamic Background Color</h1>
            <p>The background color is ${bgColor}.</p>
        </body>
        </html>
    `);
});


app.listen(3000, () => console.log('Serwer działa!'))