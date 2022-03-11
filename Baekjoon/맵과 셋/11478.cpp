#include<iostream>
#include<set>

using namespace std;

int numStr(string str) {
	set<string> ans;
	int result = 0;

	for (int i = 0; i < str.size(); i++) {
		string tmp = "";
		for (int j = i; j < str.size(); j++) {
			tmp += str[j];
			ans.insert(tmp);
		}
	}
	return ans.size();
}

int main() {
	string str;
	cin >> str;

	cout << numStr(str);
}
