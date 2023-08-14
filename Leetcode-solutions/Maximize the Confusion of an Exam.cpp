class Solution {
private:
    //Sliding Window
    int slideToFlip(string answerKey,int n,int k, char toFlip, char fromFlip)
    {
        int ans=0;
        int i=0;
        int j=0;
        while(j<n)
        {
            if(answerKey[j]==toFlip)
            {
                k--;
                if(k<0)
                {
                    while(answerKey[i]==fromFlip)
                        i++;
                    k++;
                    i++;
                }
            }
            ans=max(j-i+1,ans);
            j++;
        }
        return ans;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int i=0;
        int j=0;

        int maxConsecutiveAnswerByFlipingFalstToTrue=slideToFlip(answerKey,n,k,'F','T');
        int maxConsecutiveAnswerByFlipingTrueToFalse=slideToFlip(answerKey,n,k,'T','F');
        int maxFlips=max(maxConsecutiveAnswerByFlipingFalstToTrue,maxConsecutiveAnswerByFlipingTrueToFalse);

        return maxFlips;
    }
};
