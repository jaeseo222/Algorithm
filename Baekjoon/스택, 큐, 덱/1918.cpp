#include<iostream>
#include<stack>
using namespace std;

int priority(char c) {
	switch (c) {
	case'*': case '/': return 1; // 우선순위 가장 높아서 제일 빨리 나옴
	case '+': case '-': return 2;
	case '(': case ')': return 3;
	}
}

string conv(string str) {
	string ans = "";
	stack<char> formul;

	for (int i = 0; i < str.size(); i++) {
		switch (str[i]) {
		case '(': formul.push(str[i]); break;
		case ')':
			while (!formul.empty() && formul.top() != '(') { // () 내에 있는 연산자 출력
				ans += formul.top();
				formul.pop();
			}
			formul.pop(); // ( 제거
			break;
		case '*': case '/': case '+': case'-':
			while (!formul.empty() && priority(formul.top()) <= priority(str[i])) { // ex. * <= + 
				ans += formul.top();
				formul.pop();
			}
			formul.push(str[i]);
			break;
		default:
			ans += str[i]; // 피연산자 출력
			break;
		}
	}

	while (!formul.empty()) {
		ans += formul.top();
		formul.pop();
	}
	return ans;
}
int main() {
	string str;
	cin >> str;

	cout << conv(str);
}
