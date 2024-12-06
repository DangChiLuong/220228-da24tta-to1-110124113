#include <stdio.h>
struct PHAN_SO
{
	int tu, mau;
}PS;
void nhap (PHAN_SO *a);
void xuat (PHAN_SO a);
void rut_gon (PHAN_SO *a);
void cong_ps (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c);
void tru_ps (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c);
void nhan_ps (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c);
void chia_ps (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c);
int main()
{
	PHAN_SO a, b, c;
	//Nhap
	printf("\nNhap phan so thu nhat: ");
	nhap(&a);
	printf("\nNhap phan so thu hai: ");
	nhap(&b);
	//Xuat
	printf("\nPhan so da nhap la: ");
	xuat(a);
	printf("\t");
	xuat(b);
	//Rut gon phan so
	printf("\nPhan so dang RUT GON: ");
	rut_gon(&a);
	rut_gon(&b);
	xuat(a);
	printf("\t");
	xuat(b);
	//Cong Phan so
	printf("\nPhep cong hai phan so %d/%d va %d/%d: ", a.tu, a.mau, b.tu, b.mau);
	cong_ps(&a,&b,&c);
	rut_gon(&c);
	xuat(c);
	//Tru phan so
	printf("\nPhep tru hai phan so %d/%d va %d/%d: ", a.tu, a.mau, b.tu, b.mau);
	tru_ps(&a,&b,&c);
	rut_gon(&c);
	xuat(c);
	//Nhan phan so
	printf("\nPhep nhan hai phan so %d/%d va %d/%d: ", a.tu, a.mau, b.tu, b.mau);
	nhan_ps(&a,&b,&c);
	rut_gon(&c);
	xuat(c);
	//Chia phan so
	printf("\nPhep chia hai phan so %d/%d va %d/%d: ", a.tu, a.mau, b.tu, b.mau);
	chia_ps(&a,&b,&c);
	rut_gon(&c);
	xuat(c);
	return 0;
}
void chia_ps (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c)
{
	c -> tu = a -> tu * b -> mau;
	c -> mau = a -> mau * b -> tu;
}
void nhan_ps (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c)
{
	c -> tu = a -> tu * b -> tu;
	c -> mau = a -> mau * b -> mau;
}
void tru_ps (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c)
{
	if(a -> mau == b -> mau)
	{
		c -> mau = a -> mau;
		c -> tu = a -> tu - b ->tu;
	}
	else if(a -> mau != b -> mau)
	{
		c -> mau = a -> mau * b -> mau;
		c -> tu = (a -> tu * b -> mau) - (b -> tu * a -> mau);
	}
}
void cong_ps (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c)
{
	if(a -> mau == b -> mau)
	{
		c -> mau = a -> mau;
		c -> tu = a -> tu + b -> tu;
	}
	else if(a -> mau !=b -> mau)
	{
		c -> mau = a -> mau * b -> mau;
		c -> tu = (a -> tu * b -> mau) +( b -> tu * a -> mau);
	}
}
void rut_gon (PHAN_SO *a)
{
	for (int i = 2; i <= a -> tu ; i++)
	{
		if((a -> tu % i == 0) && (a -> mau % i == 0))
		{
			a -> tu /= i;
			a -> mau/= i;
		}
	}
	for (int i = 2; i <= a -> mau ; i++)
	{
		if((a -> tu % i == 0) && (a-> mau % i == 0))
		{
			a -> tu /= i;
			a -> mau /= i;
		}
	}
}
void xuat (PHAN_SO a)
{
	printf("%d/%d",a.tu, a.mau);
}
void nhap (PHAN_SO *a)
{
	printf("\nNhap vao tu so: ");
	scanf("%d", &a -> tu);
	printf("\nNhap vao mau so: ");
	scanf("%d", &a -> mau);
}

