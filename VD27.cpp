#include <stdio.h>
int main ()
{
	FILE *fp;
	char path[50];
	printf ("\nNhap duong dan: ");
	fflush (stdin);
	gets (path);
	fp = fopen (path , "wt");
	if (fp == NULL)
	{
		printf ("\nLoi o file");
		
	}
	else
	{
		fprintf (fp, "HOC PHAI DI DOI VOI HANH");
		fclose (fp);
	}
}
