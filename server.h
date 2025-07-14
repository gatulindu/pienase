#ifndef SERVER_H
#define SERVER_H

#define BUFFER_SIZE 4096
#define PORT 8080

void error_exit(const char *msg);
char* read_html_file(const char *filename, long *filesize);
int create_server_socket(int port);
void handle_client(int client_fd, const char *html, long filesize);

#endif
