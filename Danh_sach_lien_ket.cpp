#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int info;
    struct Node* next;
}*node;
//khoi tao
void init(node &phead){
    phead = NULL;
}
//kiem tra rong
int isEmpty(node phead){
    return (phead==NULL);
}
//tao node
node createNode(int x){
    node p=(node)malloc(sizeof(struct Node));
    p->info = x;
    p->next = NULL;
    return p;    
}
//chen dau
void insertFirst(node &phead, int x){
    node p=createNode(x);
    if(isEmpty(phead)) phead = p;
    else{
        p->next = phead;
        phead = p;
    }
}
//chen cuoi
void insertLast(node &phead, int x){
    node tmp, p;
    tmp = createNode(x);
    if(isEmpty(phead)) phead = tmp;
    else{
        p=phead;
        while(p->next!=NULL)
        p=p->next;
        p->next = tmp;
    }
}
//nhap dslk
void input(node &phead){
    init(phead);
    int n, x;
    cout<<"\nSo luong phan tu: ";
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        cout<<"nhap dong thu "<<i<<": ";
        cin >> x;
        insertLast(phead,x);
    }
}
//chen vao vi tri chi dinh
void insertAfter(node &phead, int x, int position){
    node tmp, p;
    if(position==0 || isEmpty(phead)) insertFirst(phead,x);
    else{
        int k=1;
        p=phead;
        while(p->next!=NULL && k!=position){
            p=p->next;
            k++;
        }
        if(k!=position) insertLast(phead, x);
        else{
            tmp = createNode(x);
            tmp->next = p->next;
            p->next = tmp;
        }
    }
}
//hien thi dslk
void show(node phead){
   for(node p=phead; p!=NULL; p=p->next){
        cout<<p->info<<" ";     
   }
}
void ptchan (node phead){
	for (node p = phead; p != NULL; p=p->next){
		if(p->info % 2 == 0){
			cout << p->info << " ";
		}
	}
}
int snt (int n){
	for (int i = 2;i*i <= n; i++){
		if (n % i == 0){
			return 0;
		}
	}
	return n > 1;
}
void xuatSnt (node phead){
	for (node p = phead; p != NULL; p=p->next){
		if (snt(p->info)){
			cout << p->info << " ";
		}
	}
}
int max (node phead){
	int max = 0;
	for (node p = phead; p != NULL; p = p->next){
		if (p->info > max){
			max = p->info;
		}
	}
	return max;
}
void interchange (node phead){
	for (node p = phead; p!= NULL; p=p->next){
		for (node q = phead; q!= NULL; q=q->next){
			if (p->info < q->info){
				swap(p->info,q->info);
			}
		}
	}	
}
int main(){
    node phead;
    input(phead);
    show(phead);
    cout<<endl;
    ptchan(phead);
    cout << "\n";
    interchange(phead);
    show(phead);
	return 0;
}
