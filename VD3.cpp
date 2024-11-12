#include <stdio.h>
int main()
{
	int a,b;
	//Nhap so nguyen duong thu 1
	printf("Nhap so nguyen duong thu nhat: ");
	scanf ("%d",&a);
	//Nhap so nguyen duong thu 2
	printf("\nNhap so nguyen duong thu 2: ");
	scanf("%d",&b);
	if (a>b)
	{
		printf("so be la %d",b);
	} else 
	{
		printf("so be la %d",a);
	}
	return 0;
}
