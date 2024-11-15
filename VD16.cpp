#include <stdio.h>
int main() 
{
	int n;
	//Nhap so n
	do 
	{
		printf ("Nhap so nguyen tu 2-9: ");
		scanf("%d",&n);
	} while (n<=1||n>=10);
    for (int i = 1; i <= n; i++) 
	{
        printf("\nBang cuu chuong %d:\n", i);
        for (int j = 1; j <= 10; j++) 
		{
            printf("%d x %d = %d\n", i, j, i * j);
        }
    }
    return 0;
}

