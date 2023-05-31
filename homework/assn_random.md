# 난수

## 조건
- 10장 수업자료 p. 18 예제를 참고로 하여, 짧은 동영상을 만들어서 제출하세요.
- 화면의 랜덤 위치 (x,y)로 커서를 이동시킨 뒤 특정 그림( 문자 한개도 좋고 아무거나 )을 출력합니다.
- LMS-강의콘텐츠에 있는 '난수과제결과샘플' 동영상은 별(*) 문자를 150개 출력한 예시입니다.
- x,y 좌표 범위는 콘솔창마다 다르기 때문에, 본인 콘솔창의 크기를 고려해서 난수 생성 범위를 잡으시면 됩니다.
  샘플 동영상에서 는 x의 범위는 (0, 65), y의 범위는 (0, 25)로 잡았습니다.  
- 기본 콘솔 경우 x(가로) 좌표는 맨 왼쪽이 0이고 오른쪽으로 갈 수록 숫자가 커지며
  y(세로) 좌표는 맨 위가 0이며 아래로 갈 수록 숫자가 커집니다.
- 동영상 느낌이 나도록 출력할 때마다 시간차를 두세요.
  1학년 C언어에서 배우는 system 함수를 호출해도 되지만
  더 편하게 사용하시려면 OS 마다 별도로 제공하는 함수를 사용하셔도 됩니다.

1초 딜레이 경우 Windows 경우 #include <windows.h> 한 후 1/1000초 단위의 Sleep(1000); 많이 사용
리눅스/맥 경우 #include <unistd.h> 한 후 1초 단위 sleep(1); 혹은 1/1000000초 단위의 usleep(1000000); 많이 사용
기타 본인이 선호하는 방법으로 시간 딜레이 구현
샘플동영상은 0.05초 딜레이로 설정한 경우입니다. 
 

- 커서 위치를 이동시키는 방법도 매우 다양하며 OS 마다 별도로 라이브러리를 제공하고 있습니다.
  아시는 방법 중에서 자유롭게 사용하셔도 됩니다.
  혹시 아직 커서이동을 안해보신 분들은 아래 예제를 참고하세요. (모든 OS에서 사용가능한 단순한 방법 예제입니다.)

#include <iostream>
using namespace std;
void move_cur(int x, int y) {
   printf("\033[%d;%dH", y, x);
}
int main() {
  move_cur(30, 10); cout << "hello";
  move_cur(10, 0); cout << "bye";
  move_cur(50, 5); cout << "Dooli";
  getchar();  /* 종료 메세지가 콘솔창에 뜨는 것을 잠시 막기 위한 getchar(); 입니다.
                  엔터키를 누르시면 프로그램 종료 */
  return 0;
}
 
제출: 소스(txt파일), 결과동영상 

## 코드
```C++
#include <iostream>
#include <random>
#include <unistd.h>
using namespace std;
void move_cur(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int main() {
    random_device dv;

    mt19937 gen(dv());
    uniform_int_distribution<> dist(0, 100);
    uniform_int_distribution<> dist2(5, 0);

    for(int i = 0; i < 150; i++) {
        move_cur(dist(gen), dist2(gen));
        cout << "*" << endl;
        usleep(50000);
    }
    getchar();
    return 0;
}
```
                           
## 주의할 점 - 내가 코드 짤 때 실수했던 부분
* 맥에서는 cout << "*" 뒤에 꼭 endl;을 붙여줘야 별이 한 번에 안 뜨고 시간차를 둔 채 출력된다.
