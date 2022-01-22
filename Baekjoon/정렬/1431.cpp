#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int sumNum(string str) {
	int sum = 0;
	for (int i = 0; i < str.size(); i++)
		if (isdigit(str[i]))
			sum += str[i] - '0';
	return sum;
}
bool cmp(const string& i1, const string& i2) {
	if (i1.size() != i2.size())
		return i1.size() < i2.size();

	int sum1 = sumNum(i1);
	int sum2 = sumNum(i2);
	if (sum1 != sum2)
		return sum1 < sum2;

	return i1 < i2;
}

int main() {
	int n;
	cin >> n;

	vector<string> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num.begin(), num.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << num[i] << '\n';
}
