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
const int NMAX = 5002;
int arr[NMAX];
int dp[NMAX][NMAX];
int f(int i, int j){
    if(i>j) return 0;
    if(i==j) return arr[i];
    int &ans = dp[i][j];
    if(ans != -1) return ans;
 
    ans = max(arr[i] + min(f(i+2, j), f(i+1, j-1)), arr[j] + min(f(i, j-2), f(i+1, j-1)));
 
    return ans;
}
void solve() {
    memset(dp, -1, sizeof dp);
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int ans = f(0, n-1);
    cout << ans;
}
 
signed main() {
    solve();
}