#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
	int t;cin>>t;
   int n;cin>>n;
   int deg_in[101]={0};
   int deg_out[101]={0};
   vector<pair<int,int>> p;
   int a[n+1][n+1];
   for(int i =1;i<=n;i++){
   	for(int j =1;j<=n;j++){
   		cin >>a[i][j];
   		if(a[i][j]){
   			deg_in[j] ++;
   			deg_out[i]++;
   	     p.push_back({i,j});
		   }
	   }
   }
   
   if(t==1){
     for(int i =1;i<=n;i++){
     	cout <<deg_in[i]<<" "<<deg_out[i]<<endl;
	 }
   }
   else{
   cout << n <<" "<<p.size()<<endl;
   int b[n+1][p.size()]={0};
   for(int i = 0;i<p.size();i++){
   	    int u = p[i].first;
   	    int v = p[i].second;
   	    b[u][i]=1;
   	    b[v][i] = -1;
   }
   for(int i =1;i<=n;i++){
   	for(int j = 0;j<p.size();j++){
   		cout << b[i][j]<< " ";
	   }
	   cout << endl;
   }
   
   }
}
