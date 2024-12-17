#include <stdio.h>
#include <string.h>
#define MAX_SP 100  
typedef struct 
{
    int ngay;
    int thang;
    int nam;
} NGAY_THANG;
typedef struct 
{
    char maSP[20];
    char tenSP[50];
    float donGia;
    NGAY_THANG ngaySX;
    float thoiGianSuDung;
} SAN_PHAM;
//Khai bao mang chua thong tin san pham
SAN_PHAM dsSP[MAX_SP];
int soLuongSP = 0;
//1.Nhap san pham
void ghiVaoTapTin() 
{
    FILE *file = fopen("danhsachsp.txt", "wb");
    if (file == NULL) 
	{
        printf("Loi mo tap tin.\n");
        return;
    }
	//Nhap so luong san pham
    printf("Nhap so luong san pham: ");
    scanf("%d", &soLuongSP);
	//Nhap thong tin san pham
    for (int i = 0; i < soLuongSP; i++) 
	{
        SAN_PHAM sp;
        printf("\nNhap ma san pham: ");
        getchar();
        fgets(sp.maSP, sizeof(sp.maSP), stdin);
        sp.maSP[strcspn(sp.maSP, "\n")];
        //Nhap ten san pham
        printf("Nhap ten san pham: ");
        fgets(sp.tenSP, sizeof(sp.tenSP), stdin);
        sp.tenSP[strcspn(sp.tenSP, "\n")];
		//Nhap don gia
        printf("Nhap don gia: ");
        scanf("%f", &sp.donGia);
		//Nhap ngay thang nam
        printf("Nhap ngay san xuat: ");
        scanf("%d", &sp.ngaySX.ngay);
		printf("\nNhap thang san xuat: ");
        scanf("%d", &sp.ngaySX.thang);
        printf("Nhap nam san xuat: ");
        scanf("%d", &sp.ngaySX.nam);
        printf("Nhap thoi gian su dung (so nam): ");
        scanf("%f", &sp.thoiGianSuDung);
        //Ghi tung san pham vao file
        fwrite(&sp, sizeof(SAN_PHAM), 1, file);
	}	
    fclose(file);
    printf("Danh sach san pham da duoc ghi vao tap tin.\n");
}
// Doc du lieu tu tap tin
void docTuTapTin() 
{
    FILE *f = fopen("danhsachsp.dat", "rb");
    if (f == NULL) 
	{
        printf("Loi mo tap tin.\n");
        return;
    }
    soLuongSP = 0;
    while (fread(&dsSP[soLuongSP], sizeof(SAN_PHAM), 1, f)) 
	{
        soLuongSP++;
    }
    fclose(f);
    printf("Danh sach san pham da duoc doc tu tap tin.\n");
}
//Xuat ra man hinh
void hienThiTatCaSanPham() {
    if (soLuongSP == 0) {
        printf("Danh sach san pham rong.\n");
        return;
    }

    for (int i = 0; i < soLuongSP; i++) {
        printf("\nMa san pham: %s\n", dsSP[i].maSP);
        printf("Ten san pham: %s\n", dsSP[i].tenSP);
        printf("Don gia: %.2f\n", dsSP[i].donGia);
        printf("Ngay san xuat: %d-%d-%d\n", dsSP[i].ngaySX.ngay, dsSP[i].ngaySX.thang, dsSP[i].ngaySX.nam);
        printf("Thoi gian su dung: %.2f nam\n", dsSP[i].thoiGianSuDung);
    }
}
// Tim kiem theo ma
SAN_PHAM* timSanPhamTheoMa(char maSP[]) 
{
    for (int i = 0; i < soLuongSP; i++) 
	{
        if (strcmp(dsSP[i].maSP, maSP) == 0)
		 {
            return &dsSP[i];
        }
    }
    return NULL;
}
//Tim kiem theo ten
void timSanPhamTheoTen(char tenSP[]) 
{
    int found = 0;
    for (int i = 0; i < soLuongSP; i++) 
	{
        if (strstr(dsSP[i].tenSP, tenSP) != NULL) 
		{
            printf("\nMa san pham: %s\n", dsSP[i].maSP);
            printf("Ten san pham: %s\n", dsSP[i].tenSP);
            printf("Don gia: %.2f\n", dsSP[i].donGia);
            printf("Ngay san xuat: %d-%d-%d\n", dsSP[i].ngaySX.ngay, dsSP[i].ngaySX.thang, dsSP[i].ngaySX.nam);
            printf("Thoi gian su dung: %.2f nam\n", dsSP[i].thoiGianSuDung);
            found = 1;
        }
    }
    if (!found) 
	{
        printf("Khong tim thay san pham co ten '%s'.\n", tenSP);
    }
}
//Tim kiem theo nam
void timSanPhamTheoNamSX(int namSX) 
{
    int found = 0;
    for (int i = 0; i < soLuongSP; i++) 
	{
        if (dsSP[i].ngaySX.nam == namSX) 
		{
            printf("\nMa san pham: %s\n", dsSP[i].maSP);
            printf("Ten san pham: %s\n", dsSP[i].tenSP);
            printf("Don gia: %.2f\n", dsSP[i].donGia);
            printf("Ngay san xuat: %d-%d-%d\n", dsSP[i].ngaySX.ngay, dsSP[i].ngaySX.thang, dsSP[i].ngaySX.nam);
            printf("Thoi gian su dung: %.2f nam\n", dsSP[i].thoiGianSuDung);
            found = 1;
        }
    }
    if (!found) 
	{
        printf("Khong tim thay san pham nao san xuat trong nam %d.\n", namSX);
    }
}
// Sap xep
void sapXepTheoDonGia() {
    for (int i = 0; i < soLuongSP - 1; i++) {
        for (int j = i + 1; j < soLuongSP; j++) {
            if (dsSP[i].donGia < dsSP[j].donGia) {
                SAN_PHAM temp = dsSP[i];
                dsSP[i] = dsSP[j];
                dsSP[j] = temp;
            }
        }
    }
    printf("Danh sach san pham da duoc sap xep theo don gia.\n");
}
// 8. Menu chính
void menu() {
    int luaChon;
    do {
        printf("\nQuan ly thong tin san pham\n");
        printf("1. Nhap va ghi danh sach san pham vao tap tin\n");
        printf("2. Hien thi tat ca san pham\n");
        printf("3. Tim san pham theo ma\n");
        printf("4. Tim san pham theo ten\n");
        printf("5. Tim san pham theo nam san xuat\n");
        printf("6. Sap xep san pham theo don gia\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                ghiVaoTapTin();
                break;
            case 2:
                docTuTapTin();
                hienThiTatCaSanPham();
                break;
            case 3: {
                char maSP[20];
                printf("Nhap ma san pham can tim: ");
                getchar();
                fgets(maSP, sizeof(maSP), stdin);
                maSP[strcspn(maSP, "\n")];

                SAN_PHAM *sp = timSanPhamTheoMa(maSP);
                if (sp != NULL) {
                    printf("San pham tim thay:\n");
                    printf("Ma san pham: %s\n", sp->maSP);
                    printf("Ten san pham: %s\n", sp->tenSP);
                    printf("Don gia: %.2f\n", sp->donGia);
                    printf("Ngay san xuat: %d-%d-%d\n", sp->ngaySX.ngay, sp->ngaySX.thang, sp->ngaySX.nam);
                    printf("Thoi gian su dung: %.2f nam\n", sp->thoiGianSuDung);
                } else {
                    printf("Khong tim thay san pham.\n");
                }
                break;
            }
            case 4: {
                char tenSP[50];
                printf("Nhap ten san pham can tim: ");
                getchar();
                fgets(tenSP, sizeof(tenSP), stdin);
                tenSP[strcspn(tenSP, "\n")]; 
                timSanPhamTheoTen(tenSP);
                break;
            }
            case 5: {
                int namSX;
                printf("Nhap nam san xuat can tim: ");
                scanf("%d", &namSX);
                timSanPhamTheoNamSX(namSX);
                break;
            }
            case 6:
                sapXepTheoDonGia();
                hienThiTatCaSanPham();
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 7);
}
// Hàm main
int main() 
{
    menu();
    return 0;
}

