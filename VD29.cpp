#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *p, n;
	 FILE *file = fopen ("mang.txt", "r");
	 if (file == NULL)
	 {
	 	printf ("\n\nKhong the mo file da ghi. ");
	 	return 1;
	 }
	 //Doc so phan tu n trong flie
	 fscanf (file, "%d", &n);
	 //Cap phat vung nho dong
	 p = (int*) malloc (n *sizeof (int));
	 {
	 	if (p == NULL)
	 	{
	 		printf ("\n\nKhong the cap phat vung nho dong. ");
	 		fclose (file);
	 		return 1;
	 	}
	 }
	 //Doc cac gia tri trong mang
	 for (int i = 0; i < n; i++)
	 {
	 	fscanf (file, "%d", &p[i]);
	 }
	 //Dong file
	 fclose (file);
	 //In cac gia tri trong mang da doc duoc
	 printf ("Cac gia tri trong mang da doc duoc la:\n");
	 for (int i = 0; i < n; i++)
	 {
	 	printf ("%d  ", p[i]);
	 }
	 printf ("\n");
	 return 0;
}

