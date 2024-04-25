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
    int n; cin >> n;
    vector<int> ar(n);
    int l = 0, r = 1000000000;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        if(i == 0) continue;
        int x; cin >> x;
        int d = (ar[i] > ar[i-1])?ar[i]-ar[i-1]:ar[i-1]-ar[i];
        if(x == 1){
            if(ar[i] > ar[i-1]){
                int l1 = (ar[i]+ar[i-1])>>1;
                if(d&1) l1++;
                l = max(l,l1);
            }
            else{
                int r1 = (ar[i]+ar[i-1])>>1;
                r = min(r,r1);
            }   
        }
        if(x == 2){
            if(ar[i] > ar[i-1]){
                int r1 = (ar[i]+ar[i-1])>>1;
                r = min(r,r1);
            }
            else{
                int l1 = (ar[i]+ar[i-1])>>1;
                if(d&1) l1++;
                l = max(l,l1);
            }
        }
    }
    cout << max(0LL, r-l+1);
    return 0;
}