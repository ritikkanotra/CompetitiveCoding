class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }
        int maxr = height[height.size() - 1];
        vector<int> maxr_arr(height.size());
        for (int i = height.size() - 1; i >= 0; i--) {
            maxr = max(maxr, height[i]);
            maxr_arr[i] = maxr;
        }
        int maxl = height[0];
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            maxl = max(maxl, height[i]);
            ans += (min(maxl, maxr_arr[i]) - height[i]);
        }
        return ans;
    }
};
