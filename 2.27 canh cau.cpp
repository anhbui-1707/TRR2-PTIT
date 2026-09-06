#include<bits/stdc++.h>
using namespace std;

int n; 
int used[1001];
int a[101][101];
vector<int> p[101];
vector<pair<int,int>> q;
void dfs(int u,int x, int y){
    used[u] =1;
   for(int v : p[u]){
      if(used[v]==0){
        if((u==x && v == y) || (u ==y && v ==x)) continue;
        dfs(v,x,y);
      }
   }
}
void canh(){
    int tp=0;
    for(int i =1;i<=n;i++){
        if(used[i] == 0){
            tp++;
            dfs(i,-1,-1);
        }
    }
    vector<pair<int,int>> v;
    for(int i =0;i<q.size();i++){
        int x = q[i].first;
        int y = q[i].second;
        memset(used,0,sizeof(used));
        int tp2=0;
        for(int j = 1;j<=n;j++){
            if(used[j]==0){
              tp2++;
             dfs(j,x,y);
            }
        }
        if(tp2>tp){
       v.push_back({x,y});
        }
    }
    cout << v.size()<<endl;
    for(auto x : v)
    cout << x.first<<" "<<x.second<<endl;
}
int main(){
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);
   cin >>n;
 for(int i =1;i<=n;i++){
    for(int j =1;j<=n;j++){
        cin >>a[i][j];
        if(a[i][j] && i<j)
   { q.push_back({i,j});
    p[i].push_back(j);
    p[j].push_back(i);
}
    }
 }
canh();
}