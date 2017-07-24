#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[])
{
	int fd,c, res;
	struct termios oldtio,newtio;
	char buf[255];
	fd = open(argv[1], O_RDWR | O_NOCTTY ); // O_NOCTTY���ܱ�ctrl+c��ֹ
	if (fd <0) {
		perror("open"); exit(EXIT_FAILURE); 
	}
	memset(&newtio,'\0', sizeof(newtio));
	newtio.c_cflag = B38400  | CS8 | CLOCAL | CREAD;//���ò����ʣ�����λ��ʹ�ܶ�
	newtio.c_iflag = IGNPAR | ICRNL;//������żУ�飬ӳ��CR
 	newtio.c_oflag = 0;		//���ģʽΪRAWģʽ
  	newtio.c_lflag = ICANON;//����ģʽ��������
	tcflush(fd, TCIFLUSH);	//ˢ��
 	tcsetattr(fd,TCSANOW,&newtio);	//��������

 	while (1) {
  	  	res = read(fd,buf,255); 	//�Ӹ��ն˶����ݣ������/dev/tty������ǰ�նˣ�����CR����
 	   	buf[res]=0;           //���һ������Ϊ������
  	  	printf(":recv %d bytes:%s\n\r", res,buf);	//��ӡ����ַ���
    	if (buf[0]=='E')		//ֻ�е�һ���ַ�ΪEʱ���Ž��� 
		break;
 	}
	tcsetattr(fd,TCSANOW,&oldtio);
}
