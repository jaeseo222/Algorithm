#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
string sorted(string str) {
	vector<int> arr;
	string ans;
	for (int i = 0; i < str.size(); i++)
		arr.push_back(str[i]-'0'); // 숫자로 변환
	
	sort(arr.begin(), arr.end(), greater<>()); //내림차순

	for (int i = 0; i < str.size(); i++)
		ans+=(to_string(arr[i])); // 문자로 변환

	return ans;
}

int main() {
	string str;
	cin >> str;

	cout << sorted(str);
}
