class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        vector<int> v;
        int temp=x;
        while(temp)
        {
            int rem=temp%10;
            v.push_back(rem);
            temp/=10;
        }
       temp=x;
        for(auto i:v)
            cout<<i<<" ";
        cout<<endl;
        while(temp)
        {
            int rem=temp%10;
            if(!(v.empty()) && rem==v.back())
                v.pop_back();
            else
                return false;
            temp/=10;
        }
        
        return true;
    }
};