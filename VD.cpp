#include <stdio.h>
#include <stdlib.h>

void Nhap(int **a, int D, int C) 
{
    for (int i = 0; i < D; i++) 
	{
        for (int j = 0; j < C; j++)
		{
            printf("Nhap phan tu thu [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void Xuat(int **a, int D, int C)
 {
    printf("\nNoi dung mang hai chieu:\n");
    printf ("So dong %d\n",D);
    printf ("So cot %d\n",C);
    for (int i = 0; i < D; i++)
	{
        for (int j = 0; j < C; j++) 
		{
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
void Ghi(const char *filename, int **a, int D, int C) 
{
    FILE *file = fopen(filename, "w");
    if (file == NULL) 
	{
        printf("Khong the mo tap tin de ghi!\n");
        return;
    }
    fprintf(file, " %d %d\n", D, C);
    for (int i = 0; i < D; i++) 
	{
        for (int j = 0; j < C; j++) 
		{
            fprintf(file, "%d ", a[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Du lieu da duoc ghi vao tap tin '%s'.\n", filename);
}

void Doc(const char *filename) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) 
	{
        printf("Khong the mo tap tin de doc!\n");
        return;
    }
    int D, C;
    fscanf(file, "%d %d", &D, &C);
    // Cap phat bo nho cho mang hai chieu
    int **a = (int **)malloc(D * sizeof(int *));
    for (int i = 0; i < D; i++) 
	{
        a[i] = (int *)malloc(C * sizeof(int));
    }

    // Doc du lieu tu tap tin
    for (int i = 0; i < D; i++) 
	{
        for (int j = 0; j < C; j++) 
		{
            fscanf(file, "%d", &a[i][j]);
        }
    }
    fclose(file);
    // Xuat mang hai chieu
    printf("\nNoi dung mang hai chieu doc tu tap tin:\n");
    Xuat(a, D, C);

    // Giai phong bo nho
    for (int i = 0; i < D; i++) 
	{
        free(a[i]);
    }
    free(a);
}
void Mo(const char *filename) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) 
	{
        printf("Khong the mo tap tin '%s'!\n", filename);
        return;
    }
    printf("Mo tap tin '%s' thanh cong!\n", filename);
    fclose(file);
}
int main() 
{
    int D, C;
    printf("Nhap so dong: ");
    scanf("%d", &D);
    printf("Nhap so cot: ");
    scanf("%d", &C);

    // Cap phat bo nho cho mang hai chieu
    int **a = (int **)malloc(D * sizeof(int *));
    for (int i = 0; i < C; i++)
	{
        a[i] = (int *)malloc(C * sizeof(int));
    }

    // Nhap gia tri cho mang hai chieu
    Nhap(a, D, C);
    // Xuat mang hai chieu
    Xuat(a, D, C);
    // Ghi du lieu vao tap tin
	Ghi("vd.txt", a, D, C);
    // Doc du lieu tu tap tin
    Doc("vd.txt");
    // Mo tap tin de kiem tra
    Mo("vd.txt");
    // Giai phong bo nho
    for (int i = 0; i < D; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}

