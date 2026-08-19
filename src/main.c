#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

//will continue later

int main() {
    int running = 1;
    char buff[1024];

    signal(SIGINT, SIG_IGN);

    char *username = getlogin();

    char hostname[1024];
    gethostname(hostname, 1024);

    char argument_vector[128];
    int argument_counter;

    while(running) {
        printf("%s@%s -> ", username, hostname);

        if (fgets(buff, sizeof(buff), stdin) == NULL) {
            printf("\nexit\n");
            break;
        }

        buff[strcspn(buff, "\n")] = 0;

        printf("%s\n", buff); // just for testing
    }

    return 0;
}