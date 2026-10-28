#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=998244353;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<ll> p2(200005,1);
    for(int i=1;i<200005;i++) p2[i]=p2[i-1]*2%M;
    int t; cin>>t;
    while(t--){
        int n; ll K; cin>>n>>K;
        vector<int> L(n+2);
        for(int i=1;i<=n;i++) cin>>L[i];
        ll k=K%M, k2=((K-2)%M+M)%M, ans=1;
        bool first=true, ok=true;
        int a=1;
        for(int i=1;i<n&&ok;i++){
            if(L[i+1]>L[i]+1){ ok=false; break; }
            int s0=i-L[i]+1, s1=i+1-L[i+1]+1;
            if(s1==s0) continue;
            if(L[i+1]<2){ ok=false; break; }
            if(first) ans=ans*(k*((K-1)%M)%M)%M*p2[s1-2]%M;
            else{
                if(s1<a){ ok=false; break; }
                ans=ans*p2[max(0,s1-a-1)]%M;
            }
            ans=ans*k2%M;
            a=i+1; first=false;
        }
        if(!ok){ cout<<0<<"\n"; continue; }
        if(first) ans=(k+k*((K-1)%M)%M*((p2[n-1]-1+M)%M))%M;
        else ans=ans*p2[n-a]%M;
        cout<<ans<<"\n";
    }
}