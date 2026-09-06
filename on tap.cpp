#include<bits/stdc++.h>
using namespace std;

int n;

int d[101][101];
int nxt[101][101];
void floyd(){

    for(int k =1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j =1;j<=n;j++){
                if(d[i][k] != 10000 && d[i][k] != 10000 &&d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    int mn = 0, x= 0,y=0;
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            if(d[i][j] >mn && d[i][j] != 10000 && d[i][j] !=0)
            {
                mn = d[i][j];
                x= i;
                y=j;
            }
        }
    }
    cout << x << " "<<y<<" "<<mn << endl;
    vector<int> p;
    while(x != y){
        p.push_back(x);
        x = nxt[x][y];
    }
    p.push_back(y);
    for(int x : p )
    cout << x <<" ";
}

int main(){
    freopen("DN.INP","r",stdin);
    freopen("DN.OUT","w",stdout);
    cin >>n;
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=n;j++){
            cin >>d[i][j];
            if(i== j) nxt[i][j] = i;
            else if(d[i][j] != 10000) nxt[i][j] = j;
            else
            nxt[i][j] = -1;

        }
    }
    floyd();
   
}