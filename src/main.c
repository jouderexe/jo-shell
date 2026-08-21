#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

//will do the built in command after

int main() {
    char buff[1024];

    char delimiter[] = " \t\n";

    signal(SIGINT, SIG_IGN);

    char *username = getlogin();

    char hostname[1024];
    gethostname(hostname, 1024);

    char *argument_vector[128];
    int argument_counter;

    while(1) {
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

        if (strcmp(argument_vector[0], "exit") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid == 0) {
            execvp(argument_vector[0], argument_vector);

            perror("execvp");
            return 1;
        }

        else if (pid > 0) {
            waitpid(pid, NULL, 0);
        }

        else {
            perror("fork");
        }
    }

    return 0;
}