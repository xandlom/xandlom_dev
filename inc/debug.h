#include <stdio.h>

#define ENTER printf("ENTER: %s:%d %s\n", __FILE__, __LINE__, __func__)

#define TRACE_INFO(str) printf("INFO: %s:%d %s\n", __FILE__, __LINE__, str)

#define TRACE_ERROR(str) printf("ERROR: %s:%d %s\n", __FILE__, __LINE__, str)


