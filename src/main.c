#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//will continue later

int main() {
    int running = 1;
    char buff[1024];

    signal(SIGINT, SIG_IGN);

    char *username = getlogin();

    char hostname[1024];
    gethostname(hostname, 1024);

    while(running) {
        printf("%s@%s -> ", username, hostname);
        fgets(buff, sizeof(buff), stdin);
        printf("%s", buff); // just for testing
    }

    return 0;
}