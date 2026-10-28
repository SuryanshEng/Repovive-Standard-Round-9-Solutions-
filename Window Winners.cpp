#include <bits/stdc++.h>
using namespace std;
const int M=998244353,N=1000005;
int f[N],p[N];
int main(){
    f[0]=p[0]=1;
    for(int i=1;i<N;i++) f[i]=1LL*f[i-1]*i%M, p[i]=2*p[i-1]%M;
    int t; scanf("%d",&t);
    while(t--){
        int n,k; scanf("%d %d",&n,&k);
        printf("%d\n", k==1 ? f[n] : int(1LL*f[k]*p[n-k]%M));
    }
}