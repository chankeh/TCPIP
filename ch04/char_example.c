#include<stdio.h>
int main(int argc,char *argv[])
{
    FILE *fp=NULL;
    char ch;
    if(argc<=1)
    {
        printf("check usage of %s \n",argv[0]);
        return -1;
    }
if((fp=fopen(argv[1],"r"))==NULL)			//��ֻ����ʽ��argv[1]��ָ�����ļ�
    {
        printf("can not open %s\n",argv[1]);
        return -1;
    }
    while ((ch=fgetc(fp))!=EOF)			//���Ѵ򿪵��ļ��е��������ֽڵ��������׼���stdout
        fputc(ch,stdout);
    fclose(fp);						//�ر��ļ�
    return 0;
}
