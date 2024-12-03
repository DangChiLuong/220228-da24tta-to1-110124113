#include <stdio.h>
#include <stdlib.h>
void Nhap_GT (int *A, int n);
void Xuat_GT (int *A, int n);
int Tinh_Tong(int *A, int n);
int Tim_Max (int *A, int n);
int Dem_Max (int *A, int n);
int Dem_x (int *A, int n, int x);
int KT_Co_Ton_Tai_So_Duong (int *A, int n);
void Sap_Tang (int *A, int n);
void Loc_So_Am (int *A, int n);
int main ()
{
	int *A, n, x;
	//Nhap so phan tu
	do
	{
		printf("\nNhap so luong phan tu (n < 50): ");
		scanf ("%d",&n);
	} while (n <=0 || n >= 50);  
	//Cap phat vung nho dong
	A = (int *)malloc (n * sizeof (int));
	//Nhap gia tri
	Nhap_GT(A, n);
	//Xuat gia tri
	Xuat_GT(A, n);
	//Tinh tong
	printf ("\n\nTong cac gia tri la: %d",Tinh_Tong(A, n));
	//Tim Max
	printf ("\n\nGia tri lon nhat la: %d",Tim_Max(A, n));
	//Dem gia tri max
	printf ("\n\nGia tri lon nhat xuat hien %d lan",Dem_Max(A, n));
	//Dem gia tri X
	printf ("\n\nNhap gia tri X can tim: ");
	scanf ("%d",&x);
	printf ("\n\nGia tri %d xuat hien %d lan.",x, Dem_x(A,n,x));
	//KT so duong
	if (KT_Co_Ton_Tai_So_Duong(A,n) > 0)
	{
		printf ("\n\nTrong mang co ton tai so duong.");
	}
	if (KT_Co_Ton_Tai_So_Duong(A,n) == 0)
	{
		printf ("\n\nTrong mang khong ton tai so duong.");
	}
	//Sap tang
	Sap_Tang(A, n);
	Xuat_GT(A, n);
	//Loc so am
	Loc_So_Am(A, n);
	return 0;
}
void Nhap_GT (int *A, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf ("\n\nNhap gia tri so nguyen thu %d: ",i + 1);
		scanf ("%d",&A[i]);
	}
}
void Xuat_GT (int *A, int n)
{
	for ( int i = 0; i < n; i++)
	{
		printf ("\n\nGia tri thu %d la: ",i + 1);
		printf ("%d",A[i]);
	}
}
int Tinh_Tong(int *A, int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s = s + A[i];
	}
	return s;
}
int Tim_Max (int *A, int n)
{ 	
	int Max = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] > Max)
		{
			Max = A[i];
		}
	}
	return Max;
}
int Dem_Max (int *A, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] == Tim_Max(A,n))
		{
			dem++;
		}
	}
	return dem;
}
int Dem_x (int *A, int n, int x)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if ( x == A[i])
		{
			dem++;
		}
	}
	return dem;
}
int KT_Co_Ton_Tai_So_Duong (int *A, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] > 0)
		{
			dem++;
		}
	}
	if (dem != 0)
	{
		return 1;
	}
	return 0;
}
void Sap_Tang (int *A, int n)
{
	int t = 0;
	for (int i = 0; i < (n - 1); i++)
	{
		for (int j = i + 1; j <= n; j++ )
		{
			if (A[i] > A[j])
			{
				t = A[i];
				A[i]= A[j];
				A[j] = t;
			}
		}
	}
}
void Loc_So_Am (int *A, int n)
{
	printf ("\n\nCac so am trong mang la: ");
	for (int i = 0; i < n; i++)
	{
		if (A[i] < 0)
		{
			printf ("%10d",A[i]);
		}
	}
}

