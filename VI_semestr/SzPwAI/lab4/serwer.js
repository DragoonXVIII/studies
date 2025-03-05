// 1.0 - 1.2
/*
const http = require('http') 

function process_request(req, res) { 
    const body = 'Witaj na platformie Node!\n' 
    const content_length = body.length 
    res.writeHead(200, { 
    'Content-Length': content_length, 
    'Content-Type': 'text/plain' 
    }); 
    res.end(body) 
} 

const server = http.createServer(process_request) 
server.listen(3000, () => console.log('Serwer działa!'))

function fibonacci(num){ 
    let a = 1;
    let b = 0;
    let temp;
    while (num >= 0){ 
        temp = a 
        a = a + b 
        b = temp 
        num-- 
    }   
    return b 
} 

console.log(fibonacci(5))
*/


// 1.3
/*
const http = require('http') 
const fs = require('fs') 
const port = 3000 
 
function serveStaticFile(res, path, contentType, responseCode = 200){ 
    fs.readFile(__dirname + path, (err, data) => { 
        if(err){ 
            res.writeHead(500, { 'Content-Type': 'text/plain'}) 
            return res.end('500 - Blad wewnetrzny') 
        } 
        res.writeHead(responseCode, { 'Content-Type':contentType}) 
        res.end(data) 
    }) 
} 
 
const server = http.createServer((req, res) => { 
    switch(req.url){ 
        case '/': 
         serveStaticFile(res, '/public/home.html', 'text/html' ) 
            break 
        case '/about': 
         serveStaticFile(res, '/public/about.html', 'text/html' ) 
        break 
        case '/logo.png': 
            serveStaticFile(res, '/public/img/logo.png', 'image/png' ) 
            break 
        default: 
          serveStaticFile(res, '/public/404.html','text/html' ) 
          break 
    } 
}) 
 
server.listen(port, () => console.log(`Server działa na porcie ${port}; `+ 'naciśnij Ctrl+C, aby zakończyć'))
*/

// 1.4
/*
const http = require('http') 
const url = require('url') 
 
http.createServer(function (req, res) { 
  res.writeHead(200, {'Content-Type': 'text/html'}) 
  let q = url.parse(req.url, true).query 
  let txt = q.year + " " + q.month + " " + q.day 
  res.end(txt) 
}).listen(3000) 
*/
// 1.4 modded
/*
const http = require('http');
const url = require('url');

http.createServer(function (req, res) {
  res.writeHead(200, {'Content-Type': 'text/html'});
  let q = url.parse(req.url, true).query;
  let a = parseFloat(q.a);
  let b = parseFloat(q.b);
  let c = parseFloat(q.c);

  if(isNaN(a) || isNaN(b) || isNaN(c)){
    res.end('Prosze podac liczby!');
  }
  else if (a <= 0 || b <= 0 || c <= 0) {
    res.end('Długości boków muszą być większe od zera!');
  } 
  else if (a + b <= c || a + c <= b || b + c <= a) {
    res.end('To nie jest trójkąt!');
  }
  else{
    let s = (a + b + c) / 2;
    let area = Math.sqrt(s * (s - a) * (s - b) * (s - c));
    res.end(`Pole powierzchni trojkata wynosi: ${area}`);
  }
}).listen(3000, () => console.log('Server działa na porcie 3000; naciśnij Ctrl+C, aby zakończyć'));
//http://localhost:3000/?a=2.1&b=3.2&c=4.8
*/

// 1.5
/*
const http = require("http") 
const hostname = "localhost" 
const port = 3000 
const server = http.createServer((req, res) => { 
 res.statusCode = 200 
 res.setHeader("Content-Type", "text/html") 
 res.end(`
    <html>
      <head>
        <title>Aplikacja w Node</title>
      </head>
      <body>
        <h1>Aplikacja w Node</h1>
        <p>To jest odpowiedź HTML</p>
        <ul>
          <li>1.</li>
          <li>2.</li>
          <li>3.</li>
        </ul>
      </body>
    </html>
  `);
}) 
server.listen(port, hostname, () => { 
 console.log(`Server running at http://${hostname}:${port}/`) 
})
 */

// 1.6
/*
const http = require('http');
const fs = require('fs');
const port = 3000;

function serveStaticFile(res, path, contentType, responseCode = 200) {
    fs.readFile(__dirname + path, (err, data) => {
        if (err) {
            res.writeHead(500, { 'Content-Type': 'text/plain' });
            return res.end('500 - Blad wewnetrzny');
        }
        res.writeHead(responseCode, { 'Content-Type': contentType });
        res.end(data);
    });
}

const server = http.createServer((req, res) => {
    switch (req.url) {
        case '/':
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end('Home page');
            break;
        case '/about':
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end('About page');
        case '/logo.png':
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end('logo page');
        
        // test
        case '/hello':
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end('Hello, World!');
            break;
        default:
            res.writeHead(404, { 'Content-Type': 'text/plain' });
            res.end('404 - Not Found');
            break;
    }
});

server.listen(port, () => console.log(`Server działa na porcie ${port}; naciśnij Ctrl+C, aby zakończyć`));
*/

// 1.7
//tmp
/*
const http = require('http') 
let items = [] 
const server = http.createServer(function (req, res) { 
    if ('/' == req.url) { 
        switch (req.method) { 
            case 'GET': 
                show(res) 
                break 
            case 'POST': 
                add(req, res) 
                break 
            default: 
                badRequest(res) 
        } 
    } 
    else{ 
        notFound(res) 
    } 
}) 
 
const port = 3000;
server.listen(3000, () => console.log(`Server działa na porcie ${port}; naciśnij Ctrl+C, aby zakończyć`));

function show(res) { 
    let html = '<html><head><title>Lista zadan</title></head><body>' 
        + '<h1>Lista zadan</h1>' 
        + '<form method="post" action="/">' 
        + '<p><input type="text" name="item" />' 
        + '<input type="submit" value="Dodaj" /></p>' 
          '<form method="post" action="/">'
        + '<input type="hidden" name="action" value="remove" />'
        + '<input type="submit" value="Usuń wszystkie" />'
        + '</form>'
        + '<ul>' 
        + items.map(function (item) { 
            return '<li>' + item + '</li>' 
        }).join('') 
        + '</ul>' 
        + '</form></body></html>' 
    res.setHeader('Content-Type', 'text/html') 
    res.setHeader('Content-Length', Buffer.byteLength(html)) 
    res.end(html) 
}
function notFound(res) { 
    res.statusCode = 404 
    res.setHeader('Content-Type', 'text/plain') 
    res.end('Not Found') 
} 
let qs = require('querystring') 
function add(req, res) { 
    var body = '' 
    req.setEncoding('utf8') 
    req.on('data', function (chunk) { body += chunk }) 
    req.on('end', function () { 
        var obj = qs.parse(body) 
        items.push(obj.item) 
        show(res) 
    }) 
} 
*/
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