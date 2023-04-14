#include <iostream>
using namespace std;

class Maxmin {
    double a, b, c;
public:
    Maxmin(double a, double b, double c) {
        this -> a = a;
        this -> b = b;
        this -> c = c;
    }
    double getMax();
    double getMin();
    double max, min;
};

double Maxmin::getMax() {
    max = (a > b) ? a : b;
    max = (max > c) ? max : c;
    return max;
}
double Maxmin::getMin() {
    min = (a < b) ? a : b;
    min = (min < c) ? min : c;
    return min;
}

int main() {
    double a, b, c;
    while (true) {
        cout << "실수 세개 입력: "; cin >> a >> b >> c;
        if (a+b+c == 0) break;
        Maxmin *p = new Maxmin(a, b, c);
        cout << "최대값은 " << p-> getMax() << " 최소값은 " << p->getMin() << endl;
        delete p;
    }
    cout << "bye!" << endl;
}
