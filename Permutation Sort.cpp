#include <bits/stdc++.h>

using namespace std;

int main (){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	int n;
	vector <int> v;
	for (int i=0;i<t;i++){
		cin>>n;
		int niz[n],pr=0;
		for (int j=0;j<n;j++){
			cin>>niz[j];
			if (j>0){
				if (niz[j-1]+1!=niz[j]){
					pr=1;
				}
			}
		}
		if (pr==0){
			v.push_back(0);
		}
		else {
			if (niz[0]==n and niz[n-1]==1){
				v.push_back(3);
			}
			else if (niz[0]!=1 and niz[n-1]!=n){
				v.push_back(2);
			}
			else {
				v.push_back(1);
			}
		}
	}
	for (int i=0;i<t;i++){
		cout<<v[i]<<"\n";
	}
	return 0;
}
