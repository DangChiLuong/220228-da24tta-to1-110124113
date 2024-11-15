#include <stdio.h>
int main()
{
	int a,b,c,DT;
	//Nhap so luong hang 
	printf ("So luong hang la: ");
	scanf ("%d",&a);
	//Nhap don gia
	printf ("\nDon gia: ");
	scanf ("%d",&b);
	//Chi phi van chuyen
	printf ("\nChi phi van chuyen: ");
	scanf ("%d",&c);
	//Tinh Doanh Thu
	DT= a * b - c;
	//In ket qua
	printf("\nDoanh thu cua Cty la: %d",DT);
	return 0;
}
