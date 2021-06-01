#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
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
 
struct Project{
    int start;
    int end;
    int reward;
};
 
int dp[200002];
vector<Project> arr;
vector<int> v;
 
int f(int n){
    if(n<=0) return 0;
    int &ans = dp[n];
    if(ans != -1) return ans;
    
    ans = 0;
    int i = lb(all(v), arr[n-1].start) - v.begin();
    
    ans = max(arr[n-1].reward + f(i), f(n-1));
    return ans;
}
bool cmp(const Project& a, const Project& b){
    return a.end < b.end;
}
void solve() {
    memset(dp, -1, sizeof dp);
    int n; cin >> n;
    arr.resize(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i].start >> arr[i].end >> arr[i].reward;
    }
    sort(all(arr), cmp);
 
    for(auto i: arr){
        v.pb(i.end);
    }
    int ans = f(n);
    cout << ans;
}
 
signed main() {
    solve();
}