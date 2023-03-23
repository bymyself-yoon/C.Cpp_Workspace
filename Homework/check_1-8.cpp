#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int sum3 = 0;

    for (int i = 0; i < 101; i++) {
        sum = sum + i;
        if(i % 3 == 0) {
            sum3 = sum3 + i;
        }
    }

    cout<<"1+100 사이의 정수합은 "<< sum <<"입니다."<< endl;
    cout<<"3의 배수의 합은"<< sum3 <<"입니다." << endl;

    return 0;
}