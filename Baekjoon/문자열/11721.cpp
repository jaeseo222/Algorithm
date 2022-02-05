#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	cin >> str;

	for (int i = 0; i < str.size();) {
		cout << str[i];
		if (++i%10 ==0)
			cout << '\n';
	}
}
