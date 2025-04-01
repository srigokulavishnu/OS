#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FIFO_NAME "/tmp/my_fifo"

int main() {
    int fifo;
    char write_msg[] = "Hello from Parent Process via FIFO!";

    // Create a FIFO special file
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo failed");
        return 1;
    }

    // Open the FIFO for writing
    fifo = open(FIFO_NAME, O_WRONLY);
    if (fifo == -1) {
        perror("FIFO open failed");
        return 1;
    }

    write(fifo, write_msg, strlen(write_msg) + 1);
    close(fifo);

    return 0;
}
