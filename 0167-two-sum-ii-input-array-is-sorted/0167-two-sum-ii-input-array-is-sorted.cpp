class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;
        vector<int> ans;
        int i=0, j=numbers.size()-1;

        while(i<j){
            int x= numbers[i]+numbers[j];
            if(x==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(x>target){
                j--;
            }
            else i++;
        }
        return ans;
    }
};