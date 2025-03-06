let metoda = (req, res, next) => { 
    console.log("Metoda: ",req.method) 
    let sciezka = "Ścieżka: "+ req.protocol + "://" + req.get('host') + req.originalUrl 
    console.log(sciezka) 
    next() 
}

module.exports = metoda;
