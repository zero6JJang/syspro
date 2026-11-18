#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // 1. 부모 프로세스의 PID와 GID 출력
    // (처음 실행 시에는 부모의 PID와 GID가 동일하게 출력됩니다)
    
    // 2. fork() 함수를 이용해 자식 프로세스 생성 및 pid에 값 할당
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if (pid == 0) {
        // 3. 자식 프로세스 영역
        // setpgid(0, 0)을 호출하여 자식 프로세스를 새로운 프로세스 그룹의 리더로 만듦
        // (인자가 0, 0이면 자신의 PID를 그룹 ID로 하는 새로운 그룹 생성)
        setpgid(0, 0);

        // 자식 프로세스의 PID와 변경된 그룹 ID(GID) 출력
        printf("CHILD: PID = %d GID = %d\n", getpid(), getpgrp());
    } else {
        // 부모 프로세스 영역
        // 부모 프로세스의 PID와 그룹 ID(GID) 출력
        printf("PARENT: PID = %d GID = %d\n", getpid(), getpgrp());
    }

    return 0;
}
