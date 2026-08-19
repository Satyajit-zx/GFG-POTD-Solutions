class Solution {
public:
    long long countLessEqual(vector<int>& arr, int limit) {
        int n = arr.size();
        long long count = 0;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                long long sum = (long long)arr[i] + arr[left] + arr[right];

                if (sum <= limit) {
                    count += (right - left);
                    left++;
                } 
                else {
                    right--;
                }
            }
        }

        return count;
    }

    int countTriplets(vector<int> &arr, int l, int r) {
        sort(arr.begin(), arr.end());

        long long ans = countLessEqual(arr, r)
                      - countLessEqual(arr, l - 1);

        return (int)ans;
    }
};
