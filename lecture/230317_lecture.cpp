#include <iostream>
#include <string>
using namespace std;

int main() {
    string movie("Top Gun"); //string movie = "Top Gun"; 가능
    string answer("Tom Cruise");
    string input;

    cout << movie + "의 주인공은?";
    cout << "(힌트 : 첫글자는 " << answer[0] << ")? ";

    getline(cin, input);

    if(input == answer) cout << "맞았습니다.";
    else cout << "틀렸습니다." + answer + "입니다." << endl;

    return 0;

}
