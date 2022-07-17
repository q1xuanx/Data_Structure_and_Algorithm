#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
typedef struct sinhVien{
	char masv[11],ten[41];
	float dtb;
}sv;
typedef struct Node{
	sv data;
	struct Node* next;
}*node;
struct List{
	node phead;
	node ptail;
};
void init (List &ds){
	ds.phead = NULL;
	ds.ptail = NULL;
}
int empty (List ds){
	return (ds.phead == NULL);
}
node cnode (sv x){
	node p = new Node;
	if (p == NULL){
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}
void insertLast (List &ds,node p){
	if(ds.phead == NULL){
		ds.phead = p;
		ds.ptail = p;
	}else {
		ds.ptail->next = p;
		ds.ptail=p;
	}
}
void input (List &ds, int n){
	for (int i = 0; i < n; i++){
		sv x;
		cout << "Nhap ma sinh vien: ";
		fflush(stdin);
		gets(x.masv);
		cout << "Nhap ten sinh vien: ";
		fflush(stdin);
		gets(x.ten);
		fflush(stdin);
		cout << "Nhap diem trung binh: ";
		cin >> x.dtb;
		cout << "\n \n";
		node p = new Node;
		p = cnode(x);
		insertLast(ds,p);
	}
}
void show (List ds){
	for (node p = ds.phead; p != NULL; p=p->next){
		cout << "Ma sinh vien: " << p->data.masv << endl;
		cout << "Ten sinh vien: " << p->data.ten << endl;
		cout << "Diem trung binh: " << p->data.dtb << endl;
	}	
}
void dtb5 (List ds){
	for (node p = ds.phead; p != NULL; p=p->next){
		if (p->data.dtb > 5){
			cout << "Ma sinh vien: " << p->data.masv << endl;
			cout << "Ten sinh vien: " << p->data.ten << endl;
			cout << "Diem trung binh: " << p->data.dtb << endl;
		}
	}
}
void timten (List ds, char *x){
	int dem = 0;
	for (node p = ds.phead; p != NULL; p=p->next){
		if (strstr(p->data.ten,x)){
			cout << "Ma sinh vien: " << p->data.masv << endl;
			cout << "Ten sinh vien: " << p->data.ten << endl;
			cout << "Diem trung binh: " << p->data.dtb << endl;
			dem++;
		}
	}
	if (dem == 0){
		cout << "Khong co sinh vien can tim\n";
	}
}
int main(){
	List ds;
	int n;
	cout << "Nhap so luong sinh vien: "; cin >> n;
	input(ds,n);
	cout << "DANH SACH SINH VIEN\n";
	show(ds);
	cout << "\n";
	cout << "SINH VIEN CO DIEM TRUNG BINH > 5\n";
	dtb5(ds);
	fflush(stdin);
	cout << "Nhap ten sinh vien can tim: ";
	char *x = (char*)calloc(41,sizeof(char));
	gets(x);
	timten(ds,x);
	return 0;
}

