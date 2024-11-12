#include <stdio.h>
int  main()
{
	int a=5, b=2, KQ;
	char pt;
	printf("Nhap phep toan: ");
	scanf ("%c",&pt);
	switch (pt)
	{
		case '+':
		{
			KQ=a+b;
		    printf ("Ket qua phep toan la %d:",KQ);
			break;
		}
		case '-':
		{
			KQ=a-b;
			printf ("Ket qua phep toan la %d:",KQ);
			break;
		}
			case '*':
			{	
				KQ=a*b;
				printf ("Ket qua phep toan la %d:",KQ);
				break;
			}
			case '/':{
				KQ=(float)a/b;
				printf ("Ket qua phep toan la %5.f:",KQ);
				break;
			}
	}
	return 0;
}
