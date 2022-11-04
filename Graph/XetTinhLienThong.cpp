#include<iostream>
#include<fstream>
using namespace std;

struct graph{
    int n, a[100][100];
};
int read (graph &g){
    ifstream in("C:\\Users\\Admin\\Desktop\\Visual_Code_CP\\input.txt");
    if (!in ){
        cerr << "Erorr !";
        return 0;
    }
    in >> g.n;
    for (int i = 0; i < g.n; i++){
        for (int j = 0; j < g.n; j++){
            in >> g.a[i][j];
        }
    }
    in.close();
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
#define MAX 10
void diQuaCacDinh (graph g, int check[MAX], int i){
    for (int j = 0; j < g.n; j++){
        if (g.a[i][j] != 0 and check[i] != check[j]){
            check[j] = check[i];
            diQuaCacDinh(g,check,j);
        }
    }
}
void xetLienThong (graph g){
    int check[MAX] = {};
    int TPLT = 0;
    for (int i = 0; i < g.n; i++){
        if (check[i] == 0){
            TPLT++;
            check[i] = TPLT;
            diQuaCacDinh(g,check,i);
        }
    }
    cout << "\nSo thanh phan lien thong: " << TPLT << "\n";
    for (int i = 1; i <= TPLT; i++){
        cout << "Thanh phan lien thong " << i << " gom: ";
        for (int j =0; j < g.n; j++){
            if (check[j] == i){
                cout << j << " ";
            }
        }
        cout << "\n";
    }

}
int main(){
    graph g;
    if (read(g)){
        print(g);
        xetLienThong(g);
    }
    return 0;
}
