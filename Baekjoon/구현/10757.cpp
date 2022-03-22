#include <iostream>
#include <stack>

using namespace std;

//A + B 함수, 일의 자릿수부터 더함
stack<int> calcPlus(string& a, string& b) {
	stack<int> st;
	int idxa = a.length() - 1;
	int idxb = b.length() - 1;

	bool carry = false; // 올림 여부
	while (idxa >= 0 && idxb >= 0) {
		int num = a[idxa--] - '0' + b[idxb--] - '0';
		if (carry) num++;
		carry = num / 10;
		st.push(num % 10);
	}

	while (idxa >= 0) {
		int num = a[idxa--] - '0';
		if (carry) num++;
		carry = num / 10;
		st.push(num % 10);
	}
	while (idxb >= 0) {
		int num = b[idxb--] - '0';
		if (carry) num++;
		carry = num / 10;
		st.push(num % 10);
	}

	if(carry) // 마지막 올림
		st.push(1);

	return st;
}
int main() {
	string a, b;
	stack<int> st; //더한 결과값 저장할 스택
  
	cin >> a >> b;

	st = calcPlus(a, b);

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}
