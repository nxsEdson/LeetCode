class Solution {
public:
    int reverse(int x) {
        
        int output = 0;  

        while(x/10 != 0)
        {      
            if (output > INT_MAX/10 || output < INT_MIN/10)
                return 0;
            
            if (output == INT_MAX/10 && x%10 > 7)
                return 0;
            if (output == INT_MAX/10 && x%10 < -8)
                return 0;
            
            output = output*10 + x%10;
            x = x/10;
        }
        
        if (output > INT_MAX/10 || output < INT_MIN/10)
            return 0;

        if (output == INT_MAX/10 && x%10 > 7)
            return 0;
        if (output == INT_MAX/10 && x%10 < -8)
            return 0;
        
        output = output*10 + x%10;
        
        return output;
    }
};
