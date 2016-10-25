// https://www.acmicpc.net/problem/1744
// �� ���� ����. ���� ��ġ�� �𸣰ڴ�.
// ���������� ���� ���, ��������� ���� ���, ������ 0������ ������ ���ϸ� �̵�

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool cmp(const int& a, const int& b) {
	return a > b;
}

int main() {
	int n;
	cin >> n;

	// 10^4 * 10^4 = 10^8 => int�� ����

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a.begin(), a.end(), cmp);

	int lPos = 0;
	int ans = 0;
	while (lPos < n-1 && a[lPos] >= 2 && a[lPos+1] >= 2) {
		ans += a[lPos] * a[lPos + 1];
		lPos += 2;
	}
	int rPos = a.size() - 1;
	while (rPos - 1 >= lPos && a[rPos] <= 0 && a[rPos - 1] <= 0) {
		ans += a[rPos] * a[rPos - 1];
		rPos -= 2;
	}
	while (lPos <= rPos) {
		ans += a[lPos];
		lPos += 1;
	}

	cout << ans << '\n';

	return 0;
}