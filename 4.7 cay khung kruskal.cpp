#include<bits/stdc++.h>
using namespace std;
int n,m;
int par[1001];
int sz[1001];
struct canh{
  int u,v,w;
};
vector<canh> p;
// sort theo ca 3 cai 
bool cmp(canh a, canh b){
    if(a.w != b.w) return a.w < b.w;
    if(a.u != b.u) return a.u < b.u;
    return a.v < b.v;
}
void make_set(){
    for(int i =1;i<=n;i++){
        par[i]= i;
        sz[i] = 1;
    }
}
int find(int v){
    if(v== par[v]) return v;
    return par[v] = find(par[v]);
}
bool dsu(int x, int y){
  x = find(x);
   y =find(y);
  if(x == y) return false;
 if(sz[x] < sz[y]) swap(x,y);
 par[y] =x;
 sz[x] += sz[y];
  return true;
}

void ck(){
    vector<canh> mst;
    int d = 0;
    for(auto it: p){
        if(mst.size() == n-1) break;
        if(dsu(it.u,it.v)){
          d += it.w;
          mst.push_back({it.u,it.v,it.w});
        }
    }
    if(mst.size() != n-1){
        cout << 0 << endl;
        return ;
    }
    else{
        cout << d << endl;
        for(auto x : mst){
            cout << x.u<<" "<<x.v<<" "<<x.w<<endl;
        }
    }
}
int main(){
    freopen("CK.INP","r",stdin);
    freopen("CK.OUT","w",stdout);
  cin >>n>>m;
  for(int i =1;i<=m;i++){
    int x,y,z;
    cin >>x>>y>>z;
    p.push_back(canh({x,y,z}));
  }
  sort(p.begin(),p.end(),cmp);
  make_set();
  ck();
}