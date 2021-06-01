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
int min(int a, int b) { //return min(a, b)
    return a<b ?a : b;
}
 
int binexp(int x, int n) { //return (x^n)%mod 
    int ans = 1;
    while(n>0) {
        if(n%2)
            ans = (ans*x)%mod;
        x = (x*x)%mod;
        n = n/2;
    }
    return ans;
}
 
int arr[102], dp[1000002], n;
int f(int w){
    if(w==0) return 1;
    int &ans = dp[w];
    if(ans != -1) return ans;
    ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] <= w){
            ans += f(w -arr[i]);
            ans %= mod;
        }
    }
    return ans;
}
void solve() {
    int w; cin >> n >> w;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] <= w){
            ans += f(w-arr[i]);
            ans %= mod;
        }
    }
    cout << ans;
}
 
 
signed main() {
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
}