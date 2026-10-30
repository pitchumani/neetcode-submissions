class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea = 0;
        int fidx = 0;
        int ridx = heights.size() - 1;
        while (fidx < ridx) {
            int width = ridx - fidx;
            int height = std::min(heights[fidx], heights[ridx]);
            int area = width * height;
            maxarea = area > maxarea ? area : maxarea;
            if (heights[fidx] < heights[ridx]) ++fidx;
            else --ridx;
        }
        return maxarea;
    }
};
