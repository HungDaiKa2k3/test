#include <iostream>
using namespace std;

void show(int a[], int k) {
    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int i, int a[], int k, int n) {
    for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
        a[i] = j;
        if (i == k) {
            show(a, k);
        } else {
            Try(i + 1, a, k, n);
        }
    }
}

void hienThiCauHinh(int x[],int n){
	for(int i=1;i<=n;i++){
		cout<<x[i];
	}
	cout<<endl;
}
void TryToHop(int i,int x[],int k,int n){
	for(int j=x[i-1]+1;j<=n-k+i;j++){
		x[i]=j;
		if(i==k){
			hienThiCauHinh(x,k);
		}else{
			TryToHop(i+1,x,k,n);
		}
	}
}


int main() {
    int n = 5;
    int k = 3;
    int a[k + 1]={0};
    TryToHop(1, a, 3, 5);
    return 0;
}

