#include <bits/stdc++.h>

using namespace std;

int main (){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	int k;
	vector <int> v;
	for (int i=0;i<t;i++){
		cin>>k;
		int br=1,niz[100];
		memset(niz,0,sizeof niz);
		int p1=k,p2=100-k;
		for (int j=2;j<=100;j++){
			if (p1%j==0 and niz[j-1]==0 and p2%j==0){
				while (p1%j==0 and p2%j==0){
					br=br*j;
					p1=p1/j;
					p2=p2/j;
				}
				p1=p1*j;
				p2=p2*j;
				for (int y=j;y<100;y=y+j){
					niz[y-1]=1;
				}
			}
		}
		v.push_back(100/br);
	}
	for (int i=0;i<t;i++){
		cout<<v[i]<<"\n";
	}
	return 0;
}
