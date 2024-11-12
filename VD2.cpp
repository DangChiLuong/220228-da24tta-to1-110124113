#include <stdio.h>
#include <string.h>
void XuatThongTin(char a[], char b[], char c[], int n, int m, int o, int p);
int main()
{
	char mssv[10], Hoten[30], Lop[20];
	int Namsinh, Diem1, Diem2, Diem3;
	//Nhap MSSV
	printf ("Ma so sinh vien: ");
	fflush(stdin);
	scanf("%s",mssv);
	//Nhap Ho Ten
	printf ("\nHo ten: ");
	fflush(stdin);
	gets(Hoten);
	//Nhap Ma lop
	printf ("\nMa lop:");
	fflush(stdin);
	scanf("%s",Lop);
	//Nhap Nam Sinh
	printf ("\nNam sinh:");
	scanf ("%d",&Namsinh);
	//Nhap Diem
	printf ("\nDiem mon xet tuyen so 1: ");
	scanf ("%d",&Diem1);
	printf ("\nDiem mon xet tuyen so 2: ");
	scanf ("%d",&Diem2);
	printf ("\nDiem mon xet tuyen so 3: ");
	scanf ("%d",&Diem3);
	XuatThongTin(mssv, Hoten, Lop, Namsinh, Diem1, Diem2, Diem3);
	return 0;
}
void XuatThongTin(char a[], char b[], char c[], int n, int m, int o, int p)
{
	printf("\nMa so sinh vien: %s",a);
	printf("\nHo ten: %s",b);
	printf("\nLop: %s",c);
	printf("\nNamsinh: %d",n);
	printf("\nDiem so 1: %d",m);
	printf("\nDiem so 2: %d",o);
	printf("\nDiem so 3: %d",p);
}
