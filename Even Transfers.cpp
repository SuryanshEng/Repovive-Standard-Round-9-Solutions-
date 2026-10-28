#include <bits/stdc++.h>
using namespace std;
int p[200005], c[200005], a[200005], b[200005];
int f(int x){ while(p[x]!=x) x=p[x]=p[p[x]]; return x; }
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,m; scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]), p[i]=i, c[i]=0;
        bool ok=true;
        for(int i=1;i<=n;i++){ scanf("%d",&b[i]); if((a[i]+1)/2!=(b[i]+1)/2) ok=false; }
        while(m--){
            int u,v; scanf("%d %d",&u,&v);
            if(a[u]&&a[v]) p[f(u)]=f(v);
        }
        for(int i=1;i<=n;i++) c[f(i)]+=(a[i]%2==0)-(b[i]%2==0);
        for(int i=1;i<=n&&ok;i++) if(c[i]) ok=false;
        puts(ok?"Yes":"No");
    }
}