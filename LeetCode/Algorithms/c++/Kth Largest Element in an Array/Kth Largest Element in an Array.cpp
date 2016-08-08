bool cmp(int a, int b) {
    return a > b;
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> min_heap;
        for (int i = 0; i < k; i++) {
            min_heap.push_back(nums[i]);
        }
        make_heap(min_heap.begin(), min_heap.end(), cmp);
        int size = nums.size();
        int min = min_heap.front();
        for (int i = k; i < size; i++) {
            if (nums[i] > min) {
                pop_heap(min_heap.begin(), min_heap.end(), cmp);
                min_heap.pop_back();
                min_heap.push_back(nums[i]);
                push_heap(min_heap.begin(), min_heap.end(), cmp);
                min = min_heap.front();
            }
        }
        return min;
    }

};
