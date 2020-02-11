class Solution {
public:
    int maxArea(vector<int>& height) {
        return maxPerStep(height, 0);
    }
    
    int maxPerStep(vector<int>& height, int idx)
    {
        if (idx >= height.size()-1)
            return 0;
            
        int max_a = 0;
        int n = height.size();
        for(int i = idx+1; i < n; i++)
        {
            max_a = max((i-idx)*min(height[idx], height[i]), max_a);
        }
        
        return max(max_a, maxPerStep(height, idx+1));
    }
};
