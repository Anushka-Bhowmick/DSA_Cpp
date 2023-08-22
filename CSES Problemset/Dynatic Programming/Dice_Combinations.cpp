#include<iostream>
#include<vector>
using namespace std;

/**********************************************************************************
    Your task is to count the number of ways to construct sum n
    by throwing a dice one or more times. Each throw produces an outcome between 1
    and 6.

    For example, if n=3, there are 4 ways:

    1+1+1
    1+2
    2+1
    3

    Input
    The only input line has an integer n.

    Output
    Print the number of ways modulo 109+7.

    Constraints
    1≤n≤106

    Example

    Input:
    3

    Output:
    4
**********************************************************************************/

int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[0]=1;

    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= 6; j++) {
            int smallerProblem = 0;
            if (i >= j) {
                smallerProblem = dp[i - j] % 1000000007;
            }
            dp[i] = (dp[i] + smallerProblem % 1000000007) % 1000000007;
        }
    }

    cout<<dp[n]<<endl;

    return 0;
}
