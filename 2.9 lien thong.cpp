#include<bits/stdc++.h>
using namespace std;
int n; 
int a[101][101];
int used[101] ={0};
vector<vector<int>> v;
vector<int> c;
void dfs(int u){
    c.push_back(u);
    used[u]  =1;
    for(int i =1;i<=n;i++){
        if(a[u][i] == 1 && used[i]==0){
            dfs(i);
        }
    }
}
int main(){
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);
    cin >>n;
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >>a[i][j];
        }
    }
// phai sort
    for(int i =1;i<=n;i++){
        if(used[i] == 0){
            c.clear();
            dfs(i);
            sort(c.begin(),c.end());
            v.push_back(c);
        }
    }

    cout << v.size() << endl;
    for(int i = 0;i<v.size();i++){
        for(int j =0;j<v[i].size();j++){
            cout << v[i][j]<<" ";
        }
        cout << endl;
    }
}