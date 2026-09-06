#include<bits/stdc++.h>
using namespace std;

int n; 
int used[1001];
int a[101][101];

void dfs(int u){
    used[u] =1;
    for(int i =1;i<=n;i++){
        if(used[i] == 0 && a[u][i] == 1){
            dfs(i);
        }
    }
}
void dinhtru(){
    int tplt=0;
    for(int i =1;i<=n;i++){
      if(used[i] == 0){
        tplt++;
        dfs(i);
      }
    }
   
    vector<int> v;
    for(int i = 1;i<=n;i++){
         int tplt2 = 0; 
        memset(used,0,sizeof(used));
        used[i] =1;
        for(int j =1;j<=n;j++){
            if(used[j] == 0){
                tplt2++;
                dfs(j);
            }
        }
        if(tplt2>tplt){
            v.push_back(i);
        }
    }
    cout << v.size()<<endl;
    for(int x : v)
    cout << x <<" ";
}
int main(){
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);
 cin >>n;
 for(int i =1;i<=n;i++){
    for(int j =1;j<=n;j++){
        cin >>a[i][j];
    }
 }
 dinhtru();
}