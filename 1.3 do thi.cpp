#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w" , stdout);
	
	int t; cin >>t;
	int n; cin >>n;
	int a[n+1][n+1];
	
	int deg[101] = {0};
	vector<pair<int ,int>> p;
	for(int i =1;i<=n;i++){
		for(int j =1;j<=n;j++){
			cin >>a[i][j];
			if(a[i][j] && i<j)
		{
			p.push_back({i,j});
			deg[i]++;
			deg[j]++;
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
	cout << n <<" "<<p.size()<<endl;
	
	int b[n+1][p.size()]={0};
	
	for(int i = 0;i<p.size();i++){
		int u = p[i].first;
		int v = p[i].second;
		b[u][i]=1;
		b[v][i]=1;
	}
	for(int i =1;i<=n;i++){
		for(int j = 0;j< p.size();j++){
			cout << b[i][j]<<" ";
		}
		cout << endl;
	}
}
}
