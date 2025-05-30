### 1. Utworzenie sieci
```bash
docker network create lab11net
```

### 2. Przygotowanie struktury katalogów
```bash
mkdir -p ~/lab11/web1/logs
mkdir -p ~/lab11/web2/logs
mkdir -p ~/lab11/web3/logs
mkdir -p ~/lab11/html
```
### 3. Utworzenie strony HTML

#### Opcja A: Utworzenie pliku przez cat
```bash
cat > ~/lab11/html/index.html << EOF
<!DOCTYPE html>
<html>
<head>
    <title>Laboratorium 11</title>
</head>
<body>
    <h1>Laboratorium 11</h1>
    <p>Imię i nazwisko: dragoonxviii</p>
</body>
</html>
EOF
```

#### Opcja B: Skopiowanie z repozytorium
```bash
cp index.html ~/lab11/html/
```

### 4. Uruchomienie kontenerów
```bash
# Kontener web1
docker run -d --name web1 \
  --network lab11net \
  -p 8081:80 \
  -v ~/lab11/html:/usr/share/nginx/html:ro \
  -v ~/lab11/web1/logs:/var/log/nginx \
  nginx:latest

# Kontener web2
docker run -d --name web2 \
  --network lab11net \
  -p 8082:80 \
  -v ~/lab11/html:/usr/share/nginx/html:ro \
  -v ~/lab11/web2/logs:/var/log/nginx \
  nginx:latest

# Kontener web3
docker run -d --name web3 \
  --network lab11net \
  -p 8083:80 \
  -v ~/lab11/html:/usr/share/nginx/html:ro \
  -v ~/lab11/web3/logs:/var/log/nginx \
  nginx:latest
```

### 5. Weryfikacja
```bash
# Sprawdzenie działania kontenerów
docker ps

# Test dostępności
curl http://localhost:8081
curl http://localhost:8082
curl http://localhost:8083
```

