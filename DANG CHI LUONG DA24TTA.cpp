#include <stdio.h>
void Nhap_Mang (int A[], int n);
void Xuat_Mang (int A[], int n);
void Doi_Cho (int *a, int *b);
void Sap_XepSle(int A[], int n );
void InsertionSort(int A[], int n );
void InterchangeSort(int A[], int n);
void BubbleSort(int A[], int n);
void CreateHeap(int A[], int n);
void Shift (int A[], int left, int right);
void HeapSort (int A[], int n);
void QuickSort(int A[], int left, int right);
int main ()
{
	int n , left, right;
	int A[n];
	//Nhap so luong phan tu n
	do 
	{
		printf ("\nNhap so luong phan tu: ");
		scanf ("%d",&n);
	} while (n < 0);
	Nhap_Mang (A,n);
	Xuat_Mang(A,n);	
	printf ("\n\nMang sau khi duoc sap xep. ");
	Sap_XepSle(A,n);
	printf ("\nMang sau khi duoc sap xep thep SelectionSort: ");
	Xuat_Mang(A,n);
	InsertionSort(A, n );
	printf ("\nMang sau khi duoc sap xep thep IntertionSort: ");
	Xuat_Mang(A,n);
	InterchangeSort( A, n);
	printf ("\nMang sau khi duoc sap xep thep InterchangeSort: ");
	Xuat_Mang(A,n);
	BubbleSort(A,n);
	printf ("\nMang sau khi duoc sap xep thep BublleSort: ");
	Xuat_Mang(A,n);
	HeapSort(A,n);
	printf ("\nMang sau khi duoc sap xep thep HeapSort: ");
	Xuat_Mang(A,n);
	QuickSort(A, left, right);
	printf ("\nMang sau khi duoc sap xep thep QuickSort: ");
	Xuat_Mang(A,n);
	return 0;
}
void Nhap_Mang (int A[], int n)
{
	for (int i = 1 ; i <= n; i++)
	{
		printf ("\nNhap gia tri cua phan tu mang thu %d: ", i);
		scanf("%d",&A[i]);
	}
}
void Xuat_Mang (int A[], int n)
{
	for (int i = 1 ; i <= n; i++)
	{
		printf ("\t %d" , A[i]);	
	}
}
void Doi_Cho (int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void Sap_XepSle(int A[], int n )
{
int min; 
	for (int i = 1; i < n ; i++)
	{
		min = i;
		for(int j = i + 1; j <= n  ; j++)
			{
				if (A[j] < A[min])
				min = j;
			}
		if (min != i)
		Doi_Cho(&A[min], &A[i]);
	}
}
void InsertionSort(int A[], int n )
{
int pos, x;
for(int i = 2 ; i <= n ; i++)
	{
		x = A[i];
		for(pos = i - 1;(pos >= 1) && (A[pos] > x); pos--)
		A[pos + 1] = A[pos];
		A[pos + 1] = x;
	}
}
void InterchangeSort(int A[], int n)
{
	int i, j;
	for (i = 1 ; i < n ; i++)
	for (j = i + 1; j <= n ; j++)
	if(A[j] < A[i]) 
	Doi_Cho(&A[i], &A[j]);
}
void BubbleSort(int A[], int n)
{
	int i, j;
	for (i = 1 ; i < n ; i++)
	for (j = n; j > i ; j --)
	if(A [j] < A[j-1])
	Doi_Cho(&A[j], &A[j-1]);
}
void Shift (int A[], int left, int right)
{
	int x, curr, joint;
	curr = left; joint =2 * curr;
	x = A[curr];
	while (joint <= right)
	{
		if (joint < right) 
		if (A[joint] < A[joint+1])
		joint = joint + 1;
		if (A[joint] < x) break; 
	else
		{
		A[curr] = A[joint];
		curr = joint; 
		joint = 2 * curr;
		}
	A[curr] = x; 
	}
}
void CreateHeap(int A[], int n)
{
	int left;
	for (left = (n) / 2; left >= 1; left --)
	Shift(A, left, n);
}
void HeapSort (int A[], int n)
{
	int right;
	CreateHeap(A, n); 
	right = n; 
	while (right > 1)
	{
		Doi_Cho(&A[1], &A[right]);
		right --;
		Shift(A,1,right);
	}
}
void QuickSort(int A[], int left, int right)
{
	int i, j, x;
	if (left >= right) return;
	x = A[(left+right) / 2]; 
	i = left; j = right;
	while(i <= j)
	{
		while(A[i] < x) i++;
		while(A[j] > x) j--;
		if(i <= j)
			{
				Doi_Cho(&A[i], &A[j]);
				i++ ; j--;
			}
	}
	QuickSort(A, left, j);
	QuickSort(A, i, right);
}
