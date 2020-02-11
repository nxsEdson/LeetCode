class Solution {
public:
    int mySqrt(int x) {
        
        if (x == 0)
            return 0;
        
        int i = 1;
        
        while(true)
        {
            int a = int(x/i);
            
            if (a < i)
                break;
            
            i++;
        }
        
        return --i;
    }
};
