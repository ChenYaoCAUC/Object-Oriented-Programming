#include<iostream>
#include<cmath>
using namespace std;
//作者:chenyao
class FS{
	int fz,fm;
	public:
		FS operator + ( FS &f);
		friend istream& operator>>(istream& in,FS & m);
		friend ostream& operator<<(ostream& out,FS & m);
}; 
istream& operator>>(istream& in,FS & m){
	in>>m.fz;
	getchar();
	in>>m.fm;
	getchar();
	return in;
}
ostream& operator<<(ostream& out,FS & m){
	out<<m.fz<<"z"<<m.fm<<"m";
	return out;
}
FS FS::operator + ( FS &f){
	int x;
	FS ff;
	if(fabs(f.fm)<=fabs(fm)){
		x=fabs(f.fm);
	}
	else {
		x=fabs(fm);
	}
	for(x;x>=1;x--){
		if(f.fm%x==0&&fm%x==0)
		break;
	}
	ff.fz=f.fz*(fm/x)+fz*(f.fm/x);
	ff.fm=f.fm*fm/x;
	if(fabs(ff.fm)<=fabs(ff.fz)){
		x=fabs(ff.fm);
	}
	else{
		x=fabs(ff.fz);
	}
	for(x;x>1;x--){
		if(ff.fm%x==0&&ff.fz%x==0)
		break;
	}
	ff.fz/=x;
	ff.fm/=x;
    if(ff.fz*ff.fm<0){
    	ff.fz=-fabs(ff.fz);
    	ff.fm=fabs(ff.fm);
	}
	else{
		ff.fz=fabs(ff.fz);
		ff.fm=fabs(ff.fm);
	}

if(ff.fz==0){
	ff.fz=0;
	ff.fm=1;
}
	
	return ff;
}
int main(){
	int n;
	cin>>n;
	FS *f=new FS[n],f1,f2;
	for(int i=0;i<n;i++){
		cin>>f1>>f2;
		f[i]=f1+f2;
	}
	for(int i=0;i<n;i++){
		cout<<f[i]<<endl;
	}
	return 0;
}
