#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long;
#define MAX 100
typedef struct NhanVien{
	char ma[11],ten[41];
	float diem;
}nv;
void tieuDe (){
	cout <<"MaNV\tTen\t\tDiem";
	cout << "\n";
}
void nhapN (int &n){
	do{
		cout << "Nhap so luong nhan vien: "; cin >> n;
		if (n <= 0 || n > MAX) cout << "\nBan da nhap sai moi nhap lai !";
	}while (n <= 0 || n > MAX);
}
void nhapNv (nv &a){
	cin.ignore();
	cout << "Nhap ma nhan vien: ";
	cin.get(a.ma,11);
	cin.ignore();
	cout << "Nhap ten nhan vien: ";
	cin.get(a.ten,41);
	cout << "Nhap diem: ";
	cin >> a.diem;
} 
void xuatNv (nv &a){
	cout <<a.ma << "\t" <<a.ten<<"\t\t"<< a.diem;
	cout << "\n";
} 
void nhapDs (nv a[], int n){
	for (int i = 0; i < n; i++){
		nhapNv(a[i]);
	}
}
void xuatDs (nv a[], int n){

	tieuDe();
	for (int i = 0; i < n; i++){
		xuatNv(a[i]);
	}

}
void InterchangeSort (nv a[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (strcmp(a[i].ten,a[j].ten) < 0){
				swap(a[i],a[j]);
			}
		}
	}
}
void bubbleSort (nv a[], int n){
	for (int i = 0; i < n - 1; i++){
		for (int j = n - 1; j > i; j--){
			if (strcmp(a[j-1].ten,a[j].ten) < 0) {
				swap(a[j-1],a[j]);
			}
		}
	}
}
void slectionSort (nv a[], int n){
	for (int i = 0; i < n - 1; i++){
		int tmp = i;
		for (int j = i + 1; j < n; j++){
			if (strcmp (a[j].ten,a[tmp].ten) > 0)
				tmp = j;
		}
		swap(a[tmp],a[i]);
	}
}
void insertionSort (nv a[], int n){
	int pos;
	nv x;
	for (int i = 1; i < n; i++){
		x = a[i];
		pos = i + 1;
		while (pos >= 0 and strcmp(a[pos].ten,x.ten) > 0){
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1] = x;
	}
}
int main(){
	nv a[MAX];
	int n; nhapN(n);
	nhapDs(a,n);
	xuatDs(a,n);
	cout << "\n";
	InterchangeSort(a,n);
	cout << "\n*Ten Nhan Vien Sau Khi Sap Xep*\n";
	xuatDs(a,n);
	cout << "\n";
	bubbleSort(a,n);
	cout << "\n*Ten Nhan Vien Sau Khi Sap Xep*\n";
	xuatDs(a,n);
	cout << "\n";
	slectionSort(a,n);
	cout << "\n*Ten Nhan Vien Sau Khi Sap Xep*\n";
	xuatDs(a,n);
	cout << "\n";
	insertionSort(a,n);
	cout << "\n";
	cout << "\n*Ten Nhan Vien Sau Khi Sap Xep*\n";
	xuatDs(a,n);
	return 0;
}
