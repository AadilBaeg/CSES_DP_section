#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
#define double long double
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define pii pair<int,int>
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define all(x) x.begin(),x.end()
#define fill(a,b) memset(a,b,sizeof(a))
#define sz(x) (int)x.size()
#define sp(x) setprecision(x)
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define inf 1000000000000000005LL
 
 
int ceil(int a, int b) { // calculates ceil(a, b)
    return (a+b-1)/b;
}
 
int max(int a, int b) { //return max(a, b)
    return a>b ? a : b;
}
 
int binexp(int x, int n) { //return (x^n)%mod 
    int ans = 1;
    while(n>0) {
        if(n%2)
            ans = (ans*x)%mod;
        x = (x*x)%mod;
        n /= 2;
    }
    return ans;
}
 
int arr[102];
int dp[2][1000002];
int mn = INT_MAX;
 
void solve() {
    int n, w; cin >> n >> w;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
 
    for(int i = 0 ; i < 2; i++){
        for(int j = 0 ; j < 1000002; j++){
            dp[i][j] = mn;
        }
    }
    for(int j = 1 ; j<=w ; j++)
        dp[0][j] = mn;
 
    for(int i = 0 ; i < 2; i++)
        dp[i][0] = 0;
 
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j <= w; j++){
            if(arr[i] <= j){
                dp[i%2][j] = min(1 + dp[i%2][j-arr[i]], dp[1-i%2][j]);
            }
            else {
                dp[i%2][j] = dp[1-i%2][j];
            }
        }
    }
    int ans = dp[1-n%2][w];
    cout << (ans==mn?-1:ans);
}
 
signed main() {
    solve();
}