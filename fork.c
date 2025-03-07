#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid1 = fork();  // First fork call
    
    if (pid1 < 0) {
        perror("First fork failed");
        return 1;
    }

    if (pid1 == 0) {
        printf("First Child Process. PID: %d, Parent PID: %d\n", getpid(), getppid());

        pid_t pid2 = fork();  

        if (pid2 < 0) {
            perror("Second fork failed in child process");
            return 1;
        }

        if (pid2 == 0) {
        printf("Second Child Process (Grandchild). PID: %d, Parent PID: %d\n", getpid(), getppid());
        } else {

            printf("First Child after Second Fork. PID: %d, Parent PID: %d\n", getpid(), getppid());
        }
    } else {

        printf("Parent Process after First Fork. PID: %d, First Child PID: %d\n", getpid(), pid1);
    }

    return 0;
}

