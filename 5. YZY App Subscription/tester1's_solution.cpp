#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    ll n,C;cin>>n>>C;
    vector<ll> a(n),b(n),c(n);
    map<ll,ll> m;
    ll prev=INT_MAX;
    set<ll> s1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        m[a[i]]+=c[i];
        m[b[i]+1]-=c[i];
        s1.insert(a[i]);
        s1.insert(b[i]+1);
    }
    vector<ll> v1(s1.begin(),s1.end());
    ll psum=0,ans=0;
    for(int i=0;i<v1.size()-1;i++)
    {
        psum+=m[v1[i]];
        ans+=min(psum,C)*(v1[i+1]-v1[i]);
    }
    cout<<ans<<endl;
    return 0;
}
