const express = require("express"); 
const os = require("os"); 
const packageInfo = require("./package.json"); 
const app = express(); 
app.get("/", (req, res) => { 
    res.send(`<h1>Serwer Info</h1> 
              <p>Adres IP: ${req.connection.remoteAddress}</p> 
              <p>Hostname: ${os.hostname()}</p> 
              <p>Wersja: ${packageInfo.version}</p>`); 
}); 
app.listen(8080, () => console.log("Serwer działa na porcie 8080"));