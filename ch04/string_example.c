#include<stdio.h>
int main(int argc,char *argv[])
{
    FILE *fp=NULL;
    char str[10];
    if((fp=fopen(argv[1],"r"))==NULL) 			//��ֻ����ʽ���ļ�aa.txt
    {
        printf("can not open!\n");
        return -1;
    }
    fgets(str,sizeof(str),fp);						//�Ӵ򿪵��ļ��ж�ȡsizeof(str)���ֽڵ�str
    fputs(str,stdout);							//��str�е����������������׼���
    fclose(fp);								//�ر��Ѵ򿪵��ļ�
    return 0;
}
