# https://leetcode.com/problems/subsets/

/*
Given an integer array nums of unique elements, return all possible
subsets
(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]

 

Constraints:

    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
    All the numbers of nums are unique.

*/

class Solution {
public:
	// To get all subsets : Choice problem : That is to recurse with 1: skipping current element , & 2 with selecting current element.
	// 
    void AllSubsets(vector<int>& nums, vector<vector<int>> &output, vector<int>& pfx, int index = 0)
    {
        if(index >= nums.size())
        {
            output.push_back(pfx);
            return;
        }
        // Skip current element
        AllSubsets(nums, output, pfx, index+1, sum);

        // Select current element
        pfx.push_back(nums[index]);
        AllSubsets(nums, output, pfx, index+1, sum + nums[index]);
        pfx.pop_back();
    }
	
	void AllSubsetsSum(vector<int>& nums, vector<int> &output, int index = 0, int sum = 0)
    {
        if(index >= nums.size())
        {
            output.push_back(sum);
            return;
        }
        // Skip current element
        AllSubsetsSum(nums, output, index+1, sum);

        // Select current element
        AllSubsetsSum(nums, output, index+1, sum + nums[index]);
    }
	
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> pfx;

        AllSubsets(nums, output,  pfx);
        
        return output;
    }
	
	vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> output;
        AllSubsetsSum(arr, output);
        return output;
    }
};