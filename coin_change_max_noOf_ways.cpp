#include<bits/stdc++.h>
using namespace std;

//THIS PROBLEM IS SIMILAR TO COUNTSOS PROBLEM

int coin_change1(int coin[], int sum, int n){
    //create a dp matrix
    int dp[n+1][sum+1];

    //initialization
    for(int i=0; i<=n; i++)
        dp[i][0] = 1;
    for(int j=1; j<=sum; j++)
        dp[0][j] = 0;
    
    //choice diagram
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(coin[i-1] <= j)
                dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main(){
    int coin[] = {1,2,3};
    int sum = 5;
    int n = sizeof(coin)/sizeof(coin[0]); 

    cout<<"NO. OF WAYS TO GET THE SUM THROUGH THESE COINS ARE : "<<coin_change1(coin, sum, n);

    return 0;
}