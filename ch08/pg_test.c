#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
    int fd;	
    pid_t pid;
    pid=fork();
    if(pid==-1)
	perror("fork");
    else if(pid>0)
    {
       wait(NULL);
       exit(EXIT_FAILURE);
    }
    else
    {
        if((fd=open("/dev/pts/0",O_RDWR))==-1)
        {
           perror("open");
        }
	printf("pid=%d,ppid=%d\n",getpid(),getppid());
        printf("sid=%d,tcgetsid=%d\n",getsid(getpid()),tcgetsid(fd));
        printf("tcgetpgrp=%d\n",tcgetpgrp(fd));
        printf("pigd=%d\n",getpgid(getpid()));
   }
}  

