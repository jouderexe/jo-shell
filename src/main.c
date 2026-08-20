#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

//will continue later

int main() {
    int running = 1;
    char buff[1024];

    char delimiter[] = " \t\n";

    signal(SIGINT, SIG_IGN);

    char *username = getlogin();

    char hostname[1024];
    gethostname(hostname, 1024);

    char *argument_vector[128];
    int argument_counter;

    while(running) {
        printf("%s@%s -> ", username, hostname);
        fflush(stdout);

        if (fgets(buff, sizeof(buff), stdin) == NULL) {
            printf("\nexit\n");
            break;
        }

        buff[strcspn(buff, "\n")] = 0;

        if (strlen(buff) == 0) {
            continue;
        }

        char *token = strtok(buff, delimiter);

        argument_counter = 0;

        while (token != NULL) {
            argument_vector[argument_counter] = token;
            argument_counter++;
            token = strtok(NULL, delimiter);
        }
        argument_vector[argument_counter] = NULL;    
    }

    return 0;
}