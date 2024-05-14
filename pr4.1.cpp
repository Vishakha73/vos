#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main() {
    int fd_in, fd_out;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Open file1.txt for reading
    fd_in = open("file1.txt", O_RDONLY);
    if (fd_in == -1) {
        perror("Failed to open file1.txt");
        exit(EXIT_FAILURE);
    }

    // Open or create file2.txt for writing
    fd_out = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd_out == -1) {
        perror("Failed to open or create file2.txt");
        close(fd_in);
        exit(EXIT_FAILURE);
    }

    // Copy content from file1 to file2
    while ((bytes_read = read(fd_in, buffer, BUFFER_SIZE)) > 0) {
        if (write(fd_out, buffer, bytes_read) != bytes_read) {
            perror("Write error");
            close(fd_in);
            close(fd_out);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Read error");
        close(fd_in);
        close(fd_out);
        exit(EXIT_FAILURE);
    }

    // Close file descriptors
    close(fd_in);
    close(fd_out);

    printf("Content from file1.txt has been copied to file2.txt\n");

    return 0;
}
