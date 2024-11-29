#include <stdio.h>
#define ROW 100
#define COL 100
void nhapMang (int a[][COL], int m, int n);
void xuatMang (int a[][COL], int m, int n);
int tinhTongMang (int a[][COL], int m, int n);
int tinhTongDong (int a[][COL], int m, int n);
int tinhTongCot (int a[][COL], int m, int n);
int ktSOAM (int a[][COL], int m, int n);
int ktSNT (int n);
int ktSNTCot (int a[][COL], int m, int n);
void sapGiamDong (int a[][COL], int m, int n);
int ktSOLE (int a[][COL], int m, int n);
int timSo (int a[][COL], int m, int n, int x);
void timvitri (int a[][COL], int m, int n, int x);
int timMAX (int a[][COL], int m, int n);
int timMIN (int a[][COL], int m, int n);
void inSNT (int a[][COL], int m, int n);
int main()
{
	int A[ROW][COL], m, n, k, x;
	do
	{
    	printf("Nhap so dong m (0 < m <= %d): ", ROW);
    	scanf("%d", &m);
    } while (m <= 0 || m  > ROW);
    do 
	{
    	printf("\nNhap so cot n (0 < n <= %d): ", COL);
    	scanf("%d", &n);
    } while (n <= 0 || n > COL);
	//Nhap mang
	printf("\nNhap gia tri cho Mang: ");
	nhapMang(A,m,n);
	//Xuatmang
	printf("\nCac gia tri trong Mang: \n");
	xuatMang(A, m, n);
	//Tong mang
	printf("\nTong cac gia tri trong Mang: %d", tinhTongMang(A,m,n));
	//Nhap so thao tac tren dong hay tren cot
	do
	{
		printf("\n\nNhap gia tri thao tac: ");
		scanf("%d", &k);
	}while( k < 0||k >= m);
	//Tinh tong cac gia tri tren dong
	printf("\n\nTong cac gia tri tren dong %d: %d", k, tinhTongDong(A, k, n));
	//Tinh tong cac gia tri tren cot
	printf("\n\nTong cac gia tri tren cot %d: %d", k, tinhTongCot(A, m, k));
	//Kiem tra so am
	if(ktSOAM(A, k, n) != 0)
		printf("\n\nTren dong %d co ton tai so AM", k);
	else if(ktSOAM(A, k, n) == 0)
		printf("\n\ntren dong %d khong ton tai so AM", k);
	//Kiem tra SNT tren cot
	if(ktSNTCot(A, m, k) != 0)
		printf("\n\nTren cot %d co ton tai SNT", k);
	if(ktSNTCot(A, m, k) == 0)
		printf("\n\nTren cot %d khong ton tai SNT", k);
	//Sap giam
	printf("\n\nMang sau khi sap Giam dan cac gia tri tren dong %d: \n", k);
	sapGiamDong(A, k, n);
	xuatMang(A,m,n);
	//Kiem tra so le trong mang
	if(ktSOLE(A, m, k) != 0)
		printf("\n\nTren cot %d toan gia tri LE", k);
	else if(ktSOLE(A, m, k) == 0)
		printf("\n\nTren cot %d khong toan gia tri LE", k);
	// Nhap mot gia tri bat ki tu ban phim
	printf("\n\nNhap mot gia tri bat ki de tim: ");
	scanf("%d", &x);
	//Tim gia tri trong mang
	if(timSo(A, m, n, x) != 0)
		printf("\n\nTrong Mang co ton tai so nguyen %d vua nhap", x);
	else if(timSo(A, m, n, x) == 0)
		printf("\n\nTrong Mang khong ton tai so nguyen %d vua nhap", x);
	//Tim vi tri gia tri x
	printf("\n\nVi tri trong Mang cua %d vua nhap: ", x);
	timvitri(A, m, n, x);
	//GTLN
	printf("\n\nGia tri LON NHAT tren dong %d: %d", k, timMAX(A, k, n));
	//GTNN
	printf("\n\nGia tri NHO NHAT tren dong %d: %d", k,timMIN(A, k, n));
	//SNT tren dong
	printf("\n\nSo Nguyen To tren dong %d: ", k);
	inSNT(A,k,n);
	return 0;
}
void inSNT (int a[][COL], int m, int n)
{
	for (int i = 0; i < n ; i++)
	{
		if ( ktSNT( a[m][i]) != 0)
			printf("%5d", a[m][i]);
	}
}
int timMIN (int a[][COL], int m, int n)
{
	int min = a[m][0];
	for (int i = 0 ; i < n-1 ; i++)
	{
		for (int j = i+1 ; j < n ; j++)
		{
			if( a[m][j] < a[m][i])
			{
				min = a[m][j];
			}
		}
	}
	return min;
}
int timMAX (int a[][COL], int m, int n)
{
	int max = a[m][0];
	for (int i = 0 ; i < n - 1 ; i++)
	{
		for (int j = i + 1 ; j < n ; j++)
		{
			if(a[m][j] > a[m][i])
			{
				max = a[m][j];
			}
		}
	}
	return max;
}
void timvitri (int a[][COL], int m, int n, int x)
{
	for (int i = 0 ; i < m ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			if(a[i][j] == x)
			{
				printf("\n\nSo dong: %d\tSo cot: %d", i, j);
			}
		}
	}
}
int timSo (int a[][COL], int m, int n, int x)
{
	int dem = 0; 
	for (int i = 0 ; i < m ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			if( a[i][j] == x)
			{
				dem ++;
			}
				
		}
	}
	if (dem != 0)
	{
		return 1;
	}	
	return 0;
}
int ktSOLE (int a[][COL], int m, int n)
{
	int dem = 0;
	for (int i = 0 ; i < m ; i++)
	{
		if (a[i][n] % 2 != 0)
		{
			dem ++;
		}
	}
	if (dem == m)
	{
			return 1;
	}
	return 0;
}
void sapGiamDong (int a[][COL], int m, int n)
{
	int t = a[m][0];
	for (int i  = 0 ; i < n - 1 ; i++)
	{
		for (int j = i + 1; j < n ; j++)
		{
			if(a[m][i] < a[m][j])
			{
				t = a[m][j];
				a[m][j] = a[m][i];
				a[m][i] = t;
			}
		}
	}
}
int ktSNTCot (int a[][COL], int m, int n)
{
	int dem = 0;
	for (int i = 0 ; i < m ; i++)
	{
		if( ktSNT(a[i][n]) != 0)
		{
				dem ++;
		}
	}
	if( dem != 0)
	{
		return 1;
	}	
	return 0;
}
int ktSNT (int n)
{
	int dem = 0;
	for (int i = 1; i <= n ; i++)
	{
		if ( n % i == 0)
		{
			dem ++;
		}	
	}
	if ( dem == 2)
	{
			return 1;
	}
	return 0;
}
int ktSOAM (int a[][COL], int m, int n)
{
	int dem = 0;
	for( int i = 0 ; i < n ; i++)
	{
		if(a[m][i] < 0)
		{
				dem ++;
		}		
	}
	if (dem != 0)
	{
		return 1;
	}
	return 0;
}
int tinhTongCot (int a[][COL], int m, int n)
{
	int s = 0;
	for (int i = 0 ; i < m ; i++)
	{
		s = s + a[i][n];
	}
	return s;
}
int tinhTongDong (int a[][COL], int m, int n)
{
	int s = 0;
	for (int i = 0 ; i < n ; i++)
	{
		s = s + a[m][i];
	}
	return s;
}
int tinhTongMang (int a[][COL], int m, int n)
{
	int s = 0;
	for (int i = 0 ; i < m ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			s= s + a[i][j];
		}
	}
	return s;
}
void xuatMang (int a[][COL], int m, int n)
{
	for (int i = 0 ; i < m ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			printf("%6d", a[i][j]);
		}
		printf("\n");
	}
}
void nhapMang (int a[][COL], int m, int n)
{
	for (int i = 0 ; i < m ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			printf("\nNhap gia tri cho phan tu A[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
			printf ("\n");
	}
}


