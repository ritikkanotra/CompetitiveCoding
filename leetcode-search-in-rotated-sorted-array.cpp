// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    
    int bsearch(vector<int> nums, int l, int h, int target)
    {
        if(l>h)
            return -1;
        
        int mid=(l+h)/2;
        
        if(nums[mid]==target)
            return mid;
        
        if(nums[l]<=nums[mid])
        {
            if(target>=nums[l] && target<nums[mid])
                return bsearch(nums,l,mid-1,target);
            else
                return bsearch(nums,mid+1,h,target);
        }
        else
        {
            if(target>nums[mid] && target<=nums[h])
                return bsearch(nums,mid+1,h,target);
            else
                return bsearch(nums,l,mid-1,target);
        }
    }
    
    int search(vector<int>& nums, int target) {
        
        if(nums.empty())
            return -1;
        
        int n=nums.size();
        
        return bsearch(nums,0,n-1,target);
    }
};