#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Menu() {
	int Chon;
	printf("===============Menu===============\n");
	printf("1. Tao mang 1 chieu ngau nhien co gia tri >= 15.\n");
	printf("2. Tao mang chua toan so chan.\n");
	printf("3. Tim kiem x trong a? theo thuat toan tim kiem Linear Search.\n");
	printf("4. Sap xep a tang dan / giam dan theo thuat toan Interchange Sort.\n");
	printf("5. Tim kiem x trong a theo giai th Binary Search voi mang a da duoc sap tang.\n");
	printf("6. Sap xep a tang dan theo giai thuat Selection Sort.\n");
	printf("7. Sap xep a tang dan theo giai thuat Quick Sort.\n");
	printf("8. Thoat.\n");
	printf("Vui Long Nhap Su Lua Chon :");
	scanf_s("%d", &Chon);
	return Chon;
}

void TaoMangNgauNhien(int a[], int n) {
	// Khởi tạo bộ sinh số ngẫu nhiên
	srand(time(0));

	// Tạo mảng ngẫu nhiên với các giá trị >= 15
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 86 + 15;
	}
}

void InMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void MangChuaToanSoChan(int a[], int n) {
	// Khởi tạo bộ sinh số ngẫu nhiên
	srand(time(0));

	// Tạo mảng ngẫu nhiên với các giá trị chẵn >= 15
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 86 + 15;
		if (a[i] % 2 != 0) {
			i--;
		}
	}
	printf("Mang chua toan so chan la: ");
	InMang(a, n);
}

int linearSearch(int arr[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			return i; // Trả về vị trí của x trong mảng
		}
	}
	return -1; // Trả về -1 nếu không tìm thấy x
}

void InterchangeSortTangDan(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void InterchangeSortGiamDan(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int BinarySearch(int a[], int n, int x) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (a[mid] == x) {
			return mid;  // Tìm thấy x tại vị trí mid
		}
		else if (a[mid] < x) {
			left = mid + 1;  // Tìm kiếm phía bên phải
		}
		else {
			right = mid - 1;  // Tìm kiếm phía bên trái
		}
	}

	return -1;  // Không tìm thấy x
}

void XuLyMenu(int Chon, int a[], int n) {
	int x, result, loaiSapXep;
	switch (Chon) {
	case 1:
		TaoMangNgauNhien(a, n);
		printf("Mang ngau nhien: ");
		InMang(a, n);
		break;
	case 2:
		MangChuaToanSoChan(a, n);
		break;
	case 3:
		TaoMangNgauNhien(a, n);
		printf("Mang ngau nhien: ");
		InMang(a, n);
		printf("Nhap gia tri can tim: ");
		scanf_s("%d", &x);
		result = linearSearch(a, n, x);
		if (result != -1) {
			printf("Gia tri %d duoc tim thay tai vi tri %d.\n", x, result);
		}
		else {
			printf("Gia tri %d khong co trong mang.\n", x);
		}
		break;
	case 4:
		TaoMangNgauNhien(a, n);
		printf("Chon 1 de sap xep tang dan, 2 de sap xep giam dan: ");
		scanf_s("%d", &loaiSapXep);
		if (loaiSapXep == 1) {
			InterchangeSortTangDan(a, n);
			printf("Mang sau khi sap xep tang dan: ");
		}
		else if (loaiSapXep == 2) {
			InterchangeSortGiamDan(a, n);
			printf("Mang sau khi sap xep giam dan: ");
		}
		else {
			printf("Lua chon khong hop le!\n");
			return;
		}
		InMang(a, n);
		break;
	case 5:
		TaoMangNgauNhien(a, n);
		InMang(a, n);
		printf("Nhap gia tri can tim: ");
		scanf_s("%d", &x);
		InterchangeSortTangDan(a, n);  // Đảm bảo mảng được sắp xếp tăng dần trước khi tìm kiếm
		result = BinarySearch(a, n, x);
		if (result != -1) {
			printf("Tim thay %d tai vi tri %d\n", x, result);
		}
		else {
			printf("Khong tim thay %d trong mang\n", x);
		}
		break;
	default:
		printf("Lua chon khong hop le!\n");
		break;
	}
}

int main() {
	int Chon, n;

	printf("Nhap kich thuoc mang: ");
	scanf_s("%d", &n);

	int *a = (int*)malloc(n * sizeof(int));

	do {
		Chon = Menu();
		if (Chon == 8) {
			printf("Thoat chuong trinh.\n");
			break;
		}
		XuLyMenu(Chon, a, n);
	} while (1);

	free(a);
	return 0;
}
