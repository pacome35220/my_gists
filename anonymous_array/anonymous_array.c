#include "sys/socket.h"

int main()
{

  // int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
  // const void *optval is the parameter that interest us.

  // Using a variable;
  int hello_i_m_useless = 123;
  
  setsockopt(0, SOL_SOCKET, SO_REUSEADDR, &hello_i_m_useless, sizeof(int));
  // Using anonymous array
  setsockopt(0, SOL_SOCKET, SO_REUSEADDR, (int[]){123}, sizeof(int));
  return 0;
}
