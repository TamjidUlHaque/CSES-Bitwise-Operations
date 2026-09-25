#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 10, LOG_K = 30;
 
int basis[LOG_K], sz;
 
void insertVector(int mask) {
	for (int i = LOG_K - 1; i >= 0; i--) {
		if ((mask & 1 << i) == 0) continue;
 
		if (!basis[i]) {
			basis[i] = mask;
			sz++;
 
			return;
		}
 
		mask ^= basis[i];
	}
}
 
int query(int k) {
	int mask = 0;
 
	int tot = 1 << sz;
	for (int i = LOG_K - 1; i >= 0; i--)
		if (basis[i]) {
			int low = tot / 2;
 
			if ((low < k && (mask & 1 << i) == 0) ||
				(low >= k && (mask & 1 << i) > 0)) mask ^= basis[i];
 
			if (low < k) k -= low;
 
			tot /= 2;
		}
 
	return mask;
}
 
int main() {
	int n;
	cin >> n;
 
	while (n--) {
		int t, k;
		scanf("%d %d", &t, &k);
 
		if (t == 1) insertVector(k);
		else printf("%d\n", query(k));
	}
 
	return 0;
}