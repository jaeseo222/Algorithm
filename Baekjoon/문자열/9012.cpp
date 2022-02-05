#include<iostream>
#include<stack>
using namespace std;
string vps(string str) {
	stack<int> s;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')
			s.push(str[i]);
		else if (str[i] == ')')
			if (s.empty())
				return "NO";
			else
				s.pop();
	}
	if (s.empty())
		return "YES";
	else
		return "NO";
}

int main() {
	int n;
	string str;
	cin >> n;

	while (n--) {
		cin >> str;
		cout << vps(str)<<'\n';
	}
}
