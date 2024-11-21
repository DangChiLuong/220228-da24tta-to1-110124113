#include <stdio.h>
#define SIZE 100 //Khai bao so phan tu cho SIZE
void Nhap_Phan_Tu_Mang (int A[],int n);
void In_Phan_Tu_Mang (int A[],int n);
void Tinh_Tong_Cac_Phan_Tu_Mang (int A[],int n);
void Tinh_Tong_Cac_phan_Tu_Duong (int A[], int n);
void Tinh_Tong_Cac_Phan_Tu_Tai_Vi_Tri_Le (int A[], int n);
int main()
{
	//Khai bao mang
	int A[SIZE];
	int n;
	//Nhap so nguyen duong n
	do
	{
		printf ("\nNhap vao so luong phan tu mang (0 <= n < %d): ",SIZE);
		scanf ("%d",&n);
	} while (0 >= n || n > SIZE);
	//Nhap phan tu cho mang
	Nhap_Phan_Tu_Mang (A,n);
	//In phan tu cua mang
	In_Phan_Tu_Mang (A,n);
	//Tinh tong cac phan tu mang
	Tinh_Tong_Cac_Phan_Tu_Mang (A,n);
	//Tinh tong cac phan tu duong trong mang
	Tinh_Tong_Cac_phan_Tu_Duong (A,n);
	//Tong cac phan tu tai vi tri le
	Tinh_Tong_Cac_Phan_Tu_Tai_Vi_Tri_Le (A,n);
	return 0;
}
void Nhap_Phan_Tu_Mang (int A[],int n)
{
		for (int i = 0; i < n; i++)
	{
		printf ("\nPhan tu cua mang thu %d la: ", i + 1);
		scanf ("%d",&A[i]);
	}	
}
void In_Phan_Tu_Mang (int A[],int n)
{
	printf ("\nCac phan tu cua mang la: " );
	for (int i = 0; i < n; i++)
	{
		printf ("\t%d\t",A[i]);
	}
}
void Tinh_Tong_Cac_Phan_Tu_Mang (int A[],int n)
{
	int s = 0;
	printf ("\n\nTong cac phan tu mang la: ");
	for (int i = 0; i < n; i++)
	{
		s = s + A[i];
	}
	printf ("%d",s);
}
void Tinh_Tong_Cac_phan_Tu_Duong (int A[], int n)
{
	int s = 0;
	printf ("\n\nTong cac phan tu duong trong mang la: ");
	for (int i = 0; i < n; i++)
	{
		if (A[i] > 0)
			s = s + A[i];	
	}
	printf ("%d",s);
}
void Tinh_Tong_Cac_Phan_Tu_Tai_Vi_Tri_Le (int A[], int n)
{
	int s = 0;
	printf ("\n\nTong cac phan tu tai vi tri le la: ");
	for ( int i = 1; i < n; i = i + 2)
	{
		s = s + A[i];
	}
	printf ("%d",s);
}
