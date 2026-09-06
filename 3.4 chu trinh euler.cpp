#include<bits/stdc++.h>
using namespace std;
int t, n,u;
set<int> p[1001];
int used[1001];
int a[101][101];
int deg_in[101], deg_out[101];
void dfs(int v){
  used[v] =1;
  for(int i=1;i<=n;i++){
    if(used[i] == 0 && (a[v][i] || a[i][v])){
        dfs(i);
    }
  }
}
void check(){
    int st=0,en=0;
    int bd = -1;
    bool ok = true;
  for(int i =1;i<=n;i++){
    if(deg_out[i] - deg_in[i] ==1)
    st ++;
    else if(deg_in[i]- deg_out[i]==1)
    en++;
    else if(deg_in[i] != deg_out[i])
      ok = false;
   if(bd == -1 && deg_in[i] + deg_out[i]>0){
      bd = i;
   }
  }
  if(bd == -1)
  {
    cout << 1 << endl;
    return;
  }
  dfs(bd);
  bool kt= true;
  for(int i=1;i<=n;i++){
    if(used[i]==0 && deg_in[i]+ deg_out[i]>0){
        kt = false;
        break;
    }
  }
 if(kt){
    if(ok && st==0 && en == 0) cout << 1 ;
    else if(ok && st == 1 && en ==1 ) cout << 2;
    else
    cout << 0;
 }
 else
 cout << 0;
}
void ct(int u){
    stack<int> st;
    vector<int> ce;
    st.push(u);
    while(!st.empty()){
        int s = st.top();
        if(p[s].size() !=0){
            int x = *p[s].begin();
            st.push(x);
            p[s].erase(x);
        }
        else{
            st.pop();
            ce.push_back(s);
        }
    }
    reverse(ce.begin(),ce.end());
    for(int x : ce)
    cout << x <<" ";
}
void nhap(){
    cin >>t>>n;
    if(t==2) cin>>u;
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >>a[i][j];
            if(a[i][j] ){
                deg_in[j]++;
                deg_out[i]++;
                p[i].insert(j);
            }
        }
    }
    if(t==1)
    check();
    else
    ct(u);
}
int main(){
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);
  nhap();
}