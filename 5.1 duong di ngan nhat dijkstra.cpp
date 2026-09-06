#include<bits/stdc++.h>
using namespace std;

int n,u,v;
int a[101][101];
vector<pair<int,int>> p[105];
void nhap(){
    cin >>n>>u>>v;
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            if(a[i][j] != 0 && a[i][j] != 10000 && i != j)
            p[i].push_back({j,a[i][j]});
        }
    }
}
const int maxn = 1e9;
void dijkstra(){
    vector<int> d(n+1, maxn);
    d[u] = 0;
    int truoc[105]={0};
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,u});
    while(!q.empty()){
        auto it = q.top(); q.pop();
        int x = it.second;
        int kc = it.first;
        if(kc > d[x]) continue;
        for(auto s : p[x]){
           int y = s.first;
           int w = s.second;
           if(d[y] > d[x]+w){
            d[y] = d[x] + w;
            truoc[y] = x;
            q.push({d[y],y});
           }
        }
    }
    if(d[v] == maxn)
     {
        cout <<  0 << endl;
        return;
    }

    cout << d[v]<<endl;
    vector<int> path;
    while(v != u){
        path.push_back(v);
        v = truoc[v];
    }
    path.push_back(u);
    reverse(path.begin(),path.end());
    for(int x : path){
        cout << x <<" ";
    }
    cout << endl;
}
int main(){
    freopen("DN.INP","r",stdin);
    freopen("DN.OUT","w",stdout);
  nhap();
  dijkstra();
    
}