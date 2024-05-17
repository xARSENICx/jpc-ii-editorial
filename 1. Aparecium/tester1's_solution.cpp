#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
#define ll long long

bool isSubstringPresent(string s) 
{
    int n=s.size();
    set<pair<char,char>> m;
    for(int i=0;i<n-1;i++)
    {
        m.insert({s[i],s[i+1]});
        if(m.find({s[i+1],s[i]})!=m.end())return 1;
    }
    return 0;
}

int main() 
{
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    string s;cin>>s;
    if(isSubstringPresent(s))cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}
