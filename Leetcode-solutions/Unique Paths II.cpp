class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //number of rows in grid
        int n=obstacleGrid.size();
        //number of columns in grid
        int m=obstacleGrid.at(0).size();

        //if there will be any obstacle in starting point or ending point then there will be zero ways to reach the ending point
        if(obstacleGrid[n-1][m-1]==1 || obstacleGrid[0][0]==1)
            return 0;

        /* DP matrix created to memoize the answers.
        matrix used because this is a 2D DP problem cause there are two changing states and we need to maintain whether or not we can reach (0,0) from (i,j) */
        vector<vector<int>> dp(n,vector<int>(m,-1));

        //flags to check the obstacle positions in 0'th row and 0'th column
        bool flag1=false;
        bool flag2=false;

        //if obstacle present at (0,i) then it is impossible for (0,i) to (0,m-1) blocks to reach (0,0) so from (0,i) to (0,m-1) the DP matrix will me marked as 0 as there are no paths to reach and    from (0,0) to (0,i-1) the DP matrix will me marked as 1 as there will be only one path to reach (0,0).
        for(int j=0;j<m;j++) {
            if(obstacleGrid[0][j]==1)
                flag1=true;
            if(flag1)
                dp[0][j]=0;
            else
                dp[0][j]=1;
        }

        //if obstacle present at (j,0) then it is impossible for (j,0) to (n-1,0) blocks to reach (0,0) so from (j,0) to (n-1,0) the DP matrix will me marked as 0 as there are no paths to reach and from (0,0) to (j-1,0) the DP matrix will me marked as 1 as there will be only one path to reach (0,0).
        for(int i=0;i<n;i++) {
            if(obstacleGrid[i][0]==1)
                flag2=true;
            if(flag2)
                dp[i][0]=0;
            else
                dp[i][0]=1;
        }

        //DP matrix populated using tabulation from the recurrence relation f(i,j)=f(i-1,j)+f(i,j-1) for i->1..n-1 and j->1..m-1 and if there is obstacle at (i,j) then there will be zero ways to reach (0,0).
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }

        //after populating DP matrix the answer will be stored at dp[n-1][m-1] as it represents number ways to reach (0,0) from (n-1,m-1).
        return dp[n-1][m-1];
    }
};
