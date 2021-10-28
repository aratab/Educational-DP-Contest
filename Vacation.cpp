/**
 * Author: Samuel Batara (Aratab)
**/ 
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	int a[n][3], dp[n][3];;
	for(int i=0; i<n; i++) {
		for(int j=0; j<3; j++) {
			cin >> a[i][j]; 
			dp[i][j] = 0;
		}
	}
	
	
	for(int i=0; i<3; i++) {
		dp[0][i] = a[0][i];
	}
	for(int i=1; i<n; i++) {
		for(int k=0; k<3; k++) {
			for(int j=0; j<3; j++) if(j != k) {
				dp[i][k] = max(dp[i][k], dp[i-1][j] + a[i][k]);
			}
		}
	}
	int ans = 0;
	for(int i=0; i<3; i++) {
		ans = max(ans, dp[n-1][i]);
	}
	cout << ans << '\n';
	return 0;
}
