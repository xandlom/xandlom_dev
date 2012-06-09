#include <stdio.h>
#include "debug.h"

int main(int argc, char* argv[])
{
  ENTER(__func__);

  TRACE_INFO("Hello");
  TRACE_ERROR("Hello");

  return 0;
}
