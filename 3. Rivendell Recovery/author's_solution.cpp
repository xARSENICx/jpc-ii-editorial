/*
Author: Ayush
Compiler: GNU C++
Problem Link: 
*/

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("popcnt,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops")

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
#ifndef ONLINE_JUDGE
#include <D:/CP/cp-lib/debug.h>
#else
#define debug(x...)
#endif

// ------------------------------------------------------------------------------------------

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// ------------------------------------------------------------------------------------------

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<ll, ll> pl; 
typedef vector<long long> vll;
typedef vector<pl> vpl;
typedef vector<vector<ll>> vvl;
typedef set<ll> sll;
typedef set<char> sc;
typedef map<ll,ll> mll;
typedef unordered_set<ll, custom_hash> uosll;
typedef unordered_map<ll, ll, custom_hash> uomll;
typedef unordered_map<char, ll, custom_hash> uomcll;
typedef gp_hash_table<ll, ll, custom_hash> gp_ht;


// ------------------------------------------------------------------------------------------

#define endl "\n"
#define sqrt sqrtl
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define emb emplace_back 
#define mp make_pair
#define ff first
#define ss second
#define si cout << "Yes" << endl;
#define nyet cout << "No" << endl;

// ------------------------------------------------------------------------------------------

// Loops
#define loop(i, start, n) for (ll(i) = (start); (i) < (n); ++(i))                   // For <
#define loope(i, start, n) for (ll(i) = (start); (i) <= (n); ++(i))                 // For <=
#define loopr(i, n, front) for (ll(i) = (n); (i) >= (front); (i)--)                 // Reverse For
#define loopSq(i, start, n) for (ll(i) = (start); (i) * (i) <= (n); ++(i))          // For Square
#define loopc(ch, start, n) for (char(ch) = (start); (ch) <= (n); ++(ch))           // For Char
#define foreach(it, ds) for (auto &(it) : (ds))                                     // For Each
#define iterm(key,val,ok) for(auto const& [key, val]:ok)                            // For key value 
#define riterm(key,val,ok) for (auto const& [key, val] : ok | std::views::reverse)  // For key value in reverse


// ------------------------------------------------------------------------------------------

#define all(ds) (ds).begin(), (ds).end()                                            // Full Vector
#define clr(ds) memset(ds, 0, sizeof(ds))                                           // Clear Memory
#define sort(ds) sort(all(ds))                                                      // Ascending Vector
#define rev(ds) reverse(all(ds))                                                    // Descending Vector
#define tsum(ds) (accumulate(all(ds), 0ll))                                         // Total Sum
#define ctx(ds, x) (count(all(ds), (x)))                                            // Count frequency of x
#define sz(ds) ((ll)(ds).size())                                                    // Size
#define minv(ds) (*min_element(all(ds)))                                            // Min Value
#define maxv(ds) (*max_element(all(ds)))                                            // Max Value
#define minIdx(ds) (min_element(all(ds)) - (ds).begin())                            // Min Value Index
#define maxIdx(ds) (max_element(all(ds)) - (ds).begin())                            // Max Value Index
#define bs(ds, x) (binary_search(all(ds), x))                                       // Binary Search
#define lob(ds, x) (lower_bound(all(ds), (x)) - (ds).begin())                       // Lower Bound Index
#define upb(ds, x) (upper_bound(all(ds), (x)) - (ds).begin())                       // Upper Bound Index

// ------------------------------------------------------------------------------------------

const ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;                                                             //print modulo 10^9+7
const ll MOD1=998244353;                                                            //FFT
const ll INF = 0x3f3f3f3f;                                                          //inf
const ll neg_INF = 0xcfcfcfcf;                                                      //-inf
const ld EPS = 1e-9;                                                                //epsilon
const ld PI = 3.1415926535897932384626;                                             //pi

// -------------------------------------------------------------------------------------------

ll min(ll a,ll b) { if (a<b) return a; return b; }
ll max(ll a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll pow_mod(ll a,ll b, ll m) { //(a^b)mod m 
    ll res=1;
    while(b>0){
        if(b&1){
            res=(res*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return res;
}
long long mul(long long a, long long b){
    if(b == 0)
        return 0;
    if(b & 1)
        return (mul(a, b - 1) + a) % MOD;
    long long half = mul(a, b >> 1);
    return (half + half) % MOD;
}
ll modinv(ll b, ll m){ return pow_mod(b,m-2,m); }
ll countDigit(ll n) { return n / 10 == 0 ? 1 : 1 + countDigit(n / 10); }
ld c_dist(ld x1,ld y1,ld x2,ld y2){ return sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); }
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rang);} 
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime_basic(ll a) { if (a==1) return false; if (a==2) return true; if (a%2==0) return false; for (int i=3;i<=round(sqrt(a));i+=2) if (a%i==0) return false; return true; }

// ------------------------------------------------------------------------------------------

template <typename T>                                                    
istream &operator>>(istream& istream, vector<T>& v)
{
    for (auto& it : v)
        cin >> it;
    return istream;
}
template <typename T>                                                     
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

// ------------------------------------------------------------------------------------------

/*
    *****Information & Messages:******
~ ascii: 1=49 a=97 A=65
*/

// ------------------------------------------------------------------------------------------

//solve everything here
void precompute(){

}

void solve() {
    ll n, m;
    cin >> n >> m;
    vll a(n), arr(n,-1);
    
    loop(i,0,m){
        ll x;
        cin >> x;
        arr[x-1] = 0;
    }
    ll k;
    cin >> k;
    ll p = 1;
    loop(i,0,n){
        if(arr[i] != 0){
            arr[i] = p;
            p++;
        }
    }
    auto it = find(arr.begin(), arr.end(), k); 
  
    if (it != arr.end())  
    { 
      
        int index = it - arr.begin(); 
        cout << index + 1 << endl; 
    } 
}

int32_t main(){
        auto begin = std::chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int tc = 1;
        // cin >> tc; 
        precompute();
        for (ll t = 1; t <= tc; t++) {            
            // cout << "Case #" << t << ": ";
            solve();
        }   
        auto end = std::chrono::high_resolution_clock::now();
        cerr << "Time taken: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms" << endl;
}