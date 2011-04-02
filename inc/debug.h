#include <stdio.h>

#define ENTER
printf("%s:%d %s", __FILE__, __LINE__, __func__);

#define TRACE_INFO(str)
printf("%s:%d %s", __FILE__, __LINE__, str);



