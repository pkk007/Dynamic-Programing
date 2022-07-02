#include<bits/stdc++.h>
using namespace std;

int mcm_tab(int p[], int n){
    //create a dp matrix
    int dp[n][n];

    //inirialization
    for(int i=0; i<n; i++)
        dp[i][i] = 0;
    
    //main code part
    for(int i=n-1; i>=1; i--){
        for(int j=i+1; j<n; j++){
            int min = INT_MAX;
            int temp_ans;
            for (int k=i; k<=j-1; k++){
                temp_ans = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];

                if(temp_ans < min)
                    min = temp_ans;
            }
            dp[i][j] = min;
        }
    }
    return dp[1][n-1];
}

int main(){

    int p[] = {10,30,5,60};
    int n = sizeof(p)/sizeof(p[0]);

    cout<<"MINMUM NUMBER OF MULTIPICATION OPRATION IS : "<<mcm_tab(p, n);

    return 0;
}