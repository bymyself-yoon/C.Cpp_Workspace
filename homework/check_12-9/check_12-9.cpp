#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream fin("a.txt");
    if(!fin) {cerr << "파일을 열 수 없음"; return 0;} // a.txt 파일 읽기
    ofstream fout("b.txt");
    if(!fout) {cerr << "b.txt 파일을 열 수 없음"; return 0;} // b.txt에 작성

    string atxt;
    getline(fin, atxt,'&'); // atxt 파일에서 &가 나올 때까지 파일 읽기 (공백 포함)
    cout << atxt << endl << endl; fin.close();

    string f, r;
    cout << "찾는 문구: "; getline(cin, f); // f에 찾는 문구 받아오기 (공백 포함)
    cout << "바꿀 문구: "; getline(cin, r); // r에 바꿀 문구 받아오기 (공백 포함)

    int sindex = 0;
    while(true) { 
        int findex = atxt.find(f, sindex); // atxt에서 0번째 자리부터 f 찾아서 그 인덱스를 findex에 넣기
        if(findex == -1) break; // findex 없으면 break
        atxt.replace(findex, f.length(), r); // findex를 f의 길이만큼 r로 바꾸기
        sindex = findex + r.length(); // findex와 바꿀 문구의 길이를 더해서 sindex에 넣는다 -> 다음 반복문 실행 때 중복되지 않게 함
    }
    fout << atxt << endl;
}
/* a.txt에 있는 특정 단어를 입력된 단어로 바꿔서 b.txt에 입력하는 프로그램 */
