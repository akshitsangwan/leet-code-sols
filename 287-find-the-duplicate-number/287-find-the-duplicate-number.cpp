class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int ans;
        unordered_map<int,int> mp;
        
        for(int i=0;i<a.size();i++)
            mp[a[i]]++;
        
        for(auto &i:mp)
            if(i.second>1)
            {
                ans=i.first;
                break;
            }
        
        return ans;
    }
};