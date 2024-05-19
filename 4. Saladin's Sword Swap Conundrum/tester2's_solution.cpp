#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> col(n);
	map<int,int> cnt;
	for(auto &v:col){
		cin>>v;
		cnt[v]++;
	}
	vector<int> col_temp(col);
	auto cmp = [&](int a,int b){
		if(cnt[a]==cnt[b])return a<b;
		return cnt[a]<cnt[b];
	};
	sort(col_temp.begin(),col_temp.end(),cmp);
	auto it = unique(col_temp.begin(),col_temp.end());
	col_temp.resize(distance(col_temp.begin(),it));
	int tempn = col_temp.size();
	if(cnt[col_temp[tempn-1]]>n/2){
		cout<<"Yes";
		return;
	}
	cout<<"No"<<endl;
	map<int,int> inv;
	for(int i=0;i<tempn;i++){
		inv[col_temp[i]]=i;
	}
	vector<int> ans(n);
	int diff = cnt[col_temp[tempn-1]]-cnt[col_temp[tempn-2]];
	map<int,int> diffs;
	for(int i=tempn-3;i>=0;i--){
		diffs[i]=min(diff,cnt[col_temp[i]]);
		diff-=diffs[i];
	}
	int k = 2;
	for(int i=0;i<n;i++){
		int num = inv[col[i]];
		if(num==0)ans[i]=col_temp[tempn-1];
		else if(num==tempn-1){
			if(cnt[col_temp[num-1]]==0){
				ans[i]=col_temp[num-k];
				cnt[col_temp[num-k]]--;
				if(cnt[col_temp[num-k]]<=0)k++;
			}
			else{
				ans[i]=col_temp[num-1];
				cnt[col_temp[num-1]]--;
			} 
		}
		else if(cnt[col_temp[num-1]]<=diffs[num-1]){
			ans[i]=col_temp[tempn-1];
		}
		else{
			ans[i]=col_temp[num-1];
			cnt[col_temp[num-1]]--;
		}
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
}

int main() {
	solve();
	return 0;
}

