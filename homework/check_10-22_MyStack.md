# 확인문제 10장 21번 참고 과제

원하는 결과

stack full이므로 더 넣지 못합니다.
현재 string 스택에 2개 있음
맨 위에 있는 hello 꺼냄
맨 위에 있는 bye 꺼냄
stack empty - 프로그램을 종료합니다.


₩₩₩
#include <iostream>
using namespace std;
template <class T> class MyStack {
    T data[2];
public:
    int tos = -1;
    void push(T element) {
        if (tos == 1) { cout << "stack full이므로 더 넣지 못합니다." << endl; }
        else { tos++; data[tos] = element; }
    }
    T pop() {
        if (tos == -1) { cout << "stack empty - 프로그램을 종료합니다." << endl; exit(0); }
        return data[tos--];
    }
};

int main() {
    MyStack<string> sc;
    sc.push("bye"); sc.push("hello"); sc.push("suyun"); // stack full이므로~ 이라는 문장이 나오기 위해 data 크기가 2이지만 하나 더 push
    cout << "현재 string 스택에 " << sc.tos + 1 << " 개 있음" << endl;
    cout << "맨 위에 있는 " << sc.pop() << " 꺼냄" << endl;
    cout << "맨 위에 있는 " << sc.pop() << " 꺼냄" << endl;
    sc.pop(); // stack empty~ 문장 나오기 위해 pop 한 번 더 삽입
}
₩₩₩
