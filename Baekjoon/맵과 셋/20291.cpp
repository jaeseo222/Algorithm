#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int main() {
	int n;
	cin >> n;

	string fold;
	map<string, int> ans;
	while (n--) {
		cin >> fold;

		//for (int i = fold.find(".") + 1; i < fold.size(); i++)
		//	name += fold[i];

		string name = fold.substr(fold.find(".")+1, fold.size()); // 확장자 이름 추출
		ans[name]++;
	}
	for (auto iter : ans)
		cout << iter.first << ' ' << iter.second << '\n';
}
