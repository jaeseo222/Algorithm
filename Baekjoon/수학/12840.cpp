#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MINUTE = 60; //1분 초로 나타냄
const int HOUR = 60 * MINUTE; //1시간 초로 나타냄
const int DAY = 24 * HOUR; //하루 초로 나타냄

void printTime(int second) {
	int h = second / HOUR;
	int m = (second % HOUR) / MINUTE;
	int s = (second % HOUR) % MINUTE;
	cout << h << ' ' << m << ' ' << s << '\n';
}

/**
 * 단순 구현 문제
 * 시계를 앞으로 돌리면 +, 뒤로 돌리면 -
 * !주의! 전날로 넘어갈 수 있으므로 항상 모듈러 연산을 하고,
 *       그럼에도 전날로 넘어갔을 경우 하루를 더해주는게 중요
 */

int main() {
	//입출력 속도 향상
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, h, m, s, c, q;
	//입력
	cin >> h >> m >> s;
	cin >> q;

	//시간 초기화
	int second = h * HOUR + m * MINUTE + s;

	//입력 & 연산 & 출력
	while (q--) {
		cin >> t;

		if (t == 1) { //시계 앞으로(+)
			cin >> c;
			second += c;
		}
		if (t == 2) { //시계 뒤로(-)
			cin >> c;
			second -= c;
			while (second < 0)
				second += DAY;
		}
		if (t == 3) //시계가 가리키는 시간 출력
			printTime(second);

		second %= DAY; //하루가 넘어갔을 수 있으므로 모듈러 연산
	}
}
