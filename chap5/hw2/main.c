#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE 100
#define MAX_LEN 256

int main(int argc, char *argv[]) {
    int fd;
    char buf;
    int line_count = 0;
    int line_lengths[MAX_LINE];
    int line_starts[MAX_LINE];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("file erro");
        exit(1);
    }

    line_starts[0] = 0;
    int current_len = 0;
    int cur_pos = 0;

    while (read(fd, &buf, 1) > 0) {
        current_len++;
        if (buf == '\n') {
            line_lengths[line_count] = current_len;
            line_count++;
            line_starts[line_count] = cur_pos + 1;
            current_len = 0;
        }
        cur_pos++;
    }
    if (current_len > 0) {
        line_lengths[line_count] = current_len;
        line_count++;
    }

   
    char line_buf[MAX_LEN];
    for (int i = line_count - 1; i >= 0; i--) {
        lseek(fd, line_starts[i], SEEK_SET);
        read(fd, line_buf, line_lengths[i]);
        line_buf[line_lengths[i]] = '\0';
        printf("%s", line_buf);
    }

    close(fd);
    return 0;
}
