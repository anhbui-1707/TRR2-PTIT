#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
	int t;cin>>t;
  int n; cin >>n;
   
   int deg_in[101]={0};
   int deg_out[101]={0};
  int a[n+1][n+1];
  vector<pair<pair<int,int>,int>> p;
  for(int i =1;i<=n;i++){
  	for(int j =1;j<=n;j++){
  		cin >>a[i][j];
  		if(a[i][j] != 0 && a[i][j] != 10000){
  			deg_in[j]++;
  			deg_out[i]++;
  			p.push_back({{i,j},a[i][j]});
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
    for(auto it:p){
    	cout << it.first.first<<" "<<it.first.second<< " "<<it.second<<endl;
	}
   }
}
