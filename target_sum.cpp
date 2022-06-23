#include<bits/stdc++.h>
using namespace std;

//this problem is same as count subset with given difference

int countSos(int s[], int t, int n){
    //create a dp matrix 
    int dp[n+1][t+1];
    //intialize
    for(int j=0; j<=t; j++)
        dp[0][j] = 0;
    for(int i=0; i<=n; i++)
        dp[i][0] = 1;
    
    //choice diagram
    for(int i=1; i<=n; i++){
        for(int j=1; j<=t; j++){
            if(s[i-1] <= j)
                dp[i][j] = dp[i-1][j-s[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    //return the value
    return dp[n][t];
}

int targetSum(int s[], int totalsum, int ts, int n){
    int sum  = (ts + totalsum)/2;
    
    return countSos(s, sum, n);
}

int main(){
    int s[] = {1,1,2,3};
    int n = sizeof(s)/sizeof(s[0]);
    int ts = 1;

    int totalsum = 0;
    for(int i=0; i<n; i++)
        totalsum = totalsum + s[i];

    cout<<"number of subset equals t target sum  : "<<targetSum(s, totalsum, ts, n);

    return 0;
}