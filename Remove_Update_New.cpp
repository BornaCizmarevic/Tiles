#include <bits/stdc++.h>

using namespace std;

int o,stablo[1000000];

void update (int poz,int vr){
	poz=poz+o;
	stablo[poz]=vr;
	poz=poz/2;
	while (poz>0){
		stablo[poz]=max(stablo[poz],vr);
		poz=poz/2;
	}
}

int query (int ind,int lo,int hi,int qlo,int qhi){
	if (qlo<=lo and hi<=qhi){
		return stablo[ind];
	}
	if (lo>=qhi || hi<=qlo){
		return 0;
	}
	int mid=(lo+hi)/2;
	int lijevo=query(ind*2,lo,mid,qlo,qhi);
	int desno=query(ind*2+1,mid,hi,qlo,qhi);
	return max(lijevo,desno);
}

int main (){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,q;
	cin>>n;
	cin>>q;
	int a[q],b[q],c[q];
	vector <pair <int,pair <int,int> > > v;
	for (int i=0;i<q;i++){
		cin>>a[i];
		cin>>b[i];
		cin>>c[i];
		v.push_back(make_pair(a[i]-1,make_pair(0,c[i])));
		v.push_back(make_pair(b[i],make_pair(1,c[i])));
	}
	sort(v.begin(),v.end());
	int br=0,gr=0,niz[n];
	memset(niz,0,sizeof niz);
	for (int i=0;i<v.size();i++){
		pair <int,int> p=v[i].second;
		int p1=v[i].first,p2=p.first,p3=p.second;
		if (p2==0){
			for (int j=gr;j<p1;j++){
				niz[j]=br;
			}
			gr=p1;
			br=br+p3;
		}
		else {
			for (int j=gr;j<p1;j++){
				niz[j]=br;
			}
			gr=p1;
			br=br-p3;
		}
	}
	int left[n],right[n],maxl,maxr;
	left[0]=niz[0];
	right[0]=niz[n-1];
	for (int i=1;i<n;i++){
		left[i]=max(left[i-1],niz[i]);
		right[i]=max(right[i-1],niz[n-i-1]);
	}
	int vr=n;
	br=0;
	while (vr>0){
		br++;
		vr=vr/2;
	}
	o=1<<br;
	for (int i=0;i<n;i++){
		update(i,niz[i]);
	}
	int m1,m2,m3,m,rj=0x3f3f3f3f;
	for (int i=0;i<q;i++){
		if (a[i]>1){
			m1=left[a[i]-2];
		}
		else {
			m1=0;
		}
		m2=query(1,0,o,a[i],b[i]+1)-c[i];
		if (a[i]<n){
			m3=right[n-b[i]-1];
		}
		else {
			m3=0;
		}
		m=max(max(m1,m3),m2);
		rj=min(rj,m);
	}
	cout<<rj;
	return 0;
}
