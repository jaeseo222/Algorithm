#include<iostream>
#include<unordered_set>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, m, tmp;
	cin >> t;
	while (t--) {
		cin >> n;//수첩 1
		unordered_set<int> note;
		while(n--) {
			cin >> tmp;
			note.insert(tmp);
		}

		cin >> m;//수첩 2
		while(m--) {
			cin >> tmp;
			auto iter = note.find(tmp);
			if (iter != note.end())
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
}
