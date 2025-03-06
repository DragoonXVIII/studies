const express = require('express');
const path = require('path');
const app = express();
const PORT = 3000;



//nie wiem czy tak powinno być, ale uznalem ze tak sb zrobie
const packageInfo = require('./package.json');

app.get('/', (req, res) => {
    res.send('Prosty serwer oparty na szkielecie programistycznym Express!');
});

//nie wiem czy tak powinno być, ale uznalem ze tak sb zrobie
app.get('/about', (req, res) => {
    res.send(`Autor strony: ${packageInfo.author}`);
});

//1.9
app.get('/name/:imie0-:imie1', (req, res) => {
    const { imie0, imie1 } = req.params;
    res.status(200).set('Content-Type', 'text/html');
    res.send(`Czesc ${imie0} i ${imie1}!`);
});
//http://localhost:3000/name/Jakub-Kuba

//1.10  
// a)
/*
app.get('/form', (req, res) => {
    res.sendFile(path.join(__dirname, 'form.html'));
});

app.get('/result', (req, res) => {
    let username = req.query.username;
    let password = req.query.password;
    if (!username || !password) {
        res.send('Wprowadz dane');
    }
    res.send('Uzytkownik: ' + username + ', haslo: ' + password);
});
*/

// b)
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

// +========== 1.13 ==========+
const metoda = require('./middleware/metoda');
app.use(metoda);

const isAuthorized = require('./middleware/autoryzacja');
app.use(isAuthorized);
// +========== 1.13 ==========+

app.get('/form', (req, res) => {
    res.sendFile(path.join(__dirname, 'form.html'));
});

app.post('/result', (req, res) => {
    const { username, password } = req.body;
    // opcja json (wedlug zadania ale nie ladna xD)
    /*
    if (!username || !password) {
        res.status(400).json({ message: 'Wprowadz dane' });
        return;
    }
    res.status(200).json({ message: `Uzytkownik: ${username}, haslo: ${password}` });
    */
   // opcja jak wczesniej
    if (!username || !password) {
        res.send('Wprowadz dane');
    }
    res.send('Uzytkownik: ' + username + ', haslo: ' + password);
});

// c)
app.get('/form2', (req, res) => {
    res.sendFile(path.join(__dirname, 'form2.html'));
});

app.post('/result2', (req, res) => {
    const { fullname, languages } = req.body;const languagesList = Array.isArray(languages) ? languages.map(lang => `<li>${lang}</li>`).join('') : '';
    res.send(`
        <html>
            <body>
                <p>Uzytkownik: ${fullname}</p>
                <p>Znajomsc jezykow:</p>
                <ul>
                    ${languagesList}
                </ul>
            </body>
        </html>
    `);
});

// 1.11
const{check, validationResult} = require('express-validator');

function createInitials(fullname) {
    return fullname.split(' ').map(name => name.charAt(0).toUpperCase()).join('');
}

//dziala przez postmana
app.post("/form3",[
    check('fullname').customSanitizer(createInitials),
    check('nazwisko').trim().isAlpha().isLength({min: 3}, {max: 25}).stripLow().withMessage('Nazwisko musi zawierac od 3 do 25 znakow'),
    check('email').trim().isEmail().normalizeEmail().withMessage('Niepoprawny email'),
    check('wiek').isNumeric().isInt({min: 0, max: 110}).bail()], 
    /*
    check('email').custom(email => {
        if(alreadyHaveMail(email)){
            throw new Error('Email juz istnieje');
        }
        return true;
    }
    */
    /*
    check('email).trim(),
    */
    (req, res) => {
        const errors = validationResult(req);
        if(!errors.isEmpty()){
            return res.status(400).json({errors: errors.array()});
    }
    const {fullname, nazwisko, email, wiek} = req.body;
    res.send("Uzytkownik: " + fullname + ", " + nazwisko + "<br>Email:" + email + "<br>Wiek:" + wiek);
});

//1.12
const users = require('./users');

app.get('/api/users', (req,res) => { 
    res.json(users);
});

app.get('/api/users/:id', (req,res) => { 
    const found = users.some(user => user.id === parseInt(req.params.id));
    if(found){
        res.json(users.filter(user => user.id === parseInt(req.params.id)));
    } 
    else {
        res.status(400).json({message: `Uzytkownik o id ${req.params.id} nie zostal znaleziony`}); 
    }   
});

