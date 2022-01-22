#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> ci;

bool cmp(const ci &i1, const ci &i2) {
	if (i1.second != i2.second)
		return i1.second < i2.second;
	return i1.first < i2.first;
}

int main() {
	int n;
	cin >> n;

	vector<ci> loca(n);
	
	for (int i = 0; i<n;i++)
		cin >> loca[i].first>> loca[i].second;

	sort(loca.begin(), loca.end(),cmp);

	for (int i = 0; i < n; i++)
		cout<< loca[i].first <<' '<< loca[i].second<<'\n';
}
