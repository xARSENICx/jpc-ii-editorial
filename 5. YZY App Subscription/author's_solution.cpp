#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

int main() {    
    ordered_set o;
    int n, m;
    cin >> n >> m;
    //Insert the N seats in the ordered set.
    for(int i=0;i<n;i++){
        o.insert(i+1);
    }
   
    for(int i= 0; i < m; i++)
    {   
        int x;
        cin >> x;
        o.erase(o.find(x));
    }
    
    int k;
    cin >> k;
    cout << *o.find_by_order(k - 1)<<endl; //ordered set is 0-indexed
    return 0;
}
