#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int SIZE = 987;

int solu(int n, vector<vector<int>>& arr) {
	int ans = 0;

	for (int i = 123; i <= SIZE; i++){
		string tmp = to_string(i); // 정답 숫자
		bool isNum = true;

		if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0') continue;
		if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[2] == tmp[0]) continue;


		for (int j = 0; j < n; j++) {
			string num = to_string(arr[j][0]); // 질문 숫자
			int s_cnt = 0, b_cnt = 0; // 스트라이크, 볼

			for (int k = 0; k < 3; k++)
				if (tmp[k] == num[k]) s_cnt++;
				else if (num.find(tmp[k]) != num.npos) b_cnt++;

			if (s_cnt != arr[j][1] || b_cnt != arr[j][2]) {
				isNum = false;
				break;
			}
		}

		if (isNum)
			ans++;
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(3, 0));
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	cout << solu(n, arr);
}
