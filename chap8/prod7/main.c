#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

extern char **environ;

void print_help(const char *prog_name) {
    fprintf(stderr, "Usage: %s [option] [argument]\n", prog_name);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "  -e [name] : Print environment variable(s)\n");
    fprintf(stderr, "  -u        : Print real and effective user ID\n");
    fprintf(stderr, "  -g        : Print real and effective group ID\n");
    fprintf(stderr, "  -i        : Print process ID\n");
    fprintf(stderr, "  -p        : Print parent process ID\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help(argv[0]);
        return 1;
    }

    char *option = argv[1];

    if (strcmp(option, "-e") == 0) {
        // -e 옵션: 환경변수 출력 (이름이 주어진 경우와 전체 출력)
        if (argc >= 3) {
            char *val = getenv(argv[2]);
            if (val != NULL) {
                printf("%s=%s\n", argv[2], val);
            } else {
                printf("Environment variable '%s' not found.\n", argv[2]);
            }
        } else {
            for (char **env = environ; *env != 0; env++) {
                printf("%s\n", *env);
            }
        }
    } 
    else if (strcmp(option, "-u") == 0) {
        // -u 옵션: 실제 사용자 ID (UID) 및 유효 사용자 ID (EUID)
        printf("My Realistic User ID : %d\n", getuid());
        printf("My Valid User ID : %d\n", geteuid());
    } 
    else if (strcmp(option, "-g") == 0) {
        // -g 옵션: 실제 그룹 ID (GID) 및 유효 그룹 ID (EGID)
        printf("My Realistic Group ID : %d\n", getgid());
        printf("My Valid Group ID : %d\n", getegid());
    } 
    else if (strcmp(option, "-i") == 0) {
        // -i 옵션: 프로세스 ID (PID)
        printf("my process number : [%d]\n", getpid());
    } 
    else if (strcmp(option, "-p") == 0) {
        // -p 옵션: 부모 프로세스 ID (PPID)
        printf("my parent's process number : [%d]\n", getppid());
    } 
    else {
        fprintf(stderr, "Unknown option: %s\n", option);
        print_help(argv[0]);
        return 1;
    }

    return 0;
}
