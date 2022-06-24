#include<bits/stdc++.h>
using namespace std;

int un_KS(int wt[], int val[], int M, int n){
    //create a dp matrix
    int dp[n+1][M+1];

    //intialization
    for(int j=0; j<=M; j++)
        dp[0][j] = 0;
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    
    //choice diagram
    //NOTE : WE HAVE UNLIMITED SUPPLY OF OBJECT i.e repetation of object is allowed
    for(int i=1; i<=n; i++){
        for(int j=1; j<=M; j++){
            if(wt[i-1] <= j)
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    //return the answer
    return dp[n][M];
}

int main(){
    int wt[] = {1, 3, 4, 5};
    int val[] = {10, 40, 50, 70};
    int M = 8;
    int n = sizeof(wt)/sizeof(wt[0]);

    cout<<"THE MAXIMUM PROFIT IS : "<<un_KS(wt, val, M, n);
    return 0;
}