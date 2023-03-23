#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char name[100];
    char code[100];
    char recode[100];

    cout << "이름 입력: ";
    cin.getline(name, 100);
    cout << "암호 입력: ";
    cin.getline(code, 100);
    cout << "다시 입력: ";
    cin.getline(recode, 100);

    if(strcmp(code, recode)==0) cout << name << "님께서 로그인하셨습니다." << endl;
    else cout << name << "님, 다시 입력하세요." << endl;


}
