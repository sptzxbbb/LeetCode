class Solution {
public:
    int hIndex(vector<int>& citations) {
        int index = 0;
        binary(0, citations.size() - 1, citations, index);
        return index;
    }
    void binary(int start, int end, vector<int>& citations, int& index) {
        if (start > end) {
            return;
        }
        int mid = (start + end) / 2;
        int size = citations.size();
        if (citations[mid] >= size - mid) {
            index = max(size - mid, index);
            binary(start, mid - 1, citations, index);
        } else {
            binary(mid + 1, end, citations, index);
        }
        return;
    }
};