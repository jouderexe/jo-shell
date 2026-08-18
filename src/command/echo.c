#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("error : there is no text\n");
        printf("use : echo \"text\"\n");
        return 1;
    }

    int i = 1;
    
    while(i != argc) {
        printf("%s", argv[i]);
        
        if(i < argc-1) {
            printf(" ");
        }
        i++;
    }

    printf("\n");

    return 0;
}