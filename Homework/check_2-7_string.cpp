#include<iostream>
#include<string>
using namespace std;
int main() {

    string name;
    string code;
    string recode;

    cout << "이름 입력: ";
    getline(cin,name);
    cout << "암호 입력: ";
    getline(cin,code);
    cout << "다시 입력: ";
    getline(cin,recode);

    if(code == recode) cout << name << "님께서 로그인하셨습니다." << endl;
    else cout << name << "님, 다시 입력하세요." << endl;


}