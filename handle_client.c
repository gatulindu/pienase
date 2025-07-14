#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include "server.h"

void handle_client(int client_fd, const char *html, long filesize) {
    char buffer[BUFFER_SIZE];

    read(client_fd, buffer, BUFFER_SIZE - 1);

    char response[BUFFER_SIZE * 2];
    snprintf(response, sizeof(response),
             "HTTP/1.1 200 OK\r\n"
             "Content-Type: text/html\r\n"
             "Content-Length: %ld\r\n"
             "Connection: close\r\n"
             "\r\n"
             "%s", filesize, html);

    write(client_fd, response, strlen(response));
    close(client_fd);
}

