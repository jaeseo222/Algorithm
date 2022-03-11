#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int t, n;
	string name, cloth;
	cin >> t;

	while (t--) {
		cin >> n;

		map<string, int> clothes;
		while (n--) {
			cin >> name >> cloth;
			clothes[cloth]++;
		}

		int ans = 1;
		for (auto iter : clothes)
			ans *= iter.second + 1; //입는 경우, 안 입는 경우

		cout << ans - 1 << '\n'; //알몸을 제외
	}
}

