#include <stdio.h>
#include <string.h>
#include "copy.h"

int main() {
    char lines[5][MAXLINE];
    char temp[MAXLINE];
    int count = 0;

    while (count < 5 && fgets(lines[count], MAXLINE, stdin) != NULL) {
        lines[count][strcspn(lines[count], "\n")] = '\0';
        count++;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strlen(lines[i]) < strlen(lines[j])) {
                copy(lines[i], temp);
                copy(lines[j], lines[i]);
                copy(temp, lines[j]);
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s\n", lines[i]);
    }

    return 0;
}
