#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_LINE 100
#define MAX_LEN 256

int main(int argc, char *argv[]) {
    int fd;
    char buf;
    int line_count = 0;
    int line_lengths[MAX_LINE];
    int line_starts[MAX_LINE];
    char input[50];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("file open");
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

    printf("Total Line : %d\n", line_count);

   
    printf("Pls 'Enter' the line to select : ");
    if (scanf("%s", input) == EOF) {
        close(fd);
        return 0;
    }

     if (strcmp(input, "*") == 0) {
       
        lseek(fd, 0, SEEK_SET);
        char line_buf[MAX_LEN];
        int i;
        for (i = 0; i < line_count; i++) {
            lseek(fd, line_starts[i], SEEK_SET);
            read(fd, line_buf, line_lengths[i]);
            line_buf[line_lengths[i]] = '\0';
            printf("%d: %s", i + 1, line_buf);
        }
    } else if (strchr(input, '-') != NULL) {
        
        int start, end;
        sscanf(input, "%d-%d", &start, &end);
        char line_buf[MAX_LEN];
        int i;
        for (i = start; i <= end && i <= line_count; i++) {
            lseek(fd, line_starts[i - 1], SEEK_SET);
            read(fd, line_buf, line_lengths[i - 1]);
            line_buf[line_lengths[i - 1]] = '\0';
            printf("%d: %s", i, line_buf);
        }
    } else if (strchr(input, ',') != NULL) {
        
        char *token = strtok(input, ",");
        char line_buf[MAX_LEN];
        while (token != NULL) {
            int l_num = atoi(token);
            if (l_num > 0 && l_num <= line_count) {
                lseek(fd, line_starts[l_num - 1], SEEK_SET);
                read(fd, line_buf, line_lengths[l_num - 1]);
                line_buf[line_lengths[l_num - 1]] = '\0';
                printf("%d: %s", l_num, line_buf);
            }
            token = strtok(NULL, ",");
        }
    } else {
        
        int l_num = atoi(input);
        if (l_num > 0 && l_num <= line_count) {
            char line_buf[MAX_LEN];
            lseek(fd, line_starts[l_num - 1], SEEK_SET);
            read(fd, line_buf, line_lengths[l_num - 1]);
            line_buf[line_lengths[l_num - 1]] = '\0';
            printf("%d: %s", l_num, line_buf);
        }
    }

    close(fd);
    return 0;
}
