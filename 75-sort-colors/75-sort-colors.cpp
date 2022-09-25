class Solution {
public:
    void sortColors(vector<int>& a) {
        
        // Solved with DUTCH FLAG ALGO
        int low=0;
        int mid=0;
        int high=a.size()-1;
        
        while(mid<=high)
        {
            if(a[mid]==0)
                swap(a[mid++],a[low++]);
            else if(a[mid]==1)
                mid++;
            else
                swap(a[mid],a[high--]);
        }
    }
};