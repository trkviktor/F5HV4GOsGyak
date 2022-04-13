#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void do_nothing();

int main(void) {
    printf("PID = %d\n",getpid());
    signal(SIGALRM, do_nothing);
    printf("waiting\n");
    pause();
    printf("Got the signal\n");
}

void do_nothing(){
    printf("do_nothing() is running\n");
}