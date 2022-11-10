#include <iostream>
#include <fstream>
using namespace std;
#define link "C:/Users/Administrator/Desktop/B2/PhamHoangNhan_2180605539/input.txt"
#define MAX 100
struct graph {
	int n;
	int a[MAX][MAX];
};
struct stack {
	int ar[MAX];
	int size;
};
int readFile (char tenFile[1001],graph &g){
	ifstream in (tenFile);
	if (!in){
		cerr << "\nError !\n";
		return 0;
	}
	in >> g.n;
	for (int i =0; i < g.n; i++){
		for (int j = 0; j < g.n; j++){
			in >> g.a[i][j];
		}
	}
	return 1;
}
void print (graph g){
	cout << g.n << "\n";
	for (int i = 0; i < g.n; i++){
		for (int j = 0; j < g.n; j++){
			cout << g.a[i][j] << " ";
		}
		cout << "\n";
	}
}
void init (stack &s){
	s.size = 0;
}
void putValue (stack &s, int value){
	if (s.size + 1 >= 100){
		return;
	}
	s.ar[s.size] = value;
	s.size++;
}
void findPath (int i, graph &g, stack &s){
	for (int j = 0; j < g.n; j++){
		if (g.a[i][j] != 0){
			g.a[i][j] = g.a[j][i] = 0;
			findPath(j,g,s);
		}
	}
	putValue(s,i);
}
//stack s;

int checkEuler (graph g, stack &s){
	int i,j;
	int x = 0;
	graph t = g;
	//stack s;
	init(s);
	findPath(x,t,s);
	for (int i = 0; i < t.n;i++){
		for (int j = 0;j < t.n; j++){
			if (t.a[i][j] == 1){
				return 0;
			}
		}
	}
	cout << "\nCo chu trinh euler: ";
	//printEuler(s);
	return 1;	
}
void printEuler (stack s){
	for (int i = 0; i < s.size; i++){
		cout << s.ar[i] << " ";
	}
}
int main(){
	graph g;
	stack s;
	int read = readFile(link,g);
	if (read){
		cout << "\nDoc file thang cong du lieu trong file: \n";
		print(g);
		cout << "\n";
		int check = checkEuler(g,s);
		if (check) printEuler(s);
		else cout << "Khong co chu trinh euler\n";
	}
	return 0;
}
