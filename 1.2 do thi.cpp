#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w" , stdout);
	int t; cin >>t;
	int n; cin >>n;
	int a[n+1][n+1];
	int deg[101] = {0};
  vector<int> p[101];
	for(int i =1;i<=n;i++){
		for(int j =1;j<=n;j++){
			cin >>a[i][j];
			if(a[i][j])
		{
		  deg[i]++;
		  p[i].push_back(j);
		}
	}
}
	if(t==1){
		for(int i =1;i<=n;i++){
			cout << deg[i]<<" ";
		}
		cout << endl;
	}
	else{
	cout << n <<endl;
	for(int i = 1;i<=n;i++){
		cout << p[i].size()<<" ";
		for(int j =0;j<p[i].size();j++){
			cout << p[i][j]<< " ";
		}
		cout << endl;
	}
}
}
