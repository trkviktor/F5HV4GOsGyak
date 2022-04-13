#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int SIGINTCnt = 0;

void handleSignals(int i) {
   printf("Signal kezelese: %d\n",i);   
   if(i == 2)
       SIGINTCnt++;

   if(SIGINTCnt > 1)
        kill(getpid(), SIGKILL);

   return;
}

int main(void) {
   printf("PID = %d\n",getpid());
   printf("Signal kezelo atvetele: %d\n",signal(SIGTERM,&handleSignals));
   if(signal(SIGINT, &handleSignals)){}
   signal(SIGQUIT, &handleSignals);
   while(1)
   {
      printf("lepes\n");
      sleep(3);
   }
}