#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> occ(m);
	for(auto &v:occ)cin>>v;
	sort(occ.begin(),occ.end());
	vector<int> seats(n+1);
	for(int i=0;i<m;i++){
		seats[occ[i]]=-1;
	}
	int q;
	cin>>q;
	
	int cnt=0;
	int ans;
	for(int i=1;i<=n;i++){
		if(seats[i]==-1)continue;
		cnt++;
		if(cnt==q){
			ans = i;
			break;
		}
	}
	cout<<ans;
	

}



int main(){
	solve();
	return 0;
}


