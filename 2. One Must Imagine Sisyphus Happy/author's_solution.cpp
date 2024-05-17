#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n, m, tot;
    cin >> n >> m;

    set<string> S;

    string t;
    tot = n + m;
    while(tot--){
        cin >> t;
        S.insert(t);
    }

    if((n + m - S.size()) % 2 == 1){
        n++;
    }
    
    cout << (n > m ? "Kafka" : "Camus");
}
