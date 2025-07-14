#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include "server.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s file.html\n", argv[0]);
        exit(1);
    }

    long filesize;
    char *html_content = read_html_file(argv[1], &filesize);
    int server_fd = create_server_socket(PORT);

    printf("Server running at http://localhost:%d/\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd < 0) error_exit("Error on accept");

        handle_client(client_fd, html_content, filesize);
    }

    free(html_content);
    close(server_fd);
    return 0;
}
