class Solution {

    int fibo(int n){
        if(n == 1 || n == 0){
            return n;
        }

        return fibo(n - 1) + fibo(n - 2);

    }

public:
    int fib(int n) {
        int ans = fibo(n);

        return ans;


    }
};