#include<stdio.h>
#include<string.h>
struct CONNGUOI
{
	char hoten[30], diachi[100],gioitinh[4];
	int tuoi;
	float thunhap;
};
void nhap(CONNGUOI *a);//Truyen tham bien
void xuat(CONNGUOI a);//Truyen tham tri
int main()
{
	CONNGUOI a;
	//Nhap thong tin
	nhap(&a);//Truyen dia chi tham so thuc
	//Xuat thong tin
	printf("\nThong tin vua nhap la:\n");
	xuat(a);
	return 0;
}
void nhap(CONNGUOI *a)
{
	//Nhap ho ten
	printf("\nNhap vao ho ten: ");
	fflush(stdin);
	gets(a -> hoten);	
	//Nhap tuoi
	printf("\nNhap vao tuoi: ");
	scanf("%d", &a -> tuoi);
	//Nhap dia chi
	printf ("\n\nNhap vao dia chi cua ban: ");
	fflush (stdin);
	gets(a -> diachi);
	//Nhap gioi tinh 
	printf ("\n\nGioi tinh: ");
	scanf ("%s",a -> gioitinh);
	//Nhap thu nhap 
	printf ("\n\nThu nhap cua ban la: ");
	scanf ("%f",&a -> thunhap);
}
void xuat(CONNGUOI a)
{
	printf("\nHo ten cua ban la: %s\n",a.hoten);
	printf("\nTuoi cua ban la: %d tuoi\n",a.tuoi);
	printf("\nDia chi cua ban la: %s\n",a.diachi);
	printf ("\nGioi tinh cua ban la: %s\n",a.gioitinh);
	printf ("\nThu nhap cua ban la: %.2f",a.thunhap);
}
