#include <bits/stdc++.h>
using namespace std;


void solve(){
	string a;
	cin>>a;
	set<string> hash;
	for(int i=0;i<a.length()-1;i++){
		string t = a.substr(i,2);
		hash.insert(t);
	}
	for(int i=0;i<a.length();i++){
		string t = a.substr(i,2);
		swap(t[0],t[1]);
		if(hash.find(t)!=hash.end()){
			cout<<"True";
			return;
		}
	}
	cout<<"False";
}


int main(){
	solve();
	return 0;
}
