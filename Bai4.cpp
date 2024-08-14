#include<iostream>
using namespace std;

struct chuyenBay{
	string soHieu;
	double giaVe;
	int soGhe;
	
	chuyenBay(string soHieu, double giaVe, int soGhe){
		this->soHieu=soHieu;
		this->giaVe=giaVe;
		this->soGhe=soGhe;
	}
	
	void showInfo(){
		cout<<soHieu<<"\t"<<giaVe<<"\t"<<soGhe<<"\n";
	}
};

void ChuyenBayTren700(chuyenBay b[],int n,int gia, int index=0){
	if(index>=n){
		return;
	}
	if(b[index].giaVe>gia){
		b[index].showInfo();
	}
	ChuyenBayTren700(b,n,gia,index+1);
}

chuyenBay giaVeMin(chuyenBay b[],int left,int right){
	if(left==right){
		return b[left];
	}
	int mid=(left+right)/2;
	chuyenBay minLeft=giaVeMin(b,left,mid);
	chuyenBay minRight=giaVeMin(b,mid+1,right);
	if(minLeft.giaVe<minRight.giaVe){
		return minLeft;
	}else{
		return minRight;
	}
}

void hienThiCauHinh(int x[],int k, chuyenBay b[]){
	for(int i=1;i<=k;i++){
		cout<<b[x[i]-1].soHieu<<"\t";
	}
	cout<<endl;
}

void cauHinhTiepTheo(int x[],int k,int i){
	x[i]+=1;
	i++;
	while(i<=k){
		x[i]=x[i-1]+1;
		i++;
	}
}

void lietKeCauHinh(int k,int n, chuyenBay b[]){
	int i;
	int x[k+1]={0};
	for(int i=1;i<=k;i++){
		x[i]=i;
	}
	do{
		hienThiCauHinh(x,k,b);
		i=k;
		while(i>0&&x[i]==n-k+i){
			i--;
		}
		if(i>0){
			cauHinhTiepTheo(x,k,i);
		}
	}while(i>0);
}

int main(){
	chuyenBay b[7]={
		chuyenBay("VN001",1000,100),
		chuyenBay("VN002",600,190),
		chuyenBay("VN003",1200,160),
		chuyenBay("VN004",500,100),
		chuyenBay("VN005",650,180),
		chuyenBay("VN006",900,150),
		chuyenBay("VN007",1500,200),
	};
	ChuyenBayTren700(b,7,700);
	cout<<endl;
	giaVeMin(b,0,6).showInfo();
	cout<<endl;
	lietKeCauHinh(3,7,b);
}
