#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
	int t;cin>>t;
    int n,m; cin >>n>>m;
   vector<pair<pair<int,int>,int>> p;
   int deg[101]={0};
   int a[n+1][n+1]={0};
  
   for(int i =1;i<=m;i++){
	   	int x,y,z;
	   	cin >>x>>y>>z;
   	    deg[x]++;
   	    deg[y]++;
   	    if(z!=0 && z!= 10000)
   	    a[x][y] = z;
   	    a[y][x] = z;
   	    p.push_back({{x,y},z});
   }
    for(int i=1;i<=n;i++){
   	for(int j=1;j<=n;j++){
   		if(i!=j && a[i][j]==0)
   		a[i][j] =10000;
	   }
   }
   if(t==1){
   	for(int i =1;i<=n;i++){
   		cout << deg[i]<< " ";
	   }
   }
   else{
   	cout << n<<endl;
   	 for(int i=1;i<=n;i++){
   	for(int j=1;j<=n;j++){
   	   cout << a[i][j]<<" ";
	   }
	   cout << endl;
   }
   }
}
