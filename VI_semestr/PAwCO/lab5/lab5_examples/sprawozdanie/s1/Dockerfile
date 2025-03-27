FROM golang:1.20-alpine AS builder

WORKDIR /app

COPY main.go .

RUN go mod init myapp && go mod tidy

ARG VERSION="zgodna z stage 1"
RUN CGO_ENABLED=0 go build -ldflags "-X main.version=${VERSION}" -o app

FROM alpine:latest

WORKDIR /root/

COPY --from=builder /app/app .

EXPOSE 8080

CMD ["./app"]

# docker build -t local/s1:1 .
# docker run --rm -d -p 8080:8080 --name=s1 local/s1:1