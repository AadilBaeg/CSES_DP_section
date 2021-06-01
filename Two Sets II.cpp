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
 
signed main(){
    int n; cin >> n;
    int sum = (n*(n+1))/2;
    if(sum%2==1){
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;
    int arr[502];
    for(int i = 0 ; i < 502; i++){
        arr[i] = i+1;
    }
    int dp[2][sum+1];
    for(int i = 0 ; i < 2; i++){
        for(int j = 0 ; j <= sum; j++){
            dp[i][j] = (j==0);
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= sum; j++){
            dp[i%2][j] = dp[1-i%2][j];
            if(arr[i-1] <= j)
                dp[i%2][j] += dp[1-i%2][j-arr[i-1]];
            dp[i%2][j] %= mod;
        }
    }
    int ans = dp[1-n%2][sum];
    cout << ans;
}