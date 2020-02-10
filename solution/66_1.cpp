class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> output(digits.size()+1);
        int flag = 1;
        
        for (int i = digits.size()-1; i>=0; i--)
        {
            int tmp = digits[i] + flag;
            output[i+1] = tmp%10;
            flag = tmp/10;
        }
        
        if (flag == 1)
            output[0] = 1;
        else
            output.erase(output.begin());
        
        return output;
        
    }
};
