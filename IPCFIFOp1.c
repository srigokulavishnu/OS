#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FIFO_NAME "/tmp/my_fifo"

int main() {
    int fifo;
    char read_msg[100];


    fifo = open(FIFO_NAME, O_RDONLY);
    if (fifo == -1) {
        perror("FIFO open failed");
        return 1;
    }

    read(fifo, read_msg, sizeof(read_msg));
    printf("Child received: %s\n", read_msg);
    close(fifo);

   
    unlink(FIFO_NAME);

    return 0;
}
