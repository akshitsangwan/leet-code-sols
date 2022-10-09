class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
    // Saare number ko initially prime maan lo
    vector<bool>prime(n+1,true);

    // o or 1 ko non-prime mark krdo
    prime[0]= prime[1]= false;

    //table wise number non-prime mark krdo
    for (int i = 2; i< n; i++)
    {
        if(prime[i]){
          for (int j = 2*i; j < n; j=j+i)
            {
                prime[j]= false;
            }  
        }
        
    }
    
    //prime ka count print krne ke liye
    for (int i = 2; i < n; i++) {
    if (prime[i])        
            cnt++;
    }
    return cnt;
    }
};