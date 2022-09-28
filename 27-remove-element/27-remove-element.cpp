class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt=0;
        
        for(int i=0;i<nums.size();i++)
            if(nums[i]==val)
            {
                nums[i]=-1;
                cnt++;
            }
        sort(nums.begin(),nums.end());
        nums.erase(nums.begin(),nums.begin()+cnt);
        
        return nums.size();
    }
};