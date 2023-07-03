// Combination Sum : https://leetcode.com/problems/combination-sum/description/
/*
Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:

Input: array = [2,3,6,7], target = 7

Output: [[2,2,3],[7]]

Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
             7 is a candidate, and 7 = 7.
             These are the only two combinations.


Example 2:

Input: array = [2], target = 1

Output: []

Explaination: No combination is possible.
*/

// Note :
// Given an array of distinct integers
// The same number may be chosen unlimited number of times
// return the combinations in any order

// Logic:
// If sum <= current number
// Select current index : No increment <- same number may be chosen unlimited number of times
// Do not select : Increment
// Else do not select current : Increment

class Solution {
public:
	
	// Note Input consist of 
    void combinationSum(vector<int>& candidates, int target, int CI , vector<int> &prefix, vector<vector<int>> &out)
    {
        printf("CI : %d \n", CI);
        if(target == 0)
        {
          out.push_back(prefix);
          return;  
        }

        if(CI >= candidates.size())
        {
            printf("Returning CI : %d \n", CI);
            return;
        }

        if(target >= candidates[CI])
        {
            // choose current : do not increment index becoz this element can be chosen again.
            prefix.push_back(candidates[CI]);
            combinationSum(candidates, target - candidates[CI], CI , prefix,out);
            prefix.pop_back();

            // Do not choose current : Increment the index.
            combinationSum(candidates, target , CI + 1, prefix, out);
        }
        else
        {
             // Can not choose current : Increment the index.
            combinationSum(candidates, target , CI + 1, prefix, out);           
        }

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> out;
        vector<int> prefix;
        combinationSum(candidates, target, 0, prefix, out);
        return out;
    }
};