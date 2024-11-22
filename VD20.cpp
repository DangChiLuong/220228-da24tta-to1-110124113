#include <stdio.h>
#define SIZE 100 //Khai bao so phan tu cho SIZE
void Nhap_Phan_Tu_Mang (int A[],int n);
void In_Phan_Tu_Mang (int A[],int n);
void Tinh_Tong_Cac_Phan_Tu_Mang (int A[],int n);
void Tinh_Tong_Cac_phan_Tu_Duong (int A[], int n);
void Tinh_Tong_Cac_Phan_Tu_Tai_Vi_Tri_Le (int A[], int n);
int Dem_CaC_Phan_Tu_Am (int A[], int n);
int Dem_Cac_Phan_Tu_Le (int A[], int n);
int Kiem_Tra_SNT (int x);
int Dem_SNT_Trong_Mang (int A[], int n);
int Tim_SNT_Trong_Mang (int A[], int n);
void In_Cac_So_Duong_le (int A[], int n);
int Kiem_Tra_Co_Ton_Tai_So_Am_Khong (int A[], int n);
int Tim_Gia_X (int  A[], int n,int x);
int main()
{
	//Khai bao mang
	int A[SIZE];
	int n, x;
	//Nhap so nguyen duong n
	do
	{
		printf ("\nNhap vao so luong phan tu mang (0 <= n < %d): ",SIZE);
		scanf ("%d",&n);
	} while (0 >= n || n > SIZE);
	//Nhap gia tri x
	printf ("\nNhap gia tri x: ");
	scanf ("%d",&x);
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
	//Dem cac phan tu am cua mang
	printf ("\n\nSo phan tu am trong mang la: %d",Dem_CaC_Phan_Tu_Am (A,n));
	//Dem cac phan tu le trong mang
	printf ("\n\nCac phan tu le trong mang la: %d",Dem_Cac_Phan_Tu_Le (A,n));
	//Dem SNT trong mang
	printf ("\n\nSNT trong mang la: %d\n",Dem_SNT_Trong_Mang(A,n));
	//Tim SNT
	printf ("\nSNT dau tien trong mang la: %d\n",Tim_SNT_Trong_Mang(A,n));
	//In cac so duong le trong mang
	printf ("\nCac so duong le trong mang la: ");
	In_Cac_So_Duong_le (A,n);
	//Kiem tra mang co ton tai so am khong
	if (Kiem_Tra_Co_Ton_Tai_So_Am_Khong(A,n))
	{
		printf ("\n\nMang co ton tai so am!!\n");
	} else 
	{
		printf ("\n\nMang khong ton tai so am!!\n");
	}
	//Tim Gia tri trong mang
	if (Tim_Gia_X( A, n, x))
	{
		printf ("\nGia tri %d co ton tai!!",x);
	}else 
	{
		printf ("\nGia tri %d khong ton tai!!",x);
	}
	return 0;
}
void Nhap_Phan_Tu_Mang (int A[],int n)
{
		for (int i = 0; i < n; i++)
	{
		printf ("\nPhan tu cua mang thu %d la: ", i);
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
int Dem_CaC_Phan_Tu_Am (int A[], int n)
{
    int dem = 0; 
    for (int i = 0; i < n; i++) 
	{
        if (A[i] < 0) 
		{
            dem++; 
        }
    }
    return dem;
}
int Dem_Cac_Phan_Tu_Le (int A[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{	
		if (A[i] % 2 != 0)
		{
			dem ++;
		}
	}
	return dem;
}
int Kiem_Tra_SNT (int x)
{
	if (x <= 1)
	{
		return 0;
	}
	for (int i = 2; i * i < x; i++)
	{
		if ( x % i == 0)
		{
		 return 0;	
		}
	}
	return 1;
}
int Dem_SNT_Trong_Mang (int A[], int n)
{
	int dem = 0;
	for ( int i = 0; i < n; i++)
	{
		if (Kiem_Tra_SNT(i))
		{
			dem++;
		}
	}
	return dem;
}
int Tim_SNT_Trong_Mang (int A[], int n)
{
	for ( int i = 0; i < n; i++)
	{
		if (Kiem_Tra_SNT(A[i]))
		{
			return A[i];
		}
	}
	return 0;
}
void In_Cac_So_Duong_le (int A[], int n)
{
	int timthay = 0;
	for ( int i = 0; i < n; i++)
	{
		if (A[i] > 0 && A[i] % 2 != 0)
		{
			printf ("%d\t",A[i]);
			timthay = 1;	
		}	
	}	
}
int Kiem_Tra_Co_Ton_Tai_So_Am_Khong (int A[], int n)
{
	for (int i = 0; i < n ; i++)
	{
		if (A[i] < 0)
		{
			return 1;
		}
	}
	return 0;
}
int Tim_Gia_X (int  A[], int n, int x)
{
	for (int i = 0;i < n; i++)
	{
		if (A[i] == x)
		{
			return 1;
		}
	}
	return 0;
}



