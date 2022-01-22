#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct info {
	string name;
	int ko, en, ma;
};

bool cmp(const info &i1,const info &i2) {
	if (i1.ko != i2.ko)
		return i1.ko > i2.ko;
	if (i1.en != i2.en)
		return i1.en < i2.en;
	if (i1.ma != i2.ma)
		return i1.ma > i2.ma;

	return i1.name < i2.name;
}
int main() {
	int n;
	cin >> n;

	vector<info> student(n);
	for (int i = 0; i < n; i++)
		cin >> student[i].name >> student[i].ko >> student[i].en >> student[i].ma;

	sort(student.begin(), student.end(), cmp);

	for (int i = 0; i < n; i++)
		cout<< student[i].name<<'\n';
}
