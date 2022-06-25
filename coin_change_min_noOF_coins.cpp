#include<bits/stdc++.h>
using namespace std;

int coin_change2(int coin[], int sum, int n){
    //create a dp matrix
    int dp[n+1][sum+1];

    //iniatilaztion
    for(int j=0; j<=sum; j++)
        dp[0][j] = INT_MAX - 1;
    for(int i=1; i<=n; i++)
        dp[i][0] = 0;
    //intialize 2nd row also
    for(int j=1; j<=sum; j++)
        if(j%coin[0] == 0)
            dp[1][j] = j/coin[0];
        else
            dp[1][j] = INT_MAX -1;
    
    //choice diagram
    for(int i=2; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(coin[i-1] <= j)
                dp[i][j] = min(dp[i][j-coin[i-1]] + 1, dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];
}

int main(){
    int coin[] = {3,5,2};
    int sum = 5;
    int n = sizeof(coin)/sizeof(coin[0]);

    cout<<"MIN. NO. OF COIN REQUIRED TO GET THE SUM : "<<coin_change2(coin, sum, n);

    return 0;
}