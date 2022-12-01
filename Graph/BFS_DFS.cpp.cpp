#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX 100
#define link "C:/Users/Administrator/Desktop/B3/2180605539_PhamHoangNhan/file.txt"
using namespace std;
struct graph{
	int n, a[MAX][MAX];
};
struct queue {
	int size;
	int arr[MAX];
		
};
int readFile (char tenFile[10001], graph &g){
	fstream in (tenFile);
	if (!in){
		cerr << "\nErorr !\n";
		return 0;
	}
	in >> g.n;
	for (int i = 0; i < g.n; i++){
		for (int j = 0; j < g.n; j++){
			in >> g.a[i][j];
		}
	}
	return 1;
}
void print(graph g){
	cout << g.n << "\n";
	for (int i = 0; i < g.n; i++){
		for (int j = 0; j < g.n; j++){
			cout << g.a[i][j] << " ";
		}
		cout << "\n";
	}
}
int save[MAX];
int check[MAX];
void DFS (int v, graph g){
	check[v] = 1;
	int u;
	for (u = 0; u < g.n; u++){
		if (g.a[v][u] != 0 and check[u] == 0){
			save[u] = v;
			DFS (u,g);
		}
	}
}
// f= 7
void DFSTraversal (int s, int f, graph g){
	int i;
	for (int k = 0; k < g.n; k++){
		save[k] = -1;
		check[k] = 0;
	}
	DFS(s,g);
	if (check[f] == 1){
		cout << "\nDuong di tu dinh " << s << " den dinh " << f << " la: ";
		i = f;
		cout << f << "\n";
		int t[MAX];
		int j = 0;
		while (s != i){
			i = save[i];
			//cout << i << " ";		
			t[j] = i;
			j++;
		}
		reverse(t,t+j);
		for (int k = 0; k < j; k++){
			cout << t[k] << "->";
		}
		cout << f << "\n";
	}else cout << "\nKhong co duong di !\n";
}
void init (queue &s){
	s.size = 0;
}
int putValue (queue &s, int value){
	if (s.size + 1 >= 100){
		return 0;
	}
	s.arr[s.size] = value;
	s.size++;
	return 1;
}
int checkRong(queue s){
	if (s.size <= 0) return 1;
	return 0;
}
int pop (queue &s, int &value){
	if (s.size <= 0) return 0;
	value = s.arr[0];
	for (int i = 0; i < s.size - 1; i++){
		s.arr[i] = s.arr[i+1];
	}
	s.size--;
	return 1;
}
int save1[MAX];
int check1[MAX];
void BFS (int v, graph g){
	queue s;
	init(s);
	check1[v] = 1;
	putValue(s,v);
	while (!checkRong(s)){
		pop(s,v);
		for (int u = 0; u < g.n; u++){
			if (g.a[v][u] != 0 and check1[u] == 0){
				putValue(s,u);
				check1[u] = 1;
				if (save1[u] == -1){
					save1[u] = v;
				}
			
			}
		}
	}
}
void BFSTraversal (int s, int f, graph g){
	int i;
	for (int k = 0; k < g.n; k++){
		save1[k] = -1;
		check1[k] = 0;
	}
	BFS(s,g);
	if (check1[f] == 1){
		cout << "\nDuong di tu dinh " << s << " den dinh " << f << " la: ";
		i = f;
		cout << f << "\n";
		int t[MAX];
		int j = 0;
		while (s != i){
			i = save1[i];   
			//cout << i << " ";		
			t[j] = i;
			j++;
		}
		reverse(t,t+j);
		for (int k = 0; k < j; k++){
			cout << t[k] << "->";
		}
		cout << f << "\n";
	}else cout << "\nKhong co duong di !\n";
}
int main(){
	graph g;
	int check = readFile(link, g);
	if (check){
		//cout << "Ok\n";
		cout << "\nDoc file thanh cong du lieu trong file !\n";
		print(g);
		cout << "\n";
		DFSTraversal(0,7,g);
		cout << "\n";
		BFSTraversal(0,7,g);
	}	
	return 0;
}
//int check[10] = {};
