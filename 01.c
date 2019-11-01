//TellFileReWrPos.c
#include <stdio.h.>
#pragma error(disable: 4996)

int main()
{
	long fpos;
	int i;

	/*Creat File */
	FILE * fp = fopen("text.txt", "wt");
	fputs("1234-", fp);
	fclose(fp);

	/*File open */
	fp = open("text.txt", "rt");

	for (i = 0; i < 4; i++)
	{
		putchar(fgetc(fp));
		fpos = ftell(fp); // 현재의 파일 위치 지시자 정보를 변수 fpos에 저장 하고있다. 이로써 파일 위치 지시자를 어디로 이동시키건 다시 이전 위치로 되 돌릴 수 있게 됨.
		fseek(fp, -1, SEEK_END);
		putchar(fgetc(fp));
		fseek(fp, fpos, SEEK_SET);// 19행에서 저장해 놓은 정보를 참조하여 파일 위치 지시자를 이전의 위치로 되 돌리고 있다. 
	}
	fclose(fp);
	return 0;
}