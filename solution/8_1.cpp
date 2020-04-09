class Solution {
public:
    int myAtoi(string str) {
        
        string num_str = "";
        bool onlynumber = false;
        bool sign = true;
        
        for (int i = 0; i < str.size(); i++)
        {
            if((str[i] == ' ')&&!onlynumber)
                continue;
            
            if((str[i] >= '0') && (str[i] <= '9'))
            {
                num_str.push_back(str[i]);
                onlynumber = true;
            }
            else if ((str[i] == '-')||(str[i] == '+'))
            {
                if(onlynumber)
                    break;
                else
                {
                    sign = (str[i] == '+');
                    onlynumber = true;
                }
            }
            else
                break;
        }
        
        if(num_str == "")
            return 0;
        else
        {
            int num = 0;
            for (int i = 0; i<num_str.size(); i++)
            {
                if (num > (INT_MAX - int(num_str[i] - '0'))/10)
                {
                    if(sign)
                        return INT_MAX;
                    else
                        return INT_MIN;
                }
                
                num = num*10 + int(num_str[i] - '0');
                
            }
            
            if (sign)
                return num;
            else
                return -num;
        }
        
    }
};
