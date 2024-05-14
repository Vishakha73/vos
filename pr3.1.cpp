#include <stdio.h>

int main() {
    // Resource allocation flags
    int resource1_allocated = 1;
    int resource2_allocated = 1;

    // Process 1 requests resource 1
    printf("Process 1 requests resource 1\n");
    if (resource1_allocated) {
        // Process 1 holds resource 1 and requests resource 2
        printf("Process 1 holds resource 1 and requests resource 2\n");
        if (resource2_allocated) {
            // Process 2 requests resource 2
            printf("Process 2 requests resource 2\n");
            if (resource2_allocated) {
                // Process 2 holds resource 2 and requests resource 1 (Deadlock)
                printf("Process 2 holds resource 2 and requests resource 1\n");
            } else {
                printf("Process 2 is waiting for resource 2\n");
            }
        } else {
            printf("Process 1 is waiting for resource 2\n");
        }
    } else {
        printf("Process 1 is waiting for resource 1\n");
    }

    return 0;
}
