#include<bits/stdc++.h>
using namespace std;
int t,n,u;
int a[101][101];
int deg[101];
int used[101];
set<int> p[101];

void dfs(int v){
    used[v] = 1;
    for(int i =1;i<=n;i++){
        if(used[i] == 0 && a[v][i] == 1){
            dfs(i);
        }
    }
}
void check(){
    int cnt  =0;
    int bd = -1;
    for(int i =1;i<=n;i++){
        if(deg[i]%2 )
        cnt++;
       if( bd == -1 && deg[i] > 0)
          bd = i;
    }
    if(bd == -1){
        cout << 1 << endl;
        return;
    }
    dfs(bd);
    bool kt = true;
    for(int i=1;i<=n;i++){
        if(used[i]==0 && deg[i]>0)
        kt = false;
    }
    if(kt && cnt == 0)
       cout << 1 << endl;
    else if(kt && cnt == 2)
    cout << 2 << endl;
    else
    cout << 0 <<endl;
}
void ct(int v){
    stack<int> st;
    vector<int> ce;
    st.push(v);
    while(!st.empty()){
        int s = st.top();
        if(p[s].size() != 0){
         int x = *p[s].begin();
         st.push(x);
         p[s].erase(x);
         p[x].erase(s);
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
   if(t == 2) cin >>u;
        for(int i =1;i<=n;i++){
           for(int j =1;j<=n;j++){
            cin >>a[i][j];
            if(a[i][j] && i<j){
                deg[i]++;
                deg[j]++;
                 p[i].insert(j);
                 p[j].insert(i);
            }
           }
        }
        if(t==1) check();
        else
        ct(u);
    }
int main(){
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);
  nhap();
}