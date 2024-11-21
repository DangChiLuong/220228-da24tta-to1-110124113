#include <stdio.h>
int Tinh_Tong (int n);
int Tinh_Tong_So_Le (int n);
bool Kiem_Tra_So_Nguyen_To(int x);
int Tinh_Tong_Cac_SNT (int n);
int Dem_So_0 (int n);
int Dem_Chu_So_Chia_Het_Cho_3 (int n);
int Dem_Chu_So_Chia_Het_Cho_5 (int n);
int main()
{
	int n;
	do 
	{
		printf ("Nhap so nguyen duong n (100 <= n < 10000):" );
		scanf ("%d",&n);
	} while (100 >= n || n > 10000 );
	//Tinh Tong cac so nguyen duong
	printf ("\nTong cac so nguyen duong trong %d la: %d",n,Tinh_Tong(n));
	printf ("\n");
	//Tinh tong cac chu so le
	printf ("\nTong cac so nguyen duong le trong %d la: %d",n,Tinh_Tong_So_Le(n));
	//Tinh tong cac so le
	printf ("\n");
	printf ("\nTong cac so nguyen to trong %d la: %d",n,Tinh_Tong_Cac_SNT(n));
	//Dem chu so 0
	printf ("\n");
	printf ("\nCac chu so 0 trong %d la: %d",n,Dem_So_0(n));
	//Dem chu so chia het cho 3
	printf ("\n");
	printf ("\nCac chu so chia het cho 3 trong %d la: %d",n,Dem_Chu_So_Chia_Het_Cho_3(n));
	//Dem chu so chia het cho 5
	printf ("\n");
	printf ("\nCac chu so chia het cho 5 trong %d la: %d",n,Dem_Chu_So_Chia_Het_Cho_5(n));
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
int Tinh_Tong_Cac_SNT (int n)
{
	int s = 0;
	while (n > 0)
	{
		int x = n % 10;
		if (Kiem_Tra_So_Nguyen_To(x))
			s = s + x;
		n = n / 10;
	}
	return s;
}
int Dem_So_0 (int n) 
{
	 int dem = 0;
    while (n > 0) 
	{
        if (n % 10 == 0) 
		{
            dem++;
		}
        n = n / 10;
    }
	return dem;
}
int Dem_Chu_So_Chia_Het_Cho_3 (int n)
{
	int dem = 0;
    while (n > 0) 
	{
        int i = n % 10;
        if (i % 3 == 0) 
		{
            dem++;
        }
        n = n / 10;
    }
    return dem;
}
int Dem_Chu_So_Chia_Het_Cho_5 (int n)
{
	int dem = 0;
    while (n > 0) 
	{
        int i = n % 10;
        if (i % 5 == 0) 
		{
            dem++;
        }
        n = n / 10;
    }
    return dem;
}

