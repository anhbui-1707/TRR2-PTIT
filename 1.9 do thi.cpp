#include<bits/stdc++.h>
using namespace std;

int main(){
//	freopen("DT.INP","r",stdin);
//	freopen("DT.OUT","w" , stdout);
	
	int t; cin >>t;
   int n; cin >>n;

   int deg[101]={0};
  vector<pair<int,int>> p;
   for(int i = 1;i<=n;i++){
   	int x;
   	cin >>x;
   	deg[i] = x;
   	while(x--){
   		int y; cin >>y;
   		if(i<y)
   		p.push_back({i,y});
	   }
   }
   if(t==1){
   	for(int i =1;i<=n;i++){
   		cout << deg[i]<< " ";
	   }
   }
   else{
   	cout << n <<" "<< p.size()<<endl;
   int b[n+1][p.size()]={0};
   for(int i =0;i<p.size();i++){
   	 b[p[i].first][i] = 1;
   	 b[p[i].second][i] =1;
   	 
   }
   for(int i =1;i<=n;i++){
   	for(int j =0;j<p.size();j++){
   		cout << b[i][j]<<" ";
	   }
	   cout << endl;
   }
   }
	return 0;
}
