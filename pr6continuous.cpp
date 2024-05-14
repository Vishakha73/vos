#include<stdio.h> 
#include<conio.h> 
int main() 
{ 
    int n, i, j, b[20], t[20], c[20][20], nextBlock = 0;

    printf("Enter number of files: "); 
    scanf("%d", &n); 

    for (i = 0; i < n; i++) 
    { 
        printf("Enter number of blocks occupied by file %d: ", i + 1); 
        scanf("%d", &b[i]); 

        t[i] = nextBlock;
        for (j = 0; j < b[i]; j++) 
            c[i][j] = nextBlock++;

    } 

    printf("Filename\tStart block\tLength\n"); 
    for (i = 0; i < n; i++) 
        printf("%d\t\t%d\t\t%d\n", i + 1, t[i], b[i]); 

    int x;
    printf("\nEnter file number to display details: "); 
    scanf("%d", &x); 

    printf("File name is: %d\n", x); 
    printf("Length is: %d\n", b[x - 1]); 
    printf("Blocks occupied: "); 
    for (i = 0; i < b[x - 1]; i++) 
        printf("%4d", c[x - 1][i]); 

    getch(); 
    return 0;
}

