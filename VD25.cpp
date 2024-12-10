#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct MON_HOC
{
	char mamon[15];
	float diem;
};
struct NGAY_THANG 
{
	int ngay, thang, nam;
};
typedef struct SINH_VIEN 
{
	char mssv[10], hoten[30], gioitinh[5], diachi[50];
	MON_HOC mon[10];
	NGAY_THANG ngaythang;
	int somon;
}SV;
void NhapTTSV (SV *a);
void NhapNgaysinh (NGAY_THANG *a);
void NhapMA (MON_HOC *a);
void XuatMA (MON_HOC a);
void NhapMON (MON_HOC a[], int n);
void XuatNgaysinh (NGAY_THANG a);
void XuatMON (MON_HOC a[], int n);
void XuatTTSV (SV a);
void NhapSV( SV a[], int n);
void XuatSV (SV a[], int n);
int TontaiSV(SV a[], int n, char mssv[]);
void TimSV (SV a[], int n, char t[]); 
int TachThang (NGAY_THANG a);
void TimThang (SV a[], int n);
void TimGioiTinh (SV a[], int n, char t[]);
void TimDiaChi (SV a[], int n, char t[]);

int main()
{
	SV a, *sv;
	int n;
	char t[10], c[30], d[5], e[50];
	sv = ( SV*) malloc (sizeof(SV)*n);
	//Nhap thông tin SV
	printf("\nNhap TTSV: ");
	NhapTTSV(&a);
	//xuat thong tin
	XuatTTSV(a);	
	//Nhap/xuat n SV
	printf("\nNhap vao so sinh vien: ");
	scanf("%d", &n);
	NhapSV(sv, n);
	XuatSV(sv, n);
	//tim sinh vien theo mssv
	printf("\nNhap MSSV can tim: ");
	fflush(stdin);
	gets(t);
	if(TontaiSV(sv,n,t)!=0)
		printf("\nMSSV %s CO ton tai.", t);
	if(TontaiSV(sv,n,t)==0)
		printf("\nMSSV %s KHONG ton tai.", t);
	//Nhap thong tin SV can tim
	printf("\nNhap Ho Ten can tim: ");
	fflush(stdin);
	gets(c);
	printf("\nCac SINH VIEN co ten %s duoc tim thay trong danh sach: ", c);
	TimSV(sv, n, c);	
	//Tim SV sinh thang 8
	printf("\nDSSV sinh thang 8: ");
	TimThang(sv, n);	
	//Nhap gioi tinh can tim
	printf("\nNhap vao gioi tinh can xuat DS: ");
	fflush(stdin);
	gets(d);
	printf("\nDSSV theo gioi tinh %s: ", d);
	TimGioiTinh(sv, n, d);	
	//Nhap dia chi can tim
	printf("\nNhap vao dia chi can xuat DS: ");
	fflush(stdin);
	gets(e);
	printf("\nDSSV theo dia chi %s: ", e);
	TimDiaChi(sv, n, e);
	return 0;
}

