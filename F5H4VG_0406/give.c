#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int pid;

    if (argc < 1)
    {
        perror("Doesnt exist");
        exit(1);
    }

    pid = atoi(argv[1]);
    kill(pid, SIGALRM);
    kill(pid, SIGTERM);
    kill(pid, SIGKILL);
}