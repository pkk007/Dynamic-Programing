#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int KS_memo(int wt[], int val[], int M, int n){
    //initialize all the blocks with -1
    memset(dp, -1, sizeof(dp));

    //base condition
    if(n==0 || M==0)
        return dp[n][M] = 0;
    
    //first chack in the table to avoid recursive call
    if(dp[n][M] != -1)
        return dp[n][M];
    
    //if not found in dp table code to fill the table
    if(wt[n-1] <= M)
        return dp[n][M] = max( val[n-1] + KS_memo(wt, val, M-wt[n-1], n-1), KS_memo(wt, val, M, n-1));
    
    else if(wt[n-1] > M)
        return dp[n][M] = KS_memo(wt, val, M, n-1);
}

int main(){
    
    int wt[] = {10, 20 ,30};
    int val[] = {60, 100, 120};
    int M =50;
    int n = sizeof(wt)/sizeof(wt[0]);

    cout<<"your max profit is : "<<KS_memo(wt, val , M, n);

    return 0;
}