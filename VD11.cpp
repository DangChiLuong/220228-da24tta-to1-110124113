#include <stdio.h>
int main()
{
	int a = 5,b = 6;
	float Xn, Xt;
	/*Phep chi so nguyen, ket qua x = 0*/
	 Xn = a/b;
	 printf ("Ket qua cua phep toan:%f",Xn);
	/*Phep chia so thuc, ket qua x = 0.83333*/
	 Xt = (float)a/b;
	 printf ("\nKet qua cua phep toan:%f",Xt);
	return 0;
}

