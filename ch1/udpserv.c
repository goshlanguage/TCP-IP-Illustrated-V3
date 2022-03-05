#include "cliserv.h"

int
main()
{
  struct sockaddr_in serv, cli;
  char request[REQUEST];
  char reply[REPLY] = "ack";
  int sockfd, n;
  socklen_t clilen;

  if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
    printf("socket error\n");

  memset(&serv, 0, sizeof(serv));
  serv.sin_family = AF_INET;
  serv.sin_addr.s_addr = htonl(INADDR_ANY);
  serv.sin_port = htons(UDP_SERV_PORT);

  if (bind(sockfd, (SA) &serv, sizeof(serv)) < 0)
    printf("bind error\n");

  for (;;) {
    clilen = sizeof(cli);

    if ((n = recvfrom(sockfd, request, REQUEST, 0, (SA) &cli, &clilen)) < 0)
      printf("recvfrom error\n");

    if (n > 0)
    {
      // process n bytes of request[] and create a reply[]

      printf("received: %s\n", request);
    }

    if (sendto(sockfd, reply, REPLY, 0, (SA) &cli, sizeof(cli)) != REPLY)
    {
      printf("sendto error\n");
    } else {
      printf("sent: %s\n", reply);
    }
  }
}
