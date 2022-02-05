#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	while (getline(cin, str)) // 공백일 때 루프 빠져나감
		cout << str << '\n';
}
