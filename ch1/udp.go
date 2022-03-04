package main

import (
	"fmt"
	"net"
	"os"
)

const (
	UDP_SERV_PORT = 7777
)

func request(args []string) {
	addr := os.Args[2]

	url := fmt.Sprintf("%s:%v", addr, UDP_SERV_PORT)
	conn, err := net.Dial("udp", url)
	if err != nil {
		panic(err)
	}

	defer conn.Close()

	syn := "gosyn"

	_, err = conn.Write([]byte(syn))
	if err != nil {
		panic(err)
	}

	fmt.Println("sent: ", syn)

	reply := make([]byte, 1024)

	_, err = conn.Read(reply)
	if err != nil {
		panic(err)
	}

	fmt.Printf("received: %s\n", string(reply))
}

func serve() {

}

func main() {
	if len(os.Args) > 1 {
		switch os.Args[1] {
		case "server":
			serve()
		case "client":
			request(os.Args)
		case "client100":
			for i := 0; i < 100; i++ {
				request(os.Args)
			}
		default:
			fmt.Println("usage: udp <command> <*IP address of server>")
		}
	}
}
