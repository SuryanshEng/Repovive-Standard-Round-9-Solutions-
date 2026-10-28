#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<int> d(n+1); vector<char> u(n+2,0);
        for(int i=1;i<=n;i++) scanf("%d",&d[i]);
        bool ok=true;
        for(int i=1;i<=n&&ok;i++){
            if(u[i]) continue;
            int j=i+d[i];
            if(j>n||d[j]!=d[i]) ok=false;
            else u[j]=1;
        }
        puts(ok?"Yes":"No");
    }
}