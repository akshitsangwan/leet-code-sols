class Solution {
public:
    class info
    {
        public:
        int data;
        int row;
        int col;
        
        info(int d,int r,int c)
        {
            this->data=d;
            this->row=r;
            this->col=c;
        }
    };
    
    class cmp
    {
        public:
        bool operator()(info* a, info* b) 
        {
            return a->data > b->data;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        vector<int> ans;
        priority_queue<info*,vector<info*>,cmp> minheap;
        int k=nums.size();
        // har array ka pehla element process krwalo mini or maxi update krne ke liya
        // or minheap me push krwado 
        for(int i=0;i<k;i++)
        {
            int firstElement=nums[i][0];
            mini=min(mini,firstElement);
            maxi=max(maxi,firstElement);
            minheap.push(new info(firstElement,i,0));
        }
        
        int range=maxi-mini;
        ans.push_back(mini);
        ans.push_back(maxi);
        
        while(!minheap.empty())
        {
            // top element fetch kro or save kro or fir minheap se pop krwado
            info* temp=minheap.top();
            minheap.pop();
            
            // mini upadte krwao top element se
            mini= temp->data;
            
            // range update kro agar pehle se kam aaye to
            if(maxi-mini<range)
            {
                ans.clear();
                range=maxi-mini;
                ans.push_back(mini);
                ans.push_back(maxi);
            }
            
            //element push krao
            if(temp->col+1<nums[temp->row].size())
            {
                info* toPush=new info(nums[temp->row][temp->col+1],temp->row,temp->col+1);
                minheap.push(toPush);
                maxi=max(maxi,toPush->data);
            }
            else
                break;
        }
        
        return ans;
    }
};