void TimDiaChi (SV a[], int n, char t[])
{
	for (int i = 0 ; i < n ; i++)
	{
		char *res = strstr( a[i].diachi , t);
		if ( res != NULL)
		{
			XuatTTSV(a[i]);
			printf("\n");
		}
	}
}
void TimGioiTinh (SV a[], int n, char t[])
{
	for (int  i = 0 ; i < n ; i++)
	{
		char *res = strstr( a[i].gioitinh , t);
		if ( res != NULL)
		{
			XuatTTSV(a[i]);
			printf("\n");
		}
	}
}
void TimThang (SV a[], int n)
{
	for (int i = 0 ; i < n ; i++)
	{
		if( TachThang (a[i].ngaythang) == 8)
		{
			XuatTTSV(a[i]);
			printf("\n");
		}
	}
}
int TachThang (NGAY_THANG a)
{
	return a.thang;
}
void TimSV (SV a[], int n, char t[])
{
	for (int i = 0 ; i < n ; i++)
	{
		if( strcmp (a[i].hoten, t) ==0)
		{
			XuatTTSV (a[i]);
			printf("\n");
		}
	}
}
int TontaiSV(SV a[], int n, char mssv[])
{
	int dem = 0;
	for(int i = 0; i < n ; i++)
	{
		if( strcmp (a[i].mssv, mssv) == 0)
		{
			dem++;
		}	
	}
	if(dem != 0)
	{
		return 1;
	}
	return 0;
}
void XuatSV (SV a[], int n)
{
	for (int i = 0 ; i < n ; i++)
	{
		printf("\n\nThong Tin cua SV thu %d: ", i+1);
		XuatTTSV(a[i]);
		printf("\n");
	}
}
void NhapSV( SV a[], int n)
{
	for (int i=0 ; i<n ; i++)
	{
		printf("\n\nNhap TT cua SV thu %d: ", i+1);
		NhapTTSV(&a[i]);
	}
}
void XuatTTSV (SV a)
{
	printf("\nMSSV: %s\nHo Ten: %s", a.mssv, a.hoten);
	printf("\nNgay sinh: ");
	XuatNgaysinh(a.ngaythang);
	printf("\nGioi Tinh: %s", a.gioitinh);
	printf("\nDia Chi: %s", a.diachi);
	printf("\nDiem so cac mon da hoc: ");
	XuatMON(a.mon,a.somon);
}
void XuatMAMON (MON_HOC a)
{
	printf("Ma MH: %s\tDiem: %.2f", a.mamon, a.diem);
}
void XuatMON (MON_HOC a[], int n)
{
	for (int i = 0 ; i < n ; i++)
	{
		printf("\nMon thu %d: ", i+1);
		XuatMAMON(a[i]);
	}
}
void XuatNgaysinh (NGAY_THANG a)
{
	printf("%d/%d/%d", a.ngay, a.thang, a.nam);
}
void NhapMAMON (MON_HOC *a)
{
	//Nhap mamon
	printf("\nNhap Ma Mon: ");
	fflush(stdin);
	gets(a->mamon);
	//Nhap diem
	printf("\nNhap diem: ");
	scanf("%f", &a->diem);
}
void NhapMON (MON_HOC a[], int n)
{
	for (int i = 0 ; i < n ; i++)
	{
		printf("\n\nNhap thong tin mon thu %d: ", i+1);
		NhapMAMON(&a[i]);
	}
}
void NhapNgaysinh (NGAY_THANG *a)
{
	printf("\nNhap ngay sinh: ");
	scanf("%d", &a->ngay);
	printf("\nNhap thang sinh: ");
	scanf("%d", &a->thang);
	printf("\nNhap nam sinh: ");
	scanf("%d", &a->nam);
}
void NhapTTSV (SV *a)
{
	printf("\n\nNhap vao MSSV: ");
	fflush(stdin);
	gets(a->mssv);
	//Nhap ho ten SV
	printf("\nNhap vao ho ten sinh vien: ");
	fflush(stdin);
	gets(a->hoten);
	//Nhap ngay thang nam sinh
	printf("\nNhap vao ngay, thang, nam sinh: ");
	NhapNgaysinh(&a->ngaythang);
	//Nhap gioi tinh
	printf("\nNhap gioi tinh cua sinh vien: ");
	fflush(stdin);
	gets(a->gioitinh);
	//Nhap dia chi
	printf("\nNhap vao dia chi: ");
	fflush(stdin);
	gets(a->diachi);
	//Nhap so mon hoc
	do
	{
		printf("\n\nNhap vao so mon hoc: ");
		scanf("%d", &a->somon);
	}while ( a -> somon > 10 || a -> somon <= 0);
	printf("\nNhap Ma Mon va Diem cua tung mon: ");
	NhapMON(a -> mon, a -> somon);
}

