class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A, E);
        int right = min(G, C);
        int up = min(D, H);
        int down = max(B, F);
        int share = max(right - left, 0) * max(up - down, 0);
        return (C - A) * (D - B) + (G - E) * (H - F) - share;
    }
};
