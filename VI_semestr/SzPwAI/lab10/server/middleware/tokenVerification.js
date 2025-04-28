const jwt = require("jsonwebtoken") 
 
function tokenVerification(req, res, next) { 
    //pobranie tokenu z nagłówka: 
    let token = req.headers["x-access-token"]; 
    if (!token) {
        return res.status(403).send({ message: "No token provided!" }); 
    }
    //jeśli przesłano token - weryfikacja jego poprawności: 
    try {
        const decoded = jwt.verify(token, process.env.JWTPRIVATEKEY);
        if (!decoded || !decoded._id) {
            return res.status(401).send({ message: "Invalid token format" });
        }
        req.user = decoded;
        next();
    } catch (err) {
        console.log("Token verification failed:", err);
        return res.status(401).send({ message: "Unauthorized!" });
    }
}

module.exports = tokenVerification 