//open file try.txt with readonly mode;.on failure print "fail to open file!" then return; otherwise print "open file successfully�� then close the opened file
#include<stdio.h>
int main(int argc,char *argv[])
{
    FILE *fp=NULL;
    fp=fopen("try.txt","r"); 				//��ֻ����ʽ���ļ�try.txt
    if(fp==NULL) 					//���ɹ������"fail to open file!\n"
    {
        printf("fail to open file!\n"); 
        return -1;
    }
    printf("open file successfully!\n");
    fclose(fp); 					//�ر��Ѵ򿪵��ļ�
    return 0;
}
