#include<iostream>
#include<vector>
using namespace std;

void counting(int ar[26], string word) {
	for (int i = 0; i < word.length(); i++)
		ar[word[i] - 'A']++;
}
int solu(int n, vector<string> arr) {
	int ans = 0;

	int freq[26] = { 0 };
	counting(freq, arr[0]);

	for (int i = 1; i < n; i++) {
		int diff = 0;
		int othe[26] = { 0 };
		counting(othe, arr[i]);

		for (int j = 0; j < 26; j++)
			diff += abs(freq[j] - othe[j]);

		if (diff == 0 || diff == 1 || (diff == 2 && arr[i].length() == arr[0].length()))
			ans++;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << solu(n, arr);
}
