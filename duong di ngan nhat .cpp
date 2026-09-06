#include<bits/stdc++.h>
using namespace std;

int n,m,s;
vector<pair<int,int>> adj[10001];
void nhap(){
    cin >>n>>m>>s;
   for(int i =1;i<=m;i++){
    int x,y,z;
    cin >>x>>y>>z;
    adj[x].push_back({y,z});
    adj[y].push_back({x,z});
   }
}
const long long   maxn = 1e9;
void dijstra(int s){
    vector<long long> d(n+1,maxn);
    d[s] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
   q.push({0,s});
   while(!q.empty()){
    auto it = q.top(); q.pop();
    int u = it.second;
    int kc = it.first;
    if(kc > d[u]) continue;
    for(auto a : adj[u]){
        int v = a.first;
        int w = a.second;
        if(d[v] > d[u]+w){
            d[v] = d[u]+w;
            q.push({d[v],v});
        }
    }
   }
   for(int i = 1;i<=n;i++){
    cout << d[i]<<" ";
   }
   cout << endl;
}
int main(){
 int t; cin >>t;
 while(t--){
  nhap();
  dijstra(s);
 }   
}