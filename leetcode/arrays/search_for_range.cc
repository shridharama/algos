/* https://leetcode.com/problems/search-for-a-range/

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    int findFirstInstance(vector<int>& nums, int target, int low, int high){
        
        if(low == high){
            if(nums[low] == target)
                return low;
            else 
                return -1;
        }
        
        int mid = (low + high)/2;
        
        if(target <= nums[mid])
            return findFirstInstance(nums, target, low, mid);
        else 
            return findFirstInstance(nums,target,mid+1,high);
        
    }
    
    int findLastInstance(vector<int>& nums, int target, int low, int high){
        
        if(low == high){
            if(nums[low] == target)
                return low;
            else 
                return -1;
        }
        //assign mid to be ceil((low+high)/2.0)
        int mid = (low+high)-((low + high)/2);
        
        if(target < nums[mid])
            return findLastInstance(nums, target, low, mid-1);
        else 
            return findLastInstance(nums,target,mid,high);
        
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        int first_instance = findFirstInstance(nums, target, 0,nums.size()-1);
        if(first_instance == -1){
            return result;
        }
        result[0] = first_instance;
        result[1] = findLastInstance(nums,target,0,nums.size()-1);
    }
};