#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pid_t fork(void);

#include <sys/types.h>
#include <sys/wait.h>


int main(void){
	
	pid_t pid;
	int status;

	if((pid = fork()) < 0) perror("fork hiba");
		else if(pid == 0)
			exit(7);
	if(wait(&status) != pid) perror("wait hiba");
	if(WIFEXITED(status))
		printf("Normalis befejezodes, visszaadott ertek = %d\n",WEXITSTATUS(status));

	
	if((pid = fork()) < 0 ) perror("fork hiba");
		else if(pid == 0)
			abort();

	if(wait(&status) != pid)perror("wait hiba");
	if(WIFSIGNALED(status))
		printf("Abnormalis befejezodes,a szignal sorszama = %d\n",WTERMSIG(status));

	if((pid = fork()) < 0) perror("fork hiba");
		else if(pid == 0)
			status /= 0;

	if(wait(&status) != pid) perror("wait hiba");
	if(WIFSIGNALED(status))
		printf("Visszateresi ertek = %d\n",WEXITSTATUS(status));
			




	exit(0);
}

void pr_exit(int status)
{
	if (WIFEXITED(status))
		printf("Normalis befejezodes, visszaadott ertek = %d\n",WEXITSTATUS(status));
	else
	if (WIFSIGNALED(status))
		printf("Abnormalis befejezodes, a szignal sorszama = %d\n",WTERMSIG(status));
}