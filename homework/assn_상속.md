# 상속 (강의자료 8장 참고)

## 조건
- 부모클래스 A, 자식 클래스 B 가 있습니다.  

- A에는 멤버함수가 있는데, 반지름을 매개변수로 받아서 구의 부피를 반환합니다.  
- B에도 멤버함수가 있는데, 반지름을 매개변수로 받아서 원의 둘레를 반환합니다.  

- main에서는 A객체 말고 B 객체만 생성합니다.  

-  콘솔창에는 다음과 같이 세 줄이 나옵니다.  
반지름 입력: 5  
구의 부피는 523.599 입니다.  
원의 둘레는 31.4159 입니다.  

- 물론 main에서는 계산은 안하고 멤버함수만 호출합니다.  

## 사용된 이론
### 템플릿
- 부모클래스의 속성과 기능을 자식클래스에 물려줌
- 접근지정자
> private - 선언된 클래스 내에서만 접근 가능, 자식 클래스에서도 부모 클래스의 private 멤버 직접 접근 불가  
> public - 선언된 클래스 및 모든 외부 함수에 접근 허용, 자식 클래스에서 부모 클래스의 public 멤버 접근 가능  
> protected - 선언된 클래스 및 자식 클래스에서만 접근 허용 **외부 함수에서는 protected 멤버를 접근할 수 없음**  
- 상속 시 접근 지정
> public - 부모 클래스의 멤버 속성을 그대로 계승  
> private - 부모클래스의 멤버 속성을 private으로 계승  
> protected - 부모 클래스의 멤버 속성을 protected로 계승  
#### 다중상속의 문제점 - 중복 상속
```C++
#include <iostream>
using namespace std;

class A { public: int add(int a, int b) { return a + b; } };
class B1 : public A { public: int minus(int a, int b) { return a - b } };
class B2 : public A { public: int multi(int a, int b) { return a * b } };
class C : public B1, public B2 {};

int main() {
  C c;
  cout << c.add(3, 5) << endl; // 오류 발생 -> B1, B2 중 누가 상속받은 add()를 의미?
}
```

## 코드
```C++
#include <iostream>
using namespace std;

class A {
public:
    double Orb(int radius) {
        return 4.0 / 3.0 * 3.141592 * radius * radius * radius;
    }
};

class B : public A {
public:
    double Circle(int radius) {
        return 3.141592 * 2 * radius;
    }
};

int main() {
    int a;
    B b;

    cout << "반지름 입력: ";
    cin >> a;

    cout << "구의 부피는 " << b.Orb(a) << "입니다." << endl;
    cout << "원의 둘레는 " << b.Circle(a) << "입니다.";
}
```

## 결과
<img src = "/images/assn_8.png" />

## 주의할 점 - 내가 코드 짤 때 실수했던 부분
* 결과에 소수점으로 나오기 때문에 리턴값의 데이터타입은 double 또는 float을 쓴다.
* 
```C++
class A {
public:
    double Orb(int radius) {
        return 4.0 / 3.0 * 3.141592 * radius * radius * radius;
    }
};
```
여기에서 4.0 / 3.0을 쓰지 않고 그냥 4 / 3을 하면 원하는 값이 제대로 나오지 않는다.  
이유는 뒤에 곱하는 값(3.141592)가 소수점이 붙어서 그런데,  
따라서 사칙연산을 할 때, **숫자 중에 실수가 있다면 나머지 숫자가 정수여도 소수점을 붙인 형태로 적어주는 것이 좋다.**

