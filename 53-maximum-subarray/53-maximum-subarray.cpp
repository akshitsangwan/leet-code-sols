class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int currSum=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            // update currSum from 0th index to the current index
            currSum+=nums[i];
            
            // update maxSum (maximum so far)
            maxSum=max(maxSum,currSum);
            
            //if currSum is less than zero(negative), then reset its value to zero
            if(currSum<0)
                currSum=0;
        }
        return maxSum;
    }
};