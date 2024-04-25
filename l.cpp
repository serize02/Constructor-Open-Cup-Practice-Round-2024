#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define compress_id(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define lowbit(x) x&(-x)
#define pb push_back
#define f first
#define s second
#define test() int t; cin >> t; for(;t;t--)
#define sz(x) (int)x.size()
#define cyes cout << "YES\n"
#define cno cout << "NO\n" 

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

using ull = unsigned long long;
using ld = long double;
using point = complex<double>;
const int MAX = 1e6+5;
const int INF = (1<<30);
const int mod = 998244353;
const double pi = acos(-1);

inline int pow_mod(int a, int n){
    int ans = 1;
    for(;n ;n >>= 1){
        if(n&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<vvi> dp(n, vvi(n, vi(n)));
    dp[1][1][1] = 1;
    for(int l = 2; l < n; l++){
        vector<vvi> curr(n, vvi(n, vi(n)));
        for(int i = 0; i < n; i++){
            for(int j = 0; j <  n; j++){
                for(int h = 0; h < n; h++){
                    if(dp[i][j][h]){
                        curr[i+1][h][1] = (curr[i+1][h][1] + dp[i][j][h]*h)%mod;
                        curr[i][j][h+1] = (curr[i][j][h+1] + dp[i][j][h]*j%mod*pow_mod(2,h)%mod)%mod; 
                    }
                }
            }
        }
        swap(dp,curr);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int h = 0; h < n; h++){
                ans = (ans + dp[i][j][h])%mod;
            }
        }
    } 
    cout << ans;
    return 0;
}