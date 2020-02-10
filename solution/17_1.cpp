class Solution {
public:
    
    string tmp;
    vector<string> output;
    
    vector<string> letterCombinations(string digits) {
        
        output.clear();
        
        string all_map[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if(digits.size() == 0)
            return output;
        
        int idx = 0;
        getChild(digits, all_map, idx);
        
        return output;
    }
    
    void getChild(string input, string* a, int& idx)
    {
        if (idx >= input.size())
        {
            output.push_back(tmp);
            tmp.pop_back();
            idx--;
            
            return;
        }
        
        int number = int(input[idx] - '2');
        for (int i = 0; i < a[number].size(); i++)
        {
            tmp.push_back(a[number][i]);
            idx++;
            getChild(input, a, idx);
        }
        
        tmp.pop_back();
        idx--;
    }
};
