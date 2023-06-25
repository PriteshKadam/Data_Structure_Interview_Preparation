// Combination Sum : https://leetcode.com/problems/combination-sum/description/
// Is sum <= current
// Select current index : No increment
// Do not select : Increment
// Else do not select current : Increment

class Solution {
public:
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