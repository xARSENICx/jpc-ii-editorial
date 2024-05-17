#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    ll n;cin>>n;
    map<ll,ll> m;
    vector<ll> a(n);
    ll maxi=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
        maxi=max(maxi,m[a[i]]);
    }
    if(n-maxi<maxi)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    vector<vector<ll>> v1;
    for(auto x: m)
    {
        v1.push_back({x.second,x.first});
    }
    sort(v1.begin(),v1.end());

    map<ll,ll> ind;
    for(int i=0;i<v1.size();i++)
    {
        ind[v1[i][1]]=i;
    }

    vector<vector<ll>>fans(n,vector<ll>(3,0));
    for(int i=0;i<n;i++)
    {
        fans[i][0]=ind[a[i]];
        fans[i][1]=a[i];
        fans[i][2]=i;
    }

    sort(fans.begin(),fans.end());
    
    int s=0;
    for(int i=0;i<(n+1)/2;i++)
    {
        if(fans[i][1]!=fans[n-i-1][1])
        {
            swap(fans[i][1],fans[n-i-1][1]);
        }
        else
        {
            swap(fans[i][1],fans[s++][1]);
            swap(fans[n-i-1][1],fans[s++][1]);
        }
    }

    vector<ll> ans(n,0);
    for(int i=0;i<n;i++)
    {
        ans[fans[i][2]]=fans[i][1];
    }
    for(int x: ans)
    {
        cout<<x<<" ";
    }

    return 0;
}
