#include<bits/stdc++.h>
using namespace std;

int n,u;
int a[101][101];
int used[1001];
void prim(int u){
    used[u] =1;
  vector<pair<pair<int,int>,int>> mst;
  int d = 0;
  while(mst.size() != n-1){
    int x = -1, y =-1 , mn = INT_MAX;
   for(int i =1;i<=n;i++){
    if(used[i]){
        for(int j =1;j<=n;j++){
            if(used[j] == 0 && a[i][j] < mn && a[i][j] !=0 && a[i][j]!= 10000){
                mn = a[i][j];
               x= i; y =j;
            }
        }
    }
   }
   if(x==-1 && y ==-1){
    cout << 0 ;
    return;
   }
   else
    {
        mst.push_back({{x,y},mn});
        used[y] = 1;
        d += mn;
}
  }
   cout << d << endl;
  for(auto x : mst){
    if(x.first.first > x.first.second)
    swap(x.first.first, x.first.second);
    cout << x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
  }
}
int main(){
    freopen("CK.INP","r",stdin);
    freopen("CK.OUT","w",stdout);
  cin >>n>>u;
  for(int i =1;i<=n;i++){
    for(int j =1;j<=n;j++){
        cin >> a[i][j];
    }
  }
  prim(u);
}