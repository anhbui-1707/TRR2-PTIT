#include<bits/stdc++.h>
using namespace std;
int n,s,t;
int a[101][101];
struct canh{
  int x,y,w;
};
// do thi co huong 
vector<canh> adj;
void nhap(){
    cin >>n>>s>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >>a[i][j];
            if(a[i][j] != 0 && a[i][j] != 10000)
               adj.push_back({i,j,a[i][j]});
        }
    }
}
const int maxn = 1e9;
void bellman(){
    vector<int> d(n+1,maxn);
    int truoc[105]={0};
    d[s] = 0;
    for(int k =1;k<=n-1;k++){
          bool check = false;
        for(auto c : adj){
            if(d[c.x] != maxn  && d[c.y] > d[c.x] + c.w){
                d[c.y] = d[c.x] + c.w;
                 truoc[c.y] = c.x;
                 check = true;
            }
        }
        if(!check) break;
    }
    for(auto c : adj){
            if(d[c.x] != maxn && d[c.y] > d[c.x] + c.w){
                cout << -1 << endl;
                return;
            }
        }
        if(d[t] == maxn) {
            cout << 0 << endl;
            return;
        }
        cout << d[t]<<endl;
        vector<int> p;
        while(t != s){
            p.push_back(t);
            t = truoc[t];
        }
        p.push_back(s);
        reverse(p.begin(),p.end());
     for(auto a : p)
     cout << a <<" ";
}
int main(){
  freopen("BN.INP","r",stdin);
  freopen("BN.OUT","w",stdout);
  nhap();
  bellman();
}