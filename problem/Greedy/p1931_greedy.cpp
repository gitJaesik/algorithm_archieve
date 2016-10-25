// https://www.acmicpc.net/problem/1931
// �� ȸ�ǰ� ���� �ð��� ������, ���� �����ϴ� �� ���� ��ġ�� �ؾ��Ѵ�.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {

	int n;
	cin >> n;
	vector<pair<int, int>> a(n);

	for (int i = 0; i < n; i++) {
		int start, end;
		scanf("%d %d", &start, &end);

		a[i].first = start;
		a[i].second = end;
	}

	sort(a.begin(), a.end(), cmp);

	int ans = 0;
	int endTime = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].first >= endTime) {
			ans += 1;
			endTime = a[i].second;
		}
	}

	cout << ans << '\n';

	return 0;
}