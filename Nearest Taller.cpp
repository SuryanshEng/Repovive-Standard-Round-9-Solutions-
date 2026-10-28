#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e12;
int n; vector<ll> mn,lz; vector<ll> init;
void build(int x,int l,int r){
    lz[x]=0;
    if(l==r){mn[x]=init[l];return;}
    int m=(l+r)/2; build(2*x,l,m); build(2*x+1,m+1,r);
    mn[x]=min(mn[2*x],mn[2*x+1]);
}
void add(int x,int l,int r,int a,int b,ll v){
    if(a>b||b<l||r<a) return;
    if(a<=l&&r<=b){mn[x]+=v;lz[x]+=v;return;}
    int m=(l+r)/2;
    add(2*x,l,m,a,b,v); add(2*x+1,m+1,r,a,b,v);
    mn[x]=min(mn[2*x],mn[2*x+1])+lz[x];
}
int findz(int x,int l,int r,ll acc){
    if(l==r) return l;
    acc+=lz[x]; int m=(l+r)/2;
    if(mn[2*x]+acc==0) return findz(2*x,l,m,acc);
    return findz(2*x+1,m+1,r,acc);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        cin>>n;
        vector<int> d(n+2),p(n+2,0);
        vector<ll> df(n+3,0);
        vector<vector<int>> lst(n+2);
        int zc=0;
        for(int i=1;i<=n;i++){
            cin>>d[i];
            if(!d[i]){zc++;continue;}
            int l=max(1,i-d[i]+1), r=min(n,i+d[i]-1);
            df[l]++; df[r+1]--; df[i]--; df[i+1]++;
            if(i-d[i]>=1) lst[i-d[i]].push_back(i);
            if(i+d[i]<=n) lst[i+d[i]].push_back(i);
        }
        if(zc!=1){cout<<-1<<"\n";continue;}
        init.assign(n+2,0); mn.assign(4*n+4,0); lz.assign(4*n+4,0);
        ll c=0;
        for(int i=1;i<=n;i++){c+=df[i]; init[i]=c+(d[i]?INF:0);}
        build(1,1,n);
        vector<char> ok(n+2,0);
        int cnt=0;
        while(mn[1]==0&&cnt<n){
            int i=findz(1,1,n,0);
            p[i]=n-cnt; cnt++;
            add(1,1,n,i,i,INF);
            add(1,1,n,i-d[i]+1,i-1,-1);
            add(1,1,n,i+1,i+d[i]-1,-1);
            for(int j:lst[i]) if(!ok[j]&&!p[j]){ok[j]=1;add(1,1,n,j,j,-INF);}
        }
        if(cnt<n){cout<<-1<<"\n";continue;}
        for(int i=1;i<=n;i++) cout<<p[i]<<" \n"[i==n];
    }
}