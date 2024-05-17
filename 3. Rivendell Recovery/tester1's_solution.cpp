#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

void solve()
{
    int n;cin>>n;
    int q;cin>>q;
    vector<int> v1;
    v1.push_back(0);
    for(int i=0;i<q;i++)
    {
        int h;cin>>h;
        v1.push_back(h);
    }
    v1.push_back(n+1);
    int k;cin>>k;
    sort(v1.begin(),v1.end());
    for(int i=0;i<v1.size()-1;i++)
    {
        int gh=k+i;
        if(v1[i]<gh && gh<v1[i+1])
        {
            cout<<gh<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
}


int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    solve();
    return 0;
}
