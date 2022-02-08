#include<iostream>
using namespace std;
void solu(string s) {
	int alph[26] = {0};

	for (int i = 0; i < s.size(); i++)
		alph[s[i] - 'a']++;
	for (int i = 0; i < 26; i++)
		cout << alph[i] << ' ';
}

int main() {
	string s;
	cin >> s;
	solu(s);
}
