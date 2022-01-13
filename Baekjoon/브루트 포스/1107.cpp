#include<iostream>
#include<vector>
using namespace std;
const int MAX_CHANNEL = 1000000;
vector<bool> breakBtn(11);//0~9

int canCnt(int cha) {
	int cnt = 0;
	if (cha == 0)
		return !breakBtn[0];//0 번으로 갈 때, 0고장 true->0, 고장안남 false->1
	while (cha != 0) {
		if (breakBtn[cha % 10])//고장난 게 있으면 어차피 그 채널로 못감. 그냥 0 리턴
			return 0;
		cha /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	int n, m, btn;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> btn;
		breakBtn[btn] = true;
	}

	int min_click = abs(n - 100);//현재 100에서 +,-만으로 간 횟수로 초기화
	for (int i = 0; i < MAX_CHANNEL; i++) {
		int press_cnt = canCnt(i);//i로 가기위해 눌러야  하는 횟수
		if (press_cnt)//0 아닐 때
			min_click = min(min_click, abs(n - i) + press_cnt);//그 후, +,-만으로 간 횟수 중에 작은 걸로 갱신.
	}
	cout << min_click;
}
