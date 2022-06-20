#include<bits/stdc++.h>
using namespace std;

bool sos(int s[], int t, int n){
    bool dp[n+1][t+1];
    //intialization
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    
    for (int j=1; j<=t; j++)
        dp[0][j] = false;

    //fill the table
    for(int i=1; i<=n; i++){
        for(int j=1; j<=t; j++){
            if(s[i-1] <= j)
                dp[i][j] = dp[i-1][j-s[i-1]] || dp[i-1][j];
            else if(s[i-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }
    //return the result
    return dp[n][t];
}

bool equal_sum(int s[], int n){
    int total_sum = 0;
    int target;
    for(int i=0; i<n; i++){
        total_sum = total_sum + s[i];
    }
    if(total_sum%2 !=0)
        return false;
    if(total_sum%2 == 0)
        target = total_sum/2;
    
    return sos(s, target, n);
}

int main(){
    int s[] = {1,5,11,5};
    int n = sizeof(s)/sizeof(s[0]);
    if(equal_sum(s, n))
        cout<<"YES EQUAL SUM PRESENT";
    else
        cout<<"NO EQUAL SUM IS NOT PRESENT";
    
    return 0;
}