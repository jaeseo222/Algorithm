#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findNum(int a, int b) {
	if (b == 0) return a;
	return findNum(b, a%b);
}

int main() {
	string str;

	cin >> str;

	int n = stoi(str.substr(0, str.find(':')));
	int m = stoi(str.substr(str.find(':')+1));

	int num=findNum(n,m); //최대공약수
	cout << n / num << ':' << m / num;
}
