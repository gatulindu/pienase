#include <stdio.h>
#include <stdlib.h>
#include "server.h"

char* read_html_file(const char *filename, long *filesize) {
    FILE *fp = fopen(filename, "r");
    if (!fp) error_exit("Error opening HTML file");

    fseek(fp, 0, SEEK_END);
    *filesize = ftell(fp);
    rewind(fp);

    char *content = malloc(*filesize + 1);
    if (!content) error_exit("Memory allocation failed");

    fread(content, 1, *filesize, fp);
    content[*filesize] = '\0';
    fclose(fp);

    return content;
}
