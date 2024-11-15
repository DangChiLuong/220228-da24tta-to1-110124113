#include <stdio.h>
int main()
{ 
	int n,S;
	//Nhap so nguyen duong n
	do
	{
		printf ("Nhap so nguyen duong n: ");
		scanf ("%d",&n);
	} while (n<0);
	//Tinh tong cac chu so co trong n
    while (n > 0) 
	{
         S = S + n % 10;  
         n = n / 10;       
    }
	//In ket qua
    printf("\nTong cac so la: %d",S);
    return 0;
}



