#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] == arr[j]) cnt++;
		}
	}
	delete[] arr;

	cout << cnt;
	return 0;
}