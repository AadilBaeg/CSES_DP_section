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
int dp[5001][5001];
string arr1, arr2;
int f(int m, int n){
    if(m==0 or n==0) return abs(m-n);
    int &ans = dp[m][n];
    if(ans != -1) return ans;
    
    ans = 1e5;
 
    if(arr1[m-1]==arr2[n-1]){
        ans = f(m-1, n-1);
    }
    else{
        ans = 1 + min3(f(m-1, n-1), f(m, n-1), f(m-1, n));
    }
    return ans;
}
void solve() {
    memset(dp, -1, sizeof dp);
    cin >> arr1;
    cin >> arr2;
    int m = (int)arr1.size();
    int n = (int)arr2.size();
    int ans = f(m, n);
    cout << ans;
}
 
signed main() {
    solve();
}