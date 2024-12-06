#include <stdio.h>
struct SINH_VIEN
{
	char mssv[30], hoten[40], gioitinh[4], diachi[100], ngaysinh[10], thangsinh[10], namsinh[30];
	int somon;
} SV;
void Nhap_SV (SINH_VIEN *a);
int main()
{
	SINH_VIEN a;
	//Nhap
	Nhap_SV(&a);
}
void Nhap_SV (SINH_VIEN *a)
{
	//nhap ho ten
	printf ("\nNhap ho ten sinh vien: ");
	fflush (stdin);
	gets(a -> hoten);
	//nhap mssv
	printf ("\nNhap mssv: ");
	scanf ("%s",a -> mssv);
	//Nhap ngay thang nam sinh
	printf ("\nNhap ngay sinh: ");
	scanf ("%s",a -> ngaysinh);
	printf ("\n\nNhap thang sinh: ");
	scanf ("%s",a -> thangsinh);
	printf ("\n\nNhap nam sinh: ");
	scanf ("%s",a ->namsinh);
	//Nhap dia chi
	printf ("\n\nNhap dia chi: ");
	fflush (stdin);
	gets (a -> diachi);
	//Nhap so mon hoc
	printf ("\n\nNhap so mon hoc: ");
	scanf ("%d",&a -> somon);
}
