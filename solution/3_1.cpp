class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int max_length = 0;
        int i = 1;
        
        if(s.size() == 0)
            return 0;
        
        string tmp;
        tmp.push_back(s[0]);
        max_length = 1;
        
        while(i < s.size())
        {
            int found = tmp.find_last_of(s[i]);
            if (found == std::string::npos)
            {
                tmp.push_back(s[i]);
            }
            else
            {
                if (max_length < tmp.size())
                    max_length = tmp.size();
                
                tmp = tmp.substr(found+1);
                tmp.push_back(s[i]);
            }
            
            i++;
        }
        
        if (max_length < tmp.size())
            max_length = tmp.size();
        
        return max_length;
    }
};
