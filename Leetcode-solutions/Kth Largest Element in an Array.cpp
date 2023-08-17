class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // n is the size of nums vector
        int n=nums.size();

        // creating a min heap for which we will set fixed size of k so that the top element will be the k'th largest element
        priority_queue <int, vector<int>, greater<int>> heap;

        // pushing first k elements in heap
        for(int i=0;i<k;i++) {
            heap.push(nums.at(i));
        }

        // pusing rest of the n-k elements into the heap and maintaining k sized min heap
        for(int i=k;i<n;i++) {
            // if the current element is greater than or equal to the top of min heap then only we will push the element in the heap and we will pop the heap to maintain the k'th largest element which will be the top most element in heap, we are not pushing if the current element is smaller than the top of min heap cause the smaller element will not contribute to find the k'th largest element.
            if(nums.at(i)>=heap.top()) {
                heap.push(nums.at(i));
                heap.pop();
            }
        }

        // the top element will be the k'th largest element as we are maintaining a size of k for the heap
        return heap.top();
    }
};
