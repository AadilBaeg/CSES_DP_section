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
/* this problem recurrence basically is a bit different from the solution written below
 the intuition almost same except wherever (n-1) is written in recursion it should be (n+1)
 and the base case will be if (i>=n) return 1; but I have done in this way so as to ease precomputation.
 */ 
const int mex = 1000001;
int dp[mex+1][3];
int f(int n, int ps){   
    if(n==1) return 1;
    int &ans = dp[n][ps];
    if(ans != -1) return ans;
    ans = 0;
    if(ps==1){
        ans = f(n-1, 1) + f(n-1, 1) + f(n-1, 2); 
    }
    else{
        ans = f(n-1, 2) + f(n-1, 2) + f(n-1, 1) + 2*f(n-1, 2);
    }
    ans %= mod;
    return ans;
}
void pre(){
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(int i = 1 ; i <= 2; i++){
        ans += f(mex, i);
        ans %= mod;
    }
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        int ans = f(n, 1) + f(n, 2);
        ans %= mod;
        cout << ans << endl;
    }
}