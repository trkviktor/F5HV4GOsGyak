#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int i){
    printf("Handling of signal: %d\n",i);


    while(1){
        sleep(3);
    }

    return;
}

int main(void){
    signal(SIGTERM, &handler);
}