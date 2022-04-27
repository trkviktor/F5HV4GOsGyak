#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 41234L
#define PERM 00666

main( ) {
int 	id; /* A szemafor azonosítója */
 
	if ((id = semget(KEY, 1, 0)) < 0) { /* Még nem létezik. */
		if ((id = semget(KEY, 1, PERM | IPC_CREAT)) < 0) {
		 	perror(" A szemafor nem nyitható meg. ");
			exit(-1);
		}
	}
	else    {
		perror(" Már létezik a szemafor. ");
		exit(0);
	}

	if (semctl(id, 0, SETVAL, 1) < 0) {
		perror(" Nem lehetett inicializálni. ");
	} else {
		puts(" Kész és inicializált a szemafor. ");
	}

	exit(0);
}
