#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> a(n), p(n+1,0);
        for(auto&x:a) cin>>x;
        sort(a.begin(),a.end());
        if(n&1){ cout<<a[n-1]<<"\n"; continue; }
        for(int i=0;i<n;i++) p[i+1]=p[i]+a[i];
        int r=(n-2)/2; ll ans=0;
        for(int i=0;i<n;i++){
            ll s=i<=r ? p[r+2]-a[i] : p[r+1];
            ll l=i>=n-r ? p[n]-p[n-r-1]-a[i] : p[n]-p[n-r];
            ans=max(ans,a[i]-max(0LL,s-l));
        }
        cout<<ans<<"\n";
    }
}