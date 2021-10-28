/**
 * Author: Samuel Batara (Aratab)
**/ 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	int a[n]; for(int i=0; i<n; i++) cin >> a[i];
	int dp[n]; for(int i=0; i<n; i++) dp[i] = 1e9+7;
	dp[0] = 0;
	for(int i=0; i<n; i++) {
		if(i+1 < n) dp[i+1] = min(dp[i+1], abs(a[i]-a[i+1]) + dp[i]);
		if(i+2 < n) dp[i+2] = min(dp[i+2], abs(a[i]-a[i+2]) + dp[i]);
	}
	//for(int i=0; i<n; i++) cerr << dp[i] << ' ';
	cout << dp[n-1] << '\n';
	return 0;
}

