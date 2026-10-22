class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n+1,true);
        int ans = 0;

        for(int i = 2;i < n;i++){
            if(is_prime[i]){
                ans++;

                for(int j = i * 2;j < n;j = j+i){
                    is_prime[j] = false;
                }
            }
        }

        return ans;
    }
};