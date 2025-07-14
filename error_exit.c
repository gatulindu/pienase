#include <stdio.h>
#include <stdlib.h>
#include "server.h"

void error_exit(const char *msg) {
    perror(msg);
    exit(1);
}
