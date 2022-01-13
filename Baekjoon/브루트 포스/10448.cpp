#include<iostream>
#include<vector>
using namespace std;
const int SIZE = 45;
bool solu(int n, vector<int> tri) {
	for (int i = 1; i <= SIZE; i++)
		for (int j = 1; j <= SIZE; j++)
			for (int k = 1; k <= SIZE; k++)
				if (tri[i] + tri[j] + tri[k] == n)
					return true;
	return false;
}

int main() {
	int n,x;

	vector<int> tri(SIZE);
	//삼각수를 미리 구해놓기
	for (int i = 1; i <= SIZE; i++)
		tri[i]=i*(i+1)/2;

	while (n--) {
		cin >> x;
		cout<<solu(x, tri)<<'\n';
	}
}
