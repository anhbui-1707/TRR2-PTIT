#include<bits/stdc++.h>
using namespace std;
 int t,n,u;
 int a[101][101];
 int used[101];
 vector<pair<int,int>> mst;
// co the can check lien thong nua
 void dfs(int v){
  used[v] =1;
  for(int i =1;i<=n;i++){
    if(used[i] == 0 && a[v][i]){
        mst.push_back({v,i});
        dfs(i);
    }
  }
 }
 void bfs(int v){ 
    queue<int> q;
    q.push(v);
    used[v] =1;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int i =1;i<=n;i++){
            if(used[i] == 0 && a[s][i]){
               used[i] = 1;
               q.push(i);
               mst.push_back({s,i});
            }
        }
    }
 }
 void in(){
       cout << mst.size()<<endl;
        for(auto it: mst)
       { if(it.first < it.second)
        cout << it.first<<" "<<it.second<<endl;
        else
        cout << it.second<<" "<<it.first<<endl;
    }
 }
int main(){
    freopen("CK.INP","r",stdin);
    freopen("CK.OUT","w",stdout);
    cin >>t>>n>>u;
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            cin >>a[i][j];
        }
    }
    if(t==1){
        dfs(u);
       in();
    }
    else{
        bfs(u);
      in();
    }
}