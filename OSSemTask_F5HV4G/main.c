#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define FIFO_NAME "Fifo"

void gcdCalc(int array[], int size);

int main(void)
{
    char buf[256];
    int num, fd;
    pid_t pid;

    

    if (mkfifo(FIFO_NAME, 0666) < 0)
        perror("mkfifo");

    pid = fork();
    if (pid == 0)
    {
        printf("child - waiting for readers...\n");
        if ((fd = open(FIFO_NAME, O_WRONLY)) < 0)
            perror("child - open");
        
        printf("child - got a reader\n");

        FILE *fp;
        fp = fopen("numbers.txt", "r");
        fscanf(fp, "%d", buf);
        int nmbCnt = buf[0];

        for (size_t i = 0; i < nmbCnt; i++)
        {
            fscanf(fp, "%d", buf);
            if(num = write(fd, buf, sizeof(buf[0])) < 0)
                perror("Child write error");
            /* else
                printf("Child wrote %d \n",buf[0]); */
        }
        

        close(fd);
        exit(0);
    }
    else
    {
        printf("parent - waiting for writers...\n");
        if ((fd = open(FIFO_NAME, O_RDONLY)) < 0)
            perror("parent - open");
        
        printf("parent - got a writer\n");
        int ReadArray[256];
        int db = 0;
        do
        {
            if ((num = read(fd, buf, sizeof(buf[0]))) <= 0)
                perror("parent - read");
            else
            {
                //printf("Parent read:  %d \n",buf[0]);
                ReadArray[db] = buf[0];
                db++;
            }
        } while (num > 0);

        int FinalArray[db];

        for (size_t i = 0; i < db; i++)
            FinalArray[i] = ReadArray[i];
        
        gcdCalc(FinalArray, db);


        read(fd, buf, sizeof(buf));
        close(fd);
        wait(0);
    }

    unlink(FIFO_NAME);
    return 0;
}

void gcdCalc(int array[], int size)
{
    int gcd;

    for (size_t i = 0; i < size; i+=2)
    {
        gcd = 0;
        for(size_t j = 1; j <= array[i] && j <= array[i+1]; j++)
        {
            if(array[i]%j==0 && array[i+1]%j==0)
                gcd = j;
        }

        printf("\nG.C.D of %d and %d is %d", array[i], array[i+1], gcd);
        }
}