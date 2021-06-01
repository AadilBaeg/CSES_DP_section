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
int dp[100002][102], m;
int arr[100002];
int f(int n, int last){
    if(n==0) return 1;
    if(n==1){
        if(arr[n]!=0) return abs(last-arr[n]) <= 1;
        else 1 + (last+1 <= m) + (last-1 >= 1);
    }
    int &ans = dp[n][last];
    if(ans != -1) return ans;
 
    ans = 0;
 
    if(arr[n]!=0){
        if(abs(last-arr[n])<=1){
            ans = f(n-1, arr[n]);
            ans %= mod;
        }
    }
    else{
        vector<int> v = {last-1, last, last+1};
        for(auto i: v){
            if(i<=m and i>=1){
                ans += f(n-1, i);
                ans %= mod;
            }
        }
    }
    return ans;
}
void solve() {
    int n; cin >> n >> m;
    memset(dp, -1, sizeof dp);
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }
    int ans = 0;
    if(arr[n]!=0){
        ans = f(n-1, arr[n]);
    }
    else{
        for(int i = 1 ; i <= m ; i++){
            ans += f(n-1, i);
            ans %= mod;
        }
    }
    cout << ans;
}
 
signed main() {
    solve();
}