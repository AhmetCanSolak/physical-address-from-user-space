/* This code is written for reading physical memory address on linux distributions */ 

#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main()
{
    size_t STRUCT_PAGE_SIZE = getpagesize();

    int num = 1;
    int fd;
    int *addr;

    if ((fd = open("/dev/mem", O_RDWR|O_SYNC)) < 0 )
    {
        printf("Error while opening the file. \n");
        close(fd);
        return 1;
    }

    addr = (int *)mmap(0, num*STRUCT_PAGE_SIZE, PROT_READ, MAP_PRIVATE, fd, 0x0000620000000000);

    printf("addr: %p \n",addr);
    printf("addr: %d \n",*addr);

    /* End of the program. */

    return 0;
}
