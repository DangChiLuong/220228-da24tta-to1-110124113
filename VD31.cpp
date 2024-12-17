#include <stdio.h>
#define MAX 255
int main ()
{
	char path[50];
	FILE *fp;
	printf ("\nNhap duong dan: ");
	fflush (stdin);
	gets (path);
	fp = fopen (path, "at");
	if (fp == NULL)
	{
		printf ("\nLoi mo file.");
	}
	else
	{
		fprintf (fp,"\nAi nhut thi toi dung nhi");
		fprintf (fp, "\nAi ma hon nua toi thi dung ba");
		fclose(fp);
	}
	return 0;
}
