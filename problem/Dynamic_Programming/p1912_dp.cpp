// https://www.acmicpc.net/problem/1912
// d[i-1] + a[i] �� ���� a[i] ���� ��
// �ٷ� ���� ���� ���� ���� ���Ͽ� ���� ���� ���Ѵ�.

#include <iostream>
#include <algorithm>

using namespace std;

int d[100001];
// d[i]��°���� ���� �� �ִ� ���� ū ��
int a[100001];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	d[0] = a[0];
	for (int i = 1; i < n; i++) {
		d[i] = a[i];
		if (d[i] < a[i] + d[i - 1]) {
			d[i] = a[i] + d[i - 1];
		}
	}

	int ans = -10000;
	for (int i = 0; i < n; i++) {
		if (ans < d[i]) {
			ans = d[i];
		}
	}

	cout << ans << '\n';

	return 0;
}