#include<iostream>
#include<vector>
#include<algorithm>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
using namespace std;
const int inf = 1e9;
typedef vector<int> vi;
typedef int SegT;
const SegT defvalue=inf;
class SegTree{
	private:
		vector<SegT>val;
		int n;
		SegT combine(SegT a,SegT b){return min(a,b);}
	public:
		SegTree(int size){
			n=1;
			while(n<size)n<<=1;
			val=vector<SegT>(2*n,defvalue);
		}
		SegTree(const vector<SegT> &in){
			n=1;
			while(n<in.size())n<<=1;
			val=vector<SegT>(2*n,defvalue);
			for(int i=n-1+in.size()-1;i>=0;i--){
				if(n-1<=i)val[i]=in[i-(n-1)];
				else val[i]=combine(val[i*2+1],val[i*2+2]);
			}
		}
		void update(int i,SegT a){
			i+=n-1;
			val[i]=a;
			while(i>0){
				i=(i-1)/2;
				val[i]=combine(val[i*2+1],val[i*2+2]);
			}
		}
		SegT query(int a,int b,int k=0,int l=0,int r=-1){//[a,b)
			if(r==-1)r=n;
			if(r<=a||b<=l)return defvalue;
			if(a<=l&&r<=b)return val[k];
			else return combine(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
		}
		void tmp(){
			rep(i,val.size())cout<<" "<<val[i];cout<<endl;
		}
};
int main(){
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	vi dm(n);
	rep(i,n)cin>>dm[i];
	vi mi(n,inf);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--;b--;
		mi[b]=min(mi[b],a);
	}
	SegTree st(n);
	st.update(s-1,0);
	loop(i,s,n)if(mi[i]!=inf)st.update(i,st.query(mi[i],i)+dm[i]);
	cout<<st.query(t-1,n)<<endl;
}