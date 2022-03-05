#include "cliserv.h"

int
main(int argc, char *argv[])
{
  // see more about the sockaddr_in struct in the ip man page:
  // https://man7.org/linux/man-pages/man7/ip.7.html
  struct sockaddr_in serv;
  char reply[REPLY];
  int sockfd, n;
  ssize_t sent;

  if (argc != 2)
  {
    printf("usage: updcli <IP address of server>\n");
    exit(-1);
  }

  if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
    printf("socket error\n");

  printf("sockfd declared: %d\n", sockfd);

  // osx variant of memset
  memset(&serv, 0, sizeof(serv));
  serv.sin_family = AF_INET;
  serv.sin_addr.s_addr = inet_addr(argv[1]);
  serv.sin_port = htons(UDP_SERV_PORT);

  // form request[] ...
  char request[REQUEST] = "syn";

  if ((sent = sendto(sockfd, request, REQUEST, 0, (SA) &serv, sizeof(serv))) != REQUEST)
    printf("sendto error\n");

  printf("Sent: %s\n", request);

  if ((n = recvfrom(sockfd, reply, REPLY, 0, (SA) NULL, NULL)) < 0)
    printf("recvfrom error\n");

  // process "n" bytes of the reply
  printf("Received: %s\n", reply);
  exit(0);
}
