/**
 * Author: Samuel Batara (Aratab)
**/ 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	int k; cin >> k;
	int a[n]; for(int i=0; i<n; i++) cin >> a[i];
	int dp[n]; for(int i=0; i<n; i++) dp[i] = 1e9+7;
	dp[0] = 0;
	for(int i=0; i<n; i++) {
		for(int j=1; j<=k; j++) {
			if(i+j < n) dp[i+j] = min(dp[i+j], abs(a[i]-a[i+j])+dp[i]);
		}
	}
	//for(int i=0; i<n; i++) cerr << dp[i] << ' ';
	cout << dp[n-1] << '\n';
	return 0;
}
