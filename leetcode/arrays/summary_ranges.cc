/* https://leetcode.com/problems/summary-ranges/

Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        for(int i=0;i<nums.size();){
            ostringstream oss;
            oss<<nums[i];

            int j;
            for(j=i+1;j<nums.size() && nums[j]==nums[j-1]+1;j++);
            if(nums[i] != nums[j-1])
                oss<<"->"<<nums[j-1];
            result.push_back(oss.str());
            i=j;
            
        }
        return result;
    }
};