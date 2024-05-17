#include <bits/stdc++.h>
using namespace std;

bool check(string s){
    set<string> S;
    for(int i = 0; i < s.size() - 1; i++){
        string a1=to_string(s[i])+to_string(s[i+1]);
        S.insert(a1);
        string a2=to_string(s[i+1])+to_string(s[i]);
        if(S.find(a2) != S.end()) return true;
    }
    return false;
}

int main(){
     string s;
     cin>>s;
     if(check(s)) cout << "True" << endl;
     else cout << "False" << endl;
}
