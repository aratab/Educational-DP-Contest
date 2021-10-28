/**
 * Author: Samuel Batara (Aratab)
**/ 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	int w; cin >> w;
	int a[n], b[n];
	for(int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
	} 
	vector<long long> dp(w+1,-1);
	dp[0] = 0;
	for(int i=0; i<n; i++) {
		for(int j=w; j>=0; j--) {
			if(j+a[i] <= w && dp[j] != -1) {
				dp[j+a[i]] = max(dp[j+a[i]], dp[j] + 1ll*b[i]); 
			}
		}
	} 
	long long ans = 0;
	for(int i=0; i<=w; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
	return 0;
}
