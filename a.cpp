#include <iostream>
using namespace std;

void Next_config(int x[], int k, int i) {
    x[i] += 1;
    i++;
    while (i <= k) {
        x[i] = x[i - 1] + 1;
        i++;
    }
}

void View_config(int x[], int k) {
    for (int i = 1;i <= k;i++) {
        cout << x[i];
    }
    cout << endl;
}

void List_config(int k, int n) {
    int i;
    int* x = new  int[k + 1];
    for (i = 1;i <= k;i++) {
        x[i] = i;
    }
    do {
        View_config(x, k);
        i = k;
        while (i > 0 && x[i] == n - k + i) {
            i--;
        }
        if (i > 0) {
            Next_config(x, k, i);
        }
    } while (i > 0);
}

void Try(int *a,int k, int n, int i) {
    for (int j = a[i - 1] + 1;j <= n - k + i; j++) {
        a[i] = j;
        if (i == k) View_config(a, k);
        else Try(a, k, n, i + 1);
    }
}

int main()
{
    int n = 5;
    int k = 3;
    int* a = new int[n + 1];
    a[0]=0;
   
    
    Try(a, k, n, 1);
    /*List_config(3, 7);*/
}
