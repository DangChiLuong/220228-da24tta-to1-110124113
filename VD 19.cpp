#include <stdio.h>
int Tinh_Tong (int n);
int Tinh_Tong_So_Le (int n);
bool Kiem_Tra_So_Nguyen_To(int x);
int main()
{
	int n;
	do 
	{
		printf ("Nhap so nguyen duong n (100 <= n < 10000):" );
		scanf ("%d",&n);
	} while (100 >= n || n > 10000 );
	//Tinh Tong cac so nguyen duong
	printf ("\nTong cac so nguyen duong la: %d",Tinh_Tong(n));
	printf ("\n");
	printf ("\nTong cac so nguyen duong le la: %d",Tinh_Tong_So_Le(n));
	
	
	return 0;
}
int Tinh_Tong (int n)
{
	int s = 0;
	while (n>0)
	{
		s = s + n % 10;
		n /= 10;
	}
	return s;
}
int Tinh_Tong_So_Le (int n)
{
	int s = 0;
	while (n>0)
	{
		if ((n % 10) % 2 != 0)
			s = s + n % 10;
		n /= 10;
	}
	return s;
}
bool Kiem_Tra_So_Nguyen_To(int x) 
{
    if (x <= 1) 
	{
        return false;  
    }
    for (int i = 2; i * i <= x; i++) 
	{
        if (x % i == 0) 
		{
            return false;  
        }
    }
    return true;  
}
