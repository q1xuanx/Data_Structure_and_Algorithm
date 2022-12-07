#include <iostream>
#include <fstream>
using namespace std;
#define link "input.txt"
#define MAX 100
struct graph
{
    int n, a[MAX][MAX];
};
struct stack{
    int size, ar[MAX];
};
int readFile(char tenLink[], graph &g){
    ifstream in(tenLink);
    if (!in)
    {
        cerr << "\nErorr!";
        return 0;
    }
    in >> g.n;
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            in >> g.a[i][j];
        }
    }
    return 1;
}
void print(graph g)
{
    cout << g.n << "\n";
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            cout << g.a[i][j] << " ";
        }
        cout << "\n";
    }
}
void demBacCuaDinh (graph g){
    int cnt = 0;
    int cntarr[MAX];
    for (int i = 0; i < g.n; i++){
        int j = 0;
        cnt = 0; 
        while (j < g.n){
            if (g.a[i][j] != 0){
                cnt++;
            }
            j++;
        }
        cntarr[i] = cnt;
    }
    cout << "\nSo bac cua cac dinh \n";
    for (int i = 0; i < g.n; i++){
        cout << i << " " << cntarr[i] << "\n";
    }
}
void push (stack &s, int value){
    if (s.size + 1 > 100){
        return;
    }
    s.ar[s.size] = value;
    s.size++;
}
void init (stack &s){
    s.size = 0;
}
void timDuongDi (graph &g, stack &s, int i){
    for (int j = 0; j < g.n; j++){
        if (g.a[i][j] != 0){
            g.a[i][j] = g.a[j][i] = 0;
            timDuongDi(g,s,j);
        }
    }
    push(s,i);
}
int timDinhPhuHop (graph g){
    int cnt = 0, v = 0;
    for (int i = 0; i < g.n; i++){
        cnt = 0;
        for (int j = 0; j < g.n; j++){
            if (g.a[i][j] != 0){
                cnt++;
            }
        }
        if (cnt > 0){
            v = i;
            return v;
        }
    }
    return -1;
}
int checkEuler (graph g, stack &s){
    int x = 0;
    int timDinh = timDinhPhuHop(g);
    if (timDinh) {
        cout << "\nKhong co dinh phu hop ! ";
        return 0;
    }else{ 
        x = timDinhPhuHop(g);
    }
    init(s);
    graph temp = g;
    timDuongDi(temp,s,x);
    for (int i = 0; i < temp.n; i++){
        for (int j = 0; j < temp.n; j++){
            if (temp.a[i][j] != 0){
                return 0;
            }
        }
    }
    if (s.ar[0] != s.ar[s.size - 1]){
        return 0;
    }else {
        return 1;
    }
}
void printStack(stack s){
    for (int i = 0; i < s.size-1; i++){
        cout << s.ar[i] << "->";
    }
    cout << s.ar[s.size] << "\n";
}
int timDinhPhuHop2 (graph g){
    int v = 0, cnt = 0;
    for (int i = 0; i < g.n; i++){
        cnt = 0;
        for (int j = 0; j < g.n; j++){
            if (g.a[i][j] != 0){
                cnt++;
            }
        }
        if (cnt % 2 != 0){
            v = i;
            return v;
        }
    }
    return -1;
}
int duongDiEuler (graph g, stack &t){
    int x = 0;
    if (timDinhPhuHop2(g)){
        cout << "\nKhong co dinh phu hop !";
        return 0;
    }else {
        x = timDinhPhuHop2(g);
    }
    init(t);
    graph tmp = g;
    timDuongDi(tmp,t,x);
    for (int i = 0; i < tmp.n; i++){
        for (int j = 0; j < tmp.n; j++){
            if (tmp.a[i][j] != 0){
                return 0;
            }
        }
    }
    if (t.ar[0] == t.ar[t.size - 1]){
        return 0;
    }else {
        return 1;
    }
}
int main(){
    graph g;
    stack s;
    int read = readFile(link,g);
    if (read){ 
        print(g);
        demBacCuaDinh(g);
        if (checkEuler(g,s)){
            cout << "\nCo chu trinh Euler: ";
            printStack(s);
        }else {
            cout << "\nKhong co chu trinh Euler !";
        }
        if (duongDiEuler(g,s)){
            cout << "\nCo duong di Euler !";
            printStack(s);
        }else {
            cout << "\nKhong co duong di Euler !";
        }
        cout << "\nDebug...Ok\n";
    }
    return 0;
}
