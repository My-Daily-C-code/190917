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
		fpos = ftell(fp); // ������ ���� ��ġ ������ ������ ���� fpos�� ���� �ϰ��ִ�. �̷ν� ���� ��ġ �����ڸ� ���� �̵���Ű�� �ٽ� ���� ��ġ�� �� ���� �� �ְ� ��.
		fseek(fp, -1, SEEK_END);
		putchar(fgetc(fp));
		fseek(fp, fpos, SEEK_SET);// 19�࿡�� ������ ���� ������ �����Ͽ� ���� ��ġ �����ڸ� ������ ��ġ�� �� ������ �ִ�. 
	}
	fclose(fp);
	return 0;
}