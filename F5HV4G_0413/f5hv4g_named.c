#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;

    // FIFO file path
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);

    char arr1[80], arr2[80];
   
        // Open FIFO for write only
        fd = open(myfifo, O_RDWR);

		strcpy(arr2,"fifo uzenet\0");
		printf("irok a fifoba: %s:%d\n",arr2,strlen(arr2));

        write(fd, arr2, strlen(arr2)+1);

        // Open FIFO for Read only
       // fd = open(myfifo, O_RDONLY);

        // Read from FIFO
        read(fd, arr1, sizeof(arr1));

        // Print the read message
        printf("Fifobol olvasok: %s\n", arr1);
        close(fd);
    
    return 0;
}