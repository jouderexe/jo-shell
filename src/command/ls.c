#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv)
{
    char *path = ".";
    struct dirent *entry;
    DIR *directory;

    if (argc > 2) {
        printf("error : too much argument\n");
        printf("use : ls \"directory\"\n");
        return 1;
    }

    if (argc > 1) {
        path = argv[1];
    }

    directory = opendir(path);

    if (directory == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(directory)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    if(closedir(directory) == -1) {
        printf("error : could not close directory");
        return 1;
    } 

    return 0;
}