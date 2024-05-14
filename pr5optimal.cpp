#include <stdio.h>
#include <stdbool.h>

#define NUM_FRAMES 3 // Number of frames in the memory

int findOptimal(int pages[], int page_size, int start_index) {
    int index = -1;
    int farthest = start_index;
    for (int i = 0; i < NUM_FRAMES; i++) {
        int j;
        for (j = start_index; j < page_size; j++) {
            if (pages[j] == i) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == page_size)
            return i;
    }
    return (index == -1) ? 0 : index;
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int page_size = sizeof(pages) / sizeof(pages[0]);

    int frames[NUM_FRAMES];
    int page_faults = 0;

    for (int i = 0; i < NUM_FRAMES; i++)
        frames[i] = -1; // Initializing frames with -1 indicating empty

    for (int i = 0; i < page_size; i++) {
        bool page_found = false;
        for (int j = 0; j < NUM_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                page_found = true;
                break;
            }
        }

        if (!page_found) {
            int index = findOptimal(pages, page_size, i + 1);
            frames[index] = pages[i];
            page_faults++;
        }

        printf("Pages in frames: ");
        for (int j = 0; j < NUM_FRAMES; j++) {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", page_faults);

    return 0;
}
