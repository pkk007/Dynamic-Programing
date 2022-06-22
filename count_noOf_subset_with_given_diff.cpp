#include<bits/stdc++.h>
using namespace std;

int countSos(int s[], int t, int n){
    //create a dp matrix
    int dp[n+1][t+1];

    //intialization
    for(int j=0; j<=t; j++)
        dp[0][j] = 0;
    for(int i=0; i<=n; i++)
        dp[i][0] = 1;
    
    //choice diagram
    for(int i=1; i<=n; i++){
        for(int j=1; j<=t; j++){
            if(s[i-1] <= j)
                dp[i][j] = dp[i-1][j-s[i-1]] + dp[i-1][j];
            else if(s[i-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }

    //return the result
    return dp[n][t];
}

int countGivenSumDifference(int s[], int targetDiff, int n, int totalSum){
    int sum = (targetDiff + totalSum)/2;

    return countSos(s, sum, n);
}

int main(){
    int s[] = {1,1,2,3};
    int targetDiff = 1;
    int n = sizeof(s)/sizeof(s[0]);

    //calculate the total sum
    int totalSum = 0;
    for(int i=0; i<n; i++)
        totalSum = totalSum + s[i];

    cout<<"YOUR NUMBER OF SUBSETS WHOSE SUM EQUALS TO TAGERT : "<<countGivenSumDifference(s, targetDiff, n, totalSum);

    return 0;
}