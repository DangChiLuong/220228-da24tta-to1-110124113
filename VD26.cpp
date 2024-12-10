#include <stdio.h>
#include <stdlib.h>
struct SACH 
{
	char masach[15], tensach[50], tacgia[30], nxb[50];
	int namxb, soluong;
	float dongia, thanhtien, thue, thuctien;
};
void NhapTT (SACH *a);
void XuatTT (SACH a);
void Nhap_TTSach (SACH a[], int n);
void Xuat_TTSach (SACH a[], int n);
float Thanh_tien (SACH *a);
float Thanhtien (SACH a[], int n);
float Thuc_tien (SACH *a, int m);
float Thuctien (SACH a[], int n, int m);
void SapGiam (SACH a[], int n);
float TimMax (SACH a[], int n, int m);
void InMax (SACH a[], int n, int m);
int  TongSach (SACH a[], int n);

int main ()
{
	SACH *sach, a;
	int n, m;
	sach = (SACH*)malloc( n*sizeof (SACH));
	do
	{
		printf("\nNhap vao so quyen sach can cung cap thong tin: ");
		scanf("%d", &n);
	}while(n <= 0);
	//Nhap sach
	Nhap_TTSach(sach, n);
	//xuat_TTSach(sach, n);
	printf("\nThanh Tien %d quyen sach: %.2f", n, Thanhtien(sach, n));
	do
	{
		printf("\nNhap vao thue Gia Tri Gia Tang(VAT): ");
		scanf("%d", &m);
	}while( m < 0 || m > 100);
	printf("\nThuc Tien %d quyen sach: %.2f", n, Thuctien(sach,n, m));	
	//Sap giam
	printf("\nSap xep theo chieu Giam cua Nam Xuat Ban: ");
	SapGiam(sach,n);
	Xuat_TTSach(sach,n);		
	//tim max
	printf("\nNhung quyen sach co Thuc Tien Lon Nhat: %.2f", TimMax(sach, n, m));
	InMax(sach, n, m);
	//tong so luong sach
	printf("\nTong So Luong moi quyen sach: %d", TongSach(sach , n));
	return 0;
}
int  TongSach (SACH a[], int n)
{
	int s = 0;
	for (int i = 0 ; i < n ; i++)
	{
		s += a[i].soluong;
	}
	return s;
}
void InMax (SACH a[], int n, int m)
{
	for (int i = 0 ; i < n ; i++)
	{
		if(Thuc_tien (&a[i],m) == TimMax(a, n, m))
			XuatTT(a[i]);
	}
}
float TimMax (SACH a[], int n, int m)
{
	float max = Thuc_tien(&a[0], m); 
	for (int i = 0 ; i < n ; i++)
	{
		if( Thuc_tien (&a[i], m) > max)
			max = Thuc_tien (&a[i], m);
	}
	return max;
}
void SapGiam (SACH a[], int n)
{
	int t;
	for (int i = 0 ; i < n - 1 ; i++)
	{
		for (int j = i + 1; j < n ; j++)
		{
			if(a[i].namxb < a[j].namxb)
			{
				t = a[i].namxb;
				a[i].namxb = a[j].namxb;
				a[j].namxb = t;
			}
		}
	}
}
float Thuctien (SACH a[], int n, int m)
{
	float s = 0;
	for (int i = 0; i < n ; i++)
	{
		s += Thuc_tien(&a[i], m);
	}
	return s;
}
float Thuc_tien (SACH *a, int m)
{
	a -> thuctien = Thanh_tien(a) + Thanh_tien (a)*m/100;
	return a -> thuctien;
}
float Thanhtien (SACH a[], int n)
{
	float s = 0;
	for (int i = 0 ; i < n ; i++)
	{
		s += Thanh_tien(&a[i]);
	}
	return s;
}
float Thanh_tien (SACH *a)
{
	a-> thanhtien=(a -> soluong) * (a -> dongia);
	return a -> thanhtien;
}
void Xuat_TTSach (SACH a[], int n)
{
	for (int i = 0 ; i < n ; i++)
	{
		printf("\nThong tin quyen sach thu %d: ",  i+1);
		XuatTT(a[i]);
		printf("\n");
	}
}
void Nhap_TTSach (SACH a[], int n)
{
	for (int i = 0 ; i < n ; i++)
	{
		printf("\nNhap thong tin quyen sach thu %d: ", i+1);
		NhapTT(&a[i]);
	}
}
void XuatTT (SACH a)
{
	printf("\nMa Sach: %s\nTen Sach: %s\nTac Gia: %s", a.masach, a.tensach, a.tacgia);
	printf("\nNXB: %s\nNam XB: %d", a.nxb, a.namxb);
	printf("\nSo Luong Nhap: %d\nDon Gia: %.2f", a.soluong, a.dongia);
}
void NhapTT (SACH *a)
{
	//Nhap ma sach
	printf("\nNhap vao Ma Sach: ");
	fflush(stdin);
	gets(a->masach);
	//Nhap ten sach
	printf("\nNhap vao Ten Sach: ");
	fflush(stdin);
	gets(a->tensach);
	//Nhap ten tac gia
	printf("\nNhap vao ten Tac Gia: ");
	fflush(stdin);
	gets(a->tacgia);
	//Nhap NXB
	printf("\nNhap vao Nha Xuat Ban: ");
	fflush(stdin);
	gets(a->nxb);
	//Nhap nxb
	printf("\nNhap vao Nam Xuat Ban: ");
	scanf("%d", &a->namxb);
	//Nhap don gia
	printf("\nNhap vao Don Gia: ");
	scanf("%f", &a->dongia);
	//Nhap so luong sach
	printf("\nNhap vao So Luong Nhap: ");
	scanf("%d", &a->soluong);
}

