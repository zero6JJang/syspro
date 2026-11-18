#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
// 1. system() 함수 직접 구현
int my_system(const char *cmdstring) {
    pid_t pid;
    int status;

    if (cmdstring == NULL)
        return 1;

    pid = fork();
    if (pid < 0) {
        return -1; // fork 실패
    } else if (pid == 0) {
        // 자식 프로세스에서 명령어 실행 (/bin/sh를 이용해 명령 문자열 실행)
        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127); // execl 실패 시 종료
    } else {
        // 부모 프로세스: 자식의 종료를 기다림
        while (waitpid(pid, &status, 0) < 0) {
            if (errno != EINTR) {
                status = -1;
                break;
            }
        }
    }
    return status;
}

int main() {
    int status;

    printf("[Parent] Starting system() test with 'date' command...\n");

    // 2. date 명령어를 파라미터로 하여 system() 함수 호출 및 status에 반환값 할당
    status = my_system("date");

    // 3. 반환 및 오류 처리 확인
    if (status < 0) {
        perror("my_system failed");
        return 1;
    }

    // 4. 결과 확인 (정상 종료 시 WEXITSTATUS 등을 통해 반환 코드 확인 가능)
    printf("[Parent] system() return status: %d\n", status);

    return 0;
}
