# 세 수 변경 (확인문제 10-5 참고)
  
  
## 조건
- 두 수 교환이 아닌 세 수 값 변경하도록 바꿔보세요. (myswap의 매개변수는 3개)  
  
- 예를 들어, 사용자가 a b c 정수변수 값으로 10 20 30 을 입력하면  
myswap(a,b,c); 를 호출한 후에는 a b c 가 20 30 10 으로 바뀝니다.  
사용자가 d,e,f 실수변수 값으로 1.1  2.2  3.3 을 입력하면  
myswap(d,e,f); 를 호출한 후에는 a b c 가 2.2  3.3  1.1 로 바뀝니다.  

## 사용된 이론
### 템플릿
- 함수나 클래스를 일반화 하는 C++ 도구
- 선언: template<class T>  
ex)  
```C++
void myswap(int & a, int & b) {
	int tmp;
	a = b;
	b = tmp;
}
```

```C++
void myswap(double & a, double & b) {
	double tmp;
	tmp = a;
	a = b;
	b = tmp;
}
```
위 두 코드는 데이터타입만 다르고 모두 같음 -> template으로 간단하게 변경 가능
```C++
template <class T>
void myswap(T & a, T & b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}
```
  
## 코드
```C++
#include <iostream>
using namespace std;

template <class T>
void myswap(T &a, T &b, T &c) {
    T tmp;
    tmp = a;
    a = b;
    b = c;
    c = tmp;
}

int main() {
    int a, b, c;
    cout << "세 정수 입력: ";
    cin >> a >> b >> c;
    myswap(a, b, c);
    cout << " a = " << a << ", b = " << b << ", c = " << c << endl << endl;

    double d, e, f;
    cout << "세 실수 입력: ";
    cin >> d >> e >> f;
    myswap(d, e, f);
    cout << " d = " << d << ", e = " << e << ", f = " << f << endl << endl;
}
```
## 결과
<img src = "/images/check_10-5_changethreenum.png" />
