FROM alpine:latest AS builder

WORKDIR /app

ARG VERSION="2.13.7"

RUN echo '<!DOCTYPE html> \
<html lang="pl"> \
<head> \
    <meta charset="UTF-8"> \
    <meta name="viewport" content="width=device-width, initial-scale=1.0"> \
    <title>Informacje o serwerze</title> \
</head> \
<body> \
    <h1>Informacje o serwerze</h1> \
    <p>Adres IP: '$(hostname -i)'</p> \
    <p>Hostname: '$(hostname)'</p> \
    <p>Wersja: '"$VERSION"'</p> \
</body> \
</html>' > index.html

FROM nginx:alpine

COPY --from=builder /app/index.html /usr/share/nginx/html/index.html

HEALTHCHECK --interval=10s --timeout=3s \
  CMD curl -f http://localhost:80/ || exit 1
