#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child Process before exec. PID: %d, Parent PID: %d\n", getpid(), getppid());
        execl("/bin/ls", "ls", "-l", (char *)NULL);
        perror("execl failed");
    } else {
        printf("Parent Process. PID: %d, Child PID: %d\n", getpid(), pid);
    }

    return 0;
}

