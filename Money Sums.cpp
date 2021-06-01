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
const int NMAX = 100002;
int vis[102][NMAX];
int arr[102];
int hs[NMAX];
 
void f(int n, int sum){
    if(n==0){
        hs[sum]=1;
        return;
    }
    if(vis[n][sum]==1) return;
    vis[n][sum] = 1;
    f(n-1, sum-arr[n]);
    f(n-1, sum);
}
void solve() {
    memset(vis, -1, sizeof vis);
    int n; cin >> n;
    int sum = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    f(n, sum);
    int sz = 0;
    for(int i = 1 ; i < NMAX; i++){
        if(hs[i]){
            sz++;
        }
    }
    cout << sz << endl;
    for(int i = 1; i < NMAX; i++){
        if(hs[i]) cout << i << " ";
    }
    
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}