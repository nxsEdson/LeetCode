class Solution {
public:
    int romanToInt(string s) {
        
        std::map<char,int> roma;
        
        roma['I'] = 1;
        roma['V'] = 5;
        roma['X'] = 10;
        roma['L'] = 50;
        roma['C'] = 100;
        roma['D'] = 500;
        roma['M'] = 1000;
        
        int output = 0;
        int low_bound = 1;
        
        for(int i = s.size(); i >= 0; i--)
        {
            if(roma[s[i]] >= low_bound)
            {
                output = output+roma[s[i]];
                low_bound = roma[s[i]];
            }
            else
                output = output - roma[s[i]];
        }
        
        return output;
    }
};
