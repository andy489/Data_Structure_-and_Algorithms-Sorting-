// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Time: O(n) in expectation

class Solution {
public:
    int partition(vector<int> &nums, int l, int r) {
        int pivot = l + rand() % (r - l + 1);

        swap(nums[pivot], nums[r]);

        int i = l;
        int j = l;

        for (; j <= r - 1; ++j) {
            if (nums[j] > nums[r]) {
                swap(nums[i++], nums[j]);
            }
        }

        swap(nums[i], nums[r]);

        return i;
    }

    int findKthLargest(vector<int> &nums, int k) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int pos = partition(nums, l, r);

            if (pos == k - 1) {
                return nums[pos];
            }

            pos < k - 1 ? l = pos + 1 : r = pos - 1;
        }

        return INT_MAX;
    }
};
