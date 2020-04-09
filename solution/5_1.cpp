class Solution {
public:
    string longestPalindrome(string s) {
         
        int n = s.size();
        bool** flag;
        flag = new bool*[n];
        
        for(int i = 0; i < n; i++)
        {
            flag[i] = new bool[n];
        }
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                flag[i][j] = false;
        
        for(int i = 0; i < n; i++)
        {
            flag[i][i] = true;
        }
        
        for(int i = 0; i < n-1; i++)
        {
            if (s[i] == s[i+1])
                flag[i][i+1] = true;
        }
        
        for(int len = 3; len <= s.size(); len++)
        {   
            for(int i = 0; i < n-len+1; i++)
            {   
                if ((flag[i+1][i+len-2]) && (s[i] == s[i+len-1]))
                {
                    flag[i][i+len-1] = true;
                }
            }
        }
    
        for(int len = n; len > 0; len--)
        {
            for(int i = 0; i < n - len + 1; i++)
            {
                if(flag[i][i+len-1])
                {
                    string output = "";
                    for (int j = i; j < i+len; j++)
                        output.push_back(s[j]);
                    return output;
                }
            }
        }
        
        return "";
        
    }
};
