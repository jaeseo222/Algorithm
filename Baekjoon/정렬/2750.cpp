#include<iostream>
using namespace std;
const int SIZE = 1000;
int arr[SIZE];

void sorted(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int idx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[idx] > arr[j])
				idx = j;
		}
		int tmp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = tmp;
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sorted(arr, n);

	for (int i = 0; i < n; i++)
		cout<< arr[i]<<'\n';
}
