#include <bits/stdc++.h>
using namespace std;
#define M 10
#define MINVL -1e9
typedef struct Node{
int key;
Node *next;
}*node;
node bucket[M];
node cNode (int k){
node p = new Node;
p->key = k;
p->next = NULL;
return p;
}
void initBucket(){
for (int b = 0; b < M; b++){
bucket[b] = NULL;
}
}
void push (int b, int k){
node p = cNode(k);
p->next = bucket[b];
bucket[b] = p;
}
int pop (int b){
if (bucket[b] == NULL) return MINVL;
int k = bucket[0]->key;
node p = bucket[b];
bucket[b] = bucket[b]->next;
delete p;
return k;
}
int hashFunc (int key){
return (key % M);
}
void addNode (int key){
int b = hashFunc(key);
push(b,key);
}
void input(){
srand((unsigned)time(NULL));
int n;
cout << "\nMoi nhap so luong phan tu n: "; cin >> n;
for (int i = 0; i < n; i++){
int k = rand() % 100 + 1;
addNode(k);
}
}
void TraverseBucket(int b){
node p = bucket[b];
while(p){
cout << p->key << " ";
p = p->next;
}
}
void Traverse (){
for (int b = 0; b < M; b++){
cout << "\nBucket[" << b <<"]: ";
TraverseBucket(b);
}
}
void rmvAf (node p){
if (p == NULL || p->next == NULL) return;
node q = p->next;
p->next = q->next;
delete q;
}
node search(int b, int k){
node p = bucket[b];
while (p != NULL and p->key != k){
p=p->next;
}
return p;
}
node searchbefore(int b, int k){
node p = bucket[b];
while (p != NULL and p->next->key != k){
p=p->next;
}
return p;
}
int remove (int key){
int b = hashFunc(key);
if (bucket[b] == NULL) return 0;
if (bucket[b]->key == key) return pop(b);
node p = searchbefore(b,key);
rmvAf(p);
return 1;
}
void rmvall(){
for (int b = 0; b < M; b++){
while (bucket[b]){
pop(b);
}
}
}
int menu(){
cout << "\n\tMenu";
cout << "\n1.Them node";
cout << "\n2.Them nhieu node ngau nhien";
cout << "\n3.Xoa node";
cout << "\n4.Xoa toan bo bang bam";
cout << "\n5.Duyen bang bam";
cout << "\n6.Tim kiem node";
cout << "\n0.Thoat";
cout << "\nMoi chon chuc nang: ";
int chon; cin >> chon; return chon;
}
void xuly(int chon){
int k;
node p;
switch(chon){
case 1: cout << "\nMoi nhap node can them: "; cin >> k; addNode(k); break;
case 2: input(); break;
case 3: cout << "\nMoi nhap node can xoa: "; cin >> k; remove(k); break;
case 4: rmvall(); break;
case 5: Traverse(); break;
case 6: cout << "\nMoi nhap phan tu can tim: "; cin >> k;
p = search(hashFunc(k),k);
cout << (p ? "\nTim thay" : "\nKhong tim thay");
break;
default: cout << "\nBan nhap sai chuc nang !"; break;
}
}
int main(){
initBucket();
while (1){
int chon = menu();
if (chon == 0) break;
xuly(chon);
}
}
