#include <stdio.h>
#include <stdlib.h>



int main() {
	int system(const char *command);
	char input[10];
	int ok;

	do{
		ok = 1;
		printf("Kerek egy parancsot: ");
		scanf("%s",input);
		while(getchar()!='\n'){
		ok = 0;

		}


	}
	while(!ok);

	system(input);


		

	return 0;

}