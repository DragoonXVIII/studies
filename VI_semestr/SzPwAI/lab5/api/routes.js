// 1.14

const users = require('../users');
const express = require('express');
const { check, validationResult } = require('express-validator');

const router = express.Router() 

function createInitials(fullname) {
    return fullname.split(' ').map(name => name.charAt(0).toUpperCase()).join('');
}

/*
router.post("/form3",[
    check('fullname').customSanitizer(createInitials),
    check('nazwisko').trim().isAlpha().isLength({min: 3}, {max: 25}).stripLow().withMessage('Nazwisko musi zawierac od 3 do 25 znakow'),
    check('email').trim().isEmail().normalizeEmail().withMessage('Niepoprawny email'),
    check('wiek').isNumeric().isInt({min: 0, max: 110}).bail()], 
    (req, res) => {
        const errors = validationResult(req);
        if(!errors.isEmpty()){
            return res.status(400).json({errors: errors.array()});
    }
    const {fullname, nazwisko, email, wiek} = req.body;
    res.send("Uzytkownik: " + fullname + ", " + nazwisko + "<br>Email:" + email + "<br>Wiek:" + wiek);
});
*/

router.get('/', (req,res) => { 
    res.json(users);
});

router.post('/', (req, res) => { 
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

router.get('/:id', (req,res) => { 
    const found = users.some(user => user.id === parseInt(req.params.id));
    if(found){
        res.json(users.filter(user => user.id === parseInt(req.params.id)));
    } 
    else {
        res.status(400).json({message: `Uzytkownik o id ${req.params.id} nie zostal znaleziony`}); 
    }   
});

router.patch('/:id', (req, res) => { 
    const id = parseInt(req.params.id) 
    if (users.some(user => user.id === id)) {  
        const user = users.find(user => user.id === id) 
        const updUser = req.body 
        user.name = updUser.name ? updUser.name : user.name 
        user.email = updUser.email ? updUser.email : user.email 
        res.json({ msg: 'Dane użytkownika zaktualizowane', user }) 
    } 
    else 
    { 
        res.status(400).json({ msg: `Użytkownik o id ${id} nie istnieje!` }) 
    } 
});

router.delete('/:id', (req, res) => {
    const id = parseInt(req.params.id); 
    const userIndex = users.findIndex(user => user.id === id);
    if (userIndex !== -1) {
        users.splice(userIndex, 1);
        res.json({ msg: 'Użytkownik usunięty', users });
    } else {
        res.status(400).json({ msg: `Użytkownik o id ${id} nie istnieje!` });
    }
});

module.exports = router;