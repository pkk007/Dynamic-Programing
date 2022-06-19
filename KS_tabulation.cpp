#include<bits/stdc++.h>
using namespace std;

int KS_table(int wt[], int val[], int M, int n){
    int dp[n+1][M+1];

    //intialize n=0 and M=0 with 0
    for(int i=0; i<n+1; i++){
        for(int j=0; j<M+1; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }

    //iterative code to fill the table
    for(int i=1; i<n+1; i++){
        for(int j=1; j<M+1; j++){
            if(wt[i-1] <= j){
                dp[i][j] = max( val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
            }
            else if(wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }

    //return this dp matrix
    return dp[n][M];
}

int main(){
    int wt[] = {10, 20 ,30};
    int val[] = {60, 100, 120};
    int M =50;
    // int wt[] = {4, 5 ,1};
    // int val[] = {1, 2, 3};
    // int M =4;
    int n = sizeof(wt)/sizeof(wt[0]);

    cout<<"your max profit is : "<<KS_table(wt, val , M, n);

    return 0;
}
