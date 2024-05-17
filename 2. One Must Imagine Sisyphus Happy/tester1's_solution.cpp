#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int n,m;cin>>n>>m;
    vector<string> a(n),b(m);
    set<string> s1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s1.insert(a[i]);
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
        s1.insert(b[i]);
    }
    int cn=n+m-(int)s1.size();
    n-=cn;
    m-=cn;
    if(n>m)
    {
        cout<<"Kafka"<<endl;
    }
    else if(n<m)
    {
        cout<<"Camus"<<endl;
    }
    else
    {
        if(cn%2==1)cout<<"Kafka"<<endl;
        else cout<<"Camus"<<endl;
    }
    return 0;
}
