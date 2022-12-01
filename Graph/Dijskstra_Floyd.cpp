#include<iostream>
#include<fstream>
using namespace std;
#define link "C:\\Users\\Administrator\\Desktop\\B5\\2180605539_PhamHoangNhan\\in.txt"
#define MAX 100
#define VOCUC 1000
struct graph {
	int n;
	int a[MAX][MAX];
};
int luuvet[MAX];
int chuaxet[MAX];
int dodaiduongditoi[MAX];
int read(char tenlink[], graph &g){
	ifstream in (tenlink);
	if (!in){
		cerr << "Error !";
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
	cout << g.n << "\n";
	for (int i = 0; i < g.n; i++){
		for (int j = 0; j < g.n; j++){
			cout << g.a[i][j] << " ";
		}
		cout << '\n';
	}
}
int timDuongDiNho (graph g){
	int li = -1;
	float p = VOCUC;
	for (int i = 0; i < g.n; i++){
		if (chuaxet[i] == 0 and dodaiduongditoi[i] < p){
			p = dodaiduongditoi[i];
			li = i;
		}
	}
	return li;
}
void capnhatduongdi (int u, graph g){
	chuaxet[u] = 1;
	for (int i = 0; i < g.n; i++){
		if (chuaxet[i] == 0 and g.a[u][i] > 0 and g.a[u][i] < VOCUC ){
			if (dodaiduongditoi[i] > dodaiduongditoi[u] + g.a[u][i]){
				dodaiduongditoi[i] = dodaiduongditoi[u] + g.a[u][i];
				luuvet[i] = u;
			}
		}
	}
}
void dijkstra (int s, int f, graph g){
	int i;
	for (i = 0; i < g.n; i++){
		chuaxet[i] = 0;
		dodaiduongditoi[i] = VOCUC;
		luuvet[i] = -1;
	}
	dodaiduongditoi[s] = 0;
	while (chuaxet[f] == 0){
		int u = timDuongDiNho(g);
		if (u == -1) break;
		capnhatduongdi(u,g);
	}
	int temp[MAX], j = 0, size = 0;
	if (chuaxet[f] == 1){
		cout << "\nDuong di ngan nhat tu dinh " << s << " den dinh " << f << " la: ";
		i = f;
		temp[j] = i;
		j++;
		size++;
		while (luuvet[i] != s){
			temp[j] = luuvet[i];
			j++;
			size++;
			i = luuvet[i];
		}
		temp[j] = luuvet[i];
		size += 1;
		cout << temp[size-1] << "->";
		for (int k = size - 2; k > 0; k--){
			cout << temp[k] << "->";
		}
		cout << temp[0];
		cout << "\nVoi do dai la: " << dodaiduongditoi[f];
	}else { 
		cout << "Khong co duong di tu dinh " << s << " den dinh " << f << "!\n";
	}
}         
int sau_nut[MAX][MAX];
int L[MAX][MAX];
void floyd (graph g){
	int i,j;
	for (i = 0; i < g.n; i++){
		for (j = 0; j < g.n; j++){
			if (g.a[i][j] > 0){
				sau_nut[i][j] = j;
				L[i][j] = g.a[i][j];
			}else {
				sau_nut[i][j] = -1;
				L[i][j] = VOCUC;
			}
		}
	}
	for (int k = 0; k < g.n; k++){
		for (i = 0; i < g.n; i++){
			for (j = 0; j < g.n; j++){
				if (L[i][j] > L[i][k] + L[k][j]){
					L[i][j] = L[i][k] + L[k][j];
					sau_nut[i][j] = sau_nut[i][k];
				}
			}
		}
	}
	int s,f;
	cout << "\nMoi nhat dinh bat dau: "; cin >> s;
	cout << "\nMoi nhat dinh ket thuc: "; cin >> f;
	if (sau_nut[s][f] == -1) cout << "\nKhong co duong di toi dinh nay !";
	else {
		cout << "\nDuong di ngan nhat tu dinh " << s << " den dinh " << f << " la: ";
		cout << s;
		int u = s;
		while (sau_nut[u][f] != f){
			u = sau_nut[u][f];
			cout << "->" << u;
		}
		cout << "->" << f;
		cout << "\nTong trong so la: " << L[s][f];
	}
}                                                      
int main(){
	graph g;
	int check = read(link,g);
	if (read){
		cout << "\nDoc file thank cong\n";
		print(g);
		cout << "\n";
		dijkstra(1,7,g);
		cout << "\n";
		floyd(g);
	}
	return 0;
}
