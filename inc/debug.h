#include <stdio.h>

#define ENTER printf("%s:%d %s\n", __FILE__, __LINE__, __func__);

#define TRACE_INFO(str) printf("I: %s:%d %s\n", __FILE__, __LINE__, str);

#define TRACE_ERROR(str) printf("E: %s:%d %s\n", __FILE__, __LINE__, str);


