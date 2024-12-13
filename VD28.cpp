#include <stdio.h>
void Nhap_GT_Mang (int A[], int n);
int main()
{
	//Khai bao
	int n, A[n];
	//Nhap so phan tu
	printf ("\nNhap so phan tu cho mang: ");
	scanf ("%d",&n);
	//Nhap mang
	 Nhap_GT_Mang (A,n);
	 //Mo tap tin
	 FILE *file = fopen ("mang.txt", "w");
	 if (file == NULL)
	 {
	 	printf ("\n\nKhong the mo file da ghi. ");
	 	return 1;
	 }
	 //Ghi so phan tu cho tap tin
	 fprintf (file, "%d\n", n);
	 for (int i = 0; i < n; i++)
	 {
	 	//Ghi cac gia tri phan tu vao tep
	 	fprintf (file, "  %d  ", A[i]);
	 }
	 fprintf (file, "\n");
	 //Dong tap tin
	 fclose (file);
	 printf ("\n\nGia tri da duoc luu thanh cong.");
	 return 0;
}
void Nhap_GT_Mang (int A[], int n)
{
	printf ("\n\nNhap gia tri cho mang: ");
	for (int i = 0; i < n; i++)
	{
		printf ("\n\nNhap phan tu thu %d: ",i);
		scanf ("%d",&A[i]);
	}
}

