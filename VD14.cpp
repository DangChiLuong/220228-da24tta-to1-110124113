#include <stdio.h>
int main()
{
	int n,s;
	//Nhap so nguyen duong n
	printf ("Nhap so nguyen duong n: ");
	scanf ("%d",&n);
	//Tong cac so tu 1 - n
	for (int i = 1;i <= n; i++)
		{
			s = s + i;
		}
	//In ket qua tong tu 1 - n
	printf ("\nKet tong cac so tu 1 - %d la: %d",n,s);
	return 0;
}
