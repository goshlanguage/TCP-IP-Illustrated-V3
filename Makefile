.PHONY: build
build:
	mkdir -p bin
	clang -o bin/udpserv ./ch1/udpserv.c
	clang -o bin/udpclient ./ch1/udpcli.c
	go build -o ./bin/udpgo ch1/udp.go

.PHONY: clean
clean:
	rm -rfv ./bin