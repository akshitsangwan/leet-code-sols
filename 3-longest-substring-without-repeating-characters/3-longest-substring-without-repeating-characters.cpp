class Solution {
public:
    // Using Sliding Window Technique to solve this in O(n)
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        unordered_map<char,int> m;
        int n=s.size();
        int currLen=0;
        int maxLen=INT_MIN;
        int start=0;
        
        while(j<n)
        {
            //Include current element
            char ch=s[j];
            
            //Contraction of window
            while(m.count(ch) && m[ch]>=i)
            {
                i=m[ch]+1;
                currLen=j-i;
            }
            
            //Expansion of window
            m[ch]=j;
            currLen++;
            j++;
            
            //check and update length
            if(currLen>maxLen)
            {
                maxLen=currLen;
                start=i;
            }
        }
        
        return s.substr(start,maxLen).size();
    }
};