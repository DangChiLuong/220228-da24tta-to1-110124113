#include <stdio.h>
int main() {
    int n;
    long T = 1;  

    // Nhap so nguyen n
    printf("Nhap gia tri n: ");
    scanf("%d", &n);
  	//Tinh tich cac so tu 1 - n
    for (int i = 1; i <= n; i++) 
	{
        T = T * i; 
    }

    // In ket qua
    printf("\nket qua tich cac so tu 1- %d la: %d",n,T);
    return 0;
}

