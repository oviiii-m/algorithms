#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxCandies(vector<ll> v, ll n, ll k)
{
    int min=0, max=v[n-1], ans=0;
    while(min <= max){
        int mid = (min+max)/2;
        int count=0;
        for(int i=0; i<n; i++){
            // cout << v[i]/mid << " ";
            count += v[i]/mid;
            if(count >= k){
                break;
            }
        }  
        if(count >= k){
            ans = mid;
            min = mid+1;
        }
        else{
            max = mid-1;
        }
    }
    return ans;
}
// 0 --- 9 -> 4 --> 5 ---- 9 -> 7 -> 8 -- 9 
int main() {
	int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> v;
        for(int i=0; i<n; i++){
            int val;
            cin >> val;
            v.push_back(val);
        }
        sort(v.begin(), v.end());
        cout << maxCandies(v, n, k) <<endl;
        
    }
	// Write your code here
}
