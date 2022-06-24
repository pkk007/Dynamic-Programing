#include<bits/stdc++.h>
using namespace std;

int rod_cutting(int length[], int price[], int L, int n){
    //similar to count unbounded knapsack just asking question approach is different
    //create a dp matrix
    int dp[n+1][L+1];

    //iniatization
    for(int j=0; j<=L; j++)
        dp[0][j] = 0;
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;

    //choice diagram
    for(int i=1; i<=n; i++){
        for(int j=1; j<=L; j++){
            if(length[i-1] <= j)
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    //return the answer
    return dp[n][L];
}

int main()
{
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int L = 8;
    int n = sizeof(price) / sizeof(price[0]);
    int length[n];
    for(int i=0; i<n; i++)
        length[i] = i+1;
    
    cout<<"way to cut a rod to get maximum profit : "<<rod_cutting(length, price, L, n);
    return 0;
}