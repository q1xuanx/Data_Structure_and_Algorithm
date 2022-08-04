#include <bits/stdc++.h>
using namespace std;
typedef struct sinhVien{
	char ma[11],ten[41];
	float dtb;
}sv;
typedef struct NODE{
	sv x;
	NODE *next;
}*node;
void init (node &phead){
	phead = NULL;
}
node cNode (sv x){
	node p = new NODE;
	p->x = x;
	p->next = NULL;
	return p;
}
void nhap1SinhVien (sv &x){
	cin.ignore();
	cout << "Nhap ma sinh vien: ";
	cin.get(x.ma,11);
	cin.ignore();
	cout << "Nhap ten sinh vien: ";
	cin.get(x.ten,41);
	cout << "Nhap diem: ";
	cin >> x.dtb;
}
void xuat1SinhVien (sv x){
	cout << "Ma sinh vien: " << x.ma << endl;
	cout << "Ten sinh vien: " << x.ten << endl;
	cout << "Diem: " << x.dtb << endl;
}
void insertLast(node &phead, sv x){
	node tmp = cNode(x),q;
	if (phead == NULL) phead = tmp;
	else {
		q = phead;
		while (q->next != NULL){
			q = q->next;
		}
		q->next = tmp;
	}
}
void nhapDanhSach (node &phead){
	int n; 
	sv x;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	for (int i = 0; i < n; i++){
	
		nhap1SinhVien(x);
		insertLast(phead,x);
	}
}
void xuatDanhSach (node phead){
	for (node p = phead; p != NULL; p = p->next){
		xuat1SinhVien(p->x);
	}
}
void xuatDtb(node phead){
	for (node p = phead; p != NULL; p = p->next){
		if (p->x.dtb > 5){
			xuat1SinhVien(p->x);
		}
	}
}
node timSv (node phead, char x[]){
	for (node p = phead; p != NULL; p = p->next){
		if (strcmp(p->x.ten,x) == 0){
			return p;
		}
	}
	return NULL;
}
void sapXep (node phead){
	for (node p = phead; p != NULL; p = p->next){
		for (node q = p->next; q != NULL; q = q->next){
			if (p->x.dtb > q->x.dtb){
				swap(p->x,q->x);
			}
		}
	}
}
node search(node phead, char x[]){
	for (node p = phead; p != NULL; p = p->next){
		if (strcmp(p->x.ma,x) == 0){
			return p;
		}
	}
	return NULL;
}
void insertAfter (node &p, sv x){
	node q = cNode(x);
	if (p){
		q->next = p->next;
		p->next = q; 
	}
}
void xoaDau (node &phead){
	node p;
	p = phead;
	phead = phead->next;
}
node xoaCuoi (node &phead){
	if (phead == NULL)
		return NULL;
	if (phead->next == NULL){
		delete phead;
		return NULL;
	}
	node p = phead;
	while(p->next->next != NULL){
		p = p->next;
	}
	delete (p->next);
	p->next = NULL;
	return phead;
}
void clearList (node &phead){
	node p;
	while (phead){
		p = phead;
		phead = phead->next;
	}
}
void svX (node &phead, char x[]){
	node tmp = phead, prev;
	if (tmp != NULL and strcmp(tmp->x.ma,x) == 0){
		phead = tmp->next;
		delete tmp;
		return;
	}
	while (tmp != NULL and strcmp(tmp->x.ma,x) != 0){
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL){
		cout << "\nMa sinh vien khong hop le\n";
		return;
	}
	prev->next = tmp->next;
	delete tmp;
}
int main(){
	node phead;
	init(phead);
	nhapDanhSach(phead);
	cout << "\nDanh Sach Sinh Vien Sau Khi Nhap\n";
	xuatDanhSach(phead);
	cout << "\nSinh Vien Co Diem Trung Binh Tren 5\n";
	xuatDtb(phead);
	cin.ignore();
	char x[11];
	cout << "\nNhap ten sinh vien can tim: ";
	cin.get(x,11);
	node find = timSv(phead,x);
	if (find != NULL){
		cout << "\nSinh vien co trong danh sach";
	}else {
		cout << "\nSinh vien khong co trong danh sach";
	}
	sapXep(phead);
	cout << "\nDanh sach sinh vien sau khi sap xep\n ";
	xuatDanhSach(phead);
	cin.ignore();
	char d[11];
	cout << "Nhap ma sinh vien can tim: ";
	cin.get(d,11);
	node s = search(phead,d);
	if (s == NULL) cout << "\nKhong co ma sinh vien can tim !";
	else {
		cout << "\nCo ma sinh vien can tim\n";
		sv d;
		nhap1SinhVien(d);
		insertAfter(s,d);
		cout << "\nDanh sach sinh vien sau khi da them";
		xuatDanhSach(phead);
	}
	xoaDau(phead);
	cout << "\nDanh sach sinh vien sau khi da xoa dau\n";
	xuatDanhSach(phead);
	phead = xoaCuoi(phead);
	cout << "\nDanh sach sinh vien sau khi da xoa cuoi\n";
	xuatDanhSach(phead);
//	clearList(phead);
//	cout << "Da xoa danh sach";
//	xuatDanhSach(phead);
	cin.ignore();
	char g[11];
	cout << "Nhap ma sinh vien can xoa: ";
	cin.get(g,11);
	svX(phead,g);
	cout << "\nDanh sach sinh vien sau khi da xoa sinh vien\n";
	xuatDanhSach(phead);
	return 0;
}
