#include <stdlib.h>
#include <stdio.h>
struct PHAN_SO{
	int tu, mau;
};
void nhapPS (PHAN_SO *a);
void xuatPS (PHAN_SO a);
void nhapDS (PHAN_SO a[], int n);
void xuatDS (PHAN_SO a[], int n);
void rutgon (PHAN_SO *a);
float GiaTri (PHAN_SO a);
void timMin (PHAN_SO a[], int n);
int demMin (PHAN_SO a[], int n);
void sapGiam (PHAN_SO a[], int n);
int main()
{
	PHAN_SO *ps, *ps2;
	int n, m=1;
	char path[50], path2[50];
	FILE *fp, *fp2;
	//Nhap so phan so
	do
	{
		printf("\nNhap vao so phan so: ");
		scanf("%d", &n);
	}while(n<=0);
	ps2=(PHAN_SO*)malloc(n*sizeof(PHAN_SO));
	ps=(PHAN_SO*)malloc(n*sizeof(PHAN_SO));
	//nhap danh sach voi n phan so
	printf("\nNhap danh sach cac phan so: ");
	nhapDS(ps, n);
	//Nhap duong dan
	printf("\nNhap duong dan: ");
	fflush(stdin);
	gets(path);
	//mo file
	fp=fopen(path, "wb");
	if(fp==NULL)
		printf("\nLoi mo file");
	else
	{
		for(int i=0 ; i<n ; i++)
		{
			fwrite(&ps[i], sizeof(PHAN_SO), n, fp);
		}
		fclose(fp);
	}
	printf("\nNhap duong dan can doc: ");
	fflush(stdin);
	gets(path2);
	//mo file 2
	fp2=fopen(path2,"rb");
	if(fp2==NULL)
		printf("\nLoi mo file");
	else 
	{
		int i=0;
	while(!feof(fp2))
	{
		fread(&ps2[i], sizeof(PHAN_SO), 1, fp2);
		m++;
		i++;
		ps2=(PHAN_SO*)realloc(ps2, sizeof(PHAN_SO)*m);
	}
		fclose(fp2);
	}
	printf("\nDanh sach cac phan so vua doc: ");
	xuatDS(ps2, n);
	//timmin
	printf("\nPhan so co gia tri nho nhat la: ");
	timMin(ps2, n);
	//Phan so co gia tri nho nhat
	printf("\nSo phan so nho nhat: %d", demMin(ps2, n));
	//Sap giam
	printf("\nSau khi sap xep giam dan: ");
	sapGiam(ps2,n);
	xuatDS(ps2, n);
	return 0;
}
void rutgon (PHAN_SO *a)
{
	for (int i=2; i<=a->tu ; i++)
	{
		if((a->tu%i==0)&&(a->mau%i==0))
		{
			a->tu/=i;
			a->mau/=i;
		}
	}
	for (int i=2; i<=a->mau ; i++)
	{
		if((a->tu%i==0)&&(a->mau%i==0))
		{
			a->tu/=i;
			a->mau/=i;
		}
	}
}
void xuatPS (PHAN_SO a)
{
	printf("%d/%d", a.tu, a.mau);
}
void nhapPS (PHAN_SO *a)
{
	printf("\nNhap vao tu so: ");
	scanf("%d", &a->tu);
	printf("\nNhap vao mau so: ");
	scanf("%d", &a->mau);
}
void nhapDS (PHAN_SO a[], int n)
{
	for (int i=0 ; i<n ; i++)
	{
		printf("\nNhap vao phan so thu %d: ", i+1);
		nhapPS(&a[i]);
	}
}
void xuatDS (PHAN_SO a[], int n)
{
	for (int i=0 ; i<n ; i++)
	{
		rutgon(&a[i]);
		xuatPS(a[i]);
		printf("\t");
	}
}

float GiaTri (PHAN_SO a)
{
	float temp;
	temp=(float)(a.tu)/(a.mau);
	return temp;
}
void timMin (PHAN_SO a[], int n)
{
	float min=GiaTri(a[0]);
	PHAN_SO t;
	for(int i=0 ; i<n ; i++)
	{
		if(GiaTri(a[i])<min)
			min=GiaTri(a[i]);
	}
	for (int i=0 ; i<n ; i++)
	{
		if(GiaTri(a[i])==min)
		{
			xuatPS(a[i]);
			break;
		}
	}
}
int demMin (PHAN_SO a[], int n)
{
	int dem=0;
	float min=GiaTri(a[0]);
	for(int i=0 ; i<n ; i++)
	{
		if(GiaTri(a[i])<min)
			min=GiaTri(a[i]);
	}
	for (int i=0 ; i<n ; i++)
	{
		if(GiaTri(a[i])==min)
			dem++;
	}
	return dem;
}
void sapGiam (PHAN_SO a[], int n)
{
	PHAN_SO t;
	for(int i=0; i<n-1 ; i++)
	{
		for(int j=i+1 ; j<n ; j++)
		{
			if(GiaTri(a[i])<GiaTri(a[j]))
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}

