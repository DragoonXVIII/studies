FROM golang:1.20-alpine AS builder

WORKDIR /app

COPY main.go .

RUN go mod init myapp && go mod tidy

ARG VERSION="zgodna z stage 2"
RUN CGO_ENABLED=0 go build -ldflags "-X main.version=${VERSION}" -o app

FROM nginx:alpine

WORKDIR /app
COPY --from=builder /app/app .

HEALTHCHECK --interval=30s --timeout=5s --retries=3 \
  CMD curl -f http://localhost || exit 1

CMD ["sh", "-c", "./app & nginx -g 'daemon off;'"]

# docker build -t local/s2:1 .
# docker run --rm -d -p 8080:8080 --name=s2 local/s2:1