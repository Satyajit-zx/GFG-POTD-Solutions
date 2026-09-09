class Solution {
public:
    int digitSum(int x) {
        int sum = 0;

        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int findMax(int n) {
        int ans = n;
        int maxSum = digitSum(n);

        int x = n;
        int p = 1;

        while (x > 0) {
            // Decrease current digit by 1
            // and make all digits to its right 9
            int cur = (x - 1) * p + (p - 1);

            int sum = digitSum(cur);

            if (sum > maxSum || (sum == maxSum && cur > ans)) {
                maxSum = sum;
                ans = cur;
            }

            x /= 10;
            p *= 10;
        }

        return ans;
    }
};
