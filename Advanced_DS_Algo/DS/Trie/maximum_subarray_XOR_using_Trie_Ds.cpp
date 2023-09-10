class TrieNode {
public:
    TrieNode* zero;
    TrieNode* one;
    TrieNode(TrieNode* zero=nullptr,TrieNode* one=nullptr) {
        this->zero=nullptr;
        this->one=nullptr;
    }
};

class Solution{   
public:

    void buildTrie(TrieNode* root, int num) {
        TrieNode* cur=root;
        for(int i=31;i>=0;i--) {
            int curBit=num&(1<<i);
            if(curBit==0) {
                if(cur->zero==nullptr) {
                    cur->zero=new TrieNode();
                }
                cur=cur->zero;
            } else {
                if(cur->one==nullptr) {
                    cur->one=new TrieNode();
                }
                cur=cur->one;
            }
        }
    }

    int findMaxXorForCurrentElement(TrieNode* root, int num) {
        TrieNode* cur=root;
        int maxXorCurElement=0;
        for(int i=31;i>=0;i--) {
            int curBit=num&(1<<i);
            if(curBit==0) {
                if(cur->one!=nullptr) {
                    maxXorCurElement|=1<<i;
                    cur=cur->one;
                } else {
                    cur=cur->zero;
                }
            } else {
                if(cur->zero!=nullptr) {
                    maxXorCurElement|=1<<i;
                    cur=cur->zero;
                } else {
                    cur=cur->one;
                }
            }
        }
        return maxXorCurElement;
    }

    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        int maxXor=0;
        TrieNode* root=new TrieNode();

        for(int i=0;i<n;i++) {
            buildTrie(root,nums[i]);
        }

        for(int i=0;i<n;i++) {
            maxXor=max(findMaxXorForCurrentElement(root,nums[i]),maxXor);
        }

        return maxXor;
    }

    int maxSubarrayXOR(int N, int arr[]){    
        vector<int> preXor(N+1);
        preXor[0]=0;
        for(int i=1;i<=N;i++) {
            preXor[i]=preXor[i-1]^arr[i-1];
        }
        return findMaximumXOR(preXor);
    }
};
