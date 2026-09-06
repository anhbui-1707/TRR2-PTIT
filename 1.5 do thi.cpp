#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w" , stdout);
	
	int t; cin >>t;
    int n,m; cin >>n>>m;
    int deg[101] = {0};
   vector<int> p[101];
   
   for(int i =1;i<=m;i++){
   	 int x,y;
   	 cin >>x>>y;
   	 deg[x]++;
   	 deg[y]++;
   p[x].push_back(y);
   p[y].push_back(x);
   }
   if(t==1){
   	for(int i =1;i<=n;i++){
   		cout << deg[i]<<" ";
	   }
   }
   else{
   	cout << n <<endl;
   for(int i =1;i<=n;i++){
   	cout << p[i].size()<<" ";
   	for(int j =0;j<p[i].size();j++){
   		
   		cout << p[i][j]<<" ";
	   }
	   cout << endl;
   }
	 
   }
	
}
