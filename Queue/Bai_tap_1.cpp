#include <bits/stdc++.h>
using namespace std; 
int soTT;
typedef struct BenhNhan{
	int stt,tuoi;
	char ten[41];
}BN;
typedef struct NODE{
	BN data;
	NODE *next;	
}*node;
typedef struct QUEUE{
	node phead, ptail;
}Q;
void Nhap(BN &bn){
	cin.ignore();
	bn.stt = soTT++;
	cout << "\nNhap ten: ";       
	cin.getline(bn.ten,41);
	cout << "\nNhap tuoi: ";
	cin >> bn.tuoi;
}
void Xuat (BN bn){
	cout << "\nSo thu tu: " << bn.stt << "\n";
	cout << "\nTen: " << bn.ten << "\n";
	cout << "\nTuoi: " << bn.tuoi << "\n";
}
void init (Q &q){
	q.phead = q.ptail = NULL;
}
node cNode (BN x){
	node p = new NODE;
	p->data = x;
	p->next = NULL;
	return p;
}
void insert (Q &q, BN x){
	node tmp = cNode(x);
	if (q.phead == NULL){
		q.phead = q.ptail = tmp;
	}else {
		q.ptail->next = tmp;
		q.ptail = tmp; 
	}
}
int remove (Q &q, BN &outitem){
	if (q.phead == NULL) return 0;
	outitem = q.phead->data;
	node del = q.phead;
	q.phead = q.phead->next;
	delete del;
	return 1;
}
void showQueue(Q q){
	while (q.phead){
		Xuat(q.phead->data);
		q.phead = q.phead->next;
	}
}
int Menu(){
	cout << "\n\t\tMENU";
	cout << "\n1.Them benh nhan";
	cout << "\n2.Benh nhan kham tiep theo";
	cout << "\n3.So nguoi da kham";
	cout << "\n4.So nguoi chua kham";
	cout << "\n5.Danh sach benh nhan chua kham";
	cout << "\n0.Thoat";
	cout << "\nMoi chon chuc nang: ";
	int chon; cin >> chon;
	return chon;
}
void xuLy (int chon, Q &q){
	BN bn;
	switch(chon){
		case 1: cout << "\nNhap thong tin benh nhan ";
				Nhap(bn);
				insert(q,bn);
				break;
		case 2: if (soTT == 0) cout << "\nDanh sach rong !";
				else {
					cout << "\nBenh nhan kham tiep theo ";
					remove(q,bn);
					Xuat(bn);
				}
				break;
		case 3: if (soTT == 0) cout << "\nDanh sach rong";
				else cout << "\nSo benh nhan da kham: " << soTT - q.phead->data.stt ;
				break;
		case 4: if (soTT == 0) cout << "\nDanh sach rong";
				else cout << "\nSo benh nhan chua kham: " << q.ptail->data.stt - q.phead->data.stt + 1;
				break;
		case 5: if (soTT == 0) cout << "\nDanh sach rong";
				else {
					cout << "\nDanh sach benh nhan cho kham ";
					showQueue(q);
				}
				break;
		default: cout << "\nBan da nhap sai !";
	}
}
int main(){
	Q q;
	init(q);
	while (1){
		int chon = Menu();
		if (chon == 0) break;
		xuLy(chon,q);
	}
	return 0;
}
