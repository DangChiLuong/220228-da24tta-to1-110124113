#include <stdio.h>
#include <string.h>
struct sinhvien{
	char mssv[10];
	char hoten[100];
	int namsinh;
	float dtb;	
};
typedef struct sinhvien sv;
void nhapsv(sv a[], int n){
	printf("\tNHAP THONG TIN CHO CAC SINH VIEN\t\n");
	for (int i=1;i<n;i++)
	{
		printf("\tnhap thong tin sinh vien thu %d\n", i);
		getchar();
		printf("nhap ho ten: ");
		gets(a[i].hoten);
		printf("nhap ma so sinh vien: ");
		scanf("%s",a[i].mssv);
		printf("nhap nam sinh cua sinh vien: ");
		scanf("%d",&a[i].namsinh);
		printf("nhap diem trung binh: ");
		scanf("%f",&a[i].dtb);
	}
	printf("\n");
}
void xuatsv(sv a[], int n){
	printf("\tTHONG TIN CUA CAC SINH VIEN VUA NHAP\t\n");
	for (int i=1;i<n;i++){
		printf("\tthong tin cua sinh vien thu %d\n", i);
		printf("ho ten: %s\n",a[i].hoten);
		printf("ma so sinh vien: %s\n",a[i].mssv);
		printf("nam sinh: %d\n",a[i].namsinh);
		printf("diem trung binh: %.2f\n",a[i].dtb);
	}
	printf("\n");
}
void BubbleSort(sv a[], int n) {
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (a[j].dtb > a[j + 1].dtb) {
                sv temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void InsertionSort(sv a[], int n) {
    for (int i = 2; i <= n; i++) {
        sv key = a[i];
        int j = i - 1;
        while (j >= 1 && a[j].dtb > key.dtb) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void QuickSort(sv a[], int low, int high) {
    if (low < high) {
        int pivot = a[high].dtb;
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (a[j].dtb <= pivot) {
                i++;
                sv temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        sv temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;
        QuickSort(a, low, i);
        QuickSort(a, i + 2, high);
    }
}

void SelectionSort(sv a[], int n) {
    for (int i = 1; i <= n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j <= n; j++) {
            if (a[j].dtb < a[minIdx].dtb) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            sv temp = a[i];
            a[i] = a[minIdx];
            a[minIdx] = temp;
        }
    }
}

void InterchangeSort(sv a[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i].dtb > a[j].dtb) {
                sv t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main(){
	int n;
	printf("nhap so luong sinh vien: ");
	scanf("%d",&n);
	sv a[n+1];
	nhapsv(a,n+1);
	xuatsv(a,n+1);
	BubbleSort(a,n+1);
	xuatsv(a,n+1);
	SelectionSort(a,n+1);
	xuatsv(a,n+1);
	QuickSort(a,1,n);
	xuatsv(a,n+1);
	InsertionSort(a,n+1);
	xuatsv(a,n+1);
	InterchangeSort(a,n+1);
	xuatsv(a,n+1);
	
}

