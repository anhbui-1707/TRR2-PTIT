#include<bits/stdc++.h>
using namespace std;
 int n;

int d[101][101] = {0};
int nxt[101][101];

void floyd(){
  for(int k =1;k<=n;k++){
   for(int i=  1;i<=n;i++){
    for(int j =1;j<=n;j++){
       if(d[i][k] != 10000 && d[k][j]!= 10000 && d[i][j] > d[i][k]+d[k][j]){
        d[i][j] = d[i][k]+d[k][j];
        nxt[i][j] = nxt[i][k];
       }
    }
   }
  }
  int mx = 0, u = 0, v = 0;
  for(int i =1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(d[i][j] != 10000 && d[i][j] > mx){
        mx = d[i][j];
        u = i;
        v = j;
      }
    }
  }
  if(mx == 0){
    cout << 0 << endl;
    return;
  }
  cout << u <<" "<<v<<" "<<mx <<endl;

  vector<int> p;
  int cur = u;
  while( cur != v){
    p.push_back(cur);
    cur = nxt[cur][v];
  }
  p.push_back(v);
  for(int x :p)
  cout << x <<" ";
  
}

int main(){
    freopen("DN.INP","r",stdin);
    freopen("DN.OUT","w",stdout);
 
    cin >>n;

    for(int i=1;i<=n;i++){
        for(int j =1;j<=n;j++){
            cin >> d[i][j];
            if(i==j) nxt[i][j] = i;
            else if(d[i][j] != 10000) nxt[i][j] = j;
            else
            nxt[i][j]= -1;
        }
    }
    floyd();
}