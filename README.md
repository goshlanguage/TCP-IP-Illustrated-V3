# TCP/IP

This collection is an accompaniment to [_TCP/IP Illustrated_ by W. Richard Stevens](https://www.amazon.com/TCP-Illustrated-Transactions-Addison-Wesley-Professional/dp/0201634953/ref=sr_1_6?keywords=tcp+ip+illustrated&qid=1646433338&s=books&sprefix=tcp+ip+ill%2Cstripbooks%2C112&sr=1-6).

It is written on OS X, which influences syscall function arguments. These are documented where possible, however if you run into an issue in compilation, note this, and look at your local manual, `man`, and consult the `manpage` for the syscall(s) that fail to compile. For instance, if you run into an issue with say `socketpair`, run `man 2 socketpair` for your specific system's system call function signature.

There are also implementations in `go` for select components.

TOC

|Chapter|Link|
|-|-|
|1|[./ch1](./ch1/README.md)|
|||
