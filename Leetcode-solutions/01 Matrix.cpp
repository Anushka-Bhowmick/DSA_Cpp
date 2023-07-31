class Tri
{
    public:
    int f;
    int s;
    int t;
    Tri(int f, int s, int t)
    {
        this->f=f;
        this->s=s;
        this->t=t;
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
	    int m=mat.at(0).size();
	    vector<vector<bool>> vis(n, vector<bool>(m,false));
	    vector<vector<int>> dist(n, vector<int>(m,0));
	    queue<Tri> q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(mat[i][j]==0)
	            {
	                q.push(Tri(i,j,0));
	                vis[i][j]=true;
	            }
	        }
	    }
	    //(up,left,down,right)
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        
        while(!q.empty())
        {
            Tri cur=q.front();
            q.pop();
            int curi=cur.f;
            int curj=cur.s;
            int curDist=cur.t;
            dist[curi][curj]=curDist;
            
            for(int i=0;i<4;i++)
            {
                int newi=curi+dx[i];
                int newj=curj+dy[i];
                
                if(newi>=0 && newj>=0 && newi<n && newj<m && !vis[newi][newj])
                {
                    vis[newi][newj]=true;
                    q.push(Tri(newi,newj,curDist+1));
                }
            }
        }
	    return dist;
    }
};
