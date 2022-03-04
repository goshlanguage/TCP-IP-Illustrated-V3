# Chapter 1 - T/TCP Introduction

In this chapter, a simple UDP server and client are shared in C. The OS X variant can be seen here in:

- [udpserv.c](./udpserv.c)
- [udpcli.c](./udpcli.c)
- [cliserv.h](./cliserv.h)

You can compile these targets and run the binaries manually, or use `make` from the project root, and run the binaries from `/bin`:

```bash
$ make
mkdir -p bin
clang -o bin/udpserv ./ch1/udpserv.c
clang -o bin/udpclient ./ch1/udpcli.c
go build -o ./bin/udpgo ch1/udp.go

$ ./bin/updserv

# In another terminal window

$ ./bin/udpclient 0.0.0.0
sockfd: 3
Sent: syn
received: syn
sent: ack
Received: ack

$ ./bin/udpgo client100 0.0.0.0
sent:  gosyn
received: ack
sent:  gosyn
received: ack
sent:  gosyn
received: ack

...
```
