class Solution {
public:
    void findcombi(int index, vector<int>& arr,int target, vector<int>& temp, vector<vector<int>>& ans){
        //base case
        if(index==arr.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }

        //select or not select
        //1. selecting case
        if(target>=arr[index]){
            
            temp.push_back(arr[index]);
            findcombi(index, arr, target-arr[index], temp, ans);
            // when backtracking
            temp.pop_back();
            /*When you subtract the target (target = target - arr[index]), the change affects subsequent recursive calls. As a result, you lose track of the original target value. This is not what you want when backtracking, where you should undo changes after recursive calls.

Solution:
You should pass the target - arr[index] in the recursive call directly instead of modifying target in place.
Backtracking should leave the target unchanged for other cases.*/
        }
        //2.not selecting case
        findcombi(index+1, arr, target, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        findcombi(0, candidates,target,temp, ans);
        return ans;
    }
};