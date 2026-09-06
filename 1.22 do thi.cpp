#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
	int t;cin>>t;
 int n,m; cin >>n>>m;
   
   int deg_in[101]={0};
   int deg_out[101]={0};
   int a[n+1][n+1] = {0};
  vector<pair<pair<int,int>,int>> p;
   for(int i = 1;i<=m;i++){
   	int x,y,z;
   	cin >>x>>y>>z;
   	deg_in[y]++;
   	deg_out[x]++;
   	a[x][y] = z;
   }
   for(int i =1;i<=n;i++){
   	for(int j = 1;j<=n;j++){
   		if(i!= j && a[i][j]==0){
   			a[i][j] =10000;
		   }
	   }
   }
   
   if(t==1){
     for(int i =1;i<=n;i++){
     	cout <<deg_in[i]<<" "<<deg_out[i]<<endl;
	 }
   }
   else{
  cout << n <<endl;
    for(int i =1;i<=n;i++){
   	for(int j = 1;j<=n;j++){
   	cout << a[i][j]<<" ";
	   }
	   cout << endl;
   }
   }
}
