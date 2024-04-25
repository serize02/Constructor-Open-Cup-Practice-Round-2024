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

using ull = unsigned long long;
using ld = long double;
using point = complex<double>;
const int MAX = 1e6+5;
const int INF = (1<<30);
const int mod = 1e9+7;
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
    int n, k;
    vector<string> w;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string ss; cin >> ss;
        w.push_back(ss);
    }

    int cnt = w[0].size(), ans = 0;
    for(int i = 1; i < n; i++){
        int m = w[i].size() + 1;
        if(cnt+m <= k) cnt += m;
        else{
            cnt = m-1;
            ans++;
        }
    }
    if(cnt <= k) ans++;
    cout << ans;
    return 0;
}