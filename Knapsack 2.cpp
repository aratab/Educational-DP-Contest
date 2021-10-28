/**
 * Author: Samuel Batara (Aratab)
**/ 
#include <bits/stdc++.h>
using namespace std; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,w; cin >> n >> w;
	int a[n], b[n];
	int tot = 0;
	for(int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
		tot += b[i];
	}
	
	const long long inf = 1e18+7;
	vector<long long> dp(tot+1, inf);
	dp[0] = 0;
	for(int i=0; i<n; i++) {
		for(int j=tot; j>=0; j--) {
			if(dp[j] + 1ll*a[i] <= 1ll*w) {
				assert(j + b[i] <= tot);
				dp[j+b[i]] = min(dp[j+b[i]], dp[j] + 1ll*a[i]);
			}
		}
	} 
	int ans = 0;
	for(int i=0; i<=tot; i++) {
		if(dp[i] <= 1ll*w) {
			ans = i;
		}
	}
	cout << ans << '\n';
	return 0;
}
