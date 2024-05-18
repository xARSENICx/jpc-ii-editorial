#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	set<string> hash;
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
		hash.insert(t);
	}
	for(int i=0;i<m;i++){
		string t;
		cin>>t;
		hash.insert(t);
	}
	int com = m-hash.size()+n;
	n+=com%2?1:0;
	if(n>m)cout<<"Kafka";
	else cout<<"Camus";
}



int main() {
	solve();
	return 0;
}
