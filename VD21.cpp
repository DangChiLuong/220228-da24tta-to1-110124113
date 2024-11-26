#define SIZE 100 //Khai bao mang
#include <stdio.h>
void Nhap_Mang (int A[], int n);
void Xuat_Mang (int A[], int n);
void Tinh_Tong (int A[], int n);
float Tinh_TongTB (int A[], int n);
int Dem_Phan_Tu_Duong (int A[], int n);
void Sap_Xep_Thu_Tu_Tang_Dan (int A[], int n);
void In_Cac_Gia_Tri_Tai_Vi_Tri_Le (int A[], int n);
void In_Vi_Tri_Co_Gia_Tri_Bang_0 (int A[], int n);
int main()
{
	//Nhap so luong phan tu mang A
	int A [SIZE];
	int n;
	do
	{
		printf ("\nNhap so luong phan tu mang: ");
		scanf ("%d",&n);
	} while (n <= 0 || n > SIZE);
	//Nhap phan tu mang
	Nhap_Mang (A,n);
	//Xuat phan tu mang
	Xuat_Mang (A,n);
	//Tinh Tong
	Tinh_Tong (A,n);
	//Tinh tongTB
	printf ("\nTong trung binh cac vi tri le la: %.2f\n",Tinh_TongTB(A,n));
	//Dem phan tu duong 
	printf ("\nSo phan tu duong trong mang la: %d\n",Dem_Phan_Tu_Duong(A,n));
	//Sap xep phan tu trong mang tang dan
	Sap_Xep_Thu_Tu_Tang_Dan(A,n);
	//In cac gia tri tai vi tri le
	In_Cac_Gia_Tri_Tai_Vi_Tri_Le(A,n);
	//In ra man hinh cac vi tri co gia tri = 0
	In_Vi_Tri_Co_Gia_Tri_Bang_0(A,n);
	return 0;
}
void Nhap_Mang (int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf ("\nNhap phan tu thu %d: ",i);
		scanf ("%d",&A[i]);
	}
}
void Xuat_Mang (int A[], int n)
{
	printf ("\nCac phan tu trong mang la:\t");
	for (int i = 0; i < n; i++)
	{
		printf ("%d\t",A[i]);
	}			
}
void Tinh_Tong (int A[], int n)
{
	int s = 0;
	printf ("\n\nTong phan tu mang la: ");
	for (int i = 0; i < n; i++)
	{
		s = s + A[i];
	}
	printf ("%d\n",s);
}
float Tinh_TongTB (int A[], int n)
{
	float STB = 0.0;
    int dem = 0, s= 0;
    for (int i = 1; i < n; i += 2) 
	{
        s = s + A[i];
        dem++;
    }
    STB = s / dem;
    return STB;
}
int Dem_Phan_Tu_Duong (int A[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] > 0)
		{
			dem++;
		}
	}
	return dem;
}
void Sap_Xep_Thu_Tu_Tang_Dan (int A[], int n)
{
	int t;
	for (int i = 0; i <= (n - 2); i++)
	{
		for (int j = i +1; j <= (n - 1); j++)
		{
			if (A[i] > A[j])
			{
				t = A[i];
				A[i] = A[j];
				A[j] = t;
			}
		}
	}
		printf("\nCac gia tri cua mang tang dan la: ");
    for (int i = 0; i < n; i++) 
	{
        printf("%d\t",A[i]);
    }
}
void In_Cac_Gia_Tri_Tai_Vi_Tri_Le(int A[], int n) 
{
    printf("\n\nCac gia tri tri vi tri le la: ");
    for (int i = 1; i < n; i += 2) 
	{ 
        printf("%d ", A[i]);
    }
    printf("\n");
}
void In_Vi_Tri_Co_Gia_Tri_Bang_0(int A[], int n)
{
	printf("\nCac vi tri co gia tri bang 0 trong mang la: ");
    int found = 0;
    for (int i = 0; i < n; i++) 
	{
        if (A[i] == 0) 
		{
            printf("%d ",A[i]);
            found = 1;
        }
    }
    if (!found) 
	{
        printf("\n\nKhong tim thay vi tri co gia tri bang 0 trong mang.");
    }
    printf("\n");
}

