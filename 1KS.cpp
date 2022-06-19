#include<bits/stdc++.h>
using namespace std;

int KS(int wt[], int val[], int M, int n){
    //base condition
    if(n==0 || M==0)
        return 0;
    
    //choice diagram
    if(wt[n-1] <= M)
        return max(val[n-1] + KS(wt, val, M-wt[n-1], n-1) , KS(wt, val, M, n-1));

    else if(wt[n-1] > M)
        return KS(wt, val, M, n-1);
}

int main(){
    // int n = 4;
    // int wt[] = {3, 4, 6, 5};
    // int val[] = {2, 3, 1, 4};
    // int M = 8;
    int wt[] = {10, 20 ,30};
    int val[] = {60, 100, 120};
    int M =50;
    int n = sizeof(wt)/sizeof(wt[0]);

    cout<<"your max profit is : "<<KS(wt, val , M, n);

    return 0;
}