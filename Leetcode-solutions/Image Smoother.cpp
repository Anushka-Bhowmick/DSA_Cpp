class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img.at(0).size();
        int dx[]={-1,-1,-1,0,0,0,1,1,1};
        int dy[]={-1,0,1,-1,0,1,-1,0,1};
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int sum=0;
                int count=0;
                for(int k=0;k<9;k++) {
                    int newX=i+dx[k];
                    int newY=j+dy[k];
                    if(newX>=0 && newX<n && newY>=0 && newY<m) {
                        sum+=(img[newX][newY] & ((1<<8)-1));
                        count++;
                    }
                }
                int avg=sum/count;
                int shiftedAvg=avg<<8;
                img[i][j]=(shiftedAvg|img[i][j]);
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                img[i][j]=img[i][j]>>8;
            }
        }

        return img;
    }
};
