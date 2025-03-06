const metoda = require('./middleware/metoda');
const isAuthorized = require('./middleware/autoryzacja');
const express = require('express');
const routes = require('./api/routes'); 
const path = require('path');

const packageInfo = require('./package.json');
const PORT = 3000;

const app = express();

app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(isAuthorized);
app.use(metoda);
app.use('/api/users', routes)


app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});

