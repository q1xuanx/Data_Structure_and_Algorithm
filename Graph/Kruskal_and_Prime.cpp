#include <iostream>
#include <fstream>
using namespace std;
#define input "C:\\Users\\Administrator\\Desktop\\B4\\2180605539_PhamHoangNhan\\inp.txt"
#define MAX 100
int chuaxet[MAX];
struct graph {
	int n;
	int a[MAX][MAX];
};
struct edge {
	int u,v,value;
};
edge t[MAX];
int readFile (char tenLink[], graph &g){
	ifstream in (tenLink);
	if (!in) {
		cerr << "Error !\n";
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
void print (graph g){
	cout << g.n;
	cout << "\n";
	for (int i = 0; i < g.n; i++){
		for (int j = 0; j < g.n; j++){
			cout << g.a[i][j] << " ";
		}
		cout << "\n";
	}
}
void diTimLienThong (graph g, int nhan[], int i){
	for(int j = 0; j < g.n; j++){
		if (g.a[i][j] != 0 and nhan[j] != nhan[i]){
			nhan[j] = nhan[i];
			diTimLienThong(g,nhan,j);
		}
	}
}
int xetLienThong (graph g){
	int nhan[MAX];
	int i, soTPLT = 0;
	for (i = 0; i < g.n; i++){
		nhan[i] = 0;
	}
	for (i = 0; i < g.n; i++){
		if (nhan[i] == 0){
			soTPLT++;
			nhan[i] = soTPLT;
			diTimLienThong(g,nhan,i);
		}
	}
	return soTPLT;
}
void prim (graph g){
	if (xetLienThong(g) != 1){
		cout << "Do thi khong co thanh phan lien thong khong thuc hien duoc thuat toan\n";
		return;
	}
	int temp = 0;
	for (int i = 0; i < g.n; i++){
		chuaxet[i] = 0;	
	}
	chuaxet[0] = 1;
	while (temp < g.n - 1){
		edge canhnhonhat;
		int mn = 100;
		for (int i = 0; i < g.n; i++){
			if (chuaxet[i] == 1){
				for (int j = 0; j < g.n; j++){
					if (chuaxet[j] == 0 and g.a[i][j] != 0 and mn > g.a[i][j]){
						canhnhonhat.u = i;
						canhnhonhat.v = j;
						canhnhonhat.value = g.a[i][j];
					}
				}
			}
		}
		t[temp] = canhnhonhat;
		temp++;
		chuaxet[canhnhonhat.v] = 1;
	}
	int tongTSCayKhung = 0;
	cout << "\nCay khung nho nhat cua do thi la: \n";
	for (int i = 0; i < temp - 1; i++){
		cout << t[i].u << " " << t[i].v << "\n";
		tongTSCayKhung += t[i].value;
	}
	cout << t[temp - 1].u << " " << t[temp - 1].v << "\n";
	tongTSCayKhung += t[temp - 1].value;
	cout << "Tong gia tri cay khung la: " << tongTSCayKhung << "\n";
}
void sapXep (edge e[], int tongsocanh){
	edge temp;
	for (int i = 0; i < tongsocanh - 1; i++){
		for (int j = i + 1; j < tongsocanh; j++){
			if (e[i].value > e[j].value){
				temp = e[i];
				e[i] = e[j];
				e[j] = temp;				
			}
		}
	}
}
void kruskal (graph g){
	edge list[MAX];
	int tongsocanh = 0;
	int i,j;
	for (i = 0; i < g.n; i++){
		for (j = i + 1; j < g.n; j++){
			if (g.a[i][j] > 0){
				list[tongsocanh].u = i;
				list[tongsocanh].v = j;
				list[tongsocanh].value = g.a[i][j];
				tongsocanh++;
			}
		}
	}
	sapXep(list,tongsocanh);
	int temp = 0;
	edge t[MAX];
	int nhan[MAX];
	for (i = 0; i < g.n; i++){
		nhan[i] = i;
	}
	int canhdangxet = 0;
	while (temp < g.n and canhdangxet < tongsocanh){
		if (nhan[list[canhdangxet].u] != nhan[list[canhdangxet].v]){
			t[temp] = list[canhdangxet];
			temp++;
			int vle = nhan[list[canhdangxet].v];
			for (j = 0; j < g.n; j++){
				if (nhan[j] == vle) nhan[j] = nhan[list[canhdangxet].u];
			}
		}
		canhdangxet++;
	}
	if (temp != g.n - 1){
		cout << "\nDo thi khong lien thong\n";
		return;
	}
	int tongTS = 0;
	cout << "\nDo thi lien thong\n";
	cout << "\nCay khung nho nhat cua do thi\n";
	for (i = 0; i < temp; i++){
		cout << t[i].u << " " << t[i].v << "\n";
		tongTS += t[i].value;
	}
	cout << "\nTong gia tri cua cay khung: " << tongTS << "\n";
}
int main(){
	graph g;
	int check = readFile(input,g);
	if (check){
		cout << "\nDoc file thanh cong du lieu trong file la\n";
		print(g);
		cout << "\n";
		cout << "\nThuat toan prime\n";
		prim(g);
		cout << "\n";
		cout << "\nThuat toan kruskal\n";
		kruskal(g);
	}
	return 0;
}
