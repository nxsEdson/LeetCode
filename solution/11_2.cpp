class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0;
        int right = height.size()-1;
        
        int max_a = 0;
        while(left < right)
        {
            max_a = max(max_a, min(height[left], height[right])*(right-left));
            
            if(height[left] < height[right])
                left++;
            else
                right--;
            
        }
        
        return max_a;
    }
};
