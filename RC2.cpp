#include <bits/stdc++.h>

using namespace std;

int main (){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	vector <int> k[t];
	for (int kb=0;kb<t;kb++){
		int n,m;
		cin>>n;
		cin>>m;
		vector <pair <int,pair <int,int> > > v,r;
		int  u1[n],rj[n];
		memset(rj,-1,sizeof rj);
		char u2[n];
		for (int i=0;i<n;i++){
			cin>>u1[i];
		}
		for (int i=0;i<n;i++){
			cin>>u2[i];
			if (u2[i]=='L'){
				v.push_back(make_pair(u1[i],make_pair(0,i)));
			}
			else {
				v.push_back(make_pair(u1[i],make_pair(1,i)));
			}
		}
		sort(v.begin(),v.end());
		deque <pair <int,int> > d1,d2,l1,l2;
		d1.clear();
		d2.clear();
		for (int i=0;i<n;i++){
			pair <int,int> p;
			int p1,p2,p3;
			p1=v[i].first;
			p=v[i].second;
			p2=p.first;
			p3=p.second;
			if (p2==0){
				if (p1%2==0){
					if (d1.size()>0){
						int c1=d1[0].first,c2=d1[0].second;
						rj[c2]=(p1-c1)/2;
						rj[p3]=(p1-c1)/2;
						d1.pop_front();
					}
					else {
						l1.push_front(make_pair(p1,p3));
					}
				}
				else {
					if (d2.size()>0){
						int c1=d2[0].first,c2=d2[0].second;
						rj[c2]=(p1-c1)/2;
						rj[p3]=(p1-c1)/2;
						d2.pop_front();
					}
					else {
						l2.push_front(make_pair(p1,p3));
					}
				}
			}
			else {
				if (p1%2==0){
					d1.push_front(make_pair(p1,p3));
				}
				else {
					d2.push_front(make_pair(p1,p3));
				}
			}
		}
		pair <int,int> a,b,c,d;
		int o1=0,o2=0,o3=0,o4=0;
		for (int i=0;i<d1.size();i=i+2){
			if (i+1<d1.size()){
				rj[d1[i].second]=m-d1[i].first+(d1[i].first-d1[i+1].first)/2;
				rj[d1[i+1].second]=m-d1[i].first+(d1[i].first-d1[i+1].first)/2;
			}
			else {
				a=d1[i];
				o1=1;
			}
		}
		for (int i=0;i<d2.size();i=i+2){
			if (i+1<d2.size()){
				rj[d2[i].second]=m-d2[i].first+(d2[i].first-d2[i+1].first)/2;
				rj[d2[i+1].second]=m-d2[i].first+(d2[i].first-d2[i+1].first)/2;
			}
			else {
				b=d2[i];
				o2=1;
			}
		}
		for (int i=l1.size()-1;i>=0;i=i-2){
			if (i-1>=0){
				rj[l1[i].second]=l1[i].first+(l1[i-1].first-l1[i].first)/2;
				rj[l1[i-1].second]=l1[i].first+(l1[i-1].first-l1[i].first)/2;
			}
			else {
				c=l1[i];
				o3=1;
			}
		}
		for (int i=l2.size()-1;i>=0;i=i-2){
			if (i-1>=0){
			//	cout<<"<"<<l2[i].first<<" "<<l2[i+1].first<<" "<<kb<<"\n";
				rj[l2[i].second]=l2[i].first+(l2[i-1].first-l2[i].first)/2;
				rj[l2[i-1].second]=l2[i].first+(l2[i-1].first-l2[i].first)/2;
			}
			else {
				d=l2[i];
				o4=1;
			}
		}
		if (o1==1){
			if ((m+c.first+m-a.first)%2==0 and o3==1){
				rj[a.second]=(m+c.first+m-a.first)/2;
				rj[c.second]=(m+c.first+m-a.first)/2;
			}
			if ((m+d.first+m-a.first)%2==0 and o4==1){
				rj[a.second]=(m+d.first+m-a.first)/2;
				rj[d.second]=(m+d.first+m-a.first)/2;
			}
		}
		if (o2==1){
			if ((m+c.first+m-b.first)%2==0 and o3==1){
				rj[b.second]=(m+c.first+m-b.first)/2;
				rj[c.second]=(m+c.first+m-b.first)/2;
			}
			if ((m+d.first+m-b.first)%2==0 and o4==1){
				rj[b.second]=(m+d.first+m-b.first)/2;
				rj[d.second]=(m+d.first+m-b.first)/2;
			}
		}
		for (int i=0;i<n;i++){
			k[kb].push_back(rj[i]);
		}
	}
	for (int i=0;i<t;i++){
		for (int j=0;j<k[i].size();j++){
			cout<<k[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
