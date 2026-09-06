#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
	int t;cin>>t;
  int n; cin >>n;
   
   int deg_in[101]={0};
   int deg_out[101]={0};
   int a[n+1][n+1] = {0};
    for(int i = 1;i<=n;i++){
    	int x; cin >>x;
    	deg_out[i]= x;
    	while(x--){
    		int y;
    		cin >>y;
    		deg_in[y]++;
    		a[i][y] = 1;
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
   	for(int j =1;j<=n;j++){
   		cout << a[i][j]<< " ";
	   }
	   cout << endl;
   }
   
   }
}
