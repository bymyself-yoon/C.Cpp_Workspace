#include <iostream>
#include <fstream>
using namespace std;
#define N 10

int main() {
    int a[N];
    ifstream fin;
    fin.open("a.txt");
    if (!fin) { cerr << "파일 열기 실패"; return 0; }
    ofstream fout("b.txt");
    if (!fout) { cerr << "파일 열기 실패"; return 0;}

    for(int i = 0; i < N; i++) fin >> a[i];
    for(int i = N-1; i >= 0; i--) fout << a[i] << endl;

    fin.close();
    fout.close();

}   
