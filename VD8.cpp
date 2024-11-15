#include <stdio.h>
#include <math.h>
int main()
{ 
	const float PI = 3.1415;
	int L=50, B=23, H=30;
	float C=12.56, HThang, HTron, S, r;
	//Tinh dien tich hinh thang
	HThang=((L + B) * H) / 2;
	//Tinh dien tich hinh tron
	r = C / (2 * PI);
	HTron= r * r * PI;
	//Dien tich con lai cua san truong
	S= HThang - HTron;
	printf ("Dien tich con lai cua san truong la: %f",S);
	return 0;
}





