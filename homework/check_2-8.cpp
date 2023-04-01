#include <iostream>
#include <string>
using namespace std;

int main() {
    string question[] = {"개", "고양이", "기린", "코끼리", "표범"};
    string answer[] = {"dog", "cat", "giraffe", "elephant", "leopard"};
    string ox;
    int score(0);
    string your_answer[4];

    cout << "영단어로 바꾸세요." << endl;
    for(int i = 0; i < 5; i++) {
        cout << question[i] << ": ";
        getline(cin, your_answer[i]);

        if(answer[i] == your_answer[i]) {
            ox.append("O");
            score = score + 20;
        }
        else ox.append("X");

    }
    cout << "==> " << ox << " " << score << "점입니다." << endl;
}
