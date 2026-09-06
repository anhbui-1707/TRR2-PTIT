#include<bits/stdc++.h>
using namespace std;
int n,u;
int used[1001];
int a[101][101];
int x[1001];
vector<int> ct;
int cnt = 0;
void dfs(int k){
 
  if(k > n){
    if(a[x[n]][u]){
      for(int i=1;i<=n;i++){
        cout << x[i]<<" ";
      }
      cout << u << endl;
      cnt++;
    }
    return;
  }
  for(int i = 1;i<=n;i++){
    if(used[i] == 0 && a[x[k-1]][i]){
       used[i] =1;
       x[k] = i;
       dfs(k+1);
       used[i] =0;
    }
  }

}
int main(){
  freopen("CT.INP","r",stdin);
  freopen("CT.OUT","w",stdout);
 cin >> n>>u;
 for(int i =1;i<=n;i++){
    for(int j =1;j<=n;j++){
        cin >>a[i][j];
    }
 }
 x[1] = u;
 used[u] = 1;
 dfs(2);
 if(cnt == 0 ) cout << 0 ;
 else cout << cnt;
}