#include <bits/stdc++.h>
using namespace std;
typedef struct NODE{
	int data;
	NODE *next;
}*STACK;
void init (STACK &s){
	s = NULL;
}
STACK cNode (int x){
	STACK s = new NODE;
	s->data = x;
	s->next = NULL;
	return s;
}
void Push (STACK &s, int x){
	STACK p = cNode(x);
	p->next = s;
	s = p;
}
int Pop (STACK &s, int &x){
	if (!s) return 0;
	x = s->data;
	STACK p = s;
	s = s->next;
	delete p;
	return 1;
}
void convert (STACK &s, int n, int coso = 2){
	int sodu;
	while (n != 0){
		sodu = n % coso;
		Push(s,sodu);
		n/= coso;
	}
}
void output (STACK s){
	while(s){
		int x; Pop(s,x);
		if (x > 9){
			cout << (char)((x-10)+ 'A');
		}else{
			cout << x;
		}
	}
}
int nhapN (){
	while (1){
		cout << "\nMoi nhap n > 0: ";
		int n; cin >> n;
		if (n > 0) return n;
		cout << "\nBan da nhap sai moi nhap lai !";
	}
}
int Menu(){
	cout << "\n\t\tMENU";
	cout << "\n1.Nhi Phan";
	cout << "\n2.Bat Phan";
	cout << "\n3.Thap luc phan";
	cout << "\n0.Thoat";
	cout << "\nMoi chon chuc nang: ";
	int chon; cin >> chon;
	return chon;
}
void xuLy (int chon, int n, STACK s){
	switch(chon){
		case 1: cout << "\nDoi sang nhi phan: ";
				convert(s,n); break;
		case 2: cout << "\nDoi sang bat phan: ";
				convert(s,n,8); break;
		case 3: cout << "\nDoi sang thap luc phan: ";
				convert(s,n,16); break;
		default: cout << "\nBan da nhap sai !";
	}
	output(s);
}
int main(){
	STACK s;
	init(s);
	int n = nhapN();
	while(1){
		int chon = Menu();
		if (chon == 0) break;
		xuLy(chon,n,s);
	}
}
