//#define _LARGEFILE_SOURCE
#define _LARGEFILE64_SOURCE
#define _FILE_OFFSET_BITS 64


#include<stdio.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
 
int main(int argc,char *argv[]) 
{ 
       int fd_src,fd_des; 
       char buf[128000]; 
       int num; 
       if(argc!=3)							//����ʱ���������Դ�ļ���Ŀ���ļ� 
        { 
                printf("the format must be:cp file_src file_des"); 
                exit(EXIT_FAILURE); 
        } 
       if((fd_src=open(argv[1],O_RDONLY))==-1)	//�Զ���ʽ��Դ�ļ� 
        { 
                perror("open1"); 
                exit(EXIT_FAILURE); 
        } 

      if((fd_des=open(argv[2],O_CREAT|O_EXCL|O_WRONLY,0644))==-1)	 
      		//��д��Ŀ�꣬���Ŀ���ļ����ڣ������ش��� 
      {      	//fd=src=open(argv[2],O_WRONLY|O_TRUNC)	 
                perror("open2"); 
                exit(EXIT_FAILURE); 
        } 
      do 
        { 
                num=read(fd_src,buf,128000);		//�� 
                write(fd_des,buf,num);		//д 
        }while(num==128000);					//�Զ��ķ���ֵ��Ϊ�����ж� 

		struct stat mystat;
		stat(argv[1],&mystat);
		printf("the size of src_file %s is %lld\n",argv[1],mystat.st_size);
		stat(argv[2],&mystat);
		printf("the size of dst_file %s is %lld\n",argv[2],mystat.st_size);
       close(fd_src); 
       close(fd_des); 
} 
