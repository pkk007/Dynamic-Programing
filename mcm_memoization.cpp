#include<bits/stdc++.h>
using namespace std;

int dp[101][101];

int mcm_memo(int p[], int i, int j){
    //initialize all the blocks with -1
    memset(dp, -1, sizeof(dp));

    if(i>=j)
        dp[i][j] = 0;
    
    //first chack in the table to avoid recursive call
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int min = INT_MAX;
    int temp_ans;
    for (int k=i; k<=j-1; k++){
        temp_ans = mcm_memo(p, i, k) + mcm_memo(p, k+1, j) + p[i-1]*p[k]*p[j];

        if(temp_ans < min)
            min = temp_ans;
    }
    //before returning store the min value in dp matrix
    return dp[i][j] = min;
}

int main(){

    int p[] = {10,30,5,60};
    int n = sizeof(p)/sizeof(p[0]);

    cout<<"MINMUM NUMBER OF MULTIPICATION OPRATION IS : "<<mcm_memo(p, 1, n-1);

    return 0;
}