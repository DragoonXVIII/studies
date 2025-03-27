package main

import (
	"fmt"
	"net"
	"net/http"
	"os"
)

var version = "unknown"

func handler(w http.ResponseWriter, r *http.Request) {
	addrs, _ := net.InterfaceAddrs()
	var ip string
	for _, addr := range addrs {
		if ipNet, ok := addr.(*net.IPNet); ok && !ipNet.IP.IsLoopback() {
			if ipNet.IP.To4() != nil {
				ip = ipNet.IP.String()
				break
			}
		}
	}

	hostname, _ := os.Hostname()

	fmt.Fprintf(w, "IP Serwera: %s\nHostname: %s\nWersja: %s\n", ip, hostname, version)
}

func main() {
	http.HandleFunc("/", handler)
	fmt.Println("Serwer nasłuchuje na porcie 8080...")
	http.ListenAndServe(":8080", nil)
}
