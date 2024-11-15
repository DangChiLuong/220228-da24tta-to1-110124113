#include <stdio.h>
int main()
{
	int a;
	float b;
	char c;
	printf ("Nhap so nguyen: ");
	scanf ("%d",&a);
	printf ("Nhap so thuc: ");
	scanf ("%f",&b);
	printf ("Nhap ky tu: ");
	fflush (stdin);
	scanf ("%c",&c);
	printf ("Ket qua: %d\t%f\t%c",a,b,c);
	return 0;
}
