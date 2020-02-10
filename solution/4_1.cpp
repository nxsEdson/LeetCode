class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double m = nums1.size();
        double n = nums2.size();
        
        if (m == 0)
            return double(nums2[ceil(n/2.0)-1] + nums2[ceil((n+1)/2.0)-1])/2.0;

        if (n == 0)
            return double(nums1[ceil(m/2.0)-1] + nums1[ceil((m+1)/2.0)-1])/2.0;
        
        int len = m+n;
        int idx = 1;  
        int i = 0, j = 0;
        int tmp_num;
        
        bool flag;
        if (nums1[0] <= nums2[0])
        {
            flag = true;
            tmp_num = nums1[0];
        }
        else
        {
            flag = false;
            tmp_num = nums2[0];
        }

        while(idx < ceil(len/2.0))
        {  
            tmp_num = getNext(nums1, nums2, i, j, flag);
            idx++;
        }
        
        if (len%2 == 1)
            return tmp_num;
        else
        {  
            return double((tmp_num + getNext(nums1, nums2, i, j, flag))/2);
        }
    }
    
    double getNext(vector<int>& nums1, vector<int>& nums2, int& i, int& j, bool& flag)
    { 
        if (flag)
        {
            if (i >= nums1.size()-1)
            {
                i++;
                flag = false;
                return nums2[j];
            }
            
            if (j >= nums2.size())
            {
                return nums1[++i];
            }
            
            if (nums1[i+1] <= nums2[j])
            {
                i++;
                flag = true;
                return nums1[i];
            }
            else
            {
                i++;
                flag = false;
                return nums2[j];
            }
        }
        else
        {
            if (j >= nums2.size()-1)
            {
                j++;
                flag = true;
                return nums1[i];
            }
            
            if (i >= nums1.size())
            {
                return nums2[++j];
            }
            
            if (nums2[j+1] <= nums1[i])
            {
                j++;
                flag = false;
                return nums2[j];
            }
            else
            {
                j++;
                flag = true;
                return nums1[i];
            }
        }
    }
};
