#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int SIZE = 20 + 1;
int main() {
	int card[SIZE];
	for (int i = 1; i < SIZE; i++)
		card[i] = i;

	int a, b;
	while (cin >> a >> b)
		reverse(card + a, card + b + 1);

	for (int i = 1; i < SIZE; i++)
		cout << card[i] << ' ';
}
