#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // 1. fork 전(또는 부모 프로세스 영역에서) 부모의 PID와 GID 출력
    // (문제 6-2 슬라이드 결과 화면 참고)
    
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if (pid == 0) {
        // 2. 자식 프로세스 영역
        setpgid(0, 0); // 새로운 프로세스 그룹 생성 및 설정
        printf("CHILD: PID = %d  GID = %d\n", getpid(), getpgrp());
    } else {
        // 3. 부모 프로세스 영역
        printf("PARENT: PID = %d  GID = %d\n", getpid(), getpgrp());
    }

    return 0;
}
