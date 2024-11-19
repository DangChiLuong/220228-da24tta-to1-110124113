#include <stdio.h>
#include <stdbool.h>
void In_Gia_Tri (int n);
void In_Gia_Tri_Chan (int n);
void In_Cac_So_Chia_Het_Cho_5 (int n);
bool Kiem_Tra_So_Nguyen_To(int x);
void In_So_Nguyen_To(int n);
void Tinh_Tong(int n);
int Tinh_Tong_So_Le (int n);
int Tinh_Tong_SNT (int n);
float Tinh_TB_So_Le (int n);
float Tinh_TB_So_Le_Nho_Hon_n (int n);
int main()
{
	//Nhap so nguyen n < 100
	int n;
	do 
	{	
		printf ("Nhap so nguyen duong n < 100: ");
		scanf ("%d",&n);
	} while (n <= 0 || n > 100);
    if (n > 0 && n < 100)
	{
		//In tat ca cac gia tri tu 1 - n
		printf ("\nTat ca ca gia tri tu 1 den %d la:",n);
		printf("\n");
		In_Gia_Tri(n);
		//In cac so chan tu 1 -n
		printf ("\nCac so chan tu 1 - %d la:",n);
		printf("\n");
		In_Gia_Tri_Chan(n);
		//In cac gia tri chia het cho 5 tu 1 - n
		printf ("\nCac so nguyen tu 1 - %d chia het cho 5 la:",n);
		printf ("\n");
		In_Cac_So_Chia_Het_Cho_5(n);
		//In cac so nguyen to tu 1 - n
		printf ("\nCac so nguyen to tu 1 - %d la:",n);
		printf ("\n");
		In_So_Nguyen_To(n);
		//Tinh tong cac so tu 1 den n
		Tinh_Tong(n);
		//Tinh tong cac so le
		printf ("\nTong cac so le tu 1 - %d la: %d",n,Tinh_Tong_So_Le(n));
	printf ("\n");
		//Tinh tong cac so nguyen to
		Tinh_Tong_SNT(n);
		//Tinh tong trung binh
		printf ("\nTong trung binh cac so le la:%f",Tinh_TB_So_Le(n));
		//Tinh tong trung binh cac SNT
		printf ("\nTong trung binh cac so SNT la:%f",Tinh_TB_So_Le_Nho_Hon_n(n));	
	} 
	return 0;
}
void In_Gia_Tri (int n)
{
	for (int i = 1; i <= n;i++)
	{
		//In gia tri
		printf ("%d\t",i);
	}
	printf("\n");
}
void In_Gia_Tri_Chan (int n)
{
	for (int i = 2; i <= n; i = i + 2)
	{
		//In cac gia tri chan
		{
			printf ("%d\t",i);
		}
	}
	printf ("\n");
}
void In_Cac_So_Chia_Het_Cho_5 (int n)
{
	for (int i = 1; i <= n ; i++)
	{
		if (i%5 == 0)
		{
			printf ("%d\t",i);
		}
	}
	printf("\n");
}
bool Kiem_Tra_So_Nguyen_To(int x) 
{
    if (x <= 1) 
	{
        return false;  
    }
    for (int i = 2; i * i <= x; i++) 
	{
        if (x % i == 0) 
		{
            return false;  
        }
    }
    return true;  
}
void In_So_Nguyen_To(int n) 
{
    for (int i = 2; i < n; i++) 
	{
        if (Kiem_Tra_So_Nguyen_To(i)) 
		{
            printf("%d\t", i);
        }
    }
    printf("\n");
}
void Tinh_Tong (int n)
{
	int s = 0;
	for (int i = 1; i <= n;i++)
	{
		s = s + i;
	}
	printf ("\nTong cac so tu 1 - %d la:%d",n,s);
	printf ("\n");
}
int Tinh_Tong_So_Le (int n)
{
	int s = 0;
	for ( int i = 1; i <= n; i = i + 2)
	{
		s = s + i;
	}
	return s;
}
int Tinh_Tong_SNT (int n)
{
	int s = 0;
	for (int i = 2; i < n;i++)
	if (Kiem_Tra_So_Nguyen_To(i))
	{
		s = s + i;
	}
	printf ("\nTong ca so nguyen to nho hon %d la: %d",n,s);
	printf ("\n");
	return s;
}
float Tinh_TB_So_Le (int n)
{
	float stb;
	stb = Tinh_Tong_So_Le(n) /(float)n;
    return stb;
}
float Tinh_TB_So_Le_Nho_Hon_n (int n)
{
	float stb;
	stb = Tinh_Tong_SNT(n) /(float)n;
    return stb;
}

