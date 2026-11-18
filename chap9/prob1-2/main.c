#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // fork(), getpid() 사용을 위해 필수!
#include <sys/types.h>  // pid_t 타입 사용을 위해 필수!

int main() {
    pid_t pid;
    
    pid = fork();
    
    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if (pid == 0) {
        // 자식 프로세스 영역
        printf("[Child] : Hello, world pid=%d\n", getpid());
    } else {
        // 부모 프로세스 영역
        printf("[Parent] : Hello, world pid=%d\n", getpid());
    }
    
    return 0;
}


