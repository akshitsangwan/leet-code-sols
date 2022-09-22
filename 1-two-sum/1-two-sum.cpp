class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
//         int preSum[nums.size()+1];
//         preSum[0]=0;
//         for(int i=1;i<preSum.size();i++)   
//             preSum[i]=preSum[i-1]+nums[i-1];
        
//         for(int i=1;i<preSum.size();i++)
//         {
//             for(int j=i+1;j<preSum.size();j++)
//             {
//                 if(preSum[j]-preSum[i]==target)
                    
//             }
//         }
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                } 
            }
        }
        return ans;
    }
};