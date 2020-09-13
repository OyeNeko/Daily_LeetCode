class Solution {
    int calNum(int n){
        int ans = 0;
        while(n){
            ans += (n % 10)*(n % 10);
            n /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = calNum(slow);
            fast = calNum(fast);
            fast = calNum(fast);
        }while(slow != fast);
        return slow == 1;
    }
};