app.post('/api/users', (req, res) => { 
    const existingIds = users.map(user => user.id);
    let newId = 1;
    while (existingIds.includes(newId)) {
        newId++;
    }

    const newUser = {
        id: newId,
        name: req.body.name,
        email: req.body.email,
        status: "aktywny"
    };
    if(!newUser.name || !newUser.email){ 
        return res.status(400).json({msg: 'Wprowadź poprawne imię i nazwisko oraz email!'}) 
    } 
    users.push(newUser) 
    res.json(users) 
});

app.patch('/api/users/:id', (req, res) => { 
    const id = parseInt(req.params.id) //pobierz id ze ścieżki w URL 
    //sprawdź, czy w tablicy users jest obiekt user o zadanym id: 
    if (users.some(user => user.id === id)) {  
       //znajdź użytkownika o zadanym id w tablicy - zakładamy, że istnieje tylko jeden taki user: 
        const user = users.find(user => user.id === id) 
        const updUser = req.body //pobierz obiekt z danymi do aktualizacji z ciała żądania 
        //zaktualizuj tylko te właściwości istniejącego obiektu user, które przesłano w żądaniu: 
        user.name = updUser.name ? updUser.name : user.name 
        user.email = updUser.email ? updUser.email : user.email 
        res.json({ msg: 'Dane użytkownika zaktualizowane', user }) 
    } 
    else 
    { 
        res.status(400).json({ msg: `Użytkownik o id ${id} nie istnieje!` }) 
    } 
});

app.delete('/api/users/:id', (req, res) => {
    const id = parseInt(req.params.id); //pobierz id ze ścieżki w URL
    const userIndex = users.findIndex(user => user.id === id);
    if (userIndex !== -1) {
        users.splice(userIndex, 1);
        res.json({ msg: 'Użytkownik usunięty', users });
    } else {
        res.status(400).json({ msg: `Użytkownik o id ${id} nie istnieje!` });
    }
});


app.listen(PORT, () => {
    console.log(`Server działa na porcie ${PORT}`);
});

/*
const http = require('http');
const qs = require('querystring');
let items = [];

const server = http.createServer(function (req, res) {
    if ('/' == req.url) {
        switch (req.method) {
            case 'GET':
                show(res);
                break;
            case 'POST':
                if (req.headers['content-type'] === 'application/x-www-form-urlencoded') {
                    let body = '';
                    req.setEncoding('utf8');
                    req.on('data', function (chunk) { body += chunk });
                    req.on('end', function () {
                        let obj = qs.parse(body);
                        if (obj.action === 'add') {
                            items.push(obj.item);
                        } else if (obj.action === 'remove') {
                            items = [];
                        }
                        show(res);
                    });
                } else {
                    badRequest(res);
                }
                break;
            default:
                badRequest(res);
        }
    } else {
        notFound(res);
    }
});

server.listen(3000, () => console.log('Server działa na porcie 3000; naciśnij Ctrl+C, aby zakończyć'));

function show(res) {
    let html = '<html><head><title>Lista zadan</title></head><body>'
        + '<h1>Lista zadan</h1>'
        + '<form method="post" action="/">'
        + '<p><input type="text" name="item" />'
        + '<input type="hidden" name="action" value="add" />'
        + '<input type="submit" value="add" /></p>'
        + '</form>'
        + '<form method="post" action="/">'
        + '<input type="hidden" name="action" value="remove" />'
        + '<input type="submit" value="remove all" />'
        + '</form>'
        + '<ul>'
        + items.map(function (item) {
            return '<li>' + item + '</li>'
        }).join('')
        + '</ul>'
        + '</body></html>';
    res.setHeader('Content-Type', 'text/html');
    res.setHeader('Content-Length', Buffer.byteLength(html));
    res.end(html);
}

function notFound(res) {
    res.statusCode = 404;
    res.setHeader('Content-Type', 'text/plain');
    res.end('Not Found');
}

function badRequest(res) {
    res.statusCode = 400;
    res.setHeader('Content-Type', 'text/plain');
    res.end('Bad Request');
}
*/