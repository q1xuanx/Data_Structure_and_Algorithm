#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define rep(i,a,b) for (int i = a; i < b; i++)
typedef struct Node {
	int data;
	Node *next;
}*node;
void init (node &phead){
	phead = NULL;
}
int isEmpty (node phead){
	return phead == NULL;
}
node cNode (int x){
	node p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}
void insertLast (node &phead, int x){
	node tmp = cNode(x);
	node p;
	if (isEmpty(phead)) phead = tmp;
	else {
		p = phead;
		while (p->next != NULL){
			p = p->next;
		}
		p->next = tmp;
	}
}
void addNum (node &phead){
	init(phead);
	int n,tmp;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		insertLast(phead,tmp);
	}
}
void display (node phead){
	for (node p = phead; p != NULL; p = p->next){
		cout << p->data << " ";
	}
}
void insertAfter (node phead, int x){
	node tmp;
	if (phead != NULL){
		tmp = cNode(x);
		tmp->next = phead->next;
		phead->next = tmp;
	}else {
		return;	
	}
}
void insertBehindX (node phead){
	int x,y;
	cout << "Nhap phan tu can tim: ";
	cin >> x;
	cout << "Nhap phan tu can chen sau phan tu vua tim duoc: ";
	cin >> y;
	for (node p = phead; p != NULL; p = p->next){
		if (p->data == x){
			insertAfter(p,y);
		}
	}
}
int countNode (node phead){
	int c = 0;
	for (node p = phead; p != NULL; p=p->next){
		c++;
	}
	return c;
}
int giaTriThuK (node phead){
	int x, c = -1, tmp = 0;
	cout << "Moi nhap vi tri: ";
	cin >> x;
	for (node p = phead; p != NULL; p=p->next){
		c++;
		if (c == x){
			tmp = p->data;
		}
	}
	return tmp;
}
void giaTriMinMax (node phead){
	int max = 0, min = 10000;
	for (node p = phead; p != NULL; p=p->next){
		if (p->data > max){
			max = p->data;
		}
		if (p->data < min){
			min = p->data;
		}
	}
	cout << "Gia tri max: " << max << "\n";
	cout << "Gia tri min: " << min << "\n";
}
void delNode (node &phead, int x){
	node tmp = phead, prev;
	if (tmp != NULL and tmp->data == x){
		phead = tmp->next;
		free(tmp);
		return;
	}
	while(tmp != NULL and tmp->data != x){
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL){
		return;
	}
	prev->next = tmp->next;
	free(tmp);
}
void interchangeSort (node phead){
	for (node p = phead; p != NULL; p = p->next){
		for (node q = p->next; q != NULL; q = q->next){
			if (p->data > q->data){
				swap(p->data,q->data);
			}
		}
	}
}
int main(){
	node phead;
	addNum(phead);
	display(phead);
	int x,y;
	cout << "\n";
//	insertBehindX(phead);
//	cout << "Day so nguyen sau khi chen y sau x: ";
//	display(phead);
	cout << "\n";
	cout << "So node co trong danh sach la: " << countNode(phead);
	cout << "\n";
	cout << "Gia tri thu k trong danh sach la: " << giaTriThuK(phead) << "\n";
	giaTriMinMax(phead);
	int tmp;
	cout << "Nhap gia tri can xoa: ";
	cin >> tmp;
	delNode(phead,tmp);
	cout << "Day so nguyen sau khi xoa: ";
	display(phead);
	cout << "\n";
	interchangeSort(phead);
	cout << "Day sau khi sap xep: ";
	display(phead);
	return 0;
}

