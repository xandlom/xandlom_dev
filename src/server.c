#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <nanomsg/nn.h>
#include <nanomsg/pipeline.h>

#include "debug.h"

#define NODE0 "node0"
#define NODE1 "node1"

int node0 (const char *url)
{
    ENTER;
  int sock = nn_socket (AF_SP, NN_PULL);
  int recvMsgCounter = 0;
  assert (sock >= 0);
  assert (nn_bind (sock, url) >= 0);
  while (1)
    {
      char *buf = NULL;
      int bytes = nn_recv (sock, &buf, NN_MSG, 0);
      assert (bytes >= 0);
      recvMsgCounter++;
      printf ("NODE0: %d RECEIVED \"%s\"\n", recvMsgCounter, buf);
      nn_freemsg (buf);
    }
}

int node1 (const char *url, const char *msg)
{
    ENTER;
  int sz_msg = strlen (msg) + 1; // '\0' too
  int sock = nn_socket (AF_SP, NN_PUSH);
  assert (sock >= 0);
  assert (nn_connect (sock, url) >= 0);
  for (int i = 0; i < 1000000; i++)
  {
    printf ("NODE1: SENDING \"%s\"\n", msg);
    int bytes = nn_send (sock, msg, sz_msg, 0);
    assert (bytes == sz_msg);
  }
  return nn_shutdown (sock, 0);
}

int main (const int argc, const char **argv)
{
    ENTER;
  if ((argc > 1) && (strncmp (NODE0, argv[1], strlen (NODE0)) == 0))
    return node0 (argv[2]);
  else if ((argc > 2) && (strncmp (NODE1, argv[1], strlen (NODE1)) == 0))
    return node1 (argv[2], argv[3]);
  else
    {
      fprintf (stderr, "Usage: pipeline %s|%s <URL> <ARG> ...'\n",
               NODE0, NODE1);
      return 1;
    }
}